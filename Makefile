
CC := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)g++ -o
RM := rm -f
MKDIR := mkdir -p
RMDIR := rmdir

CFLAGS=-O0 -g3 -Wall -I./src/include/

SRCDIR := src/tests
BUILDDIR ?= build

EXECUTABLE := tests-fixed

LIBS :=
C_SRCS :=
CPP_SRCS :=
OBJS :=

C_SRCS += $(wildcard $(SRCDIR)/*.c)
CPP_SRCS += $(wildcard $(SRCDIR)/*.cpp)
OBJS += \
$(C_SRCS:$(SRCDIR)/%.c=$(BUILDDIR)/%.o) \
$(CPP_SRCS:$(SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

.PHONY: all tests clean

all: tests

tests: $(BUILDDIR) $(OBJS)
	$(LD) $(BUILDDIR)/$(EXECUTABLE) $(OBJS) $(LIBS)

clean:
	$(RM) $(BUILDDIR)/$(EXECUTABLE) $(OBJS)
	$(RMDIR) $(BUILDDIR)

$(BUILDDIR):
	@$(MKDIR) "$(BUILDDIR)"

$(BUILDDIR)/%.o: ./$(SRCDIR)/%.c
	$(CC) -std=c11 $(CFLAGS) -c -o "$@" "$<"

$(BUILDDIR)/%.o: ./$(SRCDIR)/%.cpp
	$(CC) -std=c++1y $(CFLAGS) -c -o "$@" "$<"

