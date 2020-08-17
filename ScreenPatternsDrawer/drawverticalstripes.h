#ifndef DRAWVERTICALSTRIPES_H
#define DRAWVERTICALSTRIPES_H

#include <QDialog>
#include <QDebug>   /** [For debugging] **/
#include <QPainter> /*We must include the QPainter so we can create a Painter object and override the default Paint event*/

namespace Ui {
class DrawVerticalStripes;
}

class DrawVerticalStripes : public QDialog
{
    Q_OBJECT

public:
    explicit DrawVerticalStripes(QWidget *parent = nullptr);
    ~DrawVerticalStripes();

    void setLineWidth(int value);           /** Setter function for propriety m_lineWidth **/
    void setMaxScreenWidth(int value);      /** Setter function for propriety m_maxScreenWidth **/
    void setMaxScreenHeight(int value);     /** Setter function for propriety m_maxScreenHeight **/

    void init();    /* This function will start all the action when this Dialog is created */

private:
    Ui::DrawVerticalStripes *ui;

    void FullScreenWindowSize();    /* This function will make sure our dialog covers the full window */

    int m_lineWidth =0;         /* Property: store the pattern Width */
    int m_maxScreenWidth =0;    /* Property: store max Screen Width */
    int m_maxScreenHeight =0;   /* Property: store max Screen Height */

protected:
    /* We must override the paint event of the dialog..
     * This event fires up everytime the Dialog is drawn.
     * By ovveriding it we make it draw patterns based on our custom code.*/
    void paintEvent(QPaintEvent *event);

};

#endif // DRAWVERTICALSTRIPES_H
