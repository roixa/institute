#ifndef DATAMANAGER_H
#define DATAMANAGER_H\

#include <QVector>
#include <QPoint>
#include "fileparser.h"
#include "gaussfunc.h"
#include "calculator.h"

class DataManager
{
public:
    DataManager();
    Calculator calc;
    QVector<QPointF> getExperimentalData(QString file);
    QVector<QPointF> getExperimentalData();
    QVector<QPointF> approxIntervals;//intervals when  gaussians approximate on the x axis
    QVector<GaussFunc> buildGaussApprox();
    void filApproIntervals();

private:
    QVector<QPointF> experimentalData;
    FileParser parser;
    QVector<QPointF> experimentalDataFromInterval(QPointF interval);
    GaussFunc varyApprox(QVector<QPointF> expimental, int count, QPointF varyInterval);
    QPointF maxValue(QPointF interval);
    double integrieren(QVector<QPointF> func);
    QVector <QPointF> buildTeoriticalDataGaussFunc(QVector<QPointF> expimental,double param);
    GaussFunc buildGaussFuncFromDataAndParams(QVector<QPointF> expimental,double param);



};

#endif // DATAMANAGER_H
