/********************************************************************************
** Form generated from reading UI file 'calcwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCWINDOW_H
#define UI_CALCWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalcWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGridLayout *buttonlayout;
    QPushButton *equalButton;
    QPushButton *button_6;
    QPushButton *button_A;
    QPushButton *button_4;
    QPushButton *clearButton;
    QPushButton *button_9;
    QPushButton *button_3;
    QPushButton *button_8;
    QPushButton *button_1;
    QPushButton *button_5;
    QPushButton *sumButton;
    QPushButton *subtractionButton;
    QPushButton *button_B;
    QPushButton *button_0;
    QPushButton *button_7;
    QPushButton *button_2;
    QPushButton *button_C;
    QPushButton *button_D;
    QPushButton *button_E;
    QPushButton *button_F;
    QLabel *Display;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalcWindow)
    {
        if (CalcWindow->objectName().isEmpty())
            CalcWindow->setObjectName(QString::fromUtf8("CalcWindow"));
        CalcWindow->resize(200, 300);
        centralwidget = new QWidget(CalcWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonlayout = new QGridLayout();
        buttonlayout->setObjectName(QString::fromUtf8("buttonlayout"));
        equalButton = new QPushButton(centralwidget);
        equalButton->setObjectName(QString::fromUtf8("equalButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(equalButton->sizePolicy().hasHeightForWidth());
        equalButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(30);
        equalButton->setFont(font);

        buttonlayout->addWidget(equalButton, 0, 2, 1, 1);

        button_6 = new QPushButton(centralwidget);
        button_6->setObjectName(QString::fromUtf8("button_6"));
        sizePolicy.setHeightForWidth(button_6->sizePolicy().hasHeightForWidth());
        button_6->setSizePolicy(sizePolicy);
        button_6->setFont(font);

        buttonlayout->addWidget(button_6, 2, 2, 1, 1);

        button_A = new QPushButton(centralwidget);
        button_A->setObjectName(QString::fromUtf8("button_A"));
        sizePolicy.setHeightForWidth(button_A->sizePolicy().hasHeightForWidth());
        button_A->setSizePolicy(sizePolicy);
        button_A->setFont(font);

        buttonlayout->addWidget(button_A, 3, 2, 1, 1);

        button_4 = new QPushButton(centralwidget);
        button_4->setObjectName(QString::fromUtf8("button_4"));
        sizePolicy.setHeightForWidth(button_4->sizePolicy().hasHeightForWidth());
        button_4->setSizePolicy(sizePolicy);
        button_4->setFont(font);

        buttonlayout->addWidget(button_4, 2, 0, 1, 1);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);
        clearButton->setFont(font);

        buttonlayout->addWidget(clearButton, 0, 3, 1, 1);

        button_9 = new QPushButton(centralwidget);
        button_9->setObjectName(QString::fromUtf8("button_9"));
        sizePolicy.setHeightForWidth(button_9->sizePolicy().hasHeightForWidth());
        button_9->setSizePolicy(sizePolicy);
        button_9->setFont(font);

        buttonlayout->addWidget(button_9, 3, 1, 1, 1);

        button_3 = new QPushButton(centralwidget);
        button_3->setObjectName(QString::fromUtf8("button_3"));
        sizePolicy.setHeightForWidth(button_3->sizePolicy().hasHeightForWidth());
        button_3->setSizePolicy(sizePolicy);
        button_3->setFont(font);

        buttonlayout->addWidget(button_3, 1, 3, 1, 1);

        button_8 = new QPushButton(centralwidget);
        button_8->setObjectName(QString::fromUtf8("button_8"));
        sizePolicy.setHeightForWidth(button_8->sizePolicy().hasHeightForWidth());
        button_8->setSizePolicy(sizePolicy);
        button_8->setFont(font);

        buttonlayout->addWidget(button_8, 3, 0, 1, 1);

        button_1 = new QPushButton(centralwidget);
        button_1->setObjectName(QString::fromUtf8("button_1"));
        sizePolicy.setHeightForWidth(button_1->sizePolicy().hasHeightForWidth());
        button_1->setSizePolicy(sizePolicy);
        button_1->setFont(font);

        buttonlayout->addWidget(button_1, 1, 1, 1, 1);

        button_5 = new QPushButton(centralwidget);
        button_5->setObjectName(QString::fromUtf8("button_5"));
        sizePolicy.setHeightForWidth(button_5->sizePolicy().hasHeightForWidth());
        button_5->setSizePolicy(sizePolicy);
        button_5->setFont(font);

        buttonlayout->addWidget(button_5, 2, 1, 1, 1);

        sumButton = new QPushButton(centralwidget);
        sumButton->setObjectName(QString::fromUtf8("sumButton"));
        sizePolicy.setHeightForWidth(sumButton->sizePolicy().hasHeightForWidth());
        sumButton->setSizePolicy(sizePolicy);
        sumButton->setFont(font);

        buttonlayout->addWidget(sumButton, 0, 0, 1, 1);

        subtractionButton = new QPushButton(centralwidget);
        subtractionButton->setObjectName(QString::fromUtf8("subtractionButton"));
        sizePolicy.setHeightForWidth(subtractionButton->sizePolicy().hasHeightForWidth());
        subtractionButton->setSizePolicy(sizePolicy);
        subtractionButton->setFont(font);

        buttonlayout->addWidget(subtractionButton, 0, 1, 1, 1);

        button_B = new QPushButton(centralwidget);
        button_B->setObjectName(QString::fromUtf8("button_B"));
        sizePolicy.setHeightForWidth(button_B->sizePolicy().hasHeightForWidth());
        button_B->setSizePolicy(sizePolicy);
        button_B->setFont(font);

        buttonlayout->addWidget(button_B, 3, 3, 1, 1);

        button_0 = new QPushButton(centralwidget);
        button_0->setObjectName(QString::fromUtf8("button_0"));
        sizePolicy.setHeightForWidth(button_0->sizePolicy().hasHeightForWidth());
        button_0->setSizePolicy(sizePolicy);
        button_0->setFont(font);

        buttonlayout->addWidget(button_0, 1, 0, 1, 1);

        button_7 = new QPushButton(centralwidget);
        button_7->setObjectName(QString::fromUtf8("button_7"));
        sizePolicy.setHeightForWidth(button_7->sizePolicy().hasHeightForWidth());
        button_7->setSizePolicy(sizePolicy);
        button_7->setFont(font);

        buttonlayout->addWidget(button_7, 2, 3, 1, 1);

        button_2 = new QPushButton(centralwidget);
        button_2->setObjectName(QString::fromUtf8("button_2"));
        sizePolicy.setHeightForWidth(button_2->sizePolicy().hasHeightForWidth());
        button_2->setSizePolicy(sizePolicy);
        button_2->setFont(font);

        buttonlayout->addWidget(button_2, 1, 2, 1, 1);

        button_C = new QPushButton(centralwidget);
        button_C->setObjectName(QString::fromUtf8("button_C"));
        sizePolicy.setHeightForWidth(button_C->sizePolicy().hasHeightForWidth());
        button_C->setSizePolicy(sizePolicy);
        button_C->setFont(font);

        buttonlayout->addWidget(button_C, 4, 0, 1, 1);

        button_D = new QPushButton(centralwidget);
        button_D->setObjectName(QString::fromUtf8("button_D"));
        sizePolicy.setHeightForWidth(button_D->sizePolicy().hasHeightForWidth());
        button_D->setSizePolicy(sizePolicy);
        button_D->setFont(font);

        buttonlayout->addWidget(button_D, 4, 1, 1, 1);

        button_E = new QPushButton(centralwidget);
        button_E->setObjectName(QString::fromUtf8("button_E"));
        sizePolicy.setHeightForWidth(button_E->sizePolicy().hasHeightForWidth());
        button_E->setSizePolicy(sizePolicy);
        button_E->setFont(font);

        buttonlayout->addWidget(button_E, 4, 2, 1, 1);

        button_F = new QPushButton(centralwidget);
        button_F->setObjectName(QString::fromUtf8("button_F"));
        sizePolicy.setHeightForWidth(button_F->sizePolicy().hasHeightForWidth());
        button_F->setSizePolicy(sizePolicy);
        button_F->setFont(font);

        buttonlayout->addWidget(button_F, 4, 3, 1, 1);


        gridLayout->addLayout(buttonlayout, 1, 0, 1, 1);

        Display = new QLabel(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        Display->setFont(font);
        Display->setFrameShape(QFrame::Box);
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 1, 1);

        CalcWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalcWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        sizePolicy.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy);
        CalcWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalcWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CalcWindow->setStatusBar(statusbar);

        retranslateUi(CalcWindow);

        QMetaObject::connectSlotsByName(CalcWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalcWindow)
    {
        CalcWindow->setWindowTitle(QCoreApplication::translate("CalcWindow", "Hexadecimal Calculator", nullptr));
        equalButton->setText(QCoreApplication::translate("CalcWindow", "=", nullptr));
        button_6->setText(QCoreApplication::translate("CalcWindow", "6", nullptr));
        button_A->setText(QCoreApplication::translate("CalcWindow", "A", nullptr));
        button_4->setText(QCoreApplication::translate("CalcWindow", "4", nullptr));
        clearButton->setText(QCoreApplication::translate("CalcWindow", "Clr", nullptr));
        button_9->setText(QCoreApplication::translate("CalcWindow", "9", nullptr));
        button_3->setText(QCoreApplication::translate("CalcWindow", "3", nullptr));
        button_8->setText(QCoreApplication::translate("CalcWindow", "8", nullptr));
        button_1->setText(QCoreApplication::translate("CalcWindow", "1", nullptr));
        button_5->setText(QCoreApplication::translate("CalcWindow", "5", nullptr));
        sumButton->setText(QCoreApplication::translate("CalcWindow", "+", nullptr));
        subtractionButton->setText(QCoreApplication::translate("CalcWindow", "-", nullptr));
        button_B->setText(QCoreApplication::translate("CalcWindow", "B", nullptr));
        button_0->setText(QCoreApplication::translate("CalcWindow", "0", nullptr));
        button_7->setText(QCoreApplication::translate("CalcWindow", "7", nullptr));
        button_2->setText(QCoreApplication::translate("CalcWindow", "2", nullptr));
        button_C->setText(QCoreApplication::translate("CalcWindow", "C", nullptr));
        button_D->setText(QCoreApplication::translate("CalcWindow", "D", nullptr));
        button_E->setText(QCoreApplication::translate("CalcWindow", "E", nullptr));
        button_F->setText(QCoreApplication::translate("CalcWindow", "F", nullptr));
        Display->setText(QCoreApplication::translate("CalcWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalcWindow: public Ui_CalcWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCWINDOW_H
