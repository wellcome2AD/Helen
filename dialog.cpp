#include <QRegExpValidator>
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //QRegExp reg(trUtf8("([0-9],)+"));
    QRegExp reg(trUtf8("[0-9,]+"));

    // регулярное выражение, описывающее набор допустимых символов
    QRegExpValidator* valid = new QRegExpValidator(reg, this);

    // объявляем указатель на объект валидатор, использующий регулярное выражение
    ui->inputLineEdit->setValidator(valid); /* устанавливаем валидатор для элемента lineEdit, предназначенного для ввода исходных данных */
    connect(ui->inputLineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));
    /* соединяем сигнал об изменении содержимого строки со слотом, который будет вызываться в ответ на это изменение */
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onTextChanged(QString str)
{
    QString strRez = str.replace(',', ""); //метод QString по замене всех вхождений символа
    ui->outputLineEdit->setText(strRez); // выводим результат
}
