#include "task.h"

void Task::setTitle(std::string newTitle)
{
    _title = newTitle;
}

void Task::setTitle(std::string &&newTitle)
{
    _title = std::move(newTitle);
}

void Task::setDetails(std::string newDetals)
{
    _details = newDetals;
}

void Task::setDetails(std::string&& newDetails) {
    _details = std::move(newDetails);
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

std::unique_ptr<Task> Task::createTask(std::string &&newTaskTitle, std::string &&newTaskDetails, int newTaskPriority)
{
    Task newTask(newTaskTitle, newTaskDetails, newTaskPriority);
    std::unique_ptr<Task> newTaskPtr = std::make_unique<Task>(newTask);
    return newTaskPtr;
}

bool Task::editTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority)
{
    setTitle(newTaskTitle);
    setDetails(newTaskDetails);
    setPriority(newTaskPriority);
    return true;
}

bool Task::editTask(std::string &&newTaskTitle, std::string &&newTaskDetails, int newTaskPriority)
{
    setTitle(newTaskTitle);
    setDetails(newTaskDetails);
    setPriority(newTaskPriority);
    return true;
}
