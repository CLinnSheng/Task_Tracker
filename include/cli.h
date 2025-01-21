#pragma once

#include "task.h"
#include <string_view>
#include <vector>
class CLI
{
  public:
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
};
