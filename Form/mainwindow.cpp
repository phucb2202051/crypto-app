#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Event.h"
#include "Dialog.h"
#include "Convert.h"
#include "Crypto.h"
#include <gmp.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Custom Crypto Tool");
    EventHandler *eventHandler = new EventHandler(ui);
}


MainWindow::~MainWindow()
{
    delete ui;
}


