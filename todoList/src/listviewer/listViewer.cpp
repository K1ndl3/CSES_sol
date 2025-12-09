#include "listViewer.h"

void ListViewer::printList(List &list)
{
    std::size_t size = list.getSize();
        if (size == 0) {
            std::cout << "The list is empty.\n";
            return;
        }

        for (std::size_t i = 0; i < size; ++i) {
            Task* task = list.getTask(i);
            if (!task) continue;

            std::string title = task->getTitle();
            std::string details = task->getDetails();
            int priority = task->getPriority();

            // Print the box for the title
            std::cout << "+====================+\n";
            std::cout << "| " << std::setw(2) << i + 1 << ". " << std::left << std::setw(15) << title.substr(0, 15) << " |\n";
            std::cout << "+====================+\n";

            // Print the details and priority
            std::cout << "Details: " << details << "\n";
            std::cout << "Priority: " << priority << "\n\n";
        }
}

void ListViewer::printListMove(List &list)
{
    std::size_t size = list.getSize();
    for (int i = 0; i < size; ++i) {
        std::string title = list.getTask(i)->getTitle();
        std::cout << "+====================+\n";
        std::cout << "| " << std::setw(2) << i + 1 << ". " << std::left << std::setw(15) << title.substr(0, 15) << " |\n";
        std::cout << "+====================+\n\n\n";
    } 
}

void ListViewer::printOptions()
{
    std::cout << "1. Add task\n";
    std::cout << "2. Edit task\n";
    std::cout << "3. Reorder Task\n";
}
