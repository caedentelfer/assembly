# COMPUTER SCIENCE 244
# Makefile for Tutorial 3
# (c) 2023 University of Stellenbosch

# flags
DEBUG     = -ggdb
OPTIMISE  = -O0
TARGET    = -m32
WARNINGS  = -Wall -Werror -Wextra -ansi -pedantic
CFLAGS    = $(DEBUG) $(OPTIMISE) $(WARNINGS) $(TARGET)
DFLAGS    = # nothing yet....
ASMFLAGS  = -f elf32

# commands
ASM       = nasm
CC        = clang
RM        = rm -f
COMPILE   = $(CC) $(CFLAGS) $(DFLAGS)
ASSEMBLE  = $(ASM) $(ASMFLAGS)

# files
ASM_SRCS  = tut3
C_LIBS    = strtoi
TARGETS   = max power gcd
N_PREFIX  = test_
TESTDIR   = tests

ASM_OBJS  = $(addsuffix .o, $(ASM_SRCS))
C_OBJS    = $(addsuffix .o, $(C_LIBS))
EXES      = $(addprefix $(N_PREFIX), $(TARGETS))

# rules ########################################################################

.PHONY: all clean test

all: $(TARGETS) $(EXES)

test: $(EXES)

$(TARGETS): %: $(N_PREFIX)%.c $(ASM_OBJS) $(C_OBJS)
	$(COMPILE) -o $(<:.c=) $< $(ASM_OBJS) $(C_OBJS)

$(ASM_OBJS): %.o: %.asm %.h
	$(ASSEMBLE) $<

$(C_OBJS): %.o: %.c %.h
	$(COMPILE) -c $<

$(EXES): $(N_PREFIX)%: %
	@echo
	@echo "\033[33m"Testing $< ..."\033[m"
	@for TESTCASE in $$(ls $(TESTDIR)/$<); do \
		timeout 1s ./$@ $$(cat $(TESTDIR)/$</$$TESTCASE); \
	done

clean:
	$(RM) *.o *.map *.s *.bin
	$(RM) $(EXES)
