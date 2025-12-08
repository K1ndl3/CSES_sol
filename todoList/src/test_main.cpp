#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "./test_lib/catch_amalgamated.hpp"
#include "./task/task.h"
#include "./list/list.h"
#include "./listviewer/listViewer.h"

class testClass : public List{
public:
    testClass() {
        addTask("Task 1", "Details 1", 1);
        addTask("Task 2", "Details 2", 2);
        addTask("Task 3", "Details 3", 3);
        addTask("Task 4", "Details 4", 4);
    }

    static bool validateIndex(std::size_t index, std::size_t size) { 
        return List::validateIndex(index, size);
    }    
};

TEST_CASE("List::trimLeftWS") {
    std::string t1 = "    hello";
    std::string t2 = "hello";
    std::string t3 = "";
    std::string t4 = "     ";
    REQUIRE(List::trimLeftWS(t1) == "hello");
    REQUIRE(List::trimLeftWS(t2) == "hello");
    REQUIRE(List::trimLeftWS(t3) == "");
    REQUIRE(List::trimLeftWS(t4) == "");
}

TEST_CASE("List::trimRightWS") {
    std::string t1 = "hello    ";
    std::string t2 = "hello";
    std::string t3 = "     ";
    std::string t4 = "";
    std::string t0 = "h ";
    REQUIRE(List::trimRightWS(t0) == "h");
    REQUIRE(List::trimRightWS(t1) == "hello");
    REQUIRE(List::trimRightWS(t2) == "hello");
    REQUIRE(List::trimRightWS(t3) == "");
    REQUIRE(List::trimRightWS(t4) == "");
}

TEST_CASE("List::trimEntireString") {
    std::string t1 = "  hello  ";
    std::string t2 = " h";
    std::string t3 = "";
    std::string t4 = "  ";
    REQUIRE(List::trimEntireString(t1) == "hello");
    REQUIRE(List::trimEntireString(t2) == "h");
    REQUIRE(List::trimEntireString(t3) == "");
    REQUIRE(List::trimEntireString(t4) == "");
}


TEST_CASE("List::addTask, validate user input") {
    List list;
    REQUIRE(list.List::addTask("", "finish task",4) == false);
    REQUIRE(list.List::addTask("test", "", 4) == false);
    REQUIRE(list.List::addTask("test", "test", 8) == false);
}

TEST_CASE("List::addTask, check for size after adding new task") {
    List list;
    int size = list.List::getSize();
    list.addTask("test", "test", 5);
    REQUIRE(list.getSize() == size + 1);
}

TEST_CASE("List::addTask, check for same object") {
    Task testTask("test", "test", 5);
    Task* addrTestTask = &testTask;
    List list;
    list.addTask(testTask);
    addrTestTask == list.getTask(0);
}

TEST_CASE("List::validateInput") {
    std::string emptyString = "";
    std::string nonEmptyString = "test";
    int validRating = 5;
    int invalidRating = 6;
    REQUIRE(List::validateInput(emptyString, nonEmptyString, validRating) == false);
    REQUIRE(List::validateInput(nonEmptyString, emptyString, validRating) == false);
    REQUIRE(List::validateInput(nonEmptyString, nonEmptyString, invalidRating) == false);
    REQUIRE(List::validateInput(nonEmptyString, nonEmptyString, validRating) == true);
}

TEST_CASE("List::editTask") {
    Task task("test", "test", 1);
    std::string newString = "newtest";
    int newInt = 5;
    List list;
    list.List::addTask(task);
    list.List::editTask(newString, newString, newInt, 0);
    REQUIRE(list.List::getTask(0)->getTitle() == newString);
    REQUIRE(list.List::getTask(0)->getDetails() == newString);
    REQUIRE(list.List::getTask(0)->getPriority() == newInt);
}

