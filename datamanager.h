#ifndef DATAMANAGER_H
#define DATAMANAGER_H\

#include <QVector>
#include <QPoint>
#include "fileparser.h"
#include "gaussfunc.h"

class DataManager
{
public:
    DataManager();
    QVector<QPointF> getExperimentalData();
    QVector<QPointF> approxIntervals;//intervals when  gaussians approximate on the x axis
    QVector<GaussFunc> buildGaussApprox();
    void filApproIntervals();

private:
    QVector<QPointF> experimentalData;
    FileParser parser;
    QVector<double> experimentalDataFromInterval(QPointF interval);
    GaussFunc varyApprox(QVector<double> expimental,int count,QPointF varyInterval);
    QPointF maxValue(QPointF interval);

};

#endif // DATAMANAGER_H
