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

TEST_CASE("Rational: getters"){
    Rational<int64_t> r;
    REQUIRE(r.num() == 0);
    REQUIRE(r.den() == 1);
}