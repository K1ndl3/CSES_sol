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
        return false;
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
    if (index == 0) {
        std::cout << "ERROR: task already at the top (MOVE_TO_TOP) \n";
        return false; // already at the top
    }    
    if (!validateIndex(index, _list.size())) return false;
    std::rotate(_list.begin(), _list.begin() + index, _list.begin() + index + 1);
    return true;
}

bool List::moveToBottom(std::size_t index)
{
    if (index == _list.size() - 1) {
        std::cout << "ERROR: task already at the bottom (MOVE_TO_BOTTOM) \n";
        return false;
    }
    if (!validateIndex(index, _list.size())) {
        return false;
    }
    std::rotate(_list.begin() + index, _list.begin() + index + 1, _list.end());
    return true;
}

bool List::writeToFile(std::ofstream &out)
{
    std::size_t size = _list.size();
    char delimiter = '|';
    if (size == 0) {
        std::cout << "ERROR: empty list cannot be saved (WRITE_TO_FILE)\n";
        return false;
    }
    for (std::size_t i = 0; i < size; i++) {
        auto currTask = getTask(i);
        out << currTask->getTitle() << delimiter
            << currTask->getDetails() << delimiter
            << currTask->getPriority() << '\n';
    }
    return true;
}

bool List::readFromFile(std::ifstream &in)
{
    if (!in.is_open()) {  // Check if the file is open
        std::cout << "ERROR: cannot open file (READ_FROM_FILE)\n";
        return false;
    }

    std::string line;
    char delimiter = '|';

    while (std::getline(in, line)) {  // Read each line from the file
        std::size_t firstDelim = line.find(delimiter);
        std::size_t secondDelim = line.find(delimiter, firstDelim + 1);

        if (firstDelim == std::string::npos || secondDelim == std::string::npos) {
            std::cout << "ERROR: invalid file format (READ_FROM_FILE)\n";
            return false;  // Invalid format
        }

        // Extract taskTitle, taskDetails, and priority
        std::string taskTitle = line.substr(0, firstDelim);
        std::string taskDetails = line.substr(firstDelim + 1, secondDelim - firstDelim - 1);
        int priority = std::stoi(line.substr(secondDelim + 1));

        // Validate and add the task
        if (!validateInput(taskTitle, taskDetails, priority)) {
            std::cout << "ERROR: invalid task data (READ_FROM_FILE)\n";
            return false;
        }

        addTask(taskTitle, taskDetails, priority);
    }

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

