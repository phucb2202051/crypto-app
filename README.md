# 🔐 SecureDB-Crypto-Module

A lightweight and customizable **data encryption module** written in C++ and Qt, designed to be integrated into database management systems or used as a standalone encryption tool. The encryption algorithm is based on **sequential large-number division** using the GMP (GNU Multiple Precision Arithmetic) library.

---

## 📌 Features

- 🔢 Arbitrary-precision integer encryption using GMP.
- 🔐 Bit-level encryption and decryption with custom keys.
- 🧩 GUI interface built with Qt Designer for easy interaction.
- 🗃️ Supports encryption of any binary file (.txt, .bin, .csv, .db, etc.).
- 🛠️ Modular source code ready for open-source contributions.

---

## 📁 Project Structure

Crypto/
├── Convert/ # Convert string ↔ large GMP number (mpz_t)
│ ├── Convert.cpp
│ └── Convert.h
│
├── Crypto/ # Main encryption/decryption algorithm
│ ├── Crypto.cpp
│ └── Crypto.h
│
├── Dialog/ # Display messages in Qt
│ ├── Dialog.cpp
│ └── Dialog.h
│
├── Event/ # Xử lý sự kiện GUI (Encrypt, Decrypt, chọn file)
│ ├── Event.cpp
│ └── Event.h
│
├── Handler/ # Handle GUI events (Encrypt, Decrypt, select file)
│ ├── InputHandler.cpp
│ └── InputHandler.h
│
├── Form/ # User Interface (Qt UI)
│ ├── mainwindow.ui
│ ├── mainwindow.h
│ └── mainwindow.cpp
│
├── IO/ # Read/write binary files using GMP
│ ├── IO.cpp
│ └── IO.h
│
├── include/ # Header GMP tích hợp
│ ├── gmp.h
│ └── gmpxx.h
│
├── lib/ # GMP static/dynamic libraries
│ ├── gmp.lib
│ ├── gmpxx.lib
│ └── pkgconfig/
│
├── build/ # Temporary (debug/release/dll)
│ └── ...
│
├── main.cpp # Qt application startup function
├── Crypto.pro # Qt project configuration
└── Crypto.pro.user # User-specific Qt config (ignore when publishing)

--

## 🚀 How It Works

### 🔐 Encryption Flow

1. Read binary content from file.
2. Convert content to large integer `INP`.
3. Divide `INP` sequentially by user-provided 8 divisors (`DIV1`..`DIV8`).
4. Save:
   - Final result → `.encr` file.
   - Remainders → `.mod` file (MOD1..MOD8).

### 🔓 Decryption Flow

1. Load `.encr` and MOD values.
2. Reverse calculation using: