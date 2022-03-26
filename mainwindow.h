#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <exception>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ZeroDevide : public std::exception {
public:
    const char* what() const noexcept override {
        return "Zero devide.";
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digit_nums();
    void dot_click();
    void operations();
    void math_operations();
    void result_click();
    void ac_click();
};
#endif // MAINWINDOW_H
