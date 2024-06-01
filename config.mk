#### PROJECT SETTINGS ####
# The name of the executable to be created
BIN_NAME := lwm
# Compiler used
CC ?= gcc
# Extension of source files used in the project
SRC_EXT = c
# Path to the source directory, relative to the makefile
SRC_PATH = ./src
# Space-separated pkg-config libraries used by this project
LIBS = x11
# General compiler flags
COMPILE_FLAGS = -std=c11 -Wall -Wextra
# Additional release-specific flags
RCOMPILE_FLAGS =
# Additional debug-specific flags
DCOMPILE_FLAGS = -ggdb
# Add additional include paths
INCLUDES = -I $(SRC_PATH)
# General linker settings
LINK_FLAGS =
# Additional release-specific linker settings
RLINK_FLAGS = -s
# Additional debug-specific linker settings
DLINK_FLAGS =
# Destination directory, like a jail or mounted system
DESTDIR = /
# Install path (bin/ is appended automatically)
INSTALL_PREFIX = usr/local
#### END PROJECT SETTINGS ####