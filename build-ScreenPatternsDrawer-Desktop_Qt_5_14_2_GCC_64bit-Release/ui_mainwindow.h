/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_DrawChessStripes;
    QLabel *label_3;
    QSpinBox *sBox_ChessStripeSize;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_DrawVerticalStripes;
    QLabel *label;
    QSpinBox *sBox_VerticalStripeWidth;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_DrawHorizontalStripes;
    QLabel *label_2;
    QSpinBox *sBox_HorizontalStripeHeight;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QTextEdit *txtServerLog;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(502, 385);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_DrawChessStripes = new QPushButton(centralwidget);
        btn_DrawChessStripes->setObjectName(QString::fromUtf8("btn_DrawChessStripes"));

        horizontalLayout_3->addWidget(btn_DrawChessStripes);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        sBox_ChessStripeSize = new QSpinBox(centralwidget);
        sBox_ChessStripeSize->setObjectName(QString::fromUtf8("sBox_ChessStripeSize"));
        sBox_ChessStripeSize->setMaximum(300);
        sBox_ChessStripeSize->setSingleStep(5);
        sBox_ChessStripeSize->setValue(30);

        horizontalLayout_3->addWidget(sBox_ChessStripeSize);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_DrawVerticalStripes = new QPushButton(centralwidget);
        btn_DrawVerticalStripes->setObjectName(QString::fromUtf8("btn_DrawVerticalStripes"));

        horizontalLayout->addWidget(btn_DrawVerticalStripes);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        sBox_VerticalStripeWidth = new QSpinBox(centralwidget);
        sBox_VerticalStripeWidth->setObjectName(QString::fromUtf8("sBox_VerticalStripeWidth"));
        sBox_VerticalStripeWidth->setMaximum(300);
        sBox_VerticalStripeWidth->setSingleStep(5);
        sBox_VerticalStripeWidth->setValue(30);

        horizontalLayout->addWidget(sBox_VerticalStripeWidth);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_DrawHorizontalStripes = new QPushButton(centralwidget);
        btn_DrawHorizontalStripes->setObjectName(QString::fromUtf8("btn_DrawHorizontalStripes"));

        horizontalLayout_2->addWidget(btn_DrawHorizontalStripes);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        sBox_HorizontalStripeHeight = new QSpinBox(centralwidget);
        sBox_HorizontalStripeHeight->setObjectName(QString::fromUtf8("sBox_HorizontalStripeHeight"));
        sBox_HorizontalStripeHeight->setMaximum(300);
        sBox_HorizontalStripeHeight->setSingleStep(5);
        sBox_HorizontalStripeHeight->setValue(30);

        horizontalLayout_2->addWidget(sBox_HorizontalStripeHeight);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(481, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(481, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        txtServerLog = new QTextEdit(centralwidget);
        txtServerLog->setObjectName(QString::fromUtf8("txtServerLog"));

        verticalLayout_2->addWidget(txtServerLog);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_DrawChessStripes->setText(QCoreApplication::translate("MainWindow", "Draw Chess Stripes", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        btn_DrawVerticalStripes->setText(QCoreApplication::translate("MainWindow", "Draw Vertical Stripes", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "   Width: ", nullptr));
        btn_DrawHorizontalStripes->setText(QCoreApplication::translate("MainWindow", "Draw Horizontal Stripes", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "   Height: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Server Log", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
