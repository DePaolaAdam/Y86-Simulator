class ExecuteStage: public Stage
{
    uint64_t estat;
    uint64_t eicode;
    bool ecnd;
    uint64_t evalE;
    uint64_t evalA;
    uint64_t edstE = RNONE;
    uint64_t edstM = RNONE;
    private:
	void setEInput(M * ereg, uint64_t stat, uint64_t icode, 
                           bool cnd, uint64_t valE, uint64_t valA,
                           uint64_t edstE, uint64_t edstM);
   public:
      bool doClockLow(PipeReg ** pregs, Stage ** stages);
      void doClockHigh(PipeReg ** pregs);

};
