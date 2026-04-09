// Event/Event.h
#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QPushButton>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include "ui_mainwindow.h"  // Required to access UI components

class EventHandler : public QObject
{
    Q_OBJECT

public:
    // Constructor: initialize with UI and bind events
    EventHandler(Ui::MainWindow* ui);

    // Connect UI signals to event slots
    void connectEvents();

    // Validate input file path and prepare output path with given extension
    QString checkPath(QString path, QString endPath);

private slots:
    void on_BtInp_Clicked();        // Triggered when input file button is clicked
    void on_Encryption_Clicked();   // Handles encryption flow
    void on_Decryption_Clicked();   // Handles decryption flow

private:
    Ui::MainWindow* m_ui;           // Pointer to the UI for component access
};

#endif // EVENT_H
