// Event/Event.cpp
#include "Event.h"
#include "Dialog.h"
#include "IO.h"
#include "Crypto.h"
#include "InputHandler.h"

#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <gmp.h>
#include <algorithm>

EventHandler::EventHandler(Ui::MainWindow* ui) : m_ui(ui) {
    connectEvents();
}

void EventHandler::connectEvents() {
    connect(m_ui->BtInp, &QPushButton::clicked, this, &EventHandler::on_BtInp_Clicked);
    connect(m_ui->Encryption, &QPushButton::clicked, this, &EventHandler::on_Encryption_Clicked);
    connect(m_ui->Decryption, &QPushButton::clicked, this, &EventHandler::on_Decryption_Clicked);
}

// Handle file browsing
void EventHandler::on_BtInp_Clicked() {
    QString filePath = QFileDialog::getOpenFileName(nullptr, "Open File", "", "All Files (*)");
    if (!filePath.isEmpty())
        m_ui->TFInpPath->setText(filePath);
}

// Handle encryption logic: read → encrypt → write → display remainders
void EventHandler::on_Encryption_Clicked() {
    QString InpPath = m_ui->TFInpPath->text();
    QString OutpPath = checkPath(InpPath, ".encr");
    if (OutpPath.isEmpty())
        return;

    mpz_t num;
    mpz_init(num);

    if (!IO::readFileToBigInteger(InpPath.toStdString(), num)) {
        mpz_clear(num);
        Dialog::showError(nullptr, "Read File Error");
        return;
    }

    std::vector<std::string> modStrs, divStrs;
    for (QLineEdit* qLine : InputHandler::getDiv(m_ui))
        divStrs.push_back(qLine->text().toStdString());

    if (!Crypto::encrypt(num, divStrs, modStrs)) {
        Dialog::showError(nullptr, "Encrypt File Error");
        mpz_clear(num);
        return;
    }

    if (!IO::writeBigIntegerToFile(OutpPath.toStdString(), num)) {
        Dialog::showError(nullptr, "Write File Error");
        mpz_clear(num);
        return;
    }

    QVector<QLineEdit*> modFields = InputHandler::getMod(m_ui);
    int limit = std::min(static_cast<int>(modFields.size()), static_cast<int>(modStrs.size()));
    for (int i = 0; i < limit; ++i) {
        modFields[i]->setText(QString::fromStdString(modStrs[i]));
    }

    Dialog::showSuccess(nullptr, "Encryption completed successfully.");
    mpz_clear(num);
}

// Handle decryption logic: read → reverse math → write
void EventHandler::on_Decryption_Clicked() {
    QString InpPath = m_ui->TFInpPath->text();
    QString OutpPath = checkPath(InpPath, ".decr");
    if (OutpPath.isEmpty())
        return;

    mpz_t num;
    mpz_init(num);

    if (!IO::readFileToBigInteger(InpPath.toStdString(), num)) {
        Dialog::showError(nullptr, "Read Encrypted File Error");
        mpz_clear(num);
        return;
    }

    std::vector<std::string> divStrs, modStrs;
    for (QLineEdit* qLine : InputHandler::getDiv(m_ui))
        divStrs.push_back(qLine->text().toStdString());

    for (QLineEdit* qLine : InputHandler::getMod(m_ui))
        modStrs.push_back(qLine->text().toStdString());

    if (!Crypto::decrypt(num, divStrs, modStrs)) {
        Dialog::showError(nullptr, "Decryption failed (check DIV/MOD)");
        mpz_clear(num);
        return;
    }

    if (!IO::writeBigIntegerToFile(OutpPath.toStdString(), num)) {
        Dialog::showError(nullptr, "Write Decrypted File Error");
        mpz_clear(num);
        return;
    }

    Dialog::showSuccess(nullptr, "Decryption completed successfully.");
    mpz_clear(num);
}

// Check if file path is valid and generate output file path
QString EventHandler::checkPath(QString path, QString endPath) {
    if (path.isEmpty()) {
        Dialog::showError(nullptr, "Please choose input file path");
        return QString();
    }

    QFile file(path);
    if (!file.exists()) {
        Dialog::showError(nullptr, "Invalid file path");
        return QString();
    }
    if (!file.open(QIODevice::ReadOnly)) {
        Dialog::showError(nullptr, "Cannot read the selected file.");
        return QString();
    }

    QFileInfo fileInfo(path);
    QString OutpPath = fileInfo.absolutePath() + "/" + fileInfo.completeBaseName() + endPath;

    QFile fileOutp(OutpPath);
    if (fileOutp.exists()) {
        if (!Dialog::showConfirmation(nullptr, "This file already exists. Overwrite it?"))
            return QString();
    }

    return OutpPath;
}
