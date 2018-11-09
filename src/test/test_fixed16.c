/**
 * test_fixed16.c
 */

#include "common.h"

#include "../include/fixed/fixed16.h"

/**
 * fixed16
 */
void test_fixed16_abs()
{
    fixed16_t in1;
    fixed16_t out1;

    in1 = 0;
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == 0);

    in1 = 1;
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == 1);

    in1 = 0x7FFF; /* 32767 */
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == 0x7FFF);

    in1 = -1;
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == 1);

    in1 = -0x7FFF; /* -32767 */
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == 0x7FFF);

    in1 = 0x8000; /* -32768 */
    out1 = fixed16_abs(in1);
    TEST_ASSERT(out1 == (fixed16_t)0x8000); /* overflow */

}

void test_fixed16_mul()
{
    fixed16_t in1;
    fixed16_t in2;
    fixed16_t out1;

    in1 = 0;
    in2 = 0;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0);

    in1 = 0x0000;
    in2 = 0x0100;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0000);

    in1 = 0x0100;
    in2 = 0x0100;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0100);

    in1 = 0x0001;
    in2 = 0x0100;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0001);

    in1 = 0xFF00;
    in2 = 0x0100;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00);

    in1 = 0x0001;
    in2 = 0x0001;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0000);

    in1 = 0x00FF;
    in2 = 0x00FF;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x00FE);

    in1 = 0xFF00;
    in2 = 0xFF00;
    out1 = fixed16_mul(in1, in2);
    TEST_ASSERT(out1 == 0x0100); /* overflow */

}

void test_fixed16_div()
{
    fixed16_t in1;
    fixed16_t in2;
    fixed16_t out1;

    in1 = 0x0000;
    in2 = 0x0100;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0000);

    in1 = 0x0100;
    in2 = 0x0100;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0100);

    in1 = 0xFF00;
    in2 = 0x0100;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00);

    in1 = 0x0400;
    in2 = 0x0200;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0200);

    in1 = 0x0001;
    in2 = 0x0100;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0001);

    in1 = 0x0004;
    in2 = 0x0200;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0002);

    in1 = 0x0100;
    in2 = 0x0080;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == 0x0200);

    in1 = 0x7F00;
    in2 = 0x0080;
    out1 = fixed16_div(in1, in2);
    TEST_ASSERT(out1 == (fixed16_t)0xfe00); /* overflow */

}

void test_int_to_fixed16()
{
    int in1;
    fixed16_t out1;

    in1 = 0;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x0000);

    in1 = 1;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x0100);

    in1 = -1;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00);

    in1 = 127;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x7F00);

    in1 = -127;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0x8100);

    in1 = 255;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00); /* overflow */

    in1 = -255;
    out1 = int_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0x0100); /* overflow */

}

void test_double_to_fixed16()
{
    double in1;
    fixed16_t out1;

    in1 = 0.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x0000);

    in1 = 0.5;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x0080);

    in1 = -0.5;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0xff80);

    in1 = 1.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x0100);

    in1 = -1.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00);

    in1 = 127.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == 0x7F00);

    in1 = -127.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0x8100);

    in1 = 255.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0xFF00); /* overflow */

    in1 = -255.0;
    out1 = double_to_fixed16(in1);
    TEST_ASSERT(out1 == (fixed16_t)0x0100); /* overflow */

}

void test_fixed16_to_double()
{
    fixed16_t in1;
    double out1;

    in1 = 0;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == 0.0);

    in1 = 0x0100;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == 1.0);

    in1 = 0xFF00;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == -1.0);

    in1 = 0x0080;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == 0.5);

    in1 = -0x0080;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == -0.5);

    /* min > 0 */
    in1 = 0x0001;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == 0.00390625);

    /* max > 0 */
    in1 = 0x7FFF;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == 127.99609375);

    /* max < 0 */
    in1 = -0x0001;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == -0.00390625);

    /* min < 0 */
    in1 = -0x7FFF;
    out1 = fixed16_to_double(in1);
    TEST_ASSERT(out1 == -127.99609375);

}
