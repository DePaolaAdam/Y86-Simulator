CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = lab4.o MemoryTester.o Memory.o Tools.o RegisterFile.o \
RegisterFileTester.o ConditionCodes.o ConditionCodesTester.o

.C.o:
	$(CC) $(CFLAGS) $< -o $@


ConditionCodes.o: ConditionCodes.h Tools.h

ConditionCodesTester.o: ConditionCodes.h ConditionCodesTester.h 

lab4.o: Memory.h RegisterFile.h MemoryTester.h RegisterFileTester.h ConditionCodes.h ConditionCodesTester.h

Memory.o: Memory.h Tools.h

MemoryTester.o: Memory.h MemoryTester.h

RegisterFile.o: RegisterFile.h Tools.h

RegisterFileTester.o: RegisterFile.h RegisterFileTester.h 

Tools.o: Tools.h

lab4: $(OBJ)

clean:
	rm $(OBJ) lab4

run:

	make lab4
	./run.sh

