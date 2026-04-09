// IO/IO.cpp
#include "IO.h"
#include <fstream>
#include <vector>
#include <iostream>

bool IO::readFileToBigInteger(const std::string &filepath, mpz_t &result)
{
    std::ifstream file(filepath, std::ios::binary);
    if (!file.is_open())
        return false;

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(file), {});
    file.close();

    mpz_import(result, buffer.size(), 1, 1, 0, 0, buffer.data());
    return true;
}

bool IO::writeBigIntegerToFile(const std::string &filepath, const mpz_t &value)
{
    size_t count = (mpz_sizeinbase(value, 2) + 7) / 8;
    std::vector<unsigned char> buffer(count);

    mpz_export(buffer.data(), &count, 1, 1, 0, 0, value);

    std::ofstream file(filepath, std::ios::binary);
    if (!file.is_open())
        return false;

    file.write(reinterpret_cast<char*>(buffer.data()), count);
    file.close();

    return true;
}

