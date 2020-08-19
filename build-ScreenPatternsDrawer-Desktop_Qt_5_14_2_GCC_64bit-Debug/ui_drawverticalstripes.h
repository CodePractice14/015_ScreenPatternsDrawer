/********************************************************************************
** Form generated from reading UI file 'drawverticalstripes.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWVERTICALSTRIPES_H
#define UI_DRAWVERTICALSTRIPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DrawVerticalStripes
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DrawVerticalStripes)
    {
        if (DrawVerticalStripes->objectName().isEmpty())
            DrawVerticalStripes->setObjectName(QString::fromUtf8("DrawVerticalStripes"));
        DrawVerticalStripes->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DrawVerticalStripes);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);


        retranslateUi(DrawVerticalStripes);

        QMetaObject::connectSlotsByName(DrawVerticalStripes);
    } // setupUi

    void retranslateUi(QDialog *DrawVerticalStripes)
    {
        DrawVerticalStripes->setWindowTitle(QCoreApplication::translate("DrawVerticalStripes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawVerticalStripes: public Ui_DrawVerticalStripes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWVERTICALSTRIPES_H
