#include "drawcheesstripes.h"
#include "ui_drawcheesstripes.h"

DrawCheesStripes::DrawCheesStripes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawCheesStripes)
{
    ui->setupUi(this);
}

DrawCheesStripes::~DrawCheesStripes()
{
    delete ui;
}
void DrawCheesStripes::init()
{
    /*We start all action from this function. we call it from the main window*/
    //qInfo() << "Lines --- Max width --- Max height";
    //qInfo() << m_lineWidth << " ---" << m_maxScreenWidth << " --- " << m_maxScreenHeight;

    FullScreenWindowSize();
}

void DrawCheesStripes::FullScreenWindowSize()
{
    /*[Qt::FramelessWindowHint] --> Make the window borderless*/
    /*[Qt::WindowStaysOnTopHint] --> Make the window Always on top*/
    /*[Qt::X11BypassWindowManagerHint] --> Make the window byapss X11 Window manager to make it always on top over all other windows*/
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint  /*| Qt::WindowStaysOnTopHint*/);

    /*Resize window to the given width and height*/
    this->resize(m_maxScreenWidth, m_maxScreenHeight);
}

void DrawCheesStripes::paintEvent(QPaintEvent *event)
{
    /*Set intial rectangle XY values*/
    int currentRectangleX = 0;
    int currentRectangleY = 0;

    /*Set maximum number of rows on columns based on max screen height and max screen width*/
    int maxNrofRows = (m_maxScreenHeight / m_squareSize) *2 +1;
    int maxNrOfColumns = (m_maxScreenWidth / m_squareSize) *2 +1;

    /*We will use this bool to swtich colors*/
    bool useColorBlack = false;

    /*Create a QPainter object and set its parrent to this widget*/
    QPainter painter(this);

    for(int rowIndex =0; rowIndex< maxNrofRows; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < maxNrOfColumns; columnIndex++)
        {
            /*Set color depending on value of bool useColorBlack (true = black / false = white*/
            useColorBlack ? painter.setBrush(Qt::black) : painter.setBrush(Qt::white);
            /*Change the bool useColor to its opposite*/
            useColorBlack = !useColorBlack;

            /*Create a rectangle that starts at X Y, with the required height and width*/
            QRect rectangle(currentRectangleX,currentRectangleY, m_squareSize, m_squareSize);
            /*Paint the rectangle*/
            painter.drawRect(rectangle);
            /*Increment the Y axis with the size. */
            currentRectangleY += m_squareSize;
            //qInfo() << "row " <<currentRectangleX << " col" << currentRectangleY;
        }
        /*Increment the X axis with the size. This takes us to the next row*/
        currentRectangleX += m_squareSize;
        /*Reset the Y axis to the start of the line*/
        currentRectangleY = 0;
        //qInfo() << "row " <<currentRectangleY << " col" << currentRectangleX;
    }
}

void DrawCheesStripes::setSquareSize(int value)
{
    this->m_squareSize = value;
}

void DrawCheesStripes::setMaxScreenWidth(int value)
{
    this->m_maxScreenWidth = value;
}

void DrawCheesStripes::setMaxScreenHeight(int value)
{
    this->m_maxScreenHeight = value;
}
