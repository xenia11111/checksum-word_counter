#pragma once
#include <iostream>
#include <map>
#include <string>

class CommandParser
{
public:
	CommandParser(int argc, char *argv[]);
	std::string getMode();
	const std::string getFileName();
	const std::string getKeyWord();

private:
	std::map <std::string, std::string> m_options;
	std::string mode;
};





