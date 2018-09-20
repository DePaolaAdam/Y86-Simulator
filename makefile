CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = lab4.o MemoryTester.o Memory.o Tools.o RegisterFile.o \
RegisterFileTester.o ConditionCodes.o ConditionCodesTester.o

.C.o:
	$(CC) $(CFLAGS) $< -o $@


ConditionCodes.o: ConditionCodes.c ConditionCodes.h 

ConditionCodesTester.o: ConditionCodesTester.c ConditionCodesTester.h 

<<<<<<< HEAD
lab4.o: lab4.c lab4.h ConditionCodes.c ConditionCodes.h ConditionCodesTester.c ConditionCodesTester.h  Memory.h MemoryTester.h RegisterFile.c RegisterFile.h RegisterFileTester.C RegisterFileTester.h Tools.c Tools.h
=======
lab4.o: lab4.c lab4.h ConditionCodes.c ConditionCodes.h ConditionCodesTester.c ConditionCodesTester.h  Memory.h MemoryTester.h RegisterFile.C RegisterFile.h RegisterFileTester.C RegisterFileTester.h Tools.C Tools.h
>>>>>>> c680ddd4e93b1196d13d7f2302ff798da006ece4

Memory.o: Memory.c Memory.h Tools.h

MemoryTester.o: MemoryTester.h Tools.h

RegisterFile.o: RegisterFile.c RegisterFile.h Tools.h

RegisterFileTester.o: RegisterFileTester.c RegisterFileTester.h Tools.h

Tools.o: Tools.c Tools.h





lab4: $(OBJ)

clean:
	rm $(OBJ) lab4

run:
	make clean
	make lab4
	./run.sh

