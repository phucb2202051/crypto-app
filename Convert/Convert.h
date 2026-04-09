// Convert/Convert.h
#ifndef CONVERT_H
#define CONVERT_H

#include <string>
#include <gmp.h>

class Convert {
public:
    // Convert a string into a GMP big integer (mpz_t) using the specified base (default: base 10)
    static bool stringToNum(const std::string &str, mpz_t &result, int base = 10);

    // Convert a GMP big integer (mpz_t) into a string using the specified base (default: base 62)
    static std::string numToString(const mpz_t &num, int base = 62);
};

#endif // CONVERT_H
