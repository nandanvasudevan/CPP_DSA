CXX := g++
FLAGS := -Wall -Wpedantic -Wextra
BUILD := ../build/
EXEC := DiagonalMatrix
SRC := ./
LIBS :=

DEFAULT:
	$(MAKE) -C ./ EXEC
	
STATIC_ANALYSIS:
	$(MAKE) -C ./ clean 
	scan-build-10 $(MAKE) -C ./ DEFAULT

EXEC: $(BUILD)$(EXEC).out

$(BUILD)$(EXEC).out: $(BUILD)$(EXEC).o main.cpp Matrix.cpp Matrix.hpp
	$(CXX) $(FLAGS) $^ -o $@ $(LIBS)

$(BUILD)$(EXEC).o: $(SRC)$(EXEC).cpp $(SRC)$(EXEC).hpp Matrix.cpp Matrix.hpp
	$(CXX) $(FLAGS) -c $^ $(LIBS)
	mv $(SRC)$(EXEC).o $(BUILD)

clean:
	rm -rf $(BUILD)$(EXEC).o $(BUILD)$(EXEC).out $(SRC)$(EXEC)*.gch Matrix*.gch

exec:
	$(MAKE) -C ./ EXEC
	./$(BUILD)$(EXEC).out