#include "user.h"

void User::run(List& list, ListViewerInterface& viewerInterface)
{
   std::cout << "Welcome. Enter 0 to start. Enter 9 to end\n";
   int userInput = getInt();
   if (userInput == 0) flipRunning();
   if (userInput == 9) return;
   while (_running) {
    viewerInterface.printOptions();
    userInput = getInt();
    switch (userInput)
    {
    case 1:
        User::addTask(list);
        break;
    case 2:
        User::editTask(list, viewerInterface);
        break;
        
    case 9:
        return;
        
    default:
        std::cout << "Invalid Input\n";
        break;
    }
    viewerInterface.refresh();
    viewerInterface.print(list);
   }
}

void User::flipRunning()
{
    _running = (!_running) ? true : false;
}

bool User::addTask(List& list)
{
    auto [taskTitle, taskDetail, priority] = User::takeInput();
    if(list.addTask(taskTitle, taskDetail, priority)) return true;
    return false;
}

bool User::editTask(List &list, ListViewerInterface& viewerInterface)
{
    viewerInterface.printShort(list);
    std::cout << "Task Index to Edit: \n";
    int index = getInt() - 1;
    auto [title, detail, priority] = User::takeInput();
    if(!list.editTask(title, detail, priority, index)) return false;
    return true;
}

bool User::reorderTask(List &list, ListViewerInterface& ListViewerInterface)
{
    ListViewerInterface.reorderOptions();
    int option = getInt();
    return false;
}

std::tuple<std::string, std::string, int> User::takeInput()
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
    return {taskTitle, taskDetail, priority};
}

int User::getInt() {
    int value;
    while (true) {
        if (std::cin >> value)
            return value;

        std::cin.clear(); // clear fail state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
        std::cout << "Please enter a valid number: ";
    }
}
