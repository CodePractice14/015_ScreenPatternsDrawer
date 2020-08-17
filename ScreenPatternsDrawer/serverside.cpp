#include "serverside.h"

ServerSide::ServerSide(QObject *pwgt) : QObject(pwgt)
{
    /* (1) Create a new instance of the QTcpServer */
    tcpServer = new QTcpServer(this);
}

QList<QTcpSocket *> ServerSide::getClients()
{
    /* (1) Return the clients list when asked for */
    return clients;
}

void ServerSide::newConnection()
{
    /* (1) Create a new pointer and store the connection */
    QTcpSocket *clientSocket = tcpServer->nextPendingConnection();

    /* (2) Connects the clientConnection to special QTcpSocket signal / slot
     * My understanding: when this clientSocket gets discconected --> it will be send to delete list*/
    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
    /* (3) Connects the clientConnection to our custom signal / slot
     * My understanding: when this clientSocket gets new data --> we call our readClient function */
    connect(clientSocket, &QTcpSocket::readyRead, this, &ServerSide::readClient);
    /* (3) Connects the clientConnection to our custom signal / slot
     * My understanding: when this clientSocket gets discconected --> we call our gotDisconnection function */
    connect(clientSocket, &QTcpSocket::disconnected, this, &ServerSide::gotDisconnection);
    /* (4) Add the current connection to our clients list*/
    clients << clientSocket;
    /* (5) We call our sendToClient function and send him a reply to let him know we successfully connected*/
    //sendToClient(clientSocket, "Reply: connection established");
}

void ServerSide::readClient()
{
    qDebug() << "New incoming transmition";

    /* (1) Convert the sender [the signal that triggers this slot],to a QTcpSocket*/
    QTcpSocket *clientSocket = (QTcpSocket*)sender();

    /* (2) Create a byteArray where we will store our data*/
    QByteArray data;

    while(true)
    {
        /* (3) Read all info from the socket into a temporary array*/
        QByteArray tmp = clientSocket->readAll();
        /* (4) Add the data to our main array*/
        data += tmp;

        /* (5) IF there is nothing left to read wait 500 miliseconds then break the continous loop*/
        if (tmp.isEmpty()  && !clientSocket->waitForReadyRead(500))
        {
            break;
        }
    }
    /* (6) Display the recived data in a message */
    qDebug("Data recieved: %s (len = %d)", data.constData(), data.length());

    /* (7) Convert our data intro a string */
    QString str;
    str = QString(data.constData());
    /* (8) emit a gotNewMessage SIGNAL with our message */
    emit gotNewMessage(str);

    /* (9) Send a reply to the Client letting him know we recived the message */
    if(sendToClient(clientSocket, QString("Recived: [%1]").arg(str)) == -1)
    {
        /* (11) IF it fails for any reason we log a message*/
        qDebug() << "Some error occured";
    }
}

void ServerSide::gotDisconnection()
{
    /* (1) Remove the clientSocket that triggers this function from our list*/
    clients.removeAt(clients.indexOf((QTcpSocket*)sender()));
    /* (2) Trigger somebodyDisconnect function*/
    emit smbDisconnected();
}

qint64 ServerSide::sendToClient(QTcpSocket* socket, const QString &str)
{
    /* (1) Create a Byte Array to store our bytes */
    QByteArray arrBlock;
    /* (2) Convert our string to bytes array */
    arrBlock = str.toUtf8();

    /* (3) Write our data in the socket */
    return socket->write(arrBlock);
}
