#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <cctype>
#include "task.h"
class List{

public:
    List();
    //helper functions
    static std::string& trimLeftWS(std::string& strToTrim);
    static std::string& trimRightWS(std::string& strToTrim);
    static std::string& trimEntireString(std::string& s);
    // add task to list
    bool addTask(std::string taskTitle, std::string taskDetails, int priority);
    // edit a certain task
    bool editTask(std::string title, std::string details, int priority);
    // delete as task

    // change order of the list
        // move task up, down, toTop, toBottom, rearrage entire list
private:
    std::vector<std::unique_ptr<Task>> _list;
};