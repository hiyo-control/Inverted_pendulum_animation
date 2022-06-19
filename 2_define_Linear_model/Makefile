COMPILER = gcc
CFLAGS = -Wall
LDFLAGS = -lm
BUILD_DIR = build

HEADER  = ./include/define_Linear_model.c
HEADER += ./include/define_Linear_model_function.h

.PHONY: all clean

all: $(BUILD_DIR) $(BUILD_DIR)/test

$(BUILD_DIR)/test: $(BUILD_DIR)/test.o
	$(COMPILER) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(HEADER)

$(BUILD_DIR)/test.o: test.c
	$(COMPILER) $(CFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean: $(BUILD_DIR)
	rm build/*
