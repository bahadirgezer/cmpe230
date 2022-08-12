#include "calcwindow.h"
#include "ui_calcwindow.h"
#include <stack>

QString getHex(int decimal);
long long int operation(int operand);

bool clear = false;
bool ready = false;
bool registered = false;
bool equal = false;
long long int registeredNum = 0;
long long int inputNumber = 0;
int next_operator = 0;
QString display = "0";

CalcWindow::CalcWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CalcWindow)
{
    ui->setupUi(this);
    ui->Display->setText("0");

}

CalcWindow::~CalcWindow()
{
    delete ui;
}

/*
    * First press of clear does not clear the register, 
    it clears the display. The second press of clear will
    reset everything.

    * If the user presses 0 over and over, only a single 0 
    will be displayed.

    * The first press of an operator will add the input on 
    the screen. The second press adds the register as input.
    This is seen in the equal button. 

*/

void CalcWindow::on_clearButton_clicked() //clear button
{
    if (clear) { //second press will reset everything
        registeredNum = 0;
        ready = false;
        registered = false;
        equal = false;
        next_operator = 0;
        inputNumber = 0;
        display = "0";
        ui->Display->setText(display);
        clear = false;
    } else { //first press of clr will not reset the register
        inputNumber = 0; //it will just reset the input number
        display = "0";
        ui->Display->setText(display);
        clear = true;
    }
}

void CalcWindow::on_equalButton_clicked() //equal button will do the operation with the input to the register
{
    if (registered) { //if the register is ready, do the operation
        registeredNum = operation(inputNumber);
        displayNumber(registeredNum);
    }

    clear = false;
    ready = true;
    equal = true;
}

void CalcWindow::on_subtractionButton_clicked() //subtracts the input from the register, if clicked whhile registered, the registered num replaces the inputNumber
{
    if (registered && !ready && !equal) { //if the register is registered and the input is not ready, the inputNumber is replaced by the register
        registeredNum = operation(inputNumber);
        inputNumber = registeredNum;
        displayNumber(registeredNum);
    }
    if (registered && ready && !equal) { //if the user clicks the operator button twice, the inputNumber will be replaced by the registeredNum
        inputNumber = registeredNum;
    }
    if (equal) { //if equal is true, the inputNumber is the register
        inputNumber = registeredNum;
        equal = false;
    }

    clear = false;
    ready = true;
    next_operator = 2;
}

void CalcWindow::on_sumButton_clicked() //sums the input and the register, if clicked multiple times it will sum the input and the previous sum
{
    if (registered && !ready && !equal) { //if the register is registered and the input is not ready, the input is replaced by the register
        registeredNum = operation(inputNumber);
        inputNumber = registeredNum;
        displayNumber(registeredNum);
    }
    if (registered && ready && !equal) { //if the register is registered and the input is ready, the input is replaced by the register
        inputNumber = registeredNum;
    }
    if (equal) { //if the equal button is pressed, the input is replaced by the register
        inputNumber = registeredNum;
        equal = false;
    }

    clear = false;
    ready = true;
    next_operator = 1;
}

long long int operation(int operand) { //operand is the input number
    int result = 0;
    if (next_operator == 1) { //sum
        result = registeredNum + operand; 
    } else if (next_operator == 2) { //subtract
        result = registeredNum - operand;
    }
    return result;
}

void CalcWindow::displayInput(char input) //displays the input on the screen 
{
    if (ready && !registered && !equal) { //if the user has pressed an operator and then a number, the number will be added to the inputNumber
        ready = false;
        registered = true;
        registeredNum = inputNumber;
        inputNumber = 0;
        display = "0";
    }
    if (ready && registered && !equal) { //if the user has pressed an operator and then a number, the number will be added to the inputNumber
        ready = false;
        inputNumber = 0;
        display = "0";
    }
    if (equal) { //if the user has pressed an operator and then a number, the number will be added to the inputNumber
        registeredNum = 0;
        inputNumber = 0;
        display = "0";
        ready = false;
        registered = true;
        equal = false;
    }

    if (display == "0") { //if the display is 0, the input will be added to the display
        display = "";
        display += input;
    } else {
        display += input;
    }

    ui->Display->setText(display);
    clear = false;
}

void CalcWindow::displayNumber(int number)
{
    if (number == 0){ //if the number is 0, and the previous number was 0, do not display anything (as in display "0")
        display = "0";
    }
    else if(number < 0) { //if the number is negative, display the negative sign with the rest of the integer
        number *= -1;
        display = getHex(number);
        display.insert(0, '-');
    }
    else{
        display = getHex(number); //otherwise, display the integer
    }
    ui->Display->setText(display);
}

QString getHex(int decimal) {    // convert the decimal number to a hex string in order to display it
    if (decimal == 0){
        return "";                          // this is the base condition of the recursive funtion, if the result was 0 it is handled in the displayNumber(int number) methods
    }
    int nextDecimal = decimal / 16;         // call the same function recursively with this value
    char digit;
    int remainder = decimal % 16;           // the last digit is the remainder of the division
    if (remainder > 9){
        digit = remainder + '7';
    }
    else{
        digit = remainder + '0';
    }
    return getHex(nextDecimal) + digit; // toAdd part is the least significant digit of the hex value
}

void CalcWindow::on_button_0_clicked()      // for each operand button click display current number and add its numeric value to the inputNumber
{
    displayInput('0');
    inputNumber = (16 * inputNumber) + 0;
}

void CalcWindow::on_button_1_clicked() // These just convert the hex input string and add it the inputNumber variable
{
    displayInput('1');
    inputNumber = (16 * inputNumber) + 1;
}

void CalcWindow::on_button_2_clicked()
{
    displayInput('2');
    inputNumber = (16 * inputNumber) + 2;
}

void CalcWindow::on_button_3_clicked()
{
    displayInput('3');
    inputNumber = (16 * inputNumber) + 3;
}

void CalcWindow::on_button_4_clicked()
{
    displayInput('4');
    inputNumber = (16 * inputNumber) + 4;
}

void CalcWindow::on_button_5_clicked()
{
    displayInput('5');
    inputNumber = (16 * inputNumber) + 5;
}

void CalcWindow::on_button_6_clicked()
{
    displayInput('6');
    inputNumber = (16 * inputNumber) + 6;
}

void CalcWindow::on_button_7_clicked()
{
    displayInput('7');
    inputNumber = (16 * inputNumber) + 7;
}

void CalcWindow::on_button_8_clicked()
{
    displayInput('8');
    inputNumber = (16 * inputNumber) + 8;
}

void CalcWindow::on_button_9_clicked()
{
    displayInput('9');
    inputNumber = (16 * inputNumber) + 9;
}

void CalcWindow::on_button_A_clicked()
{
    displayInput('A');
    inputNumber = (16 * inputNumber) + 10;
}

void CalcWindow::on_button_B_clicked()
{
    displayInput('B');
    inputNumber = (16 * inputNumber) + 11;
}

void CalcWindow::on_button_C_clicked()
{
    displayInput('C');
    inputNumber = (16 * inputNumber) + 12;
}

void CalcWindow::on_button_D_clicked()
{
    displayInput('D');
    inputNumber = (16 * inputNumber) + 13;
}

void CalcWindow::on_button_E_clicked()
{
    displayInput('E');
    inputNumber = (16 * inputNumber) + 14;
}

void CalcWindow::on_button_F_clicked()
{
    displayInput('F');
    inputNumber = (16 * inputNumber) + 15;
}
