#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    /* (1) When this window closes DELETE our server!
     * If we don't do this we will suffer a memory leak..
     * ..that means the server will remain open in memory*/
    closeServer();
    delete server;
    delete ui;
}

void MainWindow::init()
{
    /* (1) Create a new instance of our ServerSide object */
    server = new ServerSide(this);
    /* (2) Connect signal gotNewMessage from our server, to slot gotNewMessage from this MainServerWindow */
    connect(server, &ServerSide::gotNewMessage, this, &MainWindow::gotNewMessage);
    /* (3) Connect signal newConnection from the tcpServer object on server, to slot smbConnectedToServer from this MainServerWindow */
    connect(server->tcpServer, &QTcpServer::newConnection, this, &MainWindow::smbConnectedToServer);
    /* (4) Connect signal smbDisconnected from our server, to slot smbDisconnectedFromServer from this MainServerWindow */
    connect(server, &ServerSide::smbDisconnected, this, &MainWindow:: smbDisconnectedFromServer);

    /* (5) Attempt to open the tcpServer from our server and make it listen on the given address/port.. */
    if(!server->tcpServer->listen(QHostAddress::Any, 6547))
    {
        /* (6) IF it can't connect for any reason display an error message and exit this function */
        ui->txtServerLog->append(tr("<font color=\"red\"><b>Error!</b> The port is taken by some other service.</font>"));
        return;
    }
    /* (7) IF it connects, we connect the tcpServer singal to our newConnection Slot from the server
     * ..which will add it to our open connections list*/
    connect(server->tcpServer, &QTcpServer::newConnection, server, &ServerSide::newConnection);
    /* (8) Display a success message */
    ui->txtServerLog->append(tr("<font color=\"green\"><b>Server started</b>, port is opened.</font>"));
}

void MainWindow::on_btn_DrawVerticalStripes_clicked()
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(vertical != nullptr)
    {
        if( vertical->isVisible())
        {
            vertical->close();
        }
    }
    /*Create a new dialog of the type Vertical Stripes*/
    vertical = new DrawVerticalStripes(this);

    /*Set proprieties*/
    int value = ui->sBox_VerticalStripeWidth->value();
    vertical->setLineWidth(value);
    vertical->setMaxScreenWidth(getCurrentScreenWidth());
    vertical->setMaxScreenHeight(getCurrentScreenHeight());
    vertical->init();

    /*Show it*/
    vertical->show();
}
void MainWindow::on_btn_DrawHorizontalStripes_clicked()
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(horizontal != nullptr)
    {
        if( horizontal->isVisible())
        {
            horizontal->close();
        }
    }

    /*Create a new dialog of the type Horizontal Stripes*/
    horizontal = new DrawHorizontalStripes(this);

    /*Set proprieties*/
    int value = ui->sBox_HorizontalStripeHeight->value();
    horizontal->setLineHeight(value);
    horizontal->setMaxScreenWidth(getCurrentScreenWidth());
    horizontal->setMaxScreenHeight(getCurrentScreenHeight());
    horizontal->init();

    /*Show it*/
    horizontal->show();
}
void MainWindow::on_btn_DrawChessStripes_clicked()
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(chess != nullptr)
    {
        if( chess->isVisible())
        {
            chess->close();
        }
    }

    /*Create a new dialog of the type Chess Stripes*/
    chess = new DrawCheesStripes(this);

    /*Set proprieties*/
    int value = ui->sBox_ChessStripeSize->value();
    chess->setSquareSize(value);
    chess->setMaxScreenWidth(getCurrentScreenWidth());
    chess->setMaxScreenHeight(getCurrentScreenHeight());
    chess->init();

    /*Show it*/
    chess->show();
}

int MainWindow::getCurrentScreenWidth()
{   /** Source: https://stackoverflow.com/a/42413327 **/
    /*Create an pointer of type screen that has the proprieties of primary screen*/
    QScreen *screen = QGuiApplication::primaryScreen();
    /*Get the width of the screen*/
    int width = screen->geometry().width();

    /*Return 1920 if width is 0 ..could be error or something so we return a default value.
     *Else return width*/
    if(width == 0) return 1920;
    else return width;
}
int MainWindow::getCurrentScreenHeight()
{   /** Source: https://stackoverflow.com/a/42413327 **/
    /*Create an pointer of type screen that has the proprieties of primary screen*/
    QScreen *screen = QGuiApplication::primaryScreen();
    /*Get the height of the screen*/
    int height = screen->geometry().height();

    /*Return 1080 if height is 0 ..could be error or something so we return a default value.
     *Else return height*/
    if(height == 0) return 1080;
    else return  height;
}

