// Convert/Convert.cpp
#include "Convert.h"
#include <gmp.h>
#include <Dialog.h>

// Convert string to GMP integer using a given base
bool Convert::stringToNum(const std::string &str, mpz_t &result, int base) {
    // Return false if the string cannot be parsed into a valid number
    return mpz_set_str(result, str.c_str(), base) == 0;
}

// Convert GMP integer to string representation in a given base
std::string Convert::numToString(const mpz_t &num, int base) {
    size_t size = mpz_sizeinbase(num, base);
    std::vector<char> buffer(size + 2); // Extra space for null terminator or possible overflow
    mpz_get_str(buffer.data(), base, num);
    return std::string(buffer.data());
}
