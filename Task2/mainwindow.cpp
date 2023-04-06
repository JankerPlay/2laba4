#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cfunc.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_memcpy(s2, s1, n);
    s2[n] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_memmove(s2, s1, n);
    s2[n] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_3_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_strcpy(s2, s1);
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_4_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_strncpy(s2, s1, n);
    s2[n] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_5_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + qwe.length() + 1];
    my_strcpy(s2, s1);
    s2[qwe.length()] = '\0';
    my_strcat(s2, s1);
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_6_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_strncat(s2, s1, n);
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_7_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    qwe = ui->textEdit_2->toPlainText();
    bytes = qwe.toLocal8Bit();
    const char* s2 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    if(my_memcmp(s1,s2,n))
    {
       ui->textEdit_3->setText("Равны");
    }
    else
    {
        ui->textEdit_3->setText("Не равны");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_strncpy(s2, s1, n);
    s2[n] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_9_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    qwe = ui->textEdit_2->toPlainText();
    bytes = qwe.toLocal8Bit();
    const char* s2 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    int res = my_strcoll(s1, s2, n);
    if(res < 0)
    {
        ui->textEdit_3->setText("меньше");
    }
    else if (res > 0)
    {
        ui->textEdit_3->setText("больше");
    }
    else
    {
        ui->textEdit_3->setText("равны");
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_strncpy(s2, s1, n);
    s2[n] = '\0';
    if (std::strncmp(s1, s2, n) == 0) {
        ui->textEdit_3->setText("Строки совпадают");
    } else {
        ui->textEdit_3->setText("Строки не совпадают");
    }
    delete[] s2;
}


void MainWindow::on_pushButton_11_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n * 2 + 1];
    size_t len = my_strxfrm(s2, s1, n * 2);
    s2[len] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_12_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_memcpy(s2, s1, n);
    s2[n] = '\0';
    char* token = my_strtok(s2, " ");
    QString result;
    while (token != nullptr) {
        result += QString::fromUtf8(token) + " ";
        token = my_strtok(nullptr, " ");
    }
    ui->textEdit_3->setText(result);
    delete[] s2;
}


void MainWindow::on_pushButton_13_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
    int n = ui->lineEdit->text().toInt();
    char* s2 = new char[n + 1];
    my_memset(s2, 0, n);
    my_memcpy(s2, s1, n);
    s2[n] = '\0';
    ui->textEdit_3->setText(QString::fromUtf8(s2));
    delete[] s2;
}


void MainWindow::on_pushButton_14_clicked()
{
     int n = ui->lineEdit->text().toInt();
      ui->textEdit_3->setText(QString::fromUtf8(my_strerror(n)));
}


void MainWindow::on_pushButton_15_clicked()
{
    QString qwe = ui->textEdit->toPlainText();
    QByteArray bytes = qwe.toLocal8Bit();
    const char* s1 = bytes.constData();
      ui->textEdit_3->setText(QString::number(my_strlen(s1)));
}
