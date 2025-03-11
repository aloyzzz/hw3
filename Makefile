CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

OBJS := llrec.o llrec-test.o
all: llrectest

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrectest: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec.cpp
llrec-test: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp
valgrind:
	$(VALGRIND) ./llrec-test
clean:
	rm -f *.o rh llrectest *~

.PHONY: clean 