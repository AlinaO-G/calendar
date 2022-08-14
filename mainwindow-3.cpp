#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vector"
#include "qlineedit.h"
#include <QLabel>

bool is_leap(int year){
    return ((year % 400 == 0) or (year % 100 != 0 and year % 4 == 0));
}

int num_of_days_in_year(int year){
    return (365 + is_leap(year));
}

int num_of_d_in_m(int year, int month){
    if (month != 2)
        return (30 + ((month < 8 and month % 2 == 1) or (month > 7 and month % 2 == 0)));
    else
        return (28 + is_leap(year));
}

int num_of_d_fr_beg_of_y(int year, int month, int day){
    int num = 0;
    for (int i = 1; i < month; ++i)
        num += num_of_d_in_m(year, i);
    num += day;
    return num;
}

int num_of_d_fr_beg(int year, int month, int day){
    int num = 0;
    for (int i = 1; i < year; ++i)
        num += num_of_days_in_year(i);
    num += num_of_d_fr_beg_of_y(year, month, day);
    return num;
}

int num_of_d_between_2_d(int year1, int month1, int day1, int year2, int month2, int day2){
    int num1, num2;
    num1 = num_of_d_fr_beg(year1, month1, day1);
    num2 = num_of_d_fr_beg(year2, month2, day2);
    return abs(num1 - num2);
}

int weekday(int year1, int month1, int day1, int wday1, int year2, int month2, int day2){
    int wday2;
    wday2 = (((wday1 + (7 + (num_of_d_fr_beg(year2, month2, day2) - num_of_d_fr_beg(year1, month1, day1)) % 7) % 7) - 1) % 7);
    return wday2;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_6->show();
    ui->label ->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


int year_n;

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    bool ok;
    int year;
    year = arg1.toInt(&ok);
    ui->lineEdit_2->setText(arg1);
    year_n = year;
}

int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
void MainWindow::on_lineEdit_editingFinished()
{
    ui->label ->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->show();
    ui->Jan->clearContents();
    ui->Feb->clearContents();
    ui->Mar->clearContents();
    ui->Apr->clearContents();
    ui->May->clearContents();
    ui->Jun->clearContents();
    ui->Jul->clearContents();
    ui->Aug->clearContents();
    ui->Sep->clearContents();
    ui->Oct->clearContents();
    ui->Nov->clearContents();
    ui->Dec->clearContents();
    int col, line;
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 1); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 1, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 1, i)) % 7;
        ui->Jan->setItem(line, col, text);
        if (line == 6)
             ui->Jan->item(line, col)->setBackground(Qt::red);
        if (i == 1){
            ui->Jan->item(line, col)->setBackground(Qt::cyan);
            x1 = line;
            y1 = col;
        }
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 2); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 2, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 2, i)) % 7;
        ui->Feb->setItem(line, col, text);
        if (line == 6)
            ui->Feb->item(line, col)->setBackground(Qt::red);
        if(i == 23){
            x2 = line;
            y2 = col;
            ui->Feb->item(line, col)->setBackground(Qt::cyan);
        }
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 3); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 3, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 3, i)) % 7;
        ui->Mar->setItem(line, col, text);
        if (line == 6)
            ui->Mar->item(line, col)->setBackground(Qt::red);
        if(i == 8){
            x3 = line;
            y3 = col;
            ui->Mar->item(line, col)->setBackground(Qt::cyan);
        }
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 4); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 4, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 4, i)) % 7;
        ui->Apr->setItem(line, col, text);
        if (line == 6)
            ui->Apr->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 5); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 5, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 5, i)) % 7;
        ui->May->setItem(line, col, text);
        if (line == 6)
            ui->May->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 6); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 6, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 6, i)) % 7;
        ui->Jun->setItem(line, col, text);
        if (line == 6)
            ui->Jun->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 7); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 7, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 7, i)) % 7;
        ui->Jul->setItem(line, col, text);
        if (line == 6)
            ui->Jul->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 8); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 8, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 8, i)) % 7;
        ui->Aug->setItem(line, col, text);
        if (line == 6)
            ui->Aug->item(line, col)->setBackground(Qt::red);
        if(i == 29){
            x4 = line;
            y4 = col;
            ui->Aug->item(line, col)->setBackground(Qt::cyan);
        }
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 9); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 9, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 9, i)) % 7;
        ui->Sep->setItem(line, col, text);
        if (line == 6)
            ui->Sep->item(line, col)->setBackground(Qt::red);
        if(i == 1){
            x5 = line;
            y5 = col;
            ui->Sep->item(line, col)->setBackground(Qt::cyan);
        }
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 10); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 10, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 10, i)) % 7;
        ui->Oct->setItem(line, col, text);
        if (line == 6)
            ui->Oct->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 11); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 11, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 11, i)) % 7;
        ui->Nov->setItem(line, col, text);
        if (line == 6)
            ui->Nov->item(line, col)->setBackground(Qt::red);
    }
    for (int i = 1 ; i <= num_of_d_in_m(year_n, 12); ++i){
        QString lineEdit1;
        lineEdit1.setNum(i);
        QTableWidgetItem *text = new QTableWidgetItem(lineEdit1);
        col = (i + weekday(2020, 1, 13, 1, year_n, 12, 1) - 1) / 7;
        line = (weekday(2020, 1, 13, 1, year_n, 12, i)) % 7;
        ui->Dec->setItem(line, col, text);
        if (line == 6)
            ui->Dec->item(line, col)->setBackground(Qt::red);
    }
}

void MainWindow::on_pushButton_clicked()
{
    --year_n;
    ui->lineEdit_2->setText(QString::number(year_n));
    MainWindow::on_lineEdit_editingFinished();
}

void MainWindow::on_pushButton_2_clicked()
{
    ++year_n;
    ui->lineEdit_2->setText(QString::number(year_n));
    MainWindow::on_lineEdit_editingFinished();
}

void MainWindow::on_Jan_cellClicked(int row, int column)
{
    if(x1 == row and y1 == column){
        ui->label->show();
     }
}

void MainWindow::on_Feb_cellClicked(int row, int column)
{
    if(x2 == row and y2 == column){
        ui->label_3->show();
     }
}

void MainWindow::on_Mar_cellClicked(int row, int column)
{
    if(x3 == row and y3 == column){
        ui->label_2->show();
     }
}

void MainWindow::on_Aug_cellClicked(int row, int column)
{
    if(x4 == row and y4 == column){
        ui->label_4->show();
     }
}

void MainWindow::on_Sep_cellClicked(int row, int column)
{
    if(x5 == row and y5 == column){
        ui->label_5->show();
     }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label ->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
}
