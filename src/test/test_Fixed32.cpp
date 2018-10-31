/**
 * test_Fixed32.cpp
 */

#include "common.h"

#include "../include/fixed/fixed32"

/**
 * fixed32
 */
void test_Fixed32_abs()
{
    Fixed32 in1;
    Fixed32 out1;

    in1.setRawFixed(0);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0);

    in1.setRawFixed(1);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 1);

    in1.setRawFixed(0x7FFFFFFF);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0x7FFFFFFF);

    in1.setRawFixed(-1);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 1);

    in1.setRawFixed(-0x7FFFFFFF);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0x7FFFFFFF);

    in1.setRawFixed(0x80000000);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x80000000); /* overflow */

}

void test_Fixed32_mul()
{
    Fixed32 in1;
    Fixed32 in2;
    Fixed32 out1;

    in1.setRawFixed(0);
    in2.setRawFixed(0);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0);

    in1.setRawFixed(0x00000000);
    in2.setRawFixed(0x00010000);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000000);

    in1.setRawFixed(0x00010000);
    in2.setRawFixed(0x00010000);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00010000);

    in1.setRawFixed(0x00000001);
    in2.setRawFixed(0x00010000);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000001);

    in1.setRawFixed(0xFFFF0000);
    in2.setRawFixed(0x00010000);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFF0000);

    in1.setRawFixed(0x00000001);
    in2.setRawFixed(0x00000001);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000000);

    in1.setRawFixed(0x0000FFFF);
    in2.setRawFixed(0x0000FFFF);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0000FFFE);

    in1.setRawFixed(0xFFFF0000);
    in2.setRawFixed(0xFFFF0000);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00010000); /* overflow */

}

void test_Fixed32_mul_self()
{
    Fixed32 inout1;
    Fixed32 in1;

    inout1.setRawFixed(0);
    in1.setRawFixed(0);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0);

    inout1.setRawFixed(0x00000000);
    in1.setRawFixed(0x00010000);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000000);

    inout1.setRawFixed(0x00010000);
    in1.setRawFixed(0x00010000);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00010000);

    inout1.setRawFixed(0x00000001);
    in1.setRawFixed(0x00010000);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000001);

    inout1.setRawFixed(0xFFFF0000);
    in1.setRawFixed(0x00010000);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == (fixed32_t)0xFFFF0000);

    inout1.setRawFixed(0x00000001);
    in1.setRawFixed(0x00000001);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000000);

    inout1.setRawFixed(0x0000FFFF);
    in1.setRawFixed(0x0000FFFF);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0000FFFE);

    inout1.setRawFixed(0xFFFF0000);
    in1.setRawFixed(0xFFFF0000);
    inout1 *= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00010000); /* overflow */

}

void test_Fixed32_div()
{
    Fixed32 in1;
    Fixed32 in2;
    Fixed32 out1;

    in1.setRawFixed(0x00000000);
    in2.setRawFixed(0x00010000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000000);

    in1.setRawFixed(0x00010000);
    in2.setRawFixed(0x00010000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00010000);

    in1.setRawFixed(0xFFFF0000);
    in2.setRawFixed(0x00010000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFF0000);

    in1.setRawFixed(0x00040000);
    in2.setRawFixed(0x00020000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00020000);

    in1.setRawFixed(0x00000001);
    in2.setRawFixed(0x00010000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000001);

    in1.setRawFixed(0x00000004);
    in2.setRawFixed(0x00020000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00000002);

    in1.setRawFixed(0x00010000);
    in2.setRawFixed(0x00008000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00020000);

    in1.setRawFixed(0x7FFF0000);
    in2.setRawFixed(0x00008000);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFE0000); /* overflow */

}

void test_Fixed32_div_self()
{
    Fixed32 inout1;
    Fixed32 in1;

    inout1.setRawFixed(0x00000000);
    in1.setRawFixed(0x00010000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000000);

    inout1.setRawFixed(0x00010000);
    in1.setRawFixed(0x00010000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00010000);

    inout1.setRawFixed(0xFFFF0000);
    in1.setRawFixed(0x00010000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == (fixed32_t)0xFFFF0000);

    inout1.setRawFixed(0x00040000);
    in1.setRawFixed(0x00020000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00020000);

    inout1.setRawFixed(0x00000001);
    in1.setRawFixed(0x00010000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000001);

    inout1.setRawFixed(0x00000004);
    in1.setRawFixed(0x00020000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00000002);

    inout1.setRawFixed(0x00010000);
    in1.setRawFixed(0x00008000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x00020000);

    inout1.setRawFixed(0x7FFF0000);
    in1.setRawFixed(0x00008000);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == (fixed32_t)0xFFFE0000); /* overflow */

}

void test_int_to_Fixed32()
{
    int in1;
    Fixed32 out1;

    in1 = 0;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x00000000);

    in1 = 1;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x00010000);

    in1 = -1;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFF0000);

    in1 = 32767;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x7FFF0000);

    in1 = -32767;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x80010000);

    in1 = 65535;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFF0000); /* overflow */

    in1 = -65535;
    out1 = int_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x00010000); /* overflow */

}

void test_double_to_Fixed32()
{
    double in1;
    Fixed32 out1;

    in1 = 0.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x00000000);

    in1 = 0.5;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x00008000);

    in1 = -0.5;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xffff8000);

    in1 = 1.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x00010000);

    in1 = -1.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0xFFFF0000);

    in1 = 32767.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x7FFF0000);

    in1 = -32767.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x80010000);

    in1 = 65535.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x80000000); /* overflow */

    in1 = -65535.0;
    out1 = double_to_fixed32(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed32_t)0x80000000); /* overflow */

}

void test_Fixed32_to_double()
{
    Fixed32 in1;
    double out1;

    in1.setRawFixed(0);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 0.0);

    in1.setRawFixed(0x00010000);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 1.0);

    in1.setRawFixed(0xFFFF0000);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -1.0);

    in1.setRawFixed(0x00008000);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 0.5);

    in1.setRawFixed(-0x00008000);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -0.5);

    /* min > 0 */
    in1.setRawFixed(0x00000001);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 1.52587890625e-05);

    /* max > 0 */
    in1.setRawFixed(0x7FFFFFFF);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 32767.999984741211);

    /* max < 0 */
    in1.setRawFixed(-0x00000001);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -1.52587890625e-05);

    /* min < 0 */
    in1.setRawFixed(-0x7FFFFFFF);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -32767.999984741211);

}
