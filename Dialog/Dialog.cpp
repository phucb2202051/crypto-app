// Dialog/Dialog.cpp
#include "Dialog.h"

// Display a critical error dialog
void Dialog::showError(QWidget *parent, const QString &message) {
    QMessageBox::critical(parent, "Error", message);
}

// Display an information/success dialog
void Dialog::showSuccess(QWidget *parent, const QString &message) {
    QMessageBox::information(parent, "Success", message);
}

// Ask user to confirm an action, return true if Yes is selected
bool Dialog::showConfirmation(QWidget *parent, const QString &message) {
    QMessageBox::StandardButton reply = QMessageBox::question(
        parent, "Confirm", message, QMessageBox::Yes | QMessageBox::No
        );
    return reply == QMessageBox::Yes;
}
