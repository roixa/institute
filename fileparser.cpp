#include "fileparser.h"

FileParser::FileParser()
{
}


QVector<QPointF> FileParser::parseFile(QString f){
    QVector <QPointF> ret;

    QRegExp rx("(\\d+.\\d+)");
     QString str =readFile(f);
     int pos = 0;

     double xCoord;
     double yCoord;

     bool isSecond=true;
     bool started=false;
     while ((pos = rx.indexIn(str, pos)) != -1) {
         pos += rx.matchedLength();
         QString numStr=rx.cap(1);

         double num=numStr.toDouble();
         if(isSecond){
             xCoord=num;
             isSecond=false;
         }
         else{
             yCoord=num;
             ret.append(QPointF(xCoord,yCoord));
             qDebug()<<QPointF(xCoord,yCoord);
             isSecond=true;
         }
     }
    return ret;
}

QPointF FileParser::parseNumberPair(QString str,bool isSecond){


}
QString FileParser::readFile(QString f){
    QFile file(f); // создаем объект класса QFile
    QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (!file.open(QIODevice::ReadOnly)) // Проверяем, возможно ли открыть наш файл для чтения
        return "not read"; // если это сделать невозможно, то завершаем функцию
    data = file.readAll(); //считываем все данные с файла в объект data
    qDebug() << QString(data); // Выводим данные в консоль, предварительно создав строку из полученных данных
     return QString(data);
}
