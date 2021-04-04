#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Icon
    ui->pushButton_5->setIcon(QIcon("/Users/acer/Documents/Desktop/on.jpg"));
    ui->pushButton_5->setCheckable(true);

    ui->pushButton_6->setText("Menu");
    QAction *a1 = new QAction;
    QAction *a2 = new QAction;
    QAction *a3 = new QAction;

    a1->setText("first");
    a2->setText("second");
    a3->setText("third");

    QMenu *menu = new QMenu;
    menu->addAction(a1);
    menu->addAction(a2);
    menu->addAction(a3);

    ui->pushButton_6->setMenu(menu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this,"Sushmitha T 212218203031","this is an information box");
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
           reply = QMessageBox::question(this,"Sushmitha 212218203031","do you like kpop",QMessageBox::Yes |QMessageBox::No  );
           if(reply == QMessageBox::Yes)  {
               QMessageBox::information(this,"yes","you like kpop");
            }
           else {
               QMessageBox::information(this,"No","you don't like kpop");
           }
}

void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply;
         reply = QMessageBox::question(this,"custom","This is a custom message",QMessageBox::Yes |QMessageBox::YesToAll  |QMessageBox::No  |QMessageBox::NoToAll);
         switch(reply)  {
            case QMessageBox::Yes:
              qDebug() <<"nothing is displayed";
              break;
            case QMessageBox::YesToAll:
              QMessageBox::warning(this,"Yes to all","display the message with Yes to all");
              break;
            case QMessageBox::No:
              qDebug() <<"nothig is displayed";
              break;
            default:
             QMessageBox::warning(this,"no to all","display the message with no to all");
             break;



         }
}

void MainWindow::on_pushButton_4_clicked()
{
    QMessageBox::warning(this,"critical","This is a warning message");
}

void MainWindow::on_pushButton_5_toggled(bool checked)
{
    if(checked)
    {
         ui->pushButton_5->setIcon(QIcon("/Users/acer/Documents/Desktop/off.jpg"));
        qDebug() <<"button checked-- ON--";
    }
    else
    {
         ui->pushButton_5->setIcon(QIcon("/Users/acer/Documents/Desktop/on.jpg"));
        qDebug() <<"button checked--OFF--";
    }
}