TEST_CASE("List::deleteTask - robust test cases") {
    testClass test;

    SECTION("Delete task at the beginning of the list") {
        REQUIRE(test.deleteTask(0) == true);  // Delete the first task
        REQUIRE(test.getSize() == 3);  // Ensure the size is reduced
        REQUIRE(test.getTask(0)->getTitle() == "Task 2");  // Ensure the list is updated
    }

    SECTION("Delete task in the middle of the list") {
        REQUIRE(test.deleteTask(1) == true);  // Delete the second task
        REQUIRE(test.getSize() == 3);  // Ensure the size is reduced
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");  // Ensure the list is updated
    }

    SECTION("Delete task at the end of the list") {
        REQUIRE(test.deleteTask(3) == true);  // Delete the last task
        REQUIRE(test.getSize() == 3);  // Ensure the size is reduced
        REQUIRE(test.getTask(2)->getTitle() == "Task 3");  // Ensure the list is updated
    }

    SECTION("Delete all tasks one by one") {
        REQUIRE(test.deleteTask(0) == true);  // Delete the first task
        REQUIRE(test.deleteTask(0) == true);  // Delete the next task (index shifts)
        REQUIRE(test.deleteTask(0) == true);  // Delete the next task
        REQUIRE(test.deleteTask(0) == true);  // Delete the last task
        REQUIRE(test.getSize() == 0);  // Ensure the list is empty
    }

    SECTION("Delete task from an empty list") {
        while (test.getSize() > 0) {
            test.deleteTask(0);
        }
        REQUIRE(test.getSize() == 0);  // Ensure the list is empty
        REQUIRE(test.deleteTask(0) == false);  // Attempt to delete from an empty list
    }

    SECTION("Delete task with an invalid index (out of bounds)") {
        REQUIRE(test.deleteTask(10) == false);  // Index greater than the size of the list
        REQUIRE(test.deleteTask(-1) == false);  // Negative index
        REQUIRE(test.getSize() == 4);  // Ensure the list remains unchanged
    }

    SECTION("Delete task and verify subsequent tasks shift correctly") {
        REQUIRE(test.deleteTask(1) == true);  // Delete the second task
        REQUIRE(test.getSize() == 3);  // Ensure the size is reduced
        REQUIRE(test.getTask(0)->getTitle() == "Task 1");  // Ensure the first task remains unchanged
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");  // Ensure the third task shifts to the second position
        REQUIRE(test.getTask(2)->getTitle() == "Task 4");  // Ensure the fourth task shifts to the third position
    }

    SECTION("Delete task multiple times with invalid and valid indices") {
        REQUIRE(test.deleteTask(1) == true);  // Delete the second task
        REQUIRE(test.deleteTask(10) == false);  // Invalid index
        REQUIRE(test.deleteTask(0) == true);  // Delete the first task
        REQUIRE(test.deleteTask(5) == false);  // Invalid index
        REQUIRE(test.deleteTask(0) == true);  // Delete the next task
        REQUIRE(test.deleteTask(0) == true);  // Delete the last task
        REQUIRE(test.getSize() == 0);  // Ensure the list is empty
    }
}

TEST_CASE("List::validateIndex") {
    List list;
    Task task("test", "test", 1);
    Task task1("test", "test", 1);
    Task task2("test", "test", 1);
    Task task3("test", "test", 1);
    list.addTask(task);
    list.addTask(task1);
    list.addTask(task2);
    list.addTask(task3);
    std::size_t size = list.getSize();
    REQUIRE(testClass::validateIndex(6, size) == false);
    REQUIRE(testClass::validateIndex(1, size) == true);
    REQUIRE(testClass::validateIndex(-1, size) == false);
    REQUIRE(testClass::validateIndex(3, size) == true);

}

TEST_CASE("List::moveTaskUp") {
    testClass test;
    REQUIRE(test.testClass::moveTaskUp(0) == false);
    REQUIRE(test.testClass::moveTaskUp(1) == true);
    REQUIRE(test.testClass::moveTaskUp(7) == false);
    REQUIRE(test.testClass::moveTaskUp(-1) == false);
}

TEST_CASE("list::moveTaskUp") {
    testClass test;
    test.moveTaskUp(1);
    REQUIRE(test.getTask(0)->getTitle() == "Task 2");
}

TEST_CASE("List::moveTaskUp - edge cases and invalid inputs") {
    testClass test;

    SECTION("Move task at the top of the list (index 0)") {
        REQUIRE(test.moveTaskUp(0) == false);  // Cannot move the first task up
        REQUIRE(test.getTask(0)->getTitle() == "Task 1");  // Ensure the list remains unchanged
    }

    SECTION("Move task in the middle of the list") {
        REQUIRE(test.moveTaskUp(2) == true);  // Move "Task 3" up
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");  // "Task 3" should now be at index 1
        REQUIRE(test.getTask(2)->getTitle() == "Task 2");  // "Task 2" should now be at index 2
    }

    SECTION("Move task at the bottom of the list") {
        REQUIRE(test.moveTaskUp(3) == true);  // Move "Task 4" up
        REQUIRE(test.getTask(2)->getTitle() == "Task 4");  // "Task 4" should now be at index 2
        REQUIRE(test.getTask(3)->getTitle() == "Task 3");  // "Task 3" should now be at index 3
    }

    SECTION("Invalid index (out of bounds)") {
        REQUIRE(test.moveTaskUp(7) == false);  // Index out of bounds
        REQUIRE(test.moveTaskUp(-1) == false);  // Negative index (invalid)
    }

    SECTION("Move multiple tasks up sequentially") {
        REQUIRE(test.moveTaskUp(3) == true);  // Move "Task 4" up
        REQUIRE(test.moveTaskUp(2) == true);  // Move "Task 4" up again
        REQUIRE(test.getTask(1)->getTitle() == "Task 4");  // "Task 4" should now be at index 1
        REQUIRE(test.getTask(2)->getTitle() == "Task 2");  // "Task 3" should now be at index 2
        REQUIRE(test.getTask(3)->getTitle() == "Task 3");  // "Task 2" should now be at index 3
    }

    SECTION("Move task up in a single-item list") {
        testClass singleTaskList;
        singleTaskList.deleteTask(1);  // Remove all tasks except the first one
        singleTaskList.deleteTask(1);
        singleTaskList.deleteTask(1);
        REQUIRE(singleTaskList.getSize() == 1);  // Ensure only one task remains
        REQUIRE(singleTaskList.moveTaskUp(0) == false);  // Cannot move the only task up
    }
}

TEST_CASE("List::moveTaskDown - edge cases and invalid inputs") {
    testClass test;

    SECTION("Move task at the bottom of the list (last index)") {
        REQUIRE(test.moveTaskDown(3) == false);  // Cannot move the last task down
        REQUIRE(test.getTask(3)->getTitle() == "Task 4");  // Ensure the list remains unchanged
    }

    SECTION("Move task in the middle of the list") {
        REQUIRE(test.moveTaskDown(1) == true);  // Move "Task 2" down
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");  // "Task 3" should now be at index 1
        REQUIRE(test.getTask(2)->getTitle() == "Task 2");  // "Task 2" should now be at index 2
    }

    SECTION("Move task at the top of the list") {
        REQUIRE(test.moveTaskDown(0) == true);  // Move "Task 1" down
        REQUIRE(test.getTask(0)->getTitle() == "Task 2");  // "Task 2" should now be at index 0
        REQUIRE(test.getTask(1)->getTitle() == "Task 1");  // "Task 1" should now be at index 1
    }

    SECTION("Invalid index (out of bounds)") {
        REQUIRE(test.moveTaskDown(7) == false);  // Index out of bounds
        REQUIRE(test.moveTaskDown(-1) == false);  // Negative index (invalid)
    }

    SECTION("Move multiple tasks down sequentially") {
        REQUIRE(test.moveTaskDown(0) == true);  // Move "Task 1" down
        REQUIRE(test.moveTaskDown(1) == true);  // Move "Task 1" down again
        REQUIRE(test.getTask(2)->getTitle() == "Task 1");  // "Task 1" should now be at index 2
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");  // "Task 3" should now be at index 1
        REQUIRE(test.getTask(0)->getTitle() == "Task 2");  // "Task 2" should now be at index 0
    }

    SECTION("Move task down in a single-item list") {
        testClass singleTaskList;
        singleTaskList.deleteTask(1);  // Remove all tasks except the first one
        singleTaskList.deleteTask(1);
        singleTaskList.deleteTask(1);
        REQUIRE(singleTaskList.getSize() == 1);  // Ensure only one task remains
        REQUIRE(singleTaskList.moveTaskDown(0) == false);  // Cannot move the only task down
    }
}

TEST_CASE("List::moveToTop - edge cases and invalid inputs") {
    testClass test;

    SECTION("Move task already at the top (index 0)") {
        REQUIRE(test.moveToTop(0) == false);  // Moving the first task to the top should fail
        REQUIRE(test.getTask(0)->getTitle() == "Task 1");  // Ensure the list remains unchanged
    }

    SECTION("Move task from the middle of the list to the top") {
        REQUIRE(test.moveToTop(2) == true);  // Move "Task 3" to the top
        REQUIRE(test.getTask(0)->getTitle() == "Task 3");  // "Task 3" should now be at index 0
        REQUIRE(test.getTask(1)->getTitle() == "Task 1");  // "Task 1" should now be at index 1
        REQUIRE(test.getTask(2)->getTitle() == "Task 2");  // "Task 2" should now be at index 2
    }

    SECTION("Move task from the bottom of the list to the top") {
        REQUIRE(test.moveToTop(3) == true);  // Move "Task 4" to the top
        REQUIRE(test.getTask(0)->getTitle() == "Task 4");  // "Task 4" should now be at index 0
        REQUIRE(test.getTask(1)->getTitle() == "Task 1");  // "Task 1" should now be at index 1
        REQUIRE(test.getTask(2)->getTitle() == "Task 2");  // "Task 2" should now be at index 2
        REQUIRE(test.getTask(3)->getTitle() == "Task 3");  // "Task 3" should now be at index 3
    }

    SECTION("Invalid index (out of bounds)") {
        REQUIRE(test.moveToTop(7) == false);  // Index out of bounds
        REQUIRE(test.moveToTop(-1) == false);  // Negative index (invalid)
    }

    SECTION("Move multiple tasks to the top sequentially") {
        REQUIRE(test.moveToTop(3) == true);  // Move "Task 4" to the top
        REQUIRE(test.getTask(0)->getTitle() == "Task 4");  // "Task 4" should now be at index 0

        REQUIRE(test.moveToTop(3) == true);  // Move "Task 3" to the top
        REQUIRE(test.getTask(0)->getTitle() == "Task 3");  // "Task 3" should now be at index 0
        REQUIRE(test.getTask(1)->getTitle() == "Task 4");  // "Task 4" should now be at index 1
    }

    SECTION("Move task to the top in a single-item list") {
        testClass singleTaskList;
        singleTaskList.deleteTask(1);  // Remove all tasks except the first one
        singleTaskList.deleteTask(1);
        singleTaskList.deleteTask(1);
        REQUIRE(singleTaskList.getSize() == 1);  // Ensure only one task remains
        REQUIRE(singleTaskList.moveToTop(0) == false);  // Moving the only task to the top should fail
        REQUIRE(singleTaskList.getTask(0)->getTitle() == "Task 1");  // Ensure the task remains unchanged
    }
}

