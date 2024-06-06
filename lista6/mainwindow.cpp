
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)  
    : QMainWindow(parent),               
      ui(new Ui::MainWindow)             
{
    ui->setupUi(this);                            
    QMessageBox::information(this, "Informacja",  
                             "Ten program reaguje na <br/>"                                     
                             "<b><span style=\"color:red\">kliknięcia mysza</span></b> <br/>"  
                             "w obszarze roboczym <i>okna programu</i>"
                             );
}

MainWindow::~MainWindow()
{
    delete ui;   
}


void MainWindow::on_action_Zakoncz_triggered()
{
    qApp->quit();  
}
 
void MainWindow::on_action_O_programie_triggered()
{
    QMessageBox::information(this, "O programie", "W programie mozna klikac a nie tylko .");
}
