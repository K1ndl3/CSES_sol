#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <cctype>
#include <cstddef>
#include "task.h"
class List{

public:
    List(List& other) : _list(std::move(other._list)) {}
    List() = default;
    ~List() = default;
    //helper functions
    static std::string& trimLeftWS(std::string& strToTrim); // pass test
    static std::string& trimRightWS(std::string& strToTrim); // pass test
    static std::string& trimEntireString(std::string& s); // pass test
    Task* getTask(std::size_t index); // pass test
    static Task* getTask(std::size_t index);
    inline const int getSize() { return _list.size(); } // no need for test
    // add task to list
    bool addTask(std::string taskTitle, std::string taskDetails, int priority); // pass test
    bool addTask(Task& task); // pass test
    // edit a certain task
    bool editTask(std::string title, std::string details, int priority, std::size_t index);
    // delete as task

    // change order of the list
        // move task up, down, toTop, toBottom, rearrage entire list
private:
    std::vector<std::unique_ptr<Task>> _list;
};