/********************************************************************************
** Form generated from reading UI file 'drawhorizontalstripes.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWHORIZONTALSTRIPES_H
#define UI_DRAWHORIZONTALSTRIPES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DrawHorizontalStripes
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *DrawHorizontalStripes)
    {
        if (DrawHorizontalStripes->objectName().isEmpty())
            DrawHorizontalStripes->setObjectName(QString::fromUtf8("DrawHorizontalStripes"));
        DrawHorizontalStripes->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DrawHorizontalStripes);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 297, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout->addItem(verticalSpacer);


        retranslateUi(DrawHorizontalStripes);

        QMetaObject::connectSlotsByName(DrawHorizontalStripes);
    } // setupUi

    void retranslateUi(QDialog *DrawHorizontalStripes)
    {
        DrawHorizontalStripes->setWindowTitle(QCoreApplication::translate("DrawHorizontalStripes", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawHorizontalStripes: public Ui_DrawHorizontalStripes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWHORIZONTALSTRIPES_H
