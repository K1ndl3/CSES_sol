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
        std::cout << "ERROR: Empty list (DELETE_TASK)\n";
    }
    if (index >= _list.size()) {
        std::cout << "ERROR: Invalid index (DELETE_TASK)\n";
        return false;
    }
    _list.erase(_list.begin() + index);
    return true;
}

bool List::moveTaskUp(std::size_t index)
{

    if (index == 0 || !validateIndex(index, _list.size())) {
        std::cout << "ERROR: cannot move task up (MOVE_TASK_UP)\n";
        return false; // cannot move task up bc its at the top
    }
    std::swap(_list.at(index), _list.at(index - 1));
    return true;
}

bool List::moveTaskDown(std::size_t index)
{
    // validate input
    std::size_t size = List::getSize();
    if (index >= _list.size()-1 || !validateIndex(index, size)) {
        std::cout << "ERROR: cannot move task down (MOVE_TASK_DOWN)\n";
        return false;
    }    
    std::swap(_list.at(index), _list.at(index + 1));
    return true;
}

bool List::moveToTop(std::size_t index)
{
    if (index == 0 || index >= getSize() || !validateIndex(index, _list.size())) {
        std::cout << "ERROR: cannot move task to top (MOVE_TASK_TOP)'n";
        return false;
    }
    std::rotate(_list.begin(), _list.begin() + index, _list.begin() + index + 1);
    return true;
}

bool List::validateIndex(std::size_t index, std::size_t size)
{
    if(index >= size || index < 0) {
        std::cout << "ERROR: invalid index (VALIDATE_INDEX)\n";
        return false;
    }
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
    if (strToTrim.empty()) return strToTrim;
    std::string::iterator sIt = strToTrim.end(); // iterator starts one past the last char in the string
    while (sIt != strToTrim.begin()) {
        --sIt; // Decrement the iterator first
        if (!isspace(*sIt)) {
            ++sIt; // Move back to the first non-space character
            break;
        }
    }
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
        std::cout << "ERROR: title cannot be empty (VALIDATE_INPUT)\n";
        return false;
    }
    if (details.empty()) {
        std::cout << "ERROR: details cannot be empty (VALIDATE_INPUT)\n";
        return false;
    }
    if (priority < 1 || priority > 5) {
        std::cout << "ERROR: invalid priority rating (VALIDATE_INPUT)\n";
        return false;
    }
    return true;
}

Task* List::getTask(std::size_t index)
{
    return _list.at(index).get();
}

