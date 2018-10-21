class DecodeStage: public Stage
{
	uint64_t dstat;
   	uint64_t dicode;
    uint64_t difun;
    uint64_t dvalA;
    uint64_t dvalB;
    uint64_t dvalC;
    uint64_t ddstE = RNONE;
	uint64_t ddstM = RNONE;
	uint64_t dsrcA = RNONE;
	uint64_t dsrcB = RNONE;
private:
      void setEInput(E * ereg, uint64_t stat, uint64_t icode, 
                           uint64_t ifun, uint64_t valA, uint64_t dstE,
                           uint64_t valC, uint64_t valB, uint64_t dstM, uint64_t srcA, uint64_t srcB);
   public:
      bool doClockLow(PipeReg ** pregs, Stage ** stages);
      void doClockHigh(PipeReg ** pregs);

};
