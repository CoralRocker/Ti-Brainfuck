# ----------------------------
# Set NAME to the program name
# Set ICON to the png icon file name
# Set DESCRIPTION to display within a compatible shell
# Set COMPRESSED to "YES" to create a compressed program
# ----------------------------

NAME        ?= TIBF
COMPRESSED  ?= YES
ICON        ?= icon.png
DESCRIPTION ?= "Brainfuck interpreter for Ti84"

# ----------------------------

include $(CEDEV)/include/.makefile
