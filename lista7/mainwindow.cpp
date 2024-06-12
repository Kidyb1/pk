#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->animationRunning = true;
    ui->setupUi(this);
    connect(ui->action_Koniec, &QAction::triggered, this, &MainWindow::endProgram);
    connect(ui->toggleButton, &QPushButton::clicked, this, &MainWindow::toggleIcon);
    ui->toggleButton->setIcon(QIcon(":/img/media-playback-pause.png"));
}

void MainWindow::toggleIcon()
{
    this->animationRunning = !this->animationRunning;
    ui->toggleButton->setIcon(this->animationRunning ? QIcon(":/img/media-playback-pause.png") : QIcon(":/img/media-playback-start.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::endProgram()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirm Exit");
    msgBox.setText("Are you sure you want to exit?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    msgBox.button(QMessageBox::Yes)->setText("Yes");
    msgBox.button(QMessageBox::No)->setText("No");

    if (msgBox.exec() == QMessageBox::Yes) {
        qApp->quit();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::aboutQt(this, "About This Program");
}
