#include "drawhorizontalstripes.h"
#include "ui_drawhorizontalstripes.h"

DrawHorizontalStripes::DrawHorizontalStripes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawHorizontalStripes)
{
    ui->setupUi(this);
}

DrawHorizontalStripes::~DrawHorizontalStripes()
{
    delete ui;
}

void DrawHorizontalStripes::init()
{
    /*We start all action from this function. we call it from the main window*/
    //qInfo() << "Lines --- Max width --- Max height";
    //qInfo() << m_lineWidth << " ---" << m_maxScreenWidth << " --- " << m_maxScreenHeight;

    FullScreenWindowSize();
}

void DrawHorizontalStripes::FullScreenWindowSize()
{
    /*[Qt::FramelessWindowHint] --> Make the window borderless*/
    /*[Qt::WindowStaysOnTopHint] --> Make the window Always on top*/
    /*[Qt::X11BypassWindowManagerHint] --> Make the window byapss X11 Window manager to make it always on top over all other windows*/
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint  /*| Qt::WindowStaysOnTopHint*/);

    /*Resize window to the given width and height*/
    this->resize(m_maxScreenWidth, m_maxScreenHeight);
}

void DrawHorizontalStripes::paintEvent(QPaintEvent *event)
{
    /*Set intial rectangle XY values*/
    int currentRectangleX = 0;
    int currentRectangleY = 0;

    /*Set maximum number of lines based on max screen width / line width*/
    int maxNrOfLines = m_maxScreenHeight / m_lineHeight +1;

    /*We will use this bool to swtich colors*/
    bool useColorBlack = false;

    /*Create a QPainter object and set its parrent to this widget*/
    QPainter painter(this);

    for(int i =0; i< maxNrOfLines; i++)
    {
        /*Set color depending on value of bool useColorBlack (true = black / false = white*/
        useColorBlack ? painter.setBrush(Qt::black) : painter.setBrush(Qt::white);
        /*Change the bool useColor to its opposite*/
        useColorBlack = !useColorBlack;

        /*Create a rectangle that starts at X Y, with the required height and maximum screen width*/
        QRect rectangle(currentRectangleX,currentRectangleY, m_maxScreenWidth, m_lineHeight);
        /*Paint the rectangle*/
        painter.drawRect(rectangle);
        /*Increment the Y axis with the height (this makes the rectangles be drawn on top of one another :'( */
        currentRectangleY += m_lineHeight;
    }
}

void DrawHorizontalStripes::setLineHeight(int value)
{
    this->m_lineHeight = value;
}

void DrawHorizontalStripes::setMaxScreenWidth(int value)
{
    this->m_maxScreenWidth = value;
}

void DrawHorizontalStripes::setMaxScreenHeight(int value)
{
    this->m_maxScreenHeight = value;
}

