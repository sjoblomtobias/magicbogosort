#!/bin/bash

# Compilation script for C files in src/ directory
# Uses C99 standard

# Set compiler and flags
CC=gcc
CFLAGS="-std=c99 -Wall -Wextra -O2"
SRC_DIR="src"
OUTPUT_DIR="out"
EXECUTABLE="magicbogosort"

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Compiling C files with C99 standard...${NC}"

# Check if src directory exists
if [ ! -d "$SRC_DIR" ]; then
    echo -e "${RED}Error: $SRC_DIR directory not found!${NC}"
    exit 1
fi

# Create output directory if it doesn't exist
if [ ! -d "$OUTPUT_DIR" ]; then
    echo "Creating output directory: $OUTPUT_DIR"
    mkdir -p "$OUTPUT_DIR"
fi

# Find all .c files in src directory
C_FILES=$(find "$SRC_DIR" -name "*.c" -type f)

if [ -z "$C_FILES" ]; then
    echo -e "${RED}Error: No .c files found in $SRC_DIR directory!${NC}"
    exit 1
fi

echo "Found C files:"
for file in $C_FILES; do
    echo "  - $file"
done

# Compile all C files into executable
echo -e "\n${YELLOW}Compiling...${NC}"
if $CC $CFLAGS $C_FILES -o "$OUTPUT_DIR/$EXECUTABLE"; then
    echo -e "${GREEN}✓ Compilation successful!${NC}"
    echo -e "Executable created: ${GREEN}$OUTPUT_DIR/$EXECUTABLE${NC}"
    
    # Make executable if not already
    chmod +x "$OUTPUT_DIR/$EXECUTABLE"
    
    echo -e "\nTo run the program:"
    echo -e "  ${YELLOW}$OUTPUT_DIR/$EXECUTABLE${NC}"
else
    echo -e "${RED}✗ Compilation failed!${NC}"
    exit 1
fi