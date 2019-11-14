# Compiler
CXX ?= clang++

# Compile flags
CXXFLAGS += -O3 -march=native -mtune=native -fPIC

# Error management
CXXFLAGS += -Wall -Wextra -Werror -Wnull-dereference -Wold-style-cast \
            -Wdouble-promotion -Wshadow

# C++ Version
CXXFLAGS += -std=c++17

# Includes
INCLUDES += -I../poacher
CXXFLAGS += $(INCLUDES)

# Linker flags
LDFLAGS += -lm
