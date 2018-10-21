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
#include "ExecuteStage.h"
#include "Status.h"
#include "Debug.h"
bool ExecuteStage::doClockLow(PipeReg ** pregs, Stage ** stages)
{
//   D * dreg = (D *) pregs[DREG];
   M * ereg = (M *) pregs[EREG];
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
   setEInput(ereg, estat, eicode, ecnd, evalE, evalA, edstE, edstM);
   return false;
}

void ExecuteStage::setEInput(M * ereg, uint64_t stat, uint64_t icode, 
                           bool cnd, uint64_t valE, uint64_t valA,
                           uint64_t edstE, uint64_t edstM)
{
   ereg->getstat()->setInput(stat);
   ereg->geticode()->setInput(icode);
   ereg->getCnd()->setInput(cnd);
   ereg->getvalE()->setInput(valE);
   ereg->getvalA()->setInput(valA);
   ereg->getdstE()->setInput(edstE);
   ereg->getdstM()->setInput(edstM);
}
void ExecuteStage::doClockHigh(PipeReg ** pregs)
{
   M * ereg = (M *) pregs[EREG];

   ereg->getstat()->normal();
   ereg->geticode()->normal();
   ereg->getCnd()->normal();
   ereg->getvalE()->normal();
   ereg->getvalA()->normal();
   ereg->getdstE()->normal();
   ereg->getdstM()->normal();
}
