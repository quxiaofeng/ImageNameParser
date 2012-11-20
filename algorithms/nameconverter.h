#ifndef NAMECONVERTER_H
#define NAMECONVERTER_H

#include <QObject>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QDir>

class NameConverter : public QObject
{
    Q_OBJECT
public:
    explicit NameConverter(QObject *parent = 0);
    bool convertFile(QString filename, QString dstPath);
    bool convertDir(QString dir, QString dstPath);

signals:

public slots:

};

#endif // NAMECONVERTER_H
