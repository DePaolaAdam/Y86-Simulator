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
#include "WritebackStage.h"
#include "Status.h"
#include "Debug.h"
bool WritebackStage::doClockLow(PipeReg ** pregs, Stage ** stages)
{
	return true;
}
void WritebackStage::doClockHigh(PipeReg ** pregs)
{
}
