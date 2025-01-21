#include "../include/cli.h"
#include <iostream>
#include <string>
#include <vector>

struct CommandLine
{
    std::string command;           // the command like add, update, mark-done and etc...
    std::vector<std::string> args; // the args that come after the action
};

CommandLine parseCLI(const int &argc, char *argv[])
{
    CommandLine input;
    input.command = argv[1];

    for (int i{2}; i < argc; i++)
        input.args.emplace_back(argv[i]);

    return input;
};

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "No command specified";
        return -1;
    }

    CommandLine commandInput = parseCLI(argc, argv);
    CLI TaskManager;

    if (commandInput.command == "add")
    {
        TaskManager.addTask(commandInput.args[0]);
    }
    else if (commandInput.command == "update")
    {
        TaskManager.updateTask(std::stoi(commandInput.args[0]), commandInput.args[1]);
    }
    else if (commandInput.command == "delete")
    {

        TaskManager.deleteTask(std::stoi(commandInput.args[0]));
    }
    else if (commandInput.command == "mark-in-progress")
    {
        TaskManager.markInProgress(std::stoi(commandInput.args[0]));
    }
    else if (commandInput.command == "mark-done")
    {
        TaskManager.markDone(std::stoi(commandInput.args[0]));
    }
    else if (commandInput.command == "list")
    {
        TaskManager.listTask();
    }
    else if (commandInput.command == "list" && !commandInput.args.empty())
    {
        TaskManager.listTaskByStatus(commandInput.args[0]);
    }
    else
    {
        std::cout << "Error: Enter Non-existing command.";
        return -1;
    }

    return 0;
}
