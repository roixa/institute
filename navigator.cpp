#include "navigator.h"

Navigator::Navigator()
{
    pageCount=0;
}

void Navigator::savePage(QVector<GaussFunc> approx, QVector<QPointF> exp){
    approxDatas.append(approx);
    expDatas.append(exp);
    pageCount++;
}

QVector <GaussFunc> Navigator::getApproxData(int page){
    if(page>=approxDatas.size()) return QVector <GaussFunc>();
    return approxDatas[page];
}

QVector <QPointF> Navigator::getExpData(int page){
    if(page>=expDatas.size()) return QVector <QPointF>();
    return expDatas[page];
}

