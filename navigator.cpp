#include "navigator.h"

Navigator::Navigator()
{
    pageCount=0;
    currentPageCount=0;
}

void Navigator::savePage(QVector<GaussFunc> approx, QVector<QPointF> exp, double energy){
    approxDatas.append(approx);
    expDatas.append(exp);
    energies.append(energy);
    pageCount++;
}

void Navigator::refreshPage(QVector<GaussFunc> approx, QVector<QPointF> exp,double energy){
    approxDatas[currentPageCount]=approx;
    expDatas[currentPageCount]=exp;
    energies[currentPageCount]=energy;

}

QVector <GaussFunc> Navigator::getApproxData(int page){
    if(page>=approxDatas.size()) return QVector <GaussFunc>();
    return approxDatas[page];
}

QVector <QPointF> Navigator::getExpData(int page){
    if(page>=expDatas.size()) return QVector <QPointF>();
    return expDatas[page];
}
double Navigator::getEnergy(int page){
    return energies[page];
}

