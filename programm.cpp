#include "pch.h"
#include "programm.h"
#include <string>
#include <cctype>


void programm::CalculateWordNumber(std::ifstream& in,const std::string keyword) {

	std::string word;
	int count = 0;
	
	while (in >> word) {
		delete_punctuation(word);
		if(word.compare(keyword)==0)
			count++;
	}
	std::cout << count;
}

void programm::CalculateChecksum(std::ifstream& binary_in) {
	
	std::vector<char> bytes_buffer;

	binary_in.seekg(0, binary_in.end);
	int lenght = binary_in.tellg();
	bytes_buffer.resize(lenght);
	binary_in.seekg(0, binary_in.beg);
	if (lenght != 0) {
		binary_in.read(&bytes_buffer[0], lenght);
	}

	uint32_t checksum=0;
	uint32_t step = 0;
	for (auto it = bytes_buffer.begin(); it != bytes_buffer.end(); it++) {
		checksum += (*it) << step;
		step += 8;
		if (step == 32) { step = 0; }
	}
	std::cout << checksum;
}

void programm::helpMassage() {
	std::cout << "-m mode(words or checksum)" << std::endl << "-f file name" << std::endl << "-v word for search" << std::endl;
	std::cout << "-h help information" << std::endl;
	std::cout << "Calculate number of given word in text: -f <filename> -m words -v <word for search>" << std::endl;
	std::cout << "Calculate checksum of text: -f <filename> -m checksum" << std::endl;
}

void programm::delete_punctuation(std::string& word) {
	auto it = word.begin();
	while (true) {
		if (it == word.end()) { break; }
		if (ispunct(*it))
		{
			word.erase(it);
			continue;
		}
		it++;
	}
}