# 🔐 SecureDB-Crypto-Module

## 📖 Description

SecureDB-Crypto-Module là module mã hóa dữ liệu được xây dựng bằng C++ và Qt, sử dụng thư viện GMP để xử lý số nguyên lớn.

Dự án hướng đến việc tích hợp vào hệ thống quản lý cơ sở dữ liệu hoặc sử dụng như một công cụ mã hóa file độc lập.

---

## 🚀 Features

* 🔢 Mã hóa số nguyên lớn với GMP (arbitrary precision)
* 🔐 Thuật toán mã hóa dựa trên phép chia tuần tự
* 🧩 Giao diện GUI với Qt
* 🗃️ Hỗ trợ nhiều định dạng file (txt, bin, csv, db…)
* ⚙️ Thiết kế module hóa, dễ mở rộng

---

## 🛠 Tech Stack

* C++
* Qt (Qt Widgets)
* GMP (GNU Multiple Precision Arithmetic Library)

---

## 📂 Project Structure

```
Crypto/
├── Convert/      # Convert dữ liệu ↔ số lớn GMP
├── Crypto/       # Thuật toán mã hóa / giải mã
├── Dialog/       # Hiển thị thông báo GUI
├── Event/        # Xử lý sự kiện UI
├── Handler/      # Điều phối logic
├── Form/         # Giao diện Qt (UI)
├── IO/           # Đọc/ghi file nhị phân
├── include/      # Header GMP
├── lib/          # Thư viện GMP
├── build/        # File build tạm
├── main.cpp
├── Crypto.pro
```

---

## 🔐 Encryption Algorithm

### Encryption

1. Đọc dữ liệu nhị phân từ file
2. Chuyển thành số nguyên lớn `INP` (GMP)
3. Thực hiện chia tuần tự:

INP / DIV1 → R1
Q1 / DIV2 → R2
...
Q7 / DIV8 → R8

4. Lưu:

* Kết quả cuối → `.encr`
* Các số dư (R1 → R8) → `.mod`

---

### Decryption

* Dựa vào `.encr` và các giá trị MOD
* Khôi phục lại dữ liệu ban đầu bằng phép nhân ngược

---

## ⚙️ Build & Run

### Yêu cầu

* Qt (Qt Creator)
* GMP Library

### Cách chạy

1. Mở file `Crypto.pro` bằng Qt Creator
2. Build project
3. Run ứng dụng

---


## 🎯 Use Cases

* Mã hóa dữ liệu database
* Bảo mật file nhị phân
* Nghiên cứu thuật toán mã hóa

---

## ⚠️ Notes

* Đây là thuật toán tự thiết kế (custom encryption)
* Không thay thế các chuẩn bảo mật như AES/RSA trong production

---

## 👨‍💻 Author

Nguyễn Hoàng Phúc
