#pragma once
#include <string>
#include <memory>


class Task{
private:
    std::string _title;
    std::string _details;
    int _priority;
    
public:    
    Task(std::string title, std::string details, int priority) : _title(std::move(title)), _details(std::move(details)), _priority(priority) {}
    
    // getters and setters
    void setTitle(std::string newTitle);
    void setTitle(std::string&& newTitle);
    void setDetails(std::string newDetals);
    void setDetails(std::string&& newDetails);
    void setPriority(int priority);

    //create and edit
    static std::unique_ptr<Task> createTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority);
    static std::unique_ptr<Task> createTask(std::string&& newTaskTitle, std::string&& newTaskDetails, int newTaskPriority);
    bool editTask(std::string newTaskTitle, std::string newTaskDetails, int newTaskPriority);
    bool editTask(std::string&& newTaskTitle, std::string&& newTaskDetails, int newTaskPriority);

};