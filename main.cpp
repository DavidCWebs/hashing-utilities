#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <limits>
#include <iomanip>
#include "hash-utilities.h"

#define DIGEST_LEN 32

using namespace HashUtilities;

int main()
{
	const char *intro =
		"This programme expects a hexstring - byte serialized data in "
		"hexadecimal format.\n";
	std::cout << intro;
	std::vector<uint8_t> result(DIGEST_LEN);
	std::vector<uint8_t> bytesToHash;
	std::string inputString;	
	while (1) {
		std::cout << "Enter string: ";
		std::cin >> inputString;
		if (hexstringToBytes(inputString, bytesToHash) == -1) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		} 
		break;
	}
	sha256(bytesToHash.data(), bytesToHash.size(), result);
	
	printHex(result);

	return 0;
}

