#ifndef HASHER_H
#define HASHER_H

#include <iostream>
#include <vector>
#include <string>
#include <openssl/sha.h>
#include <typeinfo>
#include <limits>
#include <iomanip>
#include <openssl/ripemd.h>
#include <algorithm>

namespace HashUtilities {
int sha256(const uint8_t preimageBytes[], size_t len, std::vector<uint8_t>& res);
int ripemd160(const uint8_t preimageBytes[], size_t len, std::vector<uint8_t>& res);
int hexstringToBytes(std::string const& hexstring, std::vector<uint8_t>& result);
int hexDigitToInt(char digit);
void printHex(std::vector<uint8_t> input);
int hexstringToBytes(std::string const& hexstring, std::vector<uint8_t>& result);
int hexDigitToInt(char digit);
void printHex(std::vector<uint8_t> input);
}
#endif