void MainWindow::gotNewMessage(QString msg)
{
    qDebug() <<"Recived: " +msg;

    /* (1) Split the message recived using the | delimitator (This is what we will use in PHP )*/
    QRegExp spliter("\\|");
    QStringList messages = msg.split(spliter);

    /* (2) We expect our message to contain 2 items. the callerFunction and the callerValue */
    if(messages.length() == 2)
    {
        /* (3) We convert the first part of our message into a string and the second part into int*/
        QString callerFunction = messages[0];
        qint32 callerValue = messages[1].toInt();

        /* (4) If the value is diffrent that 0, we call a draw function*/
        if(callerValue != 0)
        {
            qInfo() << messages[0];
            if(callerFunction == "HorizontalStripes")
            {
                funDrawHorizontalStripes(callerValue);
            }
            else if(callerFunction == "VerticalStripes")
            {
                funDrawVerticalStripes(callerValue);
            }
            else if(callerFunction == "ChessStripes")
            {
                funDrawChessStripes(callerValue);
            }
        }
    }
}
void MainWindow::smbConnectedToServer()
{
    qInfo() <<"Somebody connected..";
}
void MainWindow::smbDisconnectedFromServer()
{
    qWarning() <<"Somebody disconnected";
}
void MainWindow::closeServer()
{
    /* (1) IF the server is listening...which implies it is open */
    if(server->tcpServer->isListening())
    {
        /* (2) Send the discconect signal to the newConnection slot running on the server
         * ..This means that it closes/disloves the slot that was listening for any new connections */
        disconnect(server->tcpServer, &QTcpServer::newConnection, server, &ServerSide::newConnection);
        /* (3) Get a list of all connected clients currently connected to the server */
        QList<QTcpSocket *> clients = server->getClients();
        /* (4) For each of those clients send one last message :0 ..they'll know what it means */
        for(int i=0; i<clients.count(); i++)
        {
            server->sendToClient(clients.at(i), "0");
        }
        /* (5) Close the tcpServer */
        server->tcpServer->close();
        /* (6) Display a message */
        ui->txtServerLog->append(tr("<b>Server stopped</b>, post is closed"));
    }
    else
    {   /* (7) IF the server was not listening, means it wasn't running so we display a message */
        ui->txtServerLog->append(tr("<b>Error!</b> Server was not running"));
    }
}

void MainWindow::funDrawVerticalStripes(qint32 width)
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(vertical != nullptr)
    {
        if( vertical->isVisible())
        {
            vertical->close();
        }
    }
    /*Create a new dialog of the type Vertical Stripes*/
    vertical = new DrawVerticalStripes(this);

    /*Set proprieties*/
    vertical->setLineWidth(width);
    vertical->setMaxScreenWidth(getCurrentScreenWidth());
    vertical->setMaxScreenHeight(getCurrentScreenHeight());
    vertical->init();

    /*Show it*/
    vertical->show();
}
void MainWindow::funDrawHorizontalStripes(qint32 height)
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(horizontal != nullptr)
    {
        if( horizontal->isVisible())
        {
            horizontal->close();
        }
    }

    /*Create a new dialog of the type Horizontal Stripes*/
    horizontal = new DrawHorizontalStripes(this);

    /*Set proprieties*/
    horizontal->setLineHeight(height);
    horizontal->setMaxScreenWidth(getCurrentScreenWidth());
    horizontal->setMaxScreenHeight(getCurrentScreenHeight());
    horizontal->init();

    /*Show it*/
    horizontal->show();
}
void MainWindow::funDrawChessStripes(qint32 size)
{
    /*Check if window exist. if it does we close it to make a new one*/
    if(chess != nullptr)
    {
        if( chess->isVisible())
        {
            chess->close();
        }
    }

    /*Create a new dialog of the type Chess Stripes*/
    chess = new DrawCheesStripes(this);

    /*Set proprieties*/
    chess->setSquareSize(size);
    chess->setMaxScreenWidth(getCurrentScreenWidth());
    chess->setMaxScreenHeight(getCurrentScreenHeight());
    chess->init();

    /*Show it*/
    chess->show();
}










