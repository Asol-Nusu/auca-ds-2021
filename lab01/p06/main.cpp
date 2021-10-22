#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include <vector>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("vector's default constructor"){
    vector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("vector's constructor with count copies"){
    vector<int> v(5);
    
    REQUIRE(v.size() == 5);

    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v2(3);
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0].empty());
    REQUIRE(v2[1].empty());
    REQUIRE(v2[2].empty());

    vector<int> v3(3, 42);
    REQUIRE(v3.size() == 3);
    REQUIRE(v3[0] == 42);
    REQUIRE(v3[1] == 42);
    REQUIRE(v3[2] == 42);
}

TEST_CASE("vector's copy constructor"){
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = v; //two independent vars //value semantics

    v[1] = 1000;

    REQUIRE(v2[1] != v[1]);
    REQUIRE(v[1] == 1000);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("vector's move constructor"){ 
    vector<int> v(3);
    
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = move(v); 
    REQUIRE(v.empty()); //<-
    REQUIRE(v2.size() == 3);

    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
    REQUIRE(v2[2] == 3);
    /*
    move() constructor literally takes and moves. 
    What the 2nd array has now is what it's left with 
    */
}
