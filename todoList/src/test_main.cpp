#define CATCH_CONFIG_MAIN
#include "./test_lib/catch_amalgamated.hpp"
#include "task.h"
#include "list.h"


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
    INFO(size(List::trimRightWS(t1)));
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

TEST_CASE("List::deleteTask") {
    List list;
    Task task("test", "test", 1);
    list.addTask(task);
    list.deleteTask(0);
    REQUIRE(list.List::getSize() == 0);
    REQUIRE(list.deleteTask(1) == false);
}