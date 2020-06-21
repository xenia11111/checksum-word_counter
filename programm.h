#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

class programm
{
public:
	void CalculateWordNumber(std::ifstream& in,std::string keyword);
	void CalculateChecksum(std::ifstream& binary_in);
	static void helpMassage();
private:
	void delete_punctuation(std::string&);
};

