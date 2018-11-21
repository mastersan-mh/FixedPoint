
export BUILDDIR ?= build

export PROJ_NAME := fixed
export PROJ_INCLUDEDIR := ./src/include

export TESTS_SRCDIR := src/tests
export TESTS_INCLUDES := \
$(PROJ_INCLUDEDIR)

include common.mk

