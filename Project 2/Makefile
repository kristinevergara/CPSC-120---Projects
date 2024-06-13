#Name: Kristine Vergara 
#Email: kvergara@csu.fullerton.edu
#Name: Dahlia Sukaik 
#Email: dahliasukaik@csu.fullerton.edu

#including g++ flags

CC := g++
COMPILE_FLAGS := -Wall -pedantic -std=c++17 -g -I. -c
LFLAGS := -Wall -pedantic -std=c++17 -g -I. 

#creating variables for the executable                                  

PROJECT2_EXE := project2.bin
PROJECT2_PATH := ./$(PROJECT2_EXE)
DEFAULT_MAP := map-easy.dat

#setting my target project2 and executable to compile the main.cpp            

project2: $(PROJECT2_PATH)
	@echo Building $@
	$(PROJECT2_PATH)  "$(DEFAULT_MAP)"
	
	
$(PROJECT2_PATH): main.o helper_code.o logic.o dahlia-interface.o map.o
	$(CC) $(LFLAGS) main.o helper_code.o logic.o dahlia-interface.o map.o -o $@


helper_code.o : helper_code.cpp helper_code.hpp
	@echo Building $@
	$(CC) $(COMPILE_FLAGS) helper_code.cpp -o $@

logic.o : logic.cpp helper_code.hpp
	@echo Building $@
	$(CC) $(COMPILE_FLAGS) logic.cpp -o $@

dahlia-interface.o  : dahlia-interface.cpp helper_code.hpp
	@echo Building $@
	$(CC) $(COMPILE_FLAGS) dahlia-interface.cpp -o $@

map.o : map.cpp helper_code.hpp
	@echo Building $@
	$(CC) $(COMPILE_FLAGS) map.cpp -o $@


main.o: main.cpp logic.cpp dahlia-interface.cpp map.cpp helper_code.hpp 
	@echo Building $@
	$(CC) $(COMPILE_FLAGS) main.cpp -o $@




#cleans the executable files after they've been compiled              
clean:
	@echo Cleaning
	-rm *.bin
	-rm *.o
