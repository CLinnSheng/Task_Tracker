#include "../include/JSONFileHandler.h"
#include "../include/status.h"
#include "../include/using.h"

const std::string directory{"../data/"};

std::string statusToString(const Status &status)
{
    switch (status)
    {
    case Status::DONE:
        return "Done";
    case Status::IN_PROGRESS:
        return "In-Progress";
    case Status::TODO:
        return "To-Do";
    default:
        return "Unkown";
    }
}

Status stringToStatus(const std::string &status)
{
    if (status == "To-Do")
        return Status::TODO;
    if (status == "In-Progress")
        return Status::IN_PROGRESS;
    if (status == "Done")
        return Status::DONE;

    throw std::invalid_argument("Invalid Status String");
}

bool JSONFileHandler::writeTasksToFile(const std::string &filepath, const std::vector<Task> &tasks)
{
    nlohmann::json jsonData = nlohmann::json::array();

    for (const auto &task : tasks)
    {
        nlohmann::json taskJson;
        taskJson["id"] = task.id;
        taskJson["description"] = task.description;
        taskJson["status"] = statusToString(task.status);
        taskJson["createdAt"] = task.createdAt;
        taskJson["updatedAt"] = task.updatedAt;

        jsonData.push_back(taskJson);
    }

    std::ofstream outputfile(directory + filepath, std::ios::trunc);
    if (!outputfile.is_open())
    {
        std::cerr << "Error: Could not open or create file " << filepath << std::endl;
        return false;
    }

    try
    {
        outputfile << jsonData.dump(4);
    }
    catch (const std::exception e)
    {
        std::cerr << "Error: Failed to create Json - " << e.what() << std::endl;
        return false;
    }
    return true;
}

std::vector<Task> JSONFileHandler::readTasksFromFile(const std::string &filepath)
{
    std::ifstream inputFile(directory + filepath);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return {};
    }

    nlohmann::json jsonData;
    try
    {
        inputFile >> jsonData;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: Failed to parse JSON - " << e.what() << std::endl;
        return {};
    }

    std::vector<Task> tasks;
    for (const auto &data : jsonData)
    {
        Task task;
        task.id = data["id"];
        task.status = stringToStatus(data["status"]);
        task.description = data["description"];
        task.createdAt = data["createdAt"];
        task.updatedAt = data["updatedAt"];

        tasks.emplace_back(task);
    }
    return tasks;
}
