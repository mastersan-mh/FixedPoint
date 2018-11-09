/*
 * common.h
 *
 *  Created on: 30 окт. 2018 г.
 *      Author: mastersan
 */

#ifndef SRC_COMMON_H_
#define SRC_COMMON_H_

#include <stdlib.h>
#include <stdio.h>

#define TEST_INFO(format, ...) printf(format "\n", ##__VA_ARGS__)
#define TEST_ERROR(format, ...) printf(format "\n", ##__VA_ARGS__)

#define TEST_GLOBAL() \
        unsigned long itest = 0

#define TEST_ASSERT(cond) \
        do{ \
            if(cond){ TEST_INFO ("[  OK   ] Test #%lu in %s on line %d PASSED!", (unsigned long)itest, __FILE__, __LINE__); } \
            else    { TEST_ERROR("[ ERROR ] Test #%lu invalid status in %s on line %d", (unsigned long)itest, __FILE__, __LINE__); exit(EXIT_FAILURE);} \
            ++itest; \
        }while(0)

#define TEST_ALL_DONE() \
        TEST_INFO("[  OK   ] ALL TESTS PASSED!")

extern unsigned long itest;

#endif /* SRC_COMMON_H_ */
