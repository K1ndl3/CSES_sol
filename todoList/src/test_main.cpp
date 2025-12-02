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
    REQUIRE(List::trimRightWS(t1) == "hello");
    REQUIRE(List::trimRightWS(t2) == "hello");
    REQUIRE(List::trimRightWS(t3) == "");
    REQUIRE(List::trimRightWS(t4) == "");
}