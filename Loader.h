
class Loader
{
   private:
      bool loaded;        //set to true if a file is successfully loaded into memory
      std::ifstream inf;  //input file handle
	int count = 1;
   public:
      Loader(int argc, char * argv[]);
	void load(char *file, bool & error);
	bool checkSpaces(std::string line, uint32_t start, uint32_t end);
	bool loadline(std::string line, uint64_t *addr, bool & error);
	bool checkAddress(std::string line, uint64_t *addr, bool & error);
	uint64_t getAddress(std::string line, int start, int end);
	int checkData(std::string line);
	bool checkHex(std::string line, uint64_t start, uint64_t end);
	void storeData(std::string line, uint64_t addr, bool & error);
	void storeByte(std::string byte, uint64_t addr, bool & error);
	bool hasData(std::string line);
	bool isComment(std::string line);
	bool isBlank(std::string line);
	uint64_t convert(std::string line, int start, int end);
	bool hasErrors(std::string line);
      bool isLoaded();
};
