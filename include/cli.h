#pragma once
#include "task.h"

class CLI
{
  public:
    CLI();
    ~CLI();
    // add task
    void addTask(const std::string_view &);

    // update
    void updateTask(const int &, const std::string_view &);

    // delete
    void deleteTask(const int &);

    // mark-in-progress
    void markInProgress(const int &);

    // mark-done
    void markDone(const int &);
    // list
    void listTask();

    // list task by status
    void listTaskByStatus(const std::string_view &);

  private:
    // list of task
    std::vector<Task> tasks;
    std::string jsonFilePath{"tasks.json"};
};
