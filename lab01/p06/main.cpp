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
TEST_CASE("vector's move constructor"){ 
    vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.size() == 5);

    vector<int> v1 = move(v); 
    REQUIRE(v.empty()); //<-
    REQUIRE(v1.size() == 5);

    REQUIRE(v1[0] == 1);
    REQUIRE(v1[1] == 2);
    REQUIRE(v1[2] == 3);
    REQUIRE(v1[3] == 4);
    REQUIRE(v1[4] == 5);

    /*
    move() constructor literally takes and moves. 
    What the 2nd array has now is what it's left with 
    */
}
TEST_CASE("vector's constructor with count copies"){
    vector<int> v(5);
    REQUIRE(v.size() == 5);

    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v1(3);
    REQUIRE(v1.size() == 3);

    REQUIRE(v1[0].empty());
    REQUIRE(v1[1].empty());
    REQUIRE(v1[2].empty());

    vector<int> v2(3, 42);
    REQUIRE(v2.size() == 3);
    
    REQUIRE(v2[0] == 42);
    REQUIRE(v2[1] == 42);
    REQUIRE(v2[2] == 42);
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


TEST_CASE("vector's erase method"){
    vector<int> container = {1, 2, 3, 4, 5, 11, 12, 15, 19};
    auto it = container.begin();
    container.erase(it);

    REQUIRE(container[0] == 2); //{^2, 3, 4, ^5, 11, 12, 15, 19}

    container.erase(container.begin(), container.begin() + 4);
    REQUIRE(container[0] == 11);
}

