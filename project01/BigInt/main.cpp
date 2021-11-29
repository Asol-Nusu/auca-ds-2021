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

TEST_CASE("Constructor with string"){
    ostringstream sout;

    SUBCASE("empty string"){
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("-"){
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }
    SUBCASE("+"){
        REQUIRE_THROWS_AS(BigInt("+"), runtime_error);
    }
    SUBCASE("2334aa12"){
        REQUIRE_THROWS_AS(BigInt("2334aa12"), runtime_error);
    }
    SUBCASE("12345"){
        BigInt x("12345");
        sout << x;
        REQUIRE(sout.str() == "12345");
    }
    SUBCASE("-12345"){
        BigInt x("-12345");
        sout << x;
        REQUIRE(sout.str() == "-12345");
    }
    SUBCASE("+12345"){
        BigInt x("+2345");
        sout << x;
        REQUIRE(sout.str() == "12345");
    }
}