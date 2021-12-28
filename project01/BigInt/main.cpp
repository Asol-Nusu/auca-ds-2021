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
    SUBCASE("0000002345607"){
        BigInt x("0000002345607");
        sout << x;
        REQUIRE(sout.str() == "2345607");
    }

    SUBCASE("000"){
        BigInt x("000");
        sout << x;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("-0"){
        BigInt x("-0");
        sout << x;
        REQUIRE(sout.str() == "0");
    }
    SUBCASE("+0"){
        BigInt x("+0");
        sout << x;
        REQUIRE(sout.str() == "0");
    }
}

TEST_CASE("Constructor with long long"){
    ostringstream sout;

    SUBCASE("-9,223,372,036,854,775,808"){
        BigInt x(numeric_limits<long long>::min()); //BigInt x(numeric_limits<long long>::min())
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

    SUBCASE("999999 + 1"){
        BigInt x(999999);
        BigInt y(1);

        sout << x + y;
        REQUIRE(sout.str() == "1000000");
    }

    SUBCASE("999999 + 1"){
        BigInt x(999999);
        BigInt y(1);

        sout << x + y;
        REQUIRE(sout.str() == "1000000");
    }

    SUBCASE("-6 + (-6)"){
        BigInt x("-6");
        BigInt y("-6");

        sout << x + y;
        REQUIRE(sout.str() == "-12");
    }

    SUBCASE("-6 + 3"){
        BigInt x("-6");
        BigInt y("3");

        sout << x + y;
        REQUIRE(sout.str() == "-3");
    }
}

TEST_CASE("operator+"){
    ostringstream sout;
    SUBCASE("123 - 19"){
        BigInt x(123);
        BigInt y(19);

        sout << x - y;
        REQUIRE(sout.str() == "104");
    }

    SUBCASE("999999 - 1"){
        BigInt x(999999);
        BigInt y(1);

        sout << x - y;
        REQUIRE(sout.str() == "999998");
    }

    SUBCASE("-6 - (-6)"){
        BigInt x("-6");
        BigInt y("-6");

        sout << x - y;
        REQUIRE(sout.str() == "0");
    }

    SUBCASE("-6 - 3"){
        BigInt x("-6");
        BigInt y("3");

        sout << x - y;
        REQUIRE(sout.str() == "-9");
    }
}

TEST_CASE("operator== and operator!="){
    SUBCASE("19 and 19"){
        BigInt x("19");
        BigInt y("19");

        REQUIRE(x == y);
    }

    SUBCASE("-19 and -19"){
        BigInt x("-19");
        BigInt y("-19");

        REQUIRE(x == y);
    }

    SUBCASE("0 and 0"){
        BigInt x("0");
        BigInt y("0");

        REQUIRE(x == y);
    }

    SUBCASE("-2 and 90"){
        BigInt x("-2");
        BigInt y("90");

        REQUIRE(x != y);
    }

    SUBCASE("-2 and 2"){
        BigInt x("-2");
        BigInt y("2");

        REQUIRE(x != y);
    }

    SUBCASE("13 and 14"){
        BigInt x("13");
        BigInt y("14");

        REQUIRE(x != y);
    }
}

TEST_CASE("operator>"){
    SUBCASE("19 and 123"){
        BigInt x("19");
        BigInt y("123");

        REQUIRE(y > x);
    }

    SUBCASE("-19 and -7"){
        BigInt x("-19");
        BigInt y("-7");

        REQUIRE(y > x);
    }

    SUBCASE("-19 and 7"){
        BigInt x("-19");
        BigInt y("7");

        REQUIRE(y > x);
    }

    SUBCASE("19 and -7"){
        BigInt x("-7");
        BigInt y("19");

        REQUIRE(y > x);
    }
}

TEST_CASE("operator<"){
    SUBCASE("19 and 123"){
        BigInt x("19");
        BigInt y("123");

        REQUIRE(x < y);
    }

    SUBCASE("-19 and -7"){
        BigInt x("-19");
        BigInt y("-7");

        REQUIRE(x < y);
    }

    SUBCASE("-19 and 7"){
        BigInt x("-19");
        BigInt y("7");

        REQUIRE(x < y);
    }

    SUBCASE("19 and -7"){
        BigInt x("-7");
        BigInt y("19");

        REQUIRE(x < y);
    }
}

TEST_CASE("operator<="){
    SUBCASE("19 and 123"){
        BigInt x("19");
        BigInt y("123");

        REQUIRE(x <= y);
    }

    SUBCASE("-19 and -19"){
        BigInt x("-19");
        BigInt y("-19");

        REQUIRE(x <= y);
    }

    SUBCASE("3 and 3"){
        BigInt x("3");
        BigInt y("3");

        REQUIRE(x <= y);
    }

    SUBCASE("-2 and -7"){
        BigInt x("-7");
        BigInt y("-2");

        REQUIRE(x <= y);
    }
}

TEST_CASE("operator>="){
    SUBCASE("19 and 123"){
        BigInt x("19");
        BigInt y("123");

        REQUIRE(y >= x);
    }

    SUBCASE("-19 and -19"){
        BigInt x("-19");
        BigInt y("-19");

        REQUIRE(x >= y);
    }

    SUBCASE("3 and 3"){
        BigInt x("3");
        BigInt y("3");

        REQUIRE(x >= y);
    }

    SUBCASE("-2 and -7"){
        BigInt x("-7");
        BigInt y("-2");

        REQUIRE(y >= x);
    }
}

TEST_CASE("operator*"){
    SUBCASE("9*123"){
        BigInt x("19");
        BigInt y("123");

        REQUIRE(x * y == 123 * 9);
    }

    SUBCASE("-19 and -19"){
        BigInt x("-19");
        BigInt y("-19");

        REQUIRE(x >= y);
    }

    SUBCASE("3 and 3"){
        BigInt x("3");
        BigInt y("3");

        REQUIRE(x >= y);
    }

    SUBCASE("-2 and -7"){
        BigInt x("-7");
        BigInt y("-2");

        REQUIRE(y >= x);
    }
}
