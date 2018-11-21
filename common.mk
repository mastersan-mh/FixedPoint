#BUILDDIR ?= build

#prefix :=
#CROSS_COMPILE :=

#PROJ_NAME := fixed
#PROJ_INCLUDEDIR := ./src/include

#TESTS_SRCDIR  := src/tests
#TESTS_INCLUDES := \
#$(PROJ_INCLUDEDIR)


prefix ?= /usr/local
SHELL := /bin/sh
CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)gcc
LD := $(CROSS_COMPILE)g++ -o

MKDIR := mkdir -p

RM := rm -f
RMDIR := rmdir

CP := cp -f

ECHO := @echo

INCLUDEDIR := $(prefix)/include

FLAGS_INCLUDE := $(foreach INCLUDE, $(TESTS_INCLUDES), -I$(INCLUDE))

CFLAGS   := -std=c11 -O0 -g3 -Wall $(FLAGS_INCLUDE)
CXXFLAGS := -std=c++1y -O0 -g3 -Wall $(FLAGS_INCLUDE)

EXECUTABLE := $(BUILDDIR)/tests-$(PROJ_NAME)

LIBS :=
PROJ_HEADERS := \
    $(shell find $(PROJ_INCLUDEDIR)/nostd -type f)
C_SRCS := \
    $(wildcard $(TESTS_SRCDIR)/*.c)
CPP_SRCS := \
    $(wildcard $(TESTS_SRCDIR)/*.cpp)
OBJS := \
    $(C_SRCS:$(TESTS_SRCDIR)/%.c=$(BUILDDIR)/%.o) \
    $(CPP_SRCS:$(TESTS_SRCDIR)/%.cpp=$(BUILDDIR)/%.o)

.PHONY: all install uninstall test clean

all: install

install:
	$(CP) -r ${PROJ_INCLUDEDIR}/* ${INCLUDEDIR}

uninstall:
	-$(RM) -r ${INCLUDEDIR}/nostd/$(PROJ_NAME)
	-$(RMDIR) ${INCLUDEDIR}/nostd

test: $(EXECUTABLE)

$(EXECUTABLE): $(BUILDDIR) $(PROJ_HEADERS) $(OBJS)
	$(LD) $(EXECUTABLE) $(OBJS) $(LIBS)

clean:
	-$(RM) $(EXECUTABLE) $(OBJS)
	-$(RMDIR) $(BUILDDIR)

$(BUILDDIR):
	@$(MKDIR) "$(BUILDDIR)"

$(BUILDDIR)/%.o: ./$(TESTS_SRCDIR)/%.c ./$(TESTS_SRCDIR)/%.h
	$(CC) $(CFLAGS) -c -o "$@" "$<"

$(BUILDDIR)/%.o: ./$(TESTS_SRCDIR)/%.cpp ./$(TESTS_SRCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c -o "$@" "$<"

$(BUILDDIR)/test_main.o: ./$(TESTS_SRCDIR)/test_main.cpp
	$(CXX) $(CXXFLAGS) -c -o "$@" "$<"

