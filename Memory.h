
//size of memory
#define MEMSIZE 0x1000
class Memory 
{
   private:
      static Memory * memInstance;
      Memory();
      uint8_t mem[MEMSIZE];
   public:
      static Memory * getInstance();      
      uint64_t getLong(int32_t address, bool & error);
      uint8_t getByte(int32_t address, bool & error);
      void putLong(uint64_t value, int32_t address, bool & error);
      void putByte(uint8_t value, int32_t address, bool & error);
//	void placeByte(uint64_t byteAddress, uint8_t value);
//	void store(uint64_t waddr, uint64_t val);
//	uint64_t fetch(uint64_t waddr);


      void dump();
}; 
