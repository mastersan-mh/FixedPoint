################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)g++ -o
RM := rm -f

CFLAGS=-O0 -g3 -Wall

SRCDIR := test

EXECUTABLE := FixedPointTest

LIBS :=

C_SRCS := 
CPP_SRCS := 

OBJS := 

C_SRCS += $(wildcard $(SRCDIR)/*.c)
CPP_SRCS += $(wildcard $(SRCDIR)/*.cpp)

OBJS += \
$(C_SRCS:%.c=%.o) \
$(CPP_SRCS:%.cpp=%.o)

.PHONY: all clean


test/%.o: ./test/%.c
	$(CC) -std=c11 $(CFLAGS) -c -o "$@" "$<"

test/%.o: ./test/%.cpp
	$(CC) -std=c++1y $(CFLAGS) -c -o "$@" "$<"

all: FixedPointTest

FixedPointTest: $(OBJS)
	$(LD) $(EXECUTABLE) $(OBJS) $(LIBS)

clean:
	$(RM) $(EXECUTABLE) $(OBJS)

