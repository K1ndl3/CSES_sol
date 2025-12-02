#pragma once
#include <string>


class Task{
private:
    std::string _title;
    std::string _details;
    int _priority;
    
public:    
    Task(std::string title, std::string details, int priority) : _title(std::move(title)), _details(std::move(details)), _priority(priority) {}

    void createTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority);
    bool editTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority);

};