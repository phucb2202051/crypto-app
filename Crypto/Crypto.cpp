// Crypto/Crypto.cpp
#include "Crypto.h"
#include "Convert.h"
#include "Dialog.h"
#include <gmp.h>

// Encrypts inp using sequential division with provided divisors (in base-62).
// Stores remainders as strings in modStrs.
bool Crypto::encrypt(mpz_t &inp, const std::vector<std::string> &divStrs, std::vector<std::string> &modStrs) {
    if (divStrs.empty())
        return false;

    modStrs.clear();
    modStrs.reserve(divStrs.size());

    for (const std::string &divStr : divStrs) {
        mpz_t div, mod;
        mpz_inits(div, mod, nullptr);

        if (divStr.empty()) {
            modStrs.push_back("");  // Skip empty input but keep index
            mpz_clears(div, mod, nullptr);
            continue;
        }

        // Convert divisor string to mpz_t number using base-62
        if (!Convert::stringToNum(divStr, div, 62)) {
            Dialog::showError(nullptr, QString::fromStdString("Divisor is invalid: " + divStr));
            mpz_clears(div, mod, nullptr);
            return false;
        }

        if (mpz_cmp_ui(div, 0) == 0) {
            Dialog::showError(nullptr, "Divisor cannot be zero.");
            mpz_clears(div, mod, nullptr);
            return false;
        }

        // Store remainder and reduce inp for next division
        mpz_mod(mod, inp, div);
        mpz_div(inp, inp, div);

        modStrs.push_back(Convert::numToString(mod, 62));
        mpz_clears(div, mod, nullptr);
    }

    return true;
}

// Decrypts inp using reversed process of sequential multiplication and addition
// with saved divisors and remainders (both in base-62)
bool Crypto::decrypt(mpz_t &inp, const std::vector<std::string> &divStrs, const std::vector<std::string> &modStrs) {
    if (divStrs.empty() || modStrs.empty() || divStrs.size() != modStrs.size())
        return false;

    mpz_t div, mod;
    mpz_inits(div, mod, nullptr);

    for (int i = static_cast<int>(divStrs.size()) - 1; i >= 0; --i) {
        // Skip empty entries (used during encryption for missing divisors)
        if (divStrs[i].empty() || modStrs[i].empty())
            continue;

        // Convert strings to GMP numbers
        if (!Convert::stringToNum(divStrs[i], div, 62) ||
            !Convert::stringToNum(modStrs[i], mod, 62)) {
            mpz_clears(div, mod, nullptr);
            return false;
        }

        // Restore the previous number using: inp = inp * div + mod
        mpz_mul(inp, inp, div);
        mpz_add(inp, inp, mod);
    }

    mpz_clears(div, mod, nullptr);
    return true;
}
