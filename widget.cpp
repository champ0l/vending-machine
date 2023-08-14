#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}


void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int fiveHundreds = money / 500;
    money %= 500;

    int oneHundreds = money / 100;
    money %= 100;

    int fifties = money / 50;
    money %= 50;

    int tens = money / 10;
    money %= 10;

    QString message = QString("500won: %1\n100won: %2\n50won: %3\n10won: %4")
                          .arg(fiveHundreds).arg(oneHundreds).arg(fifties).arg(tens);

    QMessageBox mb;
    mb.information(this, "Hi", message);

    money = 0;
    ui->lcdNumber->display(money);

    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}



