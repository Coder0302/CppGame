#include <libsinterp/variables.h>
#include <libsinterp/executor.h>
#include <libsinterp/operators.h>

#include <ctest.h>

CTEST(TEST_VARIABLES, make_int_and_change_it)
{
    makeInt("one", 0);
    makeInt("two", 2);
    ASSERT_EQUAL(0, getInt("one"));
    setInt("one", 1);
    ASSERT_EQUAL(1, getInt("one"));
    setInt("one", getInt("one") + getInt("two"));
    ASSERT_EQUAL(3, getInt("one"));
    ASSERT_EQUAL(2, getInt("two"));
}

CTEST(TEST_OPERATOR, logic_operators_test)
{
    ASSERT_EQUAL(1, logicalOperation(" 11 > 3"));
    ASSERT_EQUAL(1, logicalOperation(" 2<   44 "));
    ASSERT_EQUAL(0, logicalOperation("1 ==3 "));
    ASSERT_EQUAL(1, logicalOperation("33 == 33"));
    ASSERT_EQUAL(-1, logicalOperation("33 << 33"));
    ASSERT_EQUAL(-1, logicalOperation("33 === 33"));
    ASSERT_EQUAL(-1, logicalOperation("2 + 3"));
}

CTEST(TEST_OPERATOR, arithmetic_operators_test)
{
    ASSERT_EQUAL(4, arithmeticOperation(" 1 + 3"));
    ASSERT_EQUAL(-2, arithmeticOperation(" 2- 4 "));
    ASSERT_EQUAL(5, arithmeticOperation("2 +3 "));
    ASSERT_EQUAL(0, arithmeticOperation("3 - 3"));
    ASSERT_EQUAL(-1, arithmeticOperation("3 > 3"));
}