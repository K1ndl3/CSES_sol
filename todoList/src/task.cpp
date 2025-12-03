#include "task.h"

void Task::setTitle(std::string newTitle)
{
    _title = newTitle;
}

void Task::setDetails(std::string newDetals)
{
    _details = newDetals;
}

void Task::setPriority(int priority)
{
    _priority = priority;
}

std::unique_ptr<Task> Task::createTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority)
{
    Task newTask(newTaskTitle, newTaskDetails, newTaskPriority);
    std::unique_ptr<Task> taskPtr = std::make_unique<Task>(newTask);
    return taskPtr;
}

bool Task::editTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority)
{
    _title = newTaskTitle;
    _details = newTaskDetails;
    _priority = newTaskPriority;
    return true;
}