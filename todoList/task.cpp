#include "task.h"

void Task::createTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority)
{
    _title = newTaskTitle;
    _details = newTaskDetails;
    _priority = newTaskPriority;
}

bool Task::editTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority)
{
    _title = newTaskTitle;
    _details = newTaskDetails;
    _priority = newTaskPriority;
    return true;
}