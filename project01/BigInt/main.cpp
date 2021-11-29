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
        BigInt x("+12345");
        sout << x;
        REQUIRE(sout.str() == "12345");
    }
}

TEST_CASE("Constructor with long long"){
    ostringstream sout;

    SUBCASE("-9,223,372,036,854,775,808"){
        BigInt x(-9223372036854775808); //BigInt x(numeric_limits<long long>::min())
        sout << x;
        REQUIRE(sout.str() == "-9223372036854775808");
    }
}

TEST_CASE("operator+"){
    ostringstream sout;
    SUBCASE("123 + 19"){
        BigInt x(123);
        BigInt y(19);

        sout << x + y;
        REQUIRE(sout.str() == "142");
    }
}
/*
Corner Cases:
-0
0000000678
*/