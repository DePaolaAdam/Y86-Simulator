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
#include "DecodeStage.h"
#include "Status.h"
#include "Debug.h"
bool DecodeStage::doClockLow(PipeReg ** pregs, Stage ** stages)
{
//   D * dreg = (D *) pregs[DREG];
   E * ereg = (E *) pregs[EREG];
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
   setEInput(ereg, dstat, dicode, difun, dvalC, dvalA, dvalB, ddstE, ddstM, dsrcA, dsrcB);
   return false;
}

void DecodeStage::setEInput(E * ereg, uint64_t stat, uint64_t icode, 
                           uint64_t ifun, uint64_t valA, uint64_t dstE,
                           uint64_t valC, uint64_t valB, uint64_t dstM, uint64_t srcA, uint64_t srcB)
{
   ereg->getstat()->setInput(stat);
   ereg->geticode()->setInput(icode);
   ereg->getifun()->setInput(ifun);
   ereg->getvalC()->setInput(valC);
   ereg->getvalA()->setInput(valA);
   ereg->getvalB()->setInput(valB);
   ereg->getdstE()->setInput(dstE);
   ereg->getdstM()->setInput(dstM);
   ereg->getsrcA()->setInput(srcA);
   ereg->getsrcB()->setInput(srcB);

}
void DecodeStage::doClockHigh(PipeReg ** pregs)
{
//   D * dreg = (D *) pregs[DREG];
   E * ereg = (E *) pregs[EREG];

   ereg->getstat()->normal();
   ereg->geticode()->normal();
   ereg->getifun()->normal();
   ereg->getvalC()->normal();
   ereg->getvalA()->normal();
   ereg->getvalB()->normal();
   ereg->getdstE()->normal();
   ereg->getdstM()->normal();
   ereg->getsrcA()->normal();
   ereg->getsrcB()->normal();

//   dreg->getpredPC()->normal();
//   ereg->getstat()->normal();
//   ereg->geticode()->normal();
//   ereg->getifun()->normal();
//   ereg->getrA()->normal();
//   ereg->getrB()->normal();
//   ereg->getvalC()->normal();
//   ereg->getvalP()->normal();
}
