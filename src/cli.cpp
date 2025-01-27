#include "../include/JSONFileHandler.h"
#include "../include/cli.h"
#include "../include/using.h"
#include <iostream>

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
    for (auto &task : tasks)
        if (task.id == taskID)
        {
            task.description = taskName;
            task.updatedAt = getCurrentTime();
        }
}

void CLI::deleteTask(const int &taskID)
{
    if (tasks.empty())
    {
        std::cerr << "No tasks recorded" << std::endl;
        return;
    }

    int size(tasks.size());

    if (taskID < 0 || taskID >= size)
    {
        std::cerr << "The taskId is out of bound" << std::endl;
        return;
    }

    if (size == 1 && taskID == tasks[0].id)
    {
        tasks.pop_back();
        return;
    }

    if (taskID == size - 1)
    {
        tasks.pop_back();
        return;
    }

    for (int i{taskID}; i < size - 1; i++)
    {
        tasks[i] = tasks[i + 1];
        tasks[i].id = i;
    }
}

void CLI::markInProgress(const int &taskID)
{
    for (auto &task : tasks)
        if (task.id == taskID)
        {
            task.status = Status::IN_PROGRESS;
            task.updatedAt = getCurrentTime();
            return;
        }
}

void CLI::markDone(const int &taskID)
{
    for (auto &task : tasks)
        if (task.id == taskID)
        {
            task.status = Status::DONE;
            task.updatedAt = getCurrentTime();
            return;
        }
}

void CLI::listTask()
{
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

CLI::CLI()
{
    tasks = JSONFileHandler::readTasksFromFile(jsonFilePath);
}

CLI::~CLI()
{
    JSONFileHandler::writeTasksToFile(jsonFilePath, tasks);
}
