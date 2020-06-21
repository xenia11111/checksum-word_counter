#include "pch.h"
#include <iostream>
#include <fstream>
#include "CommandParser.h"
#include "programm.h"

int main(int argc,char* argv[])
{
	CommandParser parser(argc, argv);
	try {
		std::string mode;
		mode = parser.getMode();
		if (mode == "") { 
			std::cout << "Wrong parameters! Use command -h for help";
			return EXIT_FAILURE; 
		}
		if (mode == "HELP") {
			programm::helpMassage();
			return 0;
		}
		const std::string file_name = parser.getFileName();
		if(file_name.empty()){ throw std::exception("Name of file not found!"); }
		std::ifstream in(file_name);
		if (in.fail()) {
			throw std::ifstream::failure("file error");
		}
		if (mode == "words") {
			std::string key = parser.getKeyWord();
			programm* p = new programm();
			if(!key.empty()){ 
				p->CalculateWordNumber(in, key); 
			}
			else {
				throw std::exception("Word for search not found!"); 
			}
		 }
		if (mode == "checksum") {
			std::ifstream binary_in(file_name,std::ios::binary);
			programm* p = new programm();
			p->CalculateChecksum(binary_in); 
		}
	}
	catch (std::ifstream::failure&) {
		std::cout << "Error: Failure to open file" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}
}

