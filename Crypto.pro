# Định nghĩa môi trường Qt và thêm mô-đun widget nếu cần thiết
QT       += core gui widgets

# Cấu hình C++17
CONFIG += c++17

# Cấu hình đường dẫn include cho các thư mục cần thiết
INCLUDEPATH += \
    $$PWD/Convert \
    $$PWD/Crypto \
    $$PWD/IO \
    $$PWD/Form \
    $$PWD/Handler \
    $$PWD/Dialog \
    $$PWD/Event \
    $$PWD/include  # Đảm bảo thư mục include chứa tệp gmp.h

# Định nghĩa các tệp nguồn
SOURCES += \
    main.cpp \
    Form/mainwindow.cpp \
    Convert/Convert.cpp \
    Crypto/Crypto.cpp \
    Handler/InputHandler.cpp \
    Dialog/Dialog.cpp \
    IO/IO.cpp \
    Event/Event.cpp

# Định nghĩa các tệp header
HEADERS += \
    Form/mainwindow.h \
    Convert/Convert.h \
    Crypto/Crypto.h \
    Handler/InputHandler.h \
    Dialog/Dialog.h \
    IO/IO.h \
    Event/Event.h

# Định nghĩa tệp Form Qt Designer
FORMS += \
    Form/mainwindow.ui

# Liên kết thư viện GMP (thư viện GMP phải được đặt trong thư mục lib hoặc hệ thống phải cài đặt GMP)
LIBS += -L$$PWD/lib -lgmp

# Cấu hình đường dẫn cài đặt cho các môi trường khác nhau (nếu cần)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
