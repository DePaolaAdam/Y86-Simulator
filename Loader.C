/**
 * Names:Adam DePaola Brandon Collins
 * Team: 19
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

#include "Loader.h"
#include "Memory.h"

//first column in file is assumed to be 0
#define ADDRBEGIN 2   //starting column of 3 digit hex address 
#define ADDREND 4     //ending column of 3 digit hext address
#define DATABEGIN 7   //starting column of data bytes
#define COMMENT 28    //location of the '|' character 

/**
 * Loader constructor
 * Opens the .yo file named in the command line arguments, reads the contents of the file
 * line by line and loads the program into memory.  If no file is given or the file doesn't
 * exist or the file doesn't end with a .yo extension or the .yo file contains errors then
 * loaded is set to false.  Otherwise loaded is set to true.
 *
 * @param argc is the number of command line arguments passed to the main; should
 *        be 2
 * @param argv[0] is the name of the executable
 *        argv[1] is the name of the .yo file
 */
Loader::Loader(int argc, char * argv[])
{
   loaded = false;

   //Start by writing a method that opens the file (checks whether it ends 
   //with a .yo and whether the file successfully opens; if not, return without 
   //loading)
	
   //The file handle is declared in Loader.h.  You should use that and
   //not declare another one in this file.
   
   //Next write a simple loop that reads the file line by line and prints it out
   
   //Next, add a method that will write the data in the line to memory 
   //(call that from within your loop)

   //Finally, add code to check for errors in the input line.
   //When your code finds an error, you need to print an error message and return.
   //Since your output has to be identical to your instructor's, use this cout to print the
   //error message.  Change the variable names if you use different ones.
   //  std::cout << "Error on line " << std::dec << lineNumber
   //       << ": " << line << std::endl;
	bool error = false;
	loadFile(argv[1], error);
	if(error == true)
	{
		return;
	}
   //If control reaches here then no error was found and the program
   //was loaded into memory.
   loaded = true;  
  
}
bool Loader::checkSpaces(std::string line, uint64_t start, uint64_t end)
{
	if(end >= line.length())
	{
		exit(1);
	}
	for(uint64_t i = start; i <= end; i++)
	{
		if(!isspace(line[i]))
		{
			return false;
		}
	}
	return true;
}
void Loader::loadFile(std::string file, bool & error)
{
	inf.open(file);
	std::string fname(file);
	if(!inf.is_open())
	{	
		error = true;
		return;
	}
	else if(fname.find(".yo") != fname.length() - 3)
	{
		error = true;
		return;
	}
	std::string line = "";
	uint32_t count = 1;
	uint64_t addr = 0;
//	std::streamsize cc = 0;
	
	getline(inf, line);
	while(inf)
	{
		if(!loadline(line, &addr, error))
		{
			std::cout << "error line: " <<  count;
			std::cout << line;
			error = true;
			return;
		}
		else
		{
			count++;	
			getline(inf, line);
			std::cout << inf << std::endl;
		}
	}
	error = false;
	return;
}
//bool Loader::readFile(std::string fname, std::ifstream& inf)

bool Loader::loadline(std::string line, uint64_t *addr, bool & error)
{
	int num = 0;
	uint64_t add = 0;
	if(checkSpaces(line, 0, line.length() - 1))
	{
		return true;
	}
	else if(checkSpaces(line, 0, COMMENT - 1) && (line[COMMENT] == '|' || line[COMMENT + 1] == '|'))
	{
		return true;
	}
	else if(checkAddress(line, addr, error))
	{
		add = getAddress(line);
		if(line[8] != ' ')
		{
			num = checkData(line);
			if(num == -1)
			{
				return false;
			}
			else
			{
				storeData(line, add, error);
				*addr = add + num;
				return true;
			}
		}
		else
		{
			return true;
		}
	}
	return false;
}
uint64_t Loader::getAddress(std::string line)
{
	std::fstream con;
	uint64_t address = 0;
	line = line.substr(2, 4);
	if(line.substr(3, 1) == ":")
	{
		line = line.substr(0, 3);
	}
	con << std::hex << line;
	con >> address;
	return address;
}
int Loader::checkData(std::string line)
{
	std::string record = line.substr(7);
	if(record.substr(0, 1) == " ")
	{
		if(checkSpaces(record, 0, 20))
		{
			return 0;
		}
	}
	std::string data = record.substr(0, record.find(' '));
	return data.length() / 2;
}
bool Loader::checkAddress(std::string line, uint64_t *addr, bool & error)
{
	std::string li = line.substr(0, line.length());
	if(line[0] == '0' && (line[1] == 'x' || line[1] == 'X'))
	{
		uint64_t colon = line.find(':', 0);
		if(colon == std::string::npos)
		{
			return false;	
		}
		if((colon == 5 && line[6] == ' ') || colon == 6)
		{
			std::string address = line.substr(2, 4);
			if(address[3] == ':')
			{
				address = address.substr(0, 3);
			}
			if(checkHex(address, 0, address.length()))
			{
				std::fstream converter(address);
				uint64_t newAddress;
				converter >> std::hex >> newAddress;
				if(newAddress >= *addr)
				{
					return true;
				}
			}
		}
	}
	return true;
}
void Loader::storeData(std::string line, uint64_t addr, bool & error)
{
	std::string inst = line.substr(7,20);
	unsigned i = 0;
	std::string byte = inst.substr(i, 2);
	while(i < 20 && byte != "  ")
	{
		uint8_t hex = std::stoul(byte, nullptr, 16);
		Memory *mem = Memory::getInstance();
		mem->putByte(hex, addr, error);
		addr++;
		i += 2;
		byte = inst.substr(i, 2);
	}
}
bool Loader::checkHex(std::string line, uint64_t start, uint64_t end)
{
	int num = end - start + 1;
	line = line.substr(start, num);
	if(line.find_first_not_of("0123456789abcdefABCDEF", 0) == std::string::npos)
	{
		return true;
	}
	return false;
}



/**
 * isLoaded
 * returns the value of the loaded data member; loaded is set by the constructor
 *
 * @return value of loaded (true or false)
 */
bool Loader::isLoaded()
{
   return loaded;
}


//You'll need to add more helper methods to this file.  Don't put all of your code in the
//Loader constructor.  When you add a method here, add the prototype to Loader.h in the private
//section.
