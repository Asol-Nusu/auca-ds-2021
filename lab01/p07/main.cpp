#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include "Rational.hpp"

#include <sstream>
#include <cstdint>

using namespace std;

TEST_CASE("Rational: default constructor"){
    const Rational<int> r;

    ostringstream sout; 
    sout << r; 

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Rational: constructor with numerator and denominator"){
    ostringstream sout; //with every subcase, it's in the initial/empty state

    SUBCASE("Test with 1/2"){
        Rational<int> r(1, 2);
        sout << r; 

        REQUIRE(sout.str() == "1/2");
    }

    SUBCASE("Test with 3/2"){
        Rational<int> r(3, 2);
        sout << r; 

        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("Test with 30/25"){
        Rational<int> r(30, 25);
        sout << r; 

        REQUIRE(sout.str() == "6/5");
    }

    SUBCASE("Test with 17/31"){
        Rational<int> r(17, 31);
        sout << r; 

        REQUIRE(sout.str() == "17/31");
    }

    SUBCASE("Test with -20/-30"){
        Rational<int> r(-20, -30);
        sout << r; 

        REQUIRE(sout.str() == "2/3");
    }

    //negative sign should be in the numerator
    SUBCASE("Test with 20/-30"){ 
        Rational<int> r(20, -30);
        sout << r; 

        REQUIRE(sout.str() == "-2/3");
    }

    SUBCASE("Test with 3/0"){
        REQUIRE_THROWS_AS(Rational<int> r(3, 0),runtime_error);
    }
}

TEST_CASE("Rational: addition"){
    ostringstream sout;

    SUBCASE("1/2 + 1/3"){
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 + r2;

        REQUIRE(sout.str() == "5/6");
    }
}

TEST_CASE("Rational: subtraction"){
    ostringstream sout;

    SUBCASE("1/2 - 1/3"){
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 - r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: multiplication"){
    ostringstream sout;

    SUBCASE("1/2 * 1/3"){
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 * r2;

        REQUIRE(sout.str() == "1/6");
    }
}

TEST_CASE("Rational: division"){
    ostringstream sout;

    SUBCASE("1/2 / 1/3"){
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);
        sout << r1 / r2;

        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("1/2 / 0/3"){
        Rational<int> r1(1, 2);
        Rational<int> r2(0, 3);
        REQUIRE_THROWS_AS(r1/r2, runtime_error);
    }
}

//>, <, >=, <=, ==, !=
TEST_CASE("Rational: equality and inequality"){
    SUBCASE("2/3 > 7/8"){
        Rational<int> r1(2,3);
        Rational<int> r2(7,8);
        REQUIRE((r1 > r2) == false);
    }

    SUBCASE("2/3 < 49/56"){
        Rational<int> r1(2,3);
        Rational<int> r2(49,56);
        REQUIRE((r1 < r2) == true);
    }

    SUBCASE("7/9 >= 2/7"){
        Rational<int> r1(7,9);
        Rational<int> r2(2,7);
        REQUIRE((r1 >= r2) == true);
    }

    SUBCASE("7/9 <= 2/7"){
        Rational<int> r1(7,9);
        Rational<int> r2(2,7);
        REQUIRE((r1 <= r2) == false);
    }

    SUBCASE("20/31 == 20/31"){
        Rational<int> r1(20,31);
        Rational<int> r2(20,31);
        REQUIRE((r1 == r2) == true);
    }
    SUBCASE("7/9 <= 2/7"){
        Rational<int> r1(7,9);
        Rational<int> r2(2,7);
        REQUIRE((r1 != r2) == true);
    }
} 

TEST_CASE("Rational: getters"){
    const Rational<int64_t> r;
    REQUIRE(r.numerator() == 0);
    REQUIRE(r.denominator() == 1);
}