CXX := g++
FLAGS := -Wall -Wpedantic -Wextra
BUILD := ../build/
EXEC := strings
SRC := ./
LIBS := -lboost_serialization

STATIC_ANALYSIS:
	$(MAKE) -C ./ clean 
	scan-build-10 $(MAKE) -C ./ DEFAULT
	
DEFAULT: $(BUILD)$(EXEC).out

$(BUILD)$(EXEC).out: $(BUILD)$(EXEC).o main.cpp
	$(CXX) $(FLAGS) $^ -o $@ $(LIBS)

$(BUILD)$(EXEC).o: $(SRC)$(EXEC).cpp $(SRC)$(EXEC).hpp 
	$(CXX) $(FLAGS) -c $^ $(LIBS)
	mv $(SRC)$(EXEC).o $(BUILD)

clean:
	rm -rf $(BUILD)$(EXEC).o $(BUILD)$(EXEC).out $(SRC)$(EXEC)*.gch 