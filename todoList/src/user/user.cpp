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
        /* code */
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
