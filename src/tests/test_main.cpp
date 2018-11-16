/**
 * main.c
 */

#include "test_fixed16.h"
#include "test_fixed32.h"

#include "test_Fixed16.hpp"
#include "test_Fixed32.hpp"

#include "common.h"

#include <stdlib.h>

TEST_GLOBAL();

int main()
{
    test_fixed16_abs();
    test_fixed16_mul();
    test_fixed16_div();
    test_int_to_fixed16();
    test_double_to_fixed16();
    test_fixed16_to_double();

    test_Fixed16_abs();
    test_Fixed16_mul();
    test_Fixed16_mul_self();
    test_Fixed16_div();
    test_Fixed16_div_self();
    test_int_to_Fixed16();
    test_double_to_Fixed16();
    test_Fixed16_to_double();

    test_fixed32_abs();
    test_fixed32_mul();
    test_fixed32_div();
    test_int_to_fixed32();
    test_double_to_fixed32();
    test_fixed32_to_double();

    test_Fixed32_abs();
    test_Fixed32_mul();
    test_Fixed32_mul_self();
    test_Fixed32_div();
    test_Fixed32_div_self();
    test_int_to_Fixed32();
    test_double_to_Fixed32();
    test_Fixed32_to_double();

    TEST_ALL_DONE();

    return EXIT_SUCCESS;
}
