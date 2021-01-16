CC=g++

FLAGS=-std=c++2a -ggdb -Wall -Wunused-function -Wextra -Wundef -Werror

INCLUDE_DIRS =
INCLUDE= $(foreach p, $(INCLUDE_DIRS), -Isrc/$p)
INCLUDE = src/
LIBS =

SRC = src/main.cpp

OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(SRC))))
FOLDERS = $(sort $(addprefix $(BUILD)/, $(dir $(SRC))))

BUILD = build

.PHONY: main clean tests
all: main
tests: compile_and_run_tests

$(BUILD)/%.o: %.cpp
	$(CC) -c $^ -o $@ -I$(INCLUDE) $(FLAGS)

$(FOLDERS):
	mkdir -p $@

all: $(FOLDERS) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(FLAGS) -I$(INCLUDE) -o build/main

compile_and_run_tests:
	$(CC) tests/tests.cpp -lcmocka -I$(INCLUDE) -ggdb -o build/tests
	./build/tests

clean:
	rm -rf build

vpath %.cpp src

