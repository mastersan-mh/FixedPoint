/**
 * test_Fixed16.cpp
 */

#include "common.h"

#include "../include/fixed/fixed16"

void test_Fixed16_abs()
{
    nostd::Fixed16 in1;
    nostd::Fixed16 out1;

    in1.setRawFixed(0);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0);

    in1.setRawFixed(1);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 1);

    in1.setRawFixed(0x7FFF); /* 32767 */
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0x7FFF);

    in1.setRawFixed(-1);
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 1);

    in1.setRawFixed(-0x7FFF); /* -32767 */
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == 0x7FFF);

    in1.setRawFixed(0x8000); /* -32768 */
    out1 = in1.toAbs();
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0x8000); /* overflow */

}

void test_Fixed16_mul()
{
    nostd::Fixed16 in1;
    nostd::Fixed16 in2;
    nostd::Fixed16 out1;

    in1.setRawFixed(0);
    in2.setRawFixed(0);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0);

    in1.setRawFixed(0x0000);
    in2.setRawFixed(0x0100);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0000);

    in1.setRawFixed(0x0100);
    in2.setRawFixed(0x0100);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0100);

    in1.setRawFixed(0x0001);
    in2.setRawFixed(0x0100);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0001);

    in1.setRawFixed(0xFF00);
    in2.setRawFixed(0x0100);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00);

    in1.setRawFixed(0x0001);
    in2.setRawFixed(0x0001);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0000);

    in1.setRawFixed(0x00FF);
    in2.setRawFixed(0x00FF);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x00FE);

    in1.setRawFixed(0xFF00);
    in2.setRawFixed(0xFF00);
    out1 = in1 * in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0100); /* overflow */

}

void test_Fixed16_mul_self()
{
    nostd::Fixed16 inout1;
    nostd::Fixed16 in2;

    inout1.setRawFixed(0);
    in2.setRawFixed(0);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0);

    inout1.setRawFixed(0x0000);
    in2.setRawFixed(0x0100);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x0000);

    inout1.setRawFixed(0x0100);
    in2.setRawFixed(0x0100);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x0100);

    inout1.setRawFixed(0x0001);
    in2.setRawFixed(0x0100);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x0001);

    inout1.setRawFixed(0xFF00);
    in2.setRawFixed(0x0100);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == (fixed16_t)0xFF00);

    inout1.setRawFixed(0x0001);
    in2.setRawFixed(0x0001);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x0000);

    inout1.setRawFixed(0x00FF);
    in2.setRawFixed(0x00FF);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x00FE);

    inout1.setRawFixed(0xFF00);
    in2.setRawFixed(0xFF00);
    inout1 *= in2;
    TEST_ASSERT(inout1.toRawFixed() == 0x0100); /* overflow */

}

void test_Fixed16_div()
{
    nostd::Fixed16 in1;
    nostd::Fixed16 in2;
    nostd::Fixed16 out1;

    in1.setRawFixed(0x0000);
    in2.setRawFixed(0x0100);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0000);

    in1.setRawFixed(0x0100);
    in2.setRawFixed(0x0100);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0100);

    in1.setRawFixed(0xFF00);
    in2.setRawFixed(0x0100);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00);

    in1.setRawFixed(0x0400);
    in2.setRawFixed(0x0200);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0200);

    in1.setRawFixed(0x0001);
    in2.setRawFixed(0x0100);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0001);

    in1.setRawFixed(0x0004);
    in2.setRawFixed(0x0200);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0002);

    in1.setRawFixed(0x0100);
    in2.setRawFixed(0x0080);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == 0x0200);

    in1.setRawFixed(0x7F00);
    in2.setRawFixed(0x0080);
    out1 = in1 / in2;
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xfe00); /* overflow */

}

void test_Fixed16_div_self()
{
    nostd::Fixed16 inout1;
    nostd::Fixed16 in1;

    inout1.setRawFixed(0x0000);
    in1.setRawFixed(0x0100);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0000);

    inout1.setRawFixed(0x0100);
    in1.setRawFixed(0x0100);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0100);

    inout1.setRawFixed(0xFF00);
    in1.setRawFixed(0x0100);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == (fixed16_t)0xFF00);

    inout1.setRawFixed(0x0400);
    in1.setRawFixed(0x0200);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0200);

    inout1.setRawFixed(0x0001);
    in1.setRawFixed(0x0100);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0001);

    inout1.setRawFixed(0x0004);
    in1.setRawFixed(0x0200);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0002);

    inout1.setRawFixed(0x0100);
    in1.setRawFixed(0x0080);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == 0x0200);

    inout1.setRawFixed(0x7F00);
    in1.setRawFixed(0x0080);
    inout1 /= in1;
    TEST_ASSERT(inout1.toRawFixed() == (fixed16_t)0xfe00); /* overflow */

}

void test_int_to_Fixed16()
{
    int in1;
    nostd::Fixed16 out1;

    in1 = 0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x0000);

    in1 = 1;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x0100);

    in1 = -1;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00);

    in1 = 127;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x7F00);

    in1 = -127;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0x8100);

    in1 = 255;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00); /* overflow */

    in1 = -255;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0x0100); /* overflow */

}

void test_double_to_Fixed16()
{
    double in1;
    nostd::Fixed16 out1;

    in1 = 0.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x0000);

    in1 = 0.5;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x0080);

    in1 = -0.5;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xff80);

    in1 = 1.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x0100);

    in1 = -1.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00);

    in1 = 127.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == 0x7F00);

    in1 = -127.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0x8100);

    in1 = 255.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0xFF00); /* overflow */

    in1 = -255.0;
    out1.set(in1);
    TEST_ASSERT(out1.toRawFixed() == (fixed16_t)0x0100); /* overflow */

}

void test_Fixed16_to_double()
{
    nostd::Fixed16 in1;
    double out1;

    in1.setRawFixed(0);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 0.0);

    in1.setRawFixed(0x0100);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 1.0);

    in1.setRawFixed(0xFF00);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -1.0);

    in1.setRawFixed(0x0080);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 0.5);

    in1.setRawFixed(-0x0080);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -0.5);

    /* min > 0 */
    in1.setRawFixed(0x0001);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 0.00390625);

    /* max > 0 */
    in1.setRawFixed(0x7FFF);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == 127.99609375);

    /* max < 0 */
    in1.setRawFixed(-0x0001);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -0.00390625);

    /* min < 0 */
    in1.setRawFixed(-0x7FFF);
    out1 = in1.toDouble();
    TEST_ASSERT(out1 == -127.99609375);

}
