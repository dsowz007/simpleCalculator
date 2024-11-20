// DO NOW
// do something about checkAns1 and checkAns2

// TODO
// allow more than 2 values for calculation in one expression (replace value1 & value2 with a vector to cover all values in the expression)
// simplify fractions and add ability to input fractions
// sin() cos() and tan() functions
// optimize code and make it cleaner

#include <array>
#include <vector>

#include "math.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

enum CalcOperator {none, plus, minus, multiply, divide};

CalcOperator sign = none;
QString printedNumValue = "";
QString valueHalf = "";
std::array<QString, 4> savedCalculations = {};

// -2 = negative, -1 = Ans, 0-9 = integers
std::vector<int> firstValues = {};
std::vector<int> secondValues = {};

double previousAns = 0;
double value1 = 0;
double value2 = 0;
double answer = 0;
bool zeroCount = false;
bool checkAns1 = false;
bool checkAns2 = false;
bool checkNegative1 = false;
bool checkNegative2 = false;
bool checkOperator = false;


void MainWindow::clear_values(){
    checkOperator = false;
    checkNegative1 = false;
    checkNegative2 = false;
    zeroCount = false;
    firstValues.clear();
    secondValues.clear();
    value1 = 0;
    value2 = 0;
    printedNumValue = "";
}

void MainWindow::set_input_display(std::vector<int>& vect){
    //set printedNumValue to all inputs except for the one deleted (including Ans and '-')
    for(int i = 0; i < vect.size(); ++i){
        if(vect[i] == -2){
            printedNumValue = printedNumValue + '-';
        } else if(vect[i] == -1) {
            printedNumValue = printedNumValue + "Ans";
        } else {
            printedNumValue = printedNumValue + QString::number(vect[i]);
        }
    }
}

