/**
 * test_fixed32.c
 */

#include "common.h"

#include <nostd/fixed/fixed32.h>

/**
 * fixed32
 */
void test_fixed32_abs()
{
    fixed32_t in1;
    fixed32_t out1;

    in1 = 0;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == 0);

    in1 = 1;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == 1);

    in1 = 0x7FFFFFFF;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == 0x7FFFFFFF);

    in1 = -1;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == 1);

    in1 = -0x7FFFFFFF;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == 0x7FFFFFFF);

    in1 = 0x80000000;
    out1 = fixed32_abs(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x80000000); /* overflow */

}

void test_fixed32_mul()
{
    fixed32_t in1;
    fixed32_t in2;
    fixed32_t out1;

    in1 = 0;
    in2 = 0;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0);

    in1 = 0x00000000;
    in2 = 0x00010000;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00000000);

    in1 = 0x00010000;
    in2 = 0x00010000;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00010000);

    in1 = 0x00000001;
    in2 = 0x00010000;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00000001);

    in1 = 0xFFFF0000;
    in2 = 0x00010000;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFF0000);

    in1 = 0x00000001;
    in2 = 0x00000001;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00000000);

    in1 = 0x0000FFFF;
    in2 = 0x0000FFFF;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0000FFFE);

    in1 = 0xFFFF0000;
    in2 = 0xFFFF0000;
    out1 = fixed32_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00010000); /* overflow */

}

void test_fixed32_div()
{
    fixed32_t in1;
    fixed32_t in2;
    fixed32_t out1;

    in1 = 0x00000000;
    in2 = 0x00010000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00000000);

    in1 = 0x00010000;
    in2 = 0x00010000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00010000);

    in1 = 0xFFFF0000;
    in2 = 0x00010000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFF0000);

    in1 = 0x00040000;
    in2 = 0x00020000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00020000);

    in1 = 0x00000001;
    in2 = 0x00010000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00000001);

    in1 = 0x00000004;
    in2 = 0x00020000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00000002);

    in1 = 0x00010000;
    in2 = 0x00008000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == 0x00020000);

    in1 = 0x7FFF0000;
    in2 = 0x00008000;
    out1 = fixed32_div(in1, in2);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFE0000); /* overflow */

}

void test_int_to_fixed32()
{
    int in1;
    fixed32_t out1;

    in1 = 0;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x00000000);

    in1 = 1;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x00010000);

    in1 = -1;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFF0000);

    in1 = 32767;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x7FFF0000);

    in1 = -32767;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x80010000);

    in1 = 65535;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFF0000); /* overflow */

    in1 = -65535;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x00010000); /* overflow */

}

void test_double_to_fixed32()
{
    double in1;
    fixed32_t out1;

    in1 = 0.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x00000000);

    in1 = 0.5;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x00008000);

    in1 = -0.5;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0xffff8000);

    in1 = 1.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x00010000);

    in1 = -1.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0xFFFF0000);

    in1 = 32767.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == 0x7FFF0000);

    in1 = -32767.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x80010000);

    in1 = 65535.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x80000000); /* overflow */

    in1 = -65535.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1 == (fixed32_t)0x80000000); /* overflow */

}

void test_fixed32_to_double()
{
    fixed32_t in1;
    double out1;

    in1 = 0;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == 0.0);

    in1 = 0x00010000;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == 1.0);

    in1 = 0xFFFF0000;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == -1.0);

    in1 = 0x00008000;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == 0.5);

    in1 = -0x00008000;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == -0.5);

    /* min > 0 */
    in1 = 0x00000001;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == 1.52587890625e-05);

    /* max > 0 */
    in1 = 0x7FFFFFFF;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == 32767.999984741211);

    /* max < 0 */
    in1 = -0x00000001;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == -1.52587890625e-05);

    /* min < 0 */
    in1 = -0x7FFFFFFF;
    out1 = fixed32_to_double(in1);
    TEST_ASSERT(out1 == -32767.999984741211);

}
