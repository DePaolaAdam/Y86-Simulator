CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = lab5.o Memory.o Tools.o RegisterFile.o \
lab5.o Loader.o ConditionCodes.o

.C.o:
	$(CC) $(CFLAGS) $< -o $@

lab5: $(OBJ)

ConditionCodes.o: ConditionCodes.h Tools.h

lab5.o: Memory.h RegisterFile.h ConditionCodes.h 

Memory.o: Memory.h Tools.h

Loader.o: Loader.h Memory.h

RegisterFile.o: RegisterFile.h Tools.h

Tools.o: Tools.h

clean:
	rm $(OBJ) lab5

run:

	make lab5
	./run.sh