void MainWindow::on_numberOne_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 1;
        firstValues.push_back(1);
    } else {
        value2 *= 10;
        value2 += 1;
        secondValues.push_back(1);
    }

    printedNumValue = printedNumValue + "1";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberTwo_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 2;
        firstValues.push_back(2);
    } else {
        value2 *= 10;
        value2 += 2;
        secondValues.push_back(2);
    }

    printedNumValue = printedNumValue + "2";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberThree_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 3;
        firstValues.push_back(3);
    } else {
        value2 *= 10;
        value2 += 3;
        secondValues.push_back(3);
    }

    printedNumValue = printedNumValue + "3";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberFour_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 4;
        firstValues.push_back(4);
    } else {
        value2 *= 10;
        value2 += 4;
        secondValues.push_back(4);
    }

    printedNumValue = printedNumValue + "4";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberFive_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 5;
        firstValues.push_back(5);
    } else {
        value2 *= 10;
        value2 += 5;
        secondValues.push_back(5);
    }

    printedNumValue = printedNumValue + "5";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberSix_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 6;
        firstValues.push_back(6);
    } else {
        value2 *= 10;
        value2 += 6;
        secondValues.push_back(6);
    }

    printedNumValue = printedNumValue + "6";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_NumberSeven_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 7;
        firstValues.push_back(7);
    } else {
        value2 *= 10;
        value2 += 7;
        secondValues.push_back(7);
    }

    printedNumValue = printedNumValue + "7";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberEight_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 8;
        firstValues.push_back(8);
    } else {
        value2 *= 10;
        value2 += 8;
        secondValues.push_back(8);
    }

    printedNumValue = printedNumValue + "8";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberNine_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 9;
        firstValues.push_back(9);
    } else {
        value2 *= 10;
        value2 += 9;
        secondValues.push_back(9);
    }

    printedNumValue = printedNumValue + "9";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberZero_clicked()
{
    if(value1 == 0 && !checkOperator)
        zeroCount = true;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += 0;
        firstValues.push_back(0);
    } else {
        value2 *= 10;
        value2 += 0;
        firstValues.push_back(0);
    }

    printedNumValue = printedNumValue + "0";
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_previousAnswerButton_clicked()
{
    checkAns2 = true;
    //check if value1 or value2
    if(!checkOperator){
        if(printedNumValue == ""){
            value1 = previousAns;
        } else {
            value1 *= 10;
            value1 += previousAns;
        }
        firstValues.push_back(-1);
    } else {
        if(printedNumValue == valueHalf){
            value2 = previousAns;
        } else {
            value2 *= 10;
            value2 += previousAns;
        }
        secondValues.push_back(-1);
    }

    printedNumValue = printedNumValue + "Ans";
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_negativeButton_clicked()
{
    //determine which number to make negative
    if(!checkOperator){
        checkNegative1 = true;

        //check if negitve sign is used properly, if placed in between an input, give Syntax Error
        if(printedNumValue == ""){
            printedNumValue = printedNumValue + '-';
            firstValues.push_back(-2);
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    } else {
        checkNegative2 = true;
        if(valueHalf == printedNumValue){
            printedNumValue = printedNumValue + '-';
            secondValues.push_back(-2);
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    //TODO
    //check if anything is in inputDisplay when pressed, if not, do nothing and return
    //if()

    //reverse previous input
    //check if removeing a number or an operator sign
    if(valueHalf == printedNumValue && checkOperator == true){
        //removes the operator
        checkOperator = false;
        sign = none;
        printedNumValue = "";
        set_input_display(firstValues);
        ui->inputDisplay->setText(printedNumValue);
    } else if(checkOperator == true) {
        //removes last input for value2

        //check if removing Ans, negative, or a number
        if(secondValues.back() != -1 && secondValues.back() != -2){
            double previousInput = std::fmod(value2, 10.0);
            value2 -= previousInput;
            value2 /= 10.0;
            secondValues.pop_back();
            if(secondValues.size() == 0){
                checkNegative2 = false;
                printedNumValue = valueHalf;
            } else {
                printedNumValue = valueHalf;
                set_input_display(secondValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else if(secondValues.back() == -1){
            //removes Ans at back
            //check if Ans if is the only thing in value2
            if(value2 == previousAns){
                value2 = 0;
                printedNumValue = valueHalf;
                secondValues.pop_back();
                checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else {
                secondValues.pop_back();
                value2 -= previousAns;
                value2 /= 10;
                checkAns2 = false;

                printedNumValue = valueHalf;
                set_input_display(secondValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else {
            //removes negative sign at back
            secondValues.pop_back();
            checkNegative2 = !checkNegative2;

            printedNumValue = valueHalf;
            set_input_display(secondValues);
            ui->inputDisplay->setText(printedNumValue);
        }
        ui->inputDisplay->setText(printedNumValue);
    } else {
        //removes last input for value1

        //check if removing Ans, negative, or a number
        if(firstValues.back() != -1 && firstValues.back() != -2){
            //removes number at back
            double previousInput = std::fmod(value1, 10.0);
            value1 -= previousInput;
            value1 /= 10;
            firstValues.pop_back();
            //check if the first number was deleted, then reset
            if(firstValues.size() == 0){
                checkNegative1 = false;
                zeroCount = false;
                printedNumValue = "";
                ui->inputDisplay->setText("");
            } else {
                printedNumValue = "";
                set_input_display(firstValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else if(firstValues.back() == -1){
            //removes Ans at back
            //check if Ans is the only thing in value1
            if(value1 == previousAns){
                value1 = 0;
                printedNumValue = "";
                firstValues.pop_back();
                checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else {
                firstValues.pop_back();
                value1 -= previousAns;
                value1 /= 10;
                checkAns2 = false;

                printedNumValue = "";
                set_input_display(firstValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else {
            //removes negative sign at back
            firstValues.pop_back();
            checkNegative1 = !checkNegative1;

            printedNumValue = "";
            set_input_display(firstValues);
            ui->inputDisplay->setText(printedNumValue);
        }
    }
}

void MainWindow::on_clearButton_clicked()
{
    clear_values();
    checkAns2 = false;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_allClearButton_clicked()
{
    clear_values();
    previousAns = 0;
    checkAns1 = false;
    checkAns2 = false;
    ui->inputDisplay->setText(printedNumValue);

    for(int i = 0; i < savedCalculations.size(); ++i){
        savedCalculations[i] = "";
    }

    ui->saveDisplay1->setText(savedCalculations[0]);
    ui->saveDisplay2->setText(savedCalculations[1]);
    ui->saveDisplay3->setText(savedCalculations[2]);
    ui->saveDisplay4->setText(savedCalculations[3]);
}

void MainWindow::on_plusSign_clicked()
{
    sign = plus;
    checkOperator = true;
    if(!zeroCount && value1 == 0 && !checkAns2)
        printedNumValue = '0';
    printedNumValue = printedNumValue + " + ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_minusSign_clicked()
{
    sign = minus;
    checkOperator = true;
    if(!zeroCount && value1 == 0)
        printedNumValue = '0';
    printedNumValue = printedNumValue + " - ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_multiplySign_clicked()
{
    sign = multiply;
    checkOperator = true;
    if(!zeroCount && value1 == 0)
        printedNumValue = '0';
    printedNumValue = printedNumValue + " x ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_divideSign_clicked()
{
    sign = divide;
    checkOperator = true;
    if(!zeroCount && value1 == 0)
        printedNumValue = '0';
    printedNumValue = printedNumValue + " ÷ ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_equalsSign_clicked()
{
    //check if Ans was entered without a previous Ans
    if(!checkAns1 && checkAns2)
    {
        clear_values();
        ui->inputDisplay->setText("Ans Does Not Exist");
        checkAns2 = false;
        return;
    }

    //check if a value is negative
    if(checkNegative1){
        value1 -= value1 * 2;
    }
    if(checkNegative2){
        value2 -= value2 * 2;
    }

    // performs desired calculation for answer
    switch(sign){
    case plus:
        answer = value1 + value2;
        break;
    case minus:
        answer = value1 - value2;
        break;
    case multiply:
        answer = value1 * value2;
        if(answer - (int)answer > 0 && answer - (int)answer <= 0.0001){
            answer = (int)answer;
        } else if(answer - (int)answer >= 0.9999 && answer - (int)answer < 1){
            answer = (int)answer + 1;
        }
        break;
    case divide:
        if(value2 != 0) {
            answer = value1 / value2;
            //round to the nearest thousandth
            answer = std::round(answer * 10000.0) / 10000.0;
        } else {
            clear_values();
            ui->inputDisplay->setText("Cant Divide by Zero");
            return;
        }
        break;
    default:
        answer = value1;
        break;
    }

    //savedEquation1 = printedNumValue + " = " + QString::number(answer);
    //ui->saveDisplay1->setText(savedEquation1);

    //in decending order, move savedCalculations[i-1] forward 1 until input replaces save1
    for(int i = savedCalculations.size() - 1; i > 0; --i){
        savedCalculations[i] = savedCalculations[i-1];
    }
    savedCalculations[0] = printedNumValue + " = " + QString::number(answer);
    previousAns = answer;
    checkAns1 = true;
    checkAns2 = false;

    //print saves
    ui->saveDisplay1->setText(savedCalculations[0]);
    ui->saveDisplay2->setText(savedCalculations[1]);
    ui->saveDisplay3->setText(savedCalculations[2]);
    ui->saveDisplay4->setText(savedCalculations[3]);

    clear_values();
    ui->inputDisplay->setText(printedNumValue);
}
