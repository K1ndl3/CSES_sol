#include "list.h"

bool List::addTask(std::string taskTitle, std::string taskDetails, int priority)
{
    if (taskTitle.empty()) {
        std::cout << "ERROR: cannot leave title empty (CODE: LIST)";
        return false;
    }
    
    if (taskDetails.empty()) {
        std::cout << "ERROR: cannot leave details empty (CODE: LIST)";
        return false;
    }

    if (priority < 1 || priority > 5) {
        std::cout << "ERROR: invalid priority rating (CODE: LIST)";
        return false;
    }

    // cut the ending and trailing whitespaces
    List::trimEntireString(taskTitle);
    List::trimEntireString(taskDetails);
        
    return false;
}

std::string& List::trimLeftWS(std::string &strToTrim)
{
    if (!isspace(strToTrim[0])) return strToTrim; // the check for if string is empty is already apart of another function
    std::string::iterator sIt = strToTrim.begin();
    while(isspace(*sIt)) ++sIt;
    strToTrim.erase(sIt, strToTrim.end());
    return strToTrim;
}

std::string& List::trimRightWS(std::string &strToTrim)
{
    return strToTrim;
}

std::string& List::trimEntireString(std::string &s)
{
    trimLeftWS(s);
    trimRightWS(s);
    return s;
}
