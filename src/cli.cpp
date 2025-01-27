#include "../include/JSONFileHandler.h"
#include "../include/cli.h"
#include "../include/using.h"

void CLI::addTask(const std::string_view &taskName)
{
    Task newTask;
    newTask.id = getLastId(jsonFilePath) + 1;
    newTask.description = taskName;
    newTask.status = Status::TODO;
    newTask.createdAt = getCurrentTime();
    newTask.updatedAt = getCurrentTime();

    tasks.emplace_back(newTask);
}

void CLI::updateTask(const int &taskID, const std::string_view &taskName)
{
}

void CLI::deleteTask(const int &taskID)
{
}

void CLI::markInProgress(const int &taskID)
{
}

void CLI::markDone(const int &taskID)
{
}

void CLI::listTask()
{
    std::vector<Task> tasks = JSONFileHandler::readTasksFromFile(jsonFilePath);
    std::cout << "List of Tasks: " << std::endl;

    if (tasks.empty())
    {
        std::cout << "There are no tasks recorded";
        return;
    }

    for (const auto &task : tasks)
    {
        std::cout << task.id << ". " << task.description << std::endl;
        std::cout << "Task Status: " << statusToString(task.status) << std::endl;
        std::cout << "Task created at: " << task.createdAt << std::endl;
        std::cout << "Task updated at: " << task.updatedAt << std::endl;
        std::cout << std::endl;
    }
}

void CLI::listTaskByStatus(const std::string_view &status)
{
    std::vector<Task> tasks = JSONFileHandler::readTasksFromFile(jsonFilePath);
    std::cout << "List of Tasks by Status - " << status << " : " << std::endl;

    if (tasks.empty())
    {
        std::cout << "There are no tasks recorded with status " << status;
        return;
    }

    for (const auto &task : tasks)
    {
        if (statusToString(task.status) != status)
            continue;

        std::cout << task.id << ". " << task.description << std::endl;
        std::cout << "Task Status: " << statusToString(task.status) << std::endl;
        std::cout << "Task created at: " << task.createdAt << std::endl;
        std::cout << "Task updated at: " << task.updatedAt << std::endl;
        std::cout << std::endl;
    }
}
