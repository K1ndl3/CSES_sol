
#include "list.h"

bool List::addTask(std::string taskTitle, std::string taskDetails, int priority)
{
    if (taskTitle.empty()) {
        std::cout << "ERROR: cannot leave title empty (CODE: LIST)\n";
        return false;
    }
    
    if (taskDetails.empty()) {
        std::cout << "ERROR: cannot leave details empty (CODE: LIST)\n";
        return false;
    }

    if (priority < 1 || priority > 5) {
        std::cout << "ERROR: invalid priority rating (CODE: LIST)\n";
        return false;
    }

    // cut the ending and trailing whitespaces
    List::trimEntireString(taskTitle);
    List::trimEntireString(taskDetails);
    std::unique_ptr<Task> newTask = Task::createTask(taskTitle, taskDetails, priority);
    _list.push_back(std::move(newTask));
    return true;
}

bool List::addTask(Task &task)
{
    _list.push_back(std::move(std::make_unique<Task>(task)));
    return true;
}

bool List::editTask(std::string title, std::string details, int priority, std::size_t index)
{
    // use the index to grab the task
    Task currTask = *List::getTask(index);
    // validate and trim all inputs 
    // use setters of the task class to change the title details or index
    return false;
}

std::string& List::trimLeftWS(std::string &strToTrim)
{
    if (!isspace(strToTrim[0])) return strToTrim; // the check for if string is empty is already apart of another function
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

Task* List::getTask(std::size_t index)
{
    return _list.at(index).get();
}

