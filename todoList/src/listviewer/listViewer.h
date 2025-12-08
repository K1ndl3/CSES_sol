#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>
#include "../list/list.h"
#include "../task/task.h"
class ListViewer {
    // in charge of looking at the changes of list and print the list out
    // use case:
        // print the list during move
        // print UI
        // adapt user input to list's interface
public: 
    ListViewer() = default;
    void printList(List& list);
    void printListMove(List& list);
};