CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++20

# DIRECTORIES
SRC_DIR = src
OBJ_DIR = obj

# Executable binary file
EXECUTABLE = cli

# SRC .cpp file
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default Target
all: directories $(EXECUTABLE)

# Create obj directories
directories:
	@mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(EXECUTABLE)

rebuild: clean all

.PHONY: all directories clean rebuild
