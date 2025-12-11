#pragma once
#include <iostream>
#include <iomanip>
#include "../list/list.h"
class ListViewerInterface{
public:
    virtual void printOptions() = 0;
    virtual void refresh() = 0;
    virtual void print(List& list) = 0;
    virtual void printShort(List &list) = 0;
    virtual void reorderOptions() = 0;

    virtual ~ListViewerInterface() = default;
};

class basicViewer : public ListViewerInterface {
    basicViewer() = default;
    void printOptions() override;
    void refresh() override;
    void print(List& list) override;
    void printShort(List &list) override;
    void reorderOptions() override;
};