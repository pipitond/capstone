#
# **************************************************************
# *                Simple C++ Makefile Template                *
# *                                                            *
# * Author: Arash Partow (2003)                                *
# * URL: http://www.partow.net/programming/makefile/index.html *
# *                                                            *
# * Copyright notice:                                          *
# * Free use of this C++ Makefile template is permitted under  *
# * the guidelines and in accordance with the the MIT License  *
# * http://www.opensource.org/licenses/MIT                     *
# *                                                            *
# **************************************************************
#

CXX      := g++
CXXFLAGS := -pedantic-errors -Wall -std=c++11 -g
LDFLAGS  := -lncurses
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := ./
TARGET   := adventure_tests
INCLUDE  := -Iinclude/
INCLUDE	 += -I../include/game_objects
INCLUDE	 += -I../include/room_objects
INCLUDE	 += -I../include/game
SRC      :=	$(wildcard src/*.cpp)			\
	$(wildcard ../src/game_objects/*.cpp)	\
	$(wildcard ../src/room_objects/*.cpp)	\
	$(wildcard ../src/game/*.cpp)			\

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $< $(LDFLAGS) 

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(LDFLAGS) 

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(BUILD)/*
	-rm ./adventure_tests