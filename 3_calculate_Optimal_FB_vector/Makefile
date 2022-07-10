COMPILER   = g++
CFLAGS     = -o
CFILE_NAME = test

BUILD_DIR  = build

CPPFILE_NAME  = ./include/calc_Optimal_Linear_FB_vector.cpp
CPPFILE_NAME += ./include/calc_P_matrix.cpp

HEADER_NAME  = ./include/calc_Optimal_Linear_FB_vector.h
HEADER_NAME += ./include/calc_P_matrix.h

SOFILE_NAME = ./include/calc_Optimal_Linear_FB_vector.so

all: exe_file\
	 execution

so_file:
	$(COMPILER) -shared -fPIC $(CFLAGS) $(SOFILE_NAME) $(HEADER_h) $(CPPFILE_NAME)

exe_file:
	$(COMPILER) $(CFLAGS) $(BUILD_DIR)/$(CFILE_NAME) $(CFILE_NAME).c $(SOFILE_NAME) -lstdc++

execution:
	LD_LIBRARY_PATH=. ./$(BUILD_DIR)/$(CFILE_NAME)

# How to execute main file
# LD_LIBRARY_PATH=. ./main