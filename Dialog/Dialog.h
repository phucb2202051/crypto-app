// Dialog/Dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QString>
#include <QMessageBox>
#include <QWidget>

class Dialog {
public:
    // Show an error message box
    static void showError(QWidget *parent, const QString &message);

    // Show a success/information message box
    static void showSuccess(QWidget *parent, const QString &message);

    // Show a confirmation dialog with Yes/No options and return user's choice
    static bool showConfirmation(QWidget *parent, const QString &message);
};

#endif // DIALOG_H
