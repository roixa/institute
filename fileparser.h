#ifndef FILEPARSER_H
#define FILEPARSER_H
#include <QVector>
#include <QPoint>
#include <QString>
#include <QtCore>
class FileParser
{
public:
    FileParser();
    QVector<QPointF> parseFile(QString file);

private:
    QString readFile(QString f);
    QPointF parseNumberPair(QString str, bool isSecond);
};


#endif // FILEPARSER_H
