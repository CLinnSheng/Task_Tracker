#pragma once
#include "status.h"
#include "using.h"

struct Task
{
    int id;
    std::string description;
    Status status;
    std::string createdAt;
    std::string updatedAt;
};
