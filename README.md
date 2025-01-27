# Task_Tracker

## Overview

Task_Tracker is a command-line tool for managing tasks. It allows you to add, update, delete, and list tasks, as well as mark them as in-progress or done. Tasks are stored in a JSON file.

## Features

- Add a new task
- Update an existing task
- Delete a task
- Mark a task as in-progress
- Mark a task as done
- List all tasks
- List tasks by status

## Installation

1. Clone the repository:

   ```sh
   git clone https://github.com/yourusername/Task_Tracker.git
   cd Task_Tracker
   ```

2. Build the project:
   ```sh
   make
   ```

## Usage

Run the `cli` executable with the desired command and arguments:

```sh
./cli <command> [arguments]
```

### Commands

- `add <task_description>`: Add a new task with the given description.
- `update <task_id> <new_description>`: Update the description of the task with the given ID.
- `delete <task_id>`: Delete the task with the given ID.
- `mark-in-progress <task_id>`: Mark the task with the given ID as in-progress.
- `mark-done <task_id>`: Mark the task with the given ID as done.
- `list`: List all tasks.
- `list <status>`: List tasks by the given status (TODO, IN_PROGRESS, DONE).

### Examples

- Add a new task:

  ```sh
  ./cli add "Finish the project"
  ```

- Update a task:

  ```sh
  ./cli update 1 "Finish the project with documentation"
  ```

- Delete a task:

  ```sh
  ./cli delete 1
  ```

- Mark a task as in-progress:

  ```sh
  ./cli mark-in-progress 1
  ```

- Mark a task as done:

  ```sh
  ./cli mark-done 1
  ```

- List all tasks:

  ```sh
  ./cli list
  ```

- List tasks by status:
  ```sh
  ./cli list TODO
  ```

## License

This project is licensed under the Apache License 2.0. See the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.

## Acknowledgements

- [nlohmann/json](https://github.com/nlohmann/json) for JSON parsing and serialization.

