// IO/IO.h
#ifndef IO_H
#define IO_H

#include <string>
#include <gmp.h>

class IO {
public:
    // Read an entire binary file and convert it to a big integer (mpz_t)
    static bool readFileToBigInteger(const std::string &filePath, mpz_t &output);

    // Write a big integer (mpz_t) to a binary file
    static bool writeBigIntegerToFile(const std::string &filePath, const mpz_t &value);
};

#endif // IO_H
