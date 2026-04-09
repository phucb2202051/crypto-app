// Crypto/Crypto.h
#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <vector>
#include <gmp.h>

class Crypto {
public:
    // Encrypt the input number (inp) using a list of divisors (as strings),
    // and return the list of remainders (modStrs) in base-62
    static bool encrypt(mpz_t &inp, const std::vector<std::string> &divStrs, std::vector<std::string> &modStrs);

    // Decrypt the input number (inp) using original divisors and remainders (both as base-62 strings)
    static bool decrypt(mpz_t &inp, const std::vector<std::string> &divStrs, const std::vector<std::string> &modStrs);
};

#endif // CRYPTO_H
