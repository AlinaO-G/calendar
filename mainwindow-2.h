#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_editingFinished();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Jan_cellClicked(int row, int column);

    void on_Feb_cellClicked(int row, int column);

    void on_Mar_cellClicked(int row, int column);

    void on_Aug_cellClicked(int row, int column);

    void on_Sep_cellClicked(int row, int column);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
