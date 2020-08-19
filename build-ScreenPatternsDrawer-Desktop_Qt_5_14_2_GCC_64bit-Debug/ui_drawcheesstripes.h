/********************************************************************************
** Form generated from reading UI file 'drawcheesstripes.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWCHEESSTRIPES_H
#define UI_DRAWCHEESSTRIPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DrawCheesStripes
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DrawCheesStripes)
    {
        if (DrawCheesStripes->objectName().isEmpty())
            DrawCheesStripes->setObjectName(QString::fromUtf8("DrawCheesStripes"));
        DrawCheesStripes->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DrawCheesStripes);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);


        retranslateUi(DrawCheesStripes);

        QMetaObject::connectSlotsByName(DrawCheesStripes);
    } // setupUi

    void retranslateUi(QDialog *DrawCheesStripes)
    {
        DrawCheesStripes->setWindowTitle(QCoreApplication::translate("DrawCheesStripes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawCheesStripes: public Ui_DrawCheesStripes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWCHEESSTRIPES_H
