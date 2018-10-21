CC = g++
CFLAGS = -g -c -Wall -std=c++11 -Og
OBJ = Memory.o Tools.o RegisterFile.o \
ConditionCodes.o Loader.o FetchStage.o DecodeStage.o \
ExecuteStage.o MemoryStage.o WritebackStage.o \
F.o D.o E.o M.o W.o \
PipeReg.o

.C.o:
	$(CC) $(CFLAGS) $< -o $@


ConditionCodes.o: ConditionCodes.h Tools.h

DecodeStage.o:  RegisterFile.h PipeRegField.h PipeReg.h RegisterFile.h F.h D.h M.h W.h Stage.h DecodeStage.h Status.h Debug.h Memory.h Tools.h 

D.o: Instructions.h RegisterFile.h PipeReg.h PipeRegField.h D.h Status.h

ExecuteStage.o:  RegisterFile.h PipeRegField.h PipeReg.h RegisterFile.h F.h D.h M.h W.h Stage.h ExecuteStage.h Status.h Debug.h Memory.h Tools.h 

E.o: RegisterFile.h Instructions.h PipeRegField.h PipeReg.h E.h Status.h

FetchStage.o:  RegisterFile.h PipeRegField.h PipeReg.h RegisterFile.h F.h D.h M.h W.h Stage.h FetchStage.h Status.h Debug.h Memory.h Tools.h 

F.o: PipeRegField.h PipeReg.h F.h

Loader.o: Loader.h Memory.h

Memory.o: Memory.h Tools.h

MemoryStage.o:  RegisterFile.h PipeRegField.h PipeReg.h RegisterFile.h F.h D.h M.h W.h Stage.h MemoryStage.h Status.h Debug.h Memory.h Tools.h

M.o: RegisterFile.h Instructions.h PipeReg.h M.h Status.h

PipeReg.o: PipeReg.h 

RegisterFile.o: RegisterFile.h Tools.h

Tools.o: Tools.h

WritebackStage.o:   RegisterFile.h PipeRegField.h PipeReg.h RegisterFile.h F.h D.h M.h W.h Stage.h WritebackStage.h Status.h Debug.h Memory.h Tools.h 

W.o: RegisterFile.h Instructions.h PipeRegField.h PipeReg.h W.h Status.h

yees: $(OBJ)

clean:
	rm $(OBJ) yees

run:

	make yees
	./run.sh
