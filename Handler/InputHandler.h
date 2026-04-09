// InputHandler.h
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <QVector>
#include <QLineEdit>
#include "ui_mainwindow.h" // Required to access UI components of MainWindow

class InputHandler {
public:
    // Return a list of input fields corresponding to the 8 divisor values (DIV1 to DIV8)
    static QVector<QLineEdit*> getDiv(Ui::MainWindow *ui);

    // Return a list of input fields corresponding to the 8 modulus values (MOD1 to MOD8)
    static QVector<QLineEdit*> getMod(Ui::MainWindow *ui);
};

#endif // INPUTHANDLER_H
