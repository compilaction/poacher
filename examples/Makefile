.POSIX:
.SUFFIXES: .cpp .hpp .h .d .prog

include config.mk

CXXSRC = $(shell find . -name "*.cpp") # C++ Sources
PROG 	= $(CXXSRC:.cpp=.prog) 				# Objects
DEP   = $(CXXSRC:.cpp=.d) 					# Dependency files

all: $(PROG)

# Dependencies
-include $(DEP)

# Compilation
.cpp.prog:
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -MMD -o $@ $<

debug: CXXFLAGS += -DDEBUG -g
debug: $(PROG)

clean:
	rm -f $(PROG) $(DEP)

dump: $(PROG)
	objdump -dC $(NAME) > $(NAME).asm

.PHONY: all clean echo
