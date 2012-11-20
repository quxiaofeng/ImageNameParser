#include "nameconverter.h"

bool checkFile(QString filename)
{
    QFile f(filename);
    if (f.exists()==false) return false;
    if (f.open(QIODevice::ReadOnly | QIODevice::Text)==false) return false;
    f.close();
    return true;
}

QString parseName(QString filename)
{
    QString name, time, hand;
    QFileInfo file(filename);
    QString purefilename = file.fileName();
    //qDebug() << "purefilename: " << purefilename;
    QRegExp rx("^\\_([^\\_]+)\\_([^\\_])\\_([^\\_]+)\\.[^\\.]+$");
    if (rx.indexIn(purefilename) != -1) {
        name = rx.cap(1);
        //qDebug() << "name: "<< name;
        hand = rx.cap(2);
        //qDebug() << "hand: " << hand;
        time = rx.cap(3);
        //qDebug() << "time: " << time;
        return QString("%1\\%2\\%3.png").arg(name).arg(hand).arg(time);
    }
    else return QString("error-").append(purefilename);
}

bool copyFile(QString filename, QString newfilepath)
{
    qDebug() << "copy " << filename << " to " << newfilepath;
    QDir dstDir = QDir(QFileInfo(newfilepath).path());
    if (dstDir.exists() ==false) {
        QDir::current().mkpath(dstDir.path());
    }
    QFile::copy(filename, newfilepath);
    return QFile(newfilepath).exists();
}

NameConverter::NameConverter(QObject *parent) :
    QObject(parent)
{
}

bool NameConverter::convertFile(QString filename, QString dstPath)
{
    if (checkFile(filename) == false) return false;
    QString parsedPath = parseName(filename);
    //qDebug() << "parsed path: " << parsedPath;
    QString newfilepath = QString("%1\\%2").arg(dstPath).arg(parsedPath);
    return copyFile(filename, newfilepath);
}

bool NameConverter::convertDir(QString dir, QString dstPath)
{
    qDebug() << "dir is " << dir;
    qDebug() << "dstPath is " << dstPath;
    return true;
}


