
#include "list.h"

bool List::addTask(std::string taskTitle, std::string taskDetails, int priority)
{
    if(!validateInput(taskTitle, taskDetails, priority)) return false;
    List::trimEntireString(taskTitle);
    List::trimEntireString(taskDetails);
    std::unique_ptr<Task> newTask = Task::createTask(taskTitle, taskDetails, priority);
    _list.push_back(std::move(newTask));
    return true;
}

bool List::addTask(Task &task)
{
    _list.push_back(std::make_unique<Task>(task));
    return true;
}

bool List::editTask(std::string title, std::string details, int priority, std::size_t index)
{
    Task* currTask = List::getTask(index);
    if (!currTask) return false;
    validateInput(title, details, priority);
    trimEntireString(title);
    trimEntireString(details);
    return currTask->Task::editTask(title, details, priority);
}

bool List::deleteTask(std::size_t index)
{
    if (_list.empty()) {
        std::cout << "ERROR: Empty list (DELETE_TASK)";
    }
    if (index >= _list.size()) {
        std::cout << "ERROR: Invalid index (DELETE_TASK)";
        return false;
    }
    _list.erase(_list.begin() + index);
    return true;
}

std::string& List::trimLeftWS(std::string &strToTrim)
{
    if (!isspace(strToTrim[0])) return strToTrim;
    std::string::iterator sIt = strToTrim.begin();
    while(isspace(*sIt)) ++sIt;
    strToTrim.erase(strToTrim.begin(),sIt);
    return strToTrim;
}

std::string& List::trimRightWS(std::string &strToTrim)
{
    int size = strToTrim.size() - 1;
    if (!isspace(strToTrim[size])) return strToTrim;
    std::string::iterator sIt = strToTrim.end() - 1;
    while (sIt != strToTrim.begin() && isspace(*(sIt - 1))) sIt--;
    strToTrim.erase(sIt, strToTrim.end());
    return strToTrim;
}

std::string& List::trimEntireString(std::string &s)
{
    trimLeftWS(s);
    trimRightWS(s);
    return s;
}

bool List::validateInput(std::string &title, std::string &details, int priority)
{
    if (title.empty()) {
        std::cout << "ERROR: title cannot be empty (VALIDATE_INPUT)";
        return false;
    }
    if (details.empty()) {
        std::cout << "ERROR: details cannot be empty (VALIDATE_INPUT)";
        return false;
    }
    if (priority < 1 || priority > 5) {
        std::cout << "ERROR: invalid priority rating (VALIDATE_INPUT)";
        return false;
    }
    return true;
}

Task* List::getTask(std::size_t index)
{
    return _list.at(index).get();
}

