#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <algorithm>
#include "task.h"
class List{

public:
    List(List& other) : _list(std::move(other._list)) {}
    List() = default;
    ~List() = default;
    //helper functions
    static std::string& trimLeftWS(std::string& strToTrim);                            // pass test
    static std::string& trimRightWS(std::string& strToTrim);                           // pass test
    static std::string& trimEntireString(std::string& s);                              // pass test
    static bool validateInput(std::string& title, std::string& details, int priority); // pass test
    Task* getTask(std::size_t index);                                                  // pass test
    inline const std::size_t getSize() { return _list.size(); }                                // no need for test

    // add task to list
    bool addTask(std::string taskTitle, std::string taskDetails, int priority);        // pass test
    bool addTask(Task& task);                                                          // pass test
    
    // edit a certain task
    bool editTask(std::string title, std::string details, int priority, std::size_t index); // pass test
    
    // delete a task
    bool deleteTask(std::size_t index); // pass test

    // change order of the list
    bool moveTaskUp(std::size_t index);   // pass test
    bool moveTaskDown(std::size_t index); // pass test
    bool moveToTop(std::size_t index);
    bool moveToBottom(std::size_t);

    // write/read to file
    bool writeToFile(std::ofstream& out);
    bool readFromFile(std::ifstream& out);
private:
    std::vector<std::unique_ptr<Task>> _list;
    static bool validateIndex(std::size_t index, std::size_t size); // pass test

    friend class testClass;
};