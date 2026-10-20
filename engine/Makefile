CXX				:= g++
SRC_DIR			:= src
INC_DIR			:= include
BUILD_DIR		:= build
TARGET_NAME		:= lob

SRCS			:= $(wildcard $(SRC_DIR)/*.cpp)

COMMON_FLAGS	:= -std=c++23 -Wall -Wextra -Wpedantic -I$(INC_DIR)
DEP_FLAGS		:= -MMD -MP

DEBUG_FLAGS		:= $(COMMON_FLAGS) -g -O0 -DDEBUG -fsanitize=address,undefined
RELEASE_FLAGS	:= $(COMMON_FLAGS) -O3 -DNDEBUG

DEBUG_DIR		:= $(BUILD_DIR)/debug
RELEASE_DIR		:= $(BUILD_DIR)/release
DEBUG_OBJS		:= $(SRCS:$(SRC_DIR)/%.cpp=$(DEBUG_DIR)/%.o)
RELEASE_OBJS	:= $(SRCS:$(SRC_DIR)/%.cpp=$(RELEASE_DIR)/%.o)
DEBUG_OUT		:= $(DEBUG_DIR)/$(TARGET_NAME)
RELEASE_OUT		:= $(RELEASE_DIR)/$(TARGET_NAME)

.PHONY: all debug release run-debug run-release clean

all: debug release

debug: $(DEBUG_OUT)
release: $(RELEASE_OUT)

$(DEBUG_OUT): $(DEBUG_OBJS)
	$(CXX) $(DEBUG_FLAGS) $^ -o $@

$(RELEASE_OUT): $(RELEASE_OBJS)
	$(CXX) $(RELEASE_FLAGS) $^ -o $@

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DEBUG_DIR)/
	$(CXX) $(DEBUG_FLAGS) $(DEP_FLAGS) -c $< -o $@

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.cpp | $(RELEASE_DIR)/
	$(CXX) $(RELEASE_FLAGS) $(DEP_FLAGS) -c $< -o $@

$(DEBUG_DIR)/ $(RELEASE_DIR)/:
	mkdir -p $@

run-debug: debug
	./$(DEBUG_OUT)

run-release: release
	./$(RELEASE_OUT)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEBUG_OBJS:.o=.d) $(RELEASE_OBJS:.o=.d)

