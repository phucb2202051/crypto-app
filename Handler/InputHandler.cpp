// InputHandler.cpp
#include "InputHandler.h"
#include "ui_mainwindow.h"

#include <QVector>
#include <QLineEdit>

// Collect all divisor input fields from the UI (TFDiv1 - TFDiv8)
QVector<QLineEdit*> InputHandler::getDiv(Ui::MainWindow *ui) {
    return {
        ui->TFDiv1, ui->TFDiv2, ui->TFDiv3, ui->TFDiv4,
        ui->TFDiv5, ui->TFDiv6, ui->TFDiv7, ui->TFDiv8
    };
}

// Collect all modulus input fields from the UI (TFMod1 - TFMod8)
QVector<QLineEdit*> InputHandler::getMod(Ui::MainWindow *ui) {
    return {
        ui->TFMod1, ui->TFMod2, ui->TFMod3, ui->TFMod4,
        ui->TFMod5, ui->TFMod6, ui->TFMod7, ui->TFMod8
    };
}
