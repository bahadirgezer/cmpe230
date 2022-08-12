#ifndef CALCWINDOW_H
#define CALCWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CalcWindow; }
QT_END_NAMESPACE

class CalcWindow : public QMainWindow
{
    Q_OBJECT

public:
    CalcWindow(QWidget *parent = nullptr);
    ~CalcWindow();

private slots:
    void displayInput(char);

    void on_button_1_clicked();

    void on_button_0_clicked();

    void on_button_3_clicked();

    void on_button_2_clicked();

    void on_button_4_clicked();

    void on_button_5_clicked();

    void on_button_6_clicked();

    void on_button_7_clicked();

    void on_button_8_clicked();

    void on_button_9_clicked();

    void on_button_A_clicked();

    void on_button_B_clicked();

    void on_button_C_clicked();

    void on_button_D_clicked();

    void on_button_E_clicked();

    void on_button_F_clicked();

    void displayNumber(int);

    void on_subtractionButton_clicked();

    void on_sumButton_clicked();

    void on_equalButton_clicked();
    
    void on_clearButton_clicked();

private:
    Ui::CalcWindow *ui;


};
#endif // CALCWINDOW_H
