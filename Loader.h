
class Loader
{
   private:
      bool loaded;        //set to true if a file is successfully loaded into memory
      std::ifstream inf;  //input file handle
   public:
      Loader(int argc, char * argv[]);
	void loadFile(std::string file, bool & error);
	bool checkSpaces(std::string line, uint64_t start, uint64_t end);
	bool loadline(std::string line, uint64_t *addr, bool & error);
	bool checkAddress(std::string line, uint64_t *addr, bool & error);
	uint64_t getAddress(std::string line);
	int checkData(std::string line);
	bool checkHex(std::string line, uint64_t start, uint64_t end);
	void storeData(std::string line, uint64_t addr, bool & error);
      bool isLoaded();
};
