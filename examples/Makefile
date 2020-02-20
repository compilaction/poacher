.POSIX:
.SUFFIXES: .cpp .hpp .h .d .prog .run

include config.mk

CXXSRC  = $(shell find . -name "*.cpp") # C++ Sources
PROG    = $(CXXSRC:.cpp=.prog) 	        # Objects
DEP     = $(CXXSRC:.cpp=.d)    	        # Dependency files
RUN     = $(CXXSRC:.cpp=.run)  	        # Run files (virtual)

all: $(PROG)

# Dependencies
-include $(DEP)

# Compilation
.cpp.prog:
	$(CLANG_TRUNK_HOME)/bin/clang++ $(CXXFLAGS) $(LDFLAGS) -MMD -o $@ $<
	#$(CXX) $(CXXFLAGS) $(LDFLAGS) -MMD -o $@ $<

.prog.run:
	./$<

debug: CXXFLAGS += -DDEBUG -g
debug: $(PROG)

run: $(RUN)

clean:
	rm -f $(PROG) $(DEP)

dump: $(PROG)
	objdump -dC $(NAME) > $(NAME).asm

.PHONY: all clean echo
