#include <string>
#include <cstdint>
#include "RegisterFile.h"
#include "PipeRegField.h"
#include "PipeReg.h"
#include "E.h"
#include "F.h"
#include "D.h"
#include "M.h"
#include "W.h"
#include "Stage.h"
#include "MemoryStage.h"
#include "Status.h"
#include "Debug.h"
bool MemoryStage::doClockLow(PipeReg ** pregs, Stage ** stages)
{
//   D * dreg = (D *) pregs[DREG];
   W * ereg = (W *) pregs[EREG];
//   uint64_t icode = 0, ifun = 0, valC = 0, valA = 0, valB = 0, dstE = 0, dstM = 0, srcA = 0, srcB = 0;
//   uint64_t rA = dreg->getrA(), rB = dreg->getrB, stat = dreg->getstat();
	
   //code missing here to select the value of the PC
   //and fetch the instruction from memory
   //Fetching the instruction will allow the icode, ifun,
   //rA, rB, and valC to be set.
   //The lab assignment describes what methods need to be
   //written.
	
   //The value passed to setInput below will need to be changed
//   freg->getpredPC()->setInput(f_pc + 1);

   //provide the input values for the E register
   setEInput(ereg, mstat, micode, mvalE, mvalM, mdstE, mdstM);
   return false;
}

void MemoryStage::setEInput(W * ereg, uint64_t stat, uint64_t icode, 
                           uint64_t valE, uint64_t valM,
                           uint64_t dstE, uint64_t dstM)
{
   ereg->getstat()->setInput(stat);
   ereg->geticode()->setInput(icode);
   ereg->getvalE()->setInput(valE);
   ereg->getvalM()->setInput(valM);
   ereg->getdstE()->setInput(dstE);
   ereg->getdstM()->setInput(dstM);
}
void MemoryStage::doClockHigh(PipeReg ** pregs)
{
   W * ereg = (W *) pregs[EREG];

   ereg->getstat()->normal();
   ereg->geticode()->normal();
   ereg->getvalE()->normal();
   ereg->getvalM()->normal();
   ereg->getdstE()->normal();
   ereg->getdstM()->normal();
}
