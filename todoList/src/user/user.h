#pragma once
#include <memory>
#include <iostream>
#include "../task/task.h"
#include "../list/list.h"
#include "../listviewer/listViewer.h"
#include "../listviewerInterface/listviewerInterface.h"


class User {
public:
    User() : _userList(std::make_unique<List>()) {};
    void run(List& list, ListViewerInterface& viewerInterface);
    void flipRunning();
    inline int getRunning() const { return _running; };

private:
    std::unique_ptr<List> _userList;
    bool _running = false;
};