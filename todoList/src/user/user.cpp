#include "user.h"

void User::run(List& list, ListViewerInterface& viewerInterface)
{
   int userInput = INT16_MAX;
   std::cout << "Welcome. Enter 0 to start. Enter 9 to end";
   std::cin >> userInput;
   if (userInput == 0) flipRunning();
   if (userInput == 9) return;
   while (_running) {
    viewerInterface.printOptions();
    std::cin >> userInput;
    switch (userInput)
    {
    case 1:
        User::addTask(list);
        break;
    case 2:

        break;
    
    case 3:
        break;
    
    default:
        break;
    }
   }
}

void User::flipRunning()
{
    _running = (!_running) ? true : false;
}

bool User::addTask(List& list)
{
    std::string taskTitle;
    std::string taskDetail;
    int priority;
    std::cout << "Enter Task Title: \n";
    std::cin >> taskTitle;
    std::cout << "Enter Task Details: \n";
    std::cin >> taskDetail;
    std::cout << "Enter Task Priority (1-5): \n";
    std::cin >> priority;
    Task task(taskTitle, taskDetail, priority);
    list.addTask(task);
}
