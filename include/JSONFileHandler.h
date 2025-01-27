#pragma once
#include "task.h"
#include "using.h"

Status stringToStatus(const std::string &status);
std::string statusToString(const Status &status);

class JSONFileHandler
{
  public:
    static bool writeTasksToFile(const std::string &, const std::vector<Task> &);
    static std::vector<Task> readTasksFromFile(const std::string &);
};
