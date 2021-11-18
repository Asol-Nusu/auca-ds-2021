#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <sstream>
#include "BigInt.hpp"
using namespace std;

TEST_CASE("Default Constructor"){
    BigInt a;
    ostringstream sout;
    sout << a;

    REQUIRE(sout.str() == "0");
}