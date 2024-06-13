#Name: Dahlia Sukaik 
#Email: dahliasukaik@csu.fullerton.edu

#Name: Kristine Vergara 
#Email: kvergara@csu.fullerton.edu

#Name: Elizabeth Mazuca
#Email: elizabethmazuca@csu.fullerton.edu

#g++ flags 

CC := g++
COMPILE_FLAGS :=  -Wall -g -pedantic -std=c++17

#creating variables for the executable                                  

PROJECT1_EXE := project1
PROJECT1_PATH := ./$(PROJECT1_EXE)

#setting my target project1-main and executable to compile the main.cpp            

project1-main: $(PROJECT1_PATH)
	@echo Building $@
	$(PROJECT1_PATH)

$(PROJECT1_PATH): main.cpp
	$(CC) $(COMPILE_FLAGS) main.cpp -o $@


#creating variables for the debugger
PROJECT1_2_EXE := debug-project1
PROJECT1_2_PATH := ./$(PROJECT1_2_EXE)

#setting target debug-project1-main to debug the main.cpp            
debug-project1-main: $(PROJECT1_2_PATH)	
	@echo "Debugger will now launch the main program"
	$(PROJECT1_2_PATH)

$(PROJECT1_2_PATH): main.cpp
	@echo "Building $@"
	gdb -x project1 $@


#cleans the executable files after they've been compiled              
clean:
	@echo Cleaning
	-rm project1
	




