# ======================================================
#  Project: Brainfuck Interpreter
#  Author:  [Your Name]
#  Purpose: Professional Makefile for C++ project
# ======================================================

# Compiler and Flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2
LDFLAGS  := 

# Directories
SRC_DIR := src
BUILD_DIR := build
TARGET := brainfuck

# Find all .cpp files and create .o paths in build/
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

# Colors for pretty output
GREEN  := \033[0;32m
YELLOW := \033[1;33m
RED    := \033[0;31m
BLUE   := \033[1;34m
RESET  := \033[0m

# Default target
all: $(BUILD_DIR)/$(TARGET)

# Build target
$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	@echo "$(BLUE)[LINK]$(RESET) $@"
	@$(CXX) $(OBJ_FILES) -o $@ $(LDFLAGS)
	@echo "$(GREEN)Build complete: $(BUILD_DIR)/$(TARGET)$(RESET)"

# Compile source files to object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "$(YELLOW)[CXX]$(RESET) $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	@echo "$(BLUE)Running $(TARGET)...$(RESET)"
	@./$(BUILD_DIR)/$(TARGET)

# Debug build
debug: CXXFLAGS += -g -O0
debug: clean all
	@echo "$(GREEN)Debug build ready.$(RESET)"

# Clean build artifacts
clean:
	@echo "$(RED)Cleaning build directory...$(RESET)"
	@rm -rf $(BUILD_DIR)

# Phony targets
.PHONY: all clean run debug
