#include "pch.h"
#include "CommandParser.h"


CommandParser::CommandParser(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-') {
			std::string key = argv[i];
			if (key.compare("-h") == 0) { mode = "HELP"; continue; }
			if ((key.compare("-f") == 0 || key.compare("-m") == 0 || key.compare("-v") == 0) && (i + 1) < argc) {
				std::string option = argv[i + 1];
				m_options[key] = option;
				i++;
				if (option.compare("words")==0) { mode = "words"; }
				if (option.compare("checksum")==0) { mode = "checksum"; }

			}
			else {
				m_options[key] = "";
			}
		}
	
	}
	
}

const std::string CommandParser::getFileName()
{
	if (m_options.count("-f"))
		return m_options["-f"];
	else
		return "";
}

const std::string CommandParser::getKeyWord()
{
	if (m_options.count("-v"))
		return m_options["-v"];
	else
		return "";
}

std::string CommandParser::getMode()
{
	
	return (!mode.empty()) ? mode : "";
}


