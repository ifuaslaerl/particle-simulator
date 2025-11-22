TARGET_EXEC := simulador

BUILD_DIR := ./build
SRC_DIR := ./src
INCLUDE_DIR := ./include
BIN_DIR := ./bin

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# String substitution for object files
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# String substitution for dependency files
DEPS := $(OBJS:.o=.d)

# Compiler settings
CXX := g++
CXXFLAGS := -Wall -MMD -MP -I$(INCLUDE_DIR)
LIBS := -lGL -lGLEW -lglfw

# Final Target
$(BIN_DIR)/$(TARGET_EXEC): $(OBJS)
	@mkdir -p $(BIN_DIR)
	@echo "Linking $(TARGET_EXEC)..."
	@$(CXX) $(OBJS) -o $@ $(LIBS)
	@echo "Build complete: $(BIN_DIR)/$(TARGET_EXEC)"

# Compile C++ source
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "Compiling $<..."
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependencies
-include $(DEPS)

.PHONY: run clean debug

run: $(BIN_DIR)/$(TARGET_EXEC)
	@echo "Running application..."
	@./$(BIN_DIR)/$(TARGET_EXEC)

debug: CXXFLAGS += -DDEBUG -g
debug: clean $(BIN_DIR)/$(TARGET_EXEC)
	@echo "Running in Debug mode..."
	@./$(BIN_DIR)/$(TARGET_EXEC)

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
