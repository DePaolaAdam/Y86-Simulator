class MemoryStage: public Stage
{
    uint64_t mstat;
    uint64_t micode;
    uint64_t mvalE;
    uint64_t mvalM;
    uint64_t mdstE = RNONE;
    uint64_t mdstM = RNONE; 
	private:
     void setEInput(W * ereg, uint64_t stat, uint64_t icode, 
                           uint64_t valE, uint64_t valM,
                           uint64_t dstE, uint64_t dstM);
   public:
      bool doClockLow(PipeReg ** pregs, Stage ** stages);
      void doClockHigh(PipeReg ** pregs);

};
