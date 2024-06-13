#Name: Kristine Vergara
#CWID: 886992213 
#Email: kvergara@csu.fullerton.edu


#g++ flags
CC := g++
COMPILE_FLAGS := -Wall -pedantic --std=c++17 -g
LINK_FLAGS :=

#	Declaring exectuables
PART_EXE_NAME := final.bin
PART_EXE_PATH := ./$(PART_EXE_NAME)

#	Launch/Run the main executable
final:	$(PART_EXE_PATH)
	@echo "Executing main executable"
	./$(PART_EXE_PATH) 	

#	Displaying 'main.cpp' to user
$(PART_EXE_PATH): 	main.cpp
	@echo "Building $@"
	g++ -Wall	-pedantic --std=c++17 -g main.cpp -o $@
