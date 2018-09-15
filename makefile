CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = lab4.o MemoryTester.o Memory.o Tools.o RegisterFile.o \
RegisterFileTester.o ConditionCodes.o ConditionCodesTester.o

.C.o:
	$(CC) $(CFLAGS) $< -o $@


ConditionCodes.o: ConditionCodes.c ConditionCodes.h 

ConditionCodesTester.o: ConditionCodesTester.c ConditionCodesTester.h 

Memory.o: Memory.h Tools.h

MemoryTester.o: MemoryTester.h Tools.h

RegisterFile.o: RegisterFile.C RegisterFile.h Tools.h

RegisterFileTester.o: RegisterFileTester.C RegisterFileTester.h Tools.h

Tools.o: Tools.C Tools.h

lab4: $(OBJ)

clean:
	rm $(OBJ) lab4

run:
	make clean
	make lab4
	./run.sh

