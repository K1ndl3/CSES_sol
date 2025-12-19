#pragma once
#include <memory>
#include <iostream>
#include <limits>
#include <tuple>
#include "../task/task.h"
#include "../list/list.h"
#include "../listviewer/listViewer.h"
#include "../listviewerInterface/listviewerInterface.h"


class User {
public:
    User() : _userList(std::make_unique<List>()) {};
    void run(List& list, ListViewerInterface& viewerInterface);
    void flipRunning();
    bool addTask(List& list);
    bool editTask(List& list, ListViewerInterface& viewerInterface);
    bool reorderTask(List& list, ListViewerInterface& ListViewerInterface);
    std::tuple<std::string, std::string, int> takeInput();
    inline int getRunning() const { return _running; };
    int getInt();
private:
    std::unique_ptr<List> _userList;
    bool _running = false;
};