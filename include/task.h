#pragma once
#include "status.h"
#include <string>

struct Task
{
    int id;
    std::string description;
    Status status;
    std::string createdAt;
    std::string updatedAt;
};
