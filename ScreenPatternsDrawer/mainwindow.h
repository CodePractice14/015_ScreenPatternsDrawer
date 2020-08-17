#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScreen> /*Import QScreen to get access to current screen width and height*/
#include "drawverticalstripes.h" /* Import our custom DrawVerticalStripe class */
#include "drawhorizontalstripes.h" /* Import our custom DrawHorizontalStripe class */
#include "drawcheesstripes.h" /* Import our custom DrawChessStripe class */
#include "serverside.h" /* Import our custom ServerSide class */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_DrawVerticalStripes_clicked();
    void on_btn_DrawHorizontalStripes_clicked();
    void on_btn_DrawChessStripes_clicked();

    void smbConnectedToServer();
    void smbDisconnectedFromServer();
    void gotNewMessage(QString msg);

private:
    Ui::MainWindow *ui;
    /*We makes this pointers outside the function so we can check if they exist or not
    * This helps us check if a window exists (is already open) so we can close it when we create a new one
    */

    void init();
    void closeServer();
    int getCurrentScreenWidth();
    int getCurrentScreenHeight();

    void funDrawVerticalStripes(qint32 width);
    void funDrawHorizontalStripes(qint32 height);
    void funDrawChessStripes(qint32 size);

    DrawVerticalStripes *vertical = nullptr;
    DrawHorizontalStripes *horizontal = nullptr;
    DrawCheesStripes *chess = nullptr;

    ServerSide *server;

};
#endif // MAINWINDOW_H
