#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "/usr/include/doctest.h"
#include <iostream>
#include "test_doctest.h"


TEST_CASE("Testing the factorial number") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
    CHECK(factorial(10) == 3628800);
}