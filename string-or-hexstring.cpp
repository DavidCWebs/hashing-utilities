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
		"If you enter a valid hexstring, byte-serialized values will be hashed.\n"
		"Otherwise, the input will be hashed as a string (e.g. the string \"abc\" will\n"
		"be hashed as the bytes {0x61, 0x62, 0x63}\n";
	std::cout << intro;
	std::vector<uint8_t> result(DIGEST_LEN);
	std::vector<uint8_t> bytesToHash;
	std::string inputString;	
	while (1) {
		std::cout << "Enter string: ";
		std::cin >> inputString;
		if (hexstringToBytes(inputString, bytesToHash) == -1) {
			std::cout << "Hashing as a string\n";
			std::copy(inputString.begin(), inputString.end(), std::back_inserter(bytesToHash));
		} else {
			std::cout << "Hashing as a hexstring\n";
		}

		break;
	}
	
	sha256(bytesToHash.data(), bytesToHash.size(), result);
	printHex(result);

	return 0;
}

