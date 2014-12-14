#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <QVector>
#include <QPointF>
#include "gaussfunc.h"

class Navigator
{
public:
    Navigator();
    void savePage(QVector<GaussFunc> approx,QVector<QPointF> exp,double energy);
    void refreshPage(QVector<GaussFunc> approx, QVector<QPointF> exp, double energy);
    //void refreshPage(GaussFunc saved,int page);
    int currentPageCount;
    int getPageCount(){return pageCount;}
    QVector<GaussFunc> getApproxData(int page);
    QVector<QPointF> getExpData(int page);
    double getEnergy(int page);

private:
    int pageCount;
    ;
    QVector<QVector<GaussFunc> >approxDatas;
    QVector<QVector<QPointF> >expDatas;
    QVector<double> energies;


};

#endif // NAVIGATOR_H
