#ifndef DRAWCHEESSTRIPES_H
#define DRAWCHEESSTRIPES_H

#include <QDialog>
#include <QDebug>   /** [For debugging] **/
#include <QPainter> /*We must include the QPainter so we can create a Painter object and override the default Paint event*/

namespace Ui {
class DrawCheesStripes;
}

class DrawCheesStripes : public QDialog
{
    Q_OBJECT

public:
    explicit DrawCheesStripes(QWidget *parent = nullptr);
    ~DrawCheesStripes();

    void setSquareSize(int value);              /** Setter function for propriety m_squareSize **/
    void setMaxScreenWidth(int value);          /** Setter function for propriety m_maxScreenWidth **/
    void setMaxScreenHeight(int value);         /** Setter function for propriety m_maxScreenHeight **/

    void init();    /* This function will start all the action when this Dialog is created */

private:
    Ui::DrawCheesStripes *ui;
    void FullScreenWindowSize();    /* This function will make sure our dialog covers the full window */

    int m_squareSize =0;        /* Property: store the pattern Size */
    int m_maxScreenWidth =0;    /* Property: store max Screen Width */
    int m_maxScreenHeight =0;   /* Property: store max Screen Height */

protected:
    /* We must override the paint event of the dialog..
     * This event fires up everytime the Dialog is drawn.
     * By ovveriding it we make it draw patterns based on our custom code.*/
    void paintEvent(QPaintEvent *event);
};

#endif // DRAWCHEESSTRIPES_H
