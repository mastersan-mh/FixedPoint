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

#define INFO(format, ...) printf(format "\n", ##__VA_ARGS__)
#define ERROR(format, ...) printf(format "\n", ##__VA_ARGS__)

#define TEST_ASSERT(cond) \
        do{ \
            if(cond){ INFO ("[  OK   ] TEST_ASSERT: Test #%lu in %s on line %d PASSED!", (unsigned long)itest, __FILE__, __LINE__); } \
            else    { ERROR("[ ERROR ] TEST_ASSERT: Test #%lu invalid status in %s on line %d", (unsigned long)itest, __FILE__, __LINE__); exit(EXIT_FAILURE);} \
            ++itest; \
        }while(0)

extern size_t itest;

#endif /* SRC_COMMON_H_ */