TEST_CASE("List::moveToBottom - edge cases and invalid inputs") {
    testClass test;

    SECTION("Move task already at the bottom (last index)") {
        REQUIRE(test.moveToBottom(3) == false);  // Task 4 is already at the bottom
        REQUIRE(test.getTask(3)->getTitle() == "Task 4");  // Ensure the list remains unchanged
    }

    SECTION("Move task from the middle of the list to the bottom") {
        REQUIRE(test.moveToBottom(1) == true);  // Move "Task 2" to the bottom
        REQUIRE(test.getTask(3)->getTitle() == "Task 2");  // "Task 2" should now be at the bottom
        REQUIRE(test.getTask(0)->getTitle() == "Task 1");
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");
        REQUIRE(test.getTask(2)->getTitle() == "Task 4");
    }

    SECTION("Move task from the top of the list to the bottom") {
        REQUIRE(test.moveToBottom(0) == true);  // Move "Task 1" to the bottom
        REQUIRE(test.getTask(3)->getTitle() == "Task 1");  // "Task 1" should now be at the bottom
        REQUIRE(test.getTask(0)->getTitle() == "Task 2");
        REQUIRE(test.getTask(1)->getTitle() == "Task 3");
        REQUIRE(test.getTask(2)->getTitle() == "Task 4");
    }

    SECTION("Invalid index (out of bounds)") {
        REQUIRE(test.moveToBottom(7) == false);  // Index out of bounds
        REQUIRE(test.moveToBottom(-1) == false);  // Negative index (invalid)
    }

    SECTION("Move multiple tasks to the bottom sequentially") {
        REQUIRE(test.moveToBottom(0) == true);  // Move "Task 1" to the bottom
        REQUIRE(test.getTask(3)->getTitle() == "Task 1");  // "Task 1" should now be at the bottom

        REQUIRE(test.moveToBottom(0) == true);  // Move "Task 2" to the bottom
        REQUIRE(test.getTask(3)->getTitle() == "Task 2");  // "Task 2" should now be at the bottom
        REQUIRE(test.getTask(0)->getTitle() == "Task 3");
        REQUIRE(test.getTask(1)->getTitle() == "Task 4");
    }

    SECTION("Move task to the bottom in a single-item list") {
        testClass singleTaskList;
        singleTaskList.deleteTask(1);  // Remove all tasks except the first one
        singleTaskList.deleteTask(1);
        singleTaskList.deleteTask(1);
        REQUIRE(singleTaskList.getSize() == 1);  // Ensure only one task remains
        REQUIRE(singleTaskList.moveToBottom(0) == false);  // Cannot move the only task to the bottom
        REQUIRE(singleTaskList.getTask(0)->getTitle() == "Task 1");  // Ensure the task remains unchanged
    }
}

TEST_CASE("List::writeToFile()") {
    std::ofstream out("./database/list.txt");
    REQUIRE(out.is_open() == true);
    testClass test;
    test.writeToFile(out);
}

TEST_CASE("List::readFromFile") {
    testClass test;
    std::ifstream in("./database/list.txt");
    std::ofstream out("./database/list.txt");
    while (test.getSize() > 0) {
        test.deleteTask(0);
    }
    REQUIRE(test.getSize() == 0);
    REQUIRE(out.is_open() == true);
    test.addTask("in", "in", 5);
    test.writeToFile(out);
    REQUIRE(test.getTask(0)->getTitle() == "in");

}

TEST_CASE("ListViewer::printList") {
    testClass test;
    ListViewer viewer;
    viewer.printList(test);
}

TEST_CASE("ListViewer::printListMove") {
    testClass test;
    ListViewer viewer;
    viewer.printListMove(test);
    SECTION("Intergration test between list and listviewer for movement of task") {
        test.moveTaskUp(3);
        viewer.printListMove(test);
    }
}