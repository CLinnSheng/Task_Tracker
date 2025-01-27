#include "../include/JSONFileHandler.h"
#include "../include/using.h"

std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&nowTimeT);

    std::stringstream oss;
    oss << std::put_time(&tm, "Y-%m-%d %H:%M:%S");
    std::string currentTime = oss.str();

    return currentTime;
}

int getLastId(const std::string &filepath)
{
    int maxId{};

    std::vector<Task> tasks = JSONFileHandler::readTasksFromFile(filepath);
    for (const auto &task : tasks)
        if (task.id > maxId)
            maxId = task.id;

    return maxId;
}
