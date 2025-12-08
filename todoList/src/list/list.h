#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <cctype>
#include <cstddef>
#include <fstream>
#include <algorithm>
#include "../task/task.h"
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
    static bool validateIndex(std::size_t index, std::size_t size); // pass test
    bool writeToFile(std::ofstream& out);
    bool readFromFile(std::ifstream& out);
    
    bool addTask(std::string taskTitle, std::string taskDetails, int priority);        // pass test
    bool addTask(Task& task);                                                          // pass test
    bool editTask(std::string title, std::string details, int priority, std::size_t index); // pass test
    bool deleteTask(std::size_t index); // pass test
    bool moveTaskUp(std::size_t index);   // pass test
    bool moveTaskDown(std::size_t index); // pass test
    bool moveToTop(std::size_t index);    // pass test
    bool moveToBottom(std::size_t index); // pass test
    
    Task* getTask(std::size_t index);                                                  // pass test
    inline const std::size_t getSize() const { return _list.size(); }                                // no need for test
    
private:
    std::vector<std::unique_ptr<Task>> _list;

    friend class testClass;
};