#include "hash-utilities.h"

namespace HashUtilities {
/**
 * preImageBytes is typically a pointer to first element in a vector.
 * For a preimage container `std::vector<uint8_t> v` the caller can either pass `v.data()` or `&v[0]`.
 * */
int sha256(const uint8_t preimageBytes[], size_t len, std::vector<uint8_t>& res)
{
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, preimageBytes, len); 
	int ret = SHA256_Final(res.data(), &sha256);
	return ret;
}

int ripemd160(const uint8_t preimageBytes[], size_t len, std::vector<uint8_t>& res)
{
	RIPEMD160_CTX ripemd160;
	RIPEMD160_Init(&ripemd160);
	RIPEMD160_Update(&ripemd160, preimageBytes, len);
	int ret = RIPEMD160_Final(res.data(), &ripemd160);
	return ret;
}

/**
 * Parse a hexstring as serialized byte format, storing byte values in `result`.
 * If the `hexstring` is invalid - wrong length, or containing invalid characters, returns -1.
 * Returns length of result on success.
 * */
int hexstringToBytes(std::string const& hexstring, std::vector<uint8_t>& result)
{
	if (hexstring.size() % 2) {
		std::cerr << "The input is not an even number of characters, so not a valid hexstring.\n";
		return -1;
	}
	
	size_t resultLength = hexstring.size() / 2;
	size_t i = 0;
	for (auto it = hexstring.begin(); it != hexstring.end(); it = it + 2) {
		int sixteens = hexDigitToInt(*it);
		int units = hexDigitToInt(*std::next(it));
		if (sixteens == -1 || units == -1) {
			return -1;
		}
		result.push_back((sixteens << 4) | units);
		i++;
	}
	return resultLength;
}

int hexDigitToInt(char digit)
{
	digit = tolower(digit);
	if (digit >= '0' && digit <='9')
	       return (int)(digit - '0');
	else if (digit >= 'a' && digit <= 'f') {
		return (int)(digit - '1' - '0') + 10; 
	}
	std::cout << "Non-hex digit detected.\n";	
	return -1;
}

void printHex(std::vector<uint8_t> input)
{
	for (auto& el : input)
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)el;
	std::cout << '\n';
}

void switchEndianness(std::vector<uint8_t>& b)
{
	std::reverse(b.begin(), b.end());
}

int hexstringToIntArray(std::string const& hexstring, uint8_t result[])
{
	if (hexstring.size() % 2) {
		std::cerr << "The hexstring is not an even number of characters.\n";
		exit(EXIT_FAILURE);
	}
	
	size_t resultLength = hexstring.size() / 2;
	size_t i = 0;
	for (auto it = hexstring.begin(); it != hexstring.end(); it = it + 2) {
		int sixteens = hexDigitToInt(*it);
		int units = hexDigitToInt(*std::next(it));
		if (sixteens == -1 || units == -1) {
			return -1;
		}
		result[i] = (sixteens << 4) | units;
		i++;
	}
	return resultLength;
}

/**
 * Print a string as hexadecimal values.
 *
 * */ 
void printStringToHex(std::string s)
{
	for(size_t i = 0; i < s.size(); i++) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)s[i];
	}
	std::cout << '\n';
}

/**
 *
 * return a hex string representation of the value of an integer
 *
 * */ 
std::string intToHexString(int num)
{
	std::stringstream ss;
	ss << std::hex << num;
	return ss.str();
}

/**
 * Convert an int to a hexadecimal string, using arithmetic.
 *
 * */
std::string intToHexString2(int num)
{
	const char hexChars[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	std::string result;
	while (num) {
		char tmp = hexChars[num % 16];
		result.insert(result.begin(), tmp);
		num /= 16;
	}
	return result;
}

/**
 * Build a hex string representation of bytes.
 * 
 * */
void charToHexString(const char& c, std::string& s)
{
	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)c);
	s.append(ss.str());
}

} // End HashUtilities
