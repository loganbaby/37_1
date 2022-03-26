#include "mainwindow.h"
#include "ui_mainwindow.h"

double first_num = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->pushButton_num_0,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_1,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_2,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_3,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_4,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_5,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_6,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_7,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_8,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect (ui->pushButton_num_9,
             SIGNAL(clicked()),
             this,
             SLOT(digit_nums()));

    connect(ui->pushButton_dot,
            SIGNAL(clicked()),
            this,
            SLOT(dot_click()));

    connect(ui->pushButton_change_tip,
            SIGNAL(clicked()),
            this,
            SLOT(operations()));

    connect(ui->pushButton_mod,
            SIGNAL(clicked()),
            this,
            SLOT(operations()));

    connect(ui->pushButton_minus,
            SIGNAL(clicked()),
            this,
            SLOT(math_operations()));

    connect(ui->pushButton_plus,
            SIGNAL(clicked()),
            this,
            SLOT(math_operations()));

    connect(ui->pushButton_del,
            SIGNAL(clicked()),
            this,
            SLOT(math_operations()));

    connect(ui->pushButton_multiply,
            SIGNAL(clicked()),
            this,
            SLOT(math_operations()));

    connect(ui->pushButton_result,
            SIGNAL(clicked()),
            this,
            SLOT(result_click()));

    connect(ui->pushButton_reroll,
            SIGNAL(clicked()),
            this,
            SLOT(ac_click()));

    ui->pushButton_del->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_nums() {
    QPushButton* current_button = dynamic_cast<QPushButton*>(sender());

    double long_number =
            (ui->label->text() + current_button->text()).toDouble();
    QString new_label = QString::number(long_number, 'g', 18);
    ui->label->setText(new_label);
}

void MainWindow::dot_click() {
    if(!ui->label->text().contains('.')) {
      ui->label->setText(ui->label->text() + '.');
    }
}

void MainWindow::operations()
{
    QPushButton* current_button = dynamic_cast<QPushButton*>(sender());

    if(current_button->text() == "+/-") {
      double long_number =
              ui->label->text().toDouble();
      long_number *= -1;
      QString new_label = QString::number(long_number, 'g', 18);
      ui->label->setText(new_label);
    } else if(current_button->text() == '%') {
        double long_number =
                ui->label->text().toDouble();
        long_number /= 100;
        QString new_label = QString::number(long_number, 'g', 18);
        ui->label->setText(new_label);
    }
}

void MainWindow::math_operations() {
    QPushButton* current_button = dynamic_cast<QPushButton*>(sender());
    first_num = ui->label->text().toDouble();
    ui->label->setText("");
    current_button->setChecked(true);
}

void MainWindow::result_click() {
    double label_number = 0;
    double second_number = 0;
    QString newLabel = "";

    second_number = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {
        label_number = first_num + second_number;
        newLabel = QString::number(label_number, 'g', 18);

        ui->label->setText(newLabel);
        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()) {
        label_number = first_num - second_number;
        newLabel = QString::number(label_number, 'g', 18);

        ui->label->setText(newLabel);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_multiply->isChecked()) {
        label_number = first_num * second_number;
        newLabel = QString::number(label_number, 'g', 18);

        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    } else if(ui->pushButton_del->isChecked()) {
        try {
            if(second_number == 0) throw ZeroDevide();
        }  catch (const ZeroDevide& x) {
            ui->label->setText(x.what());
        }

        label_number = first_num / second_number;
        newLabel = QString::number(label_number, 'g', 18);

        ui->label->setText(newLabel);
        ui->pushButton_del->setChecked(false);
    }
}

void MainWindow::ac_click() {
    first_num = 0;
    ui->label->setText("");
}
