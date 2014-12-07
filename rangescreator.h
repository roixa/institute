#ifndef RANGESCREATOR_H
#define RANGESCREATOR_H
#include <QVector>
#include <QPointF>
class RangesCreator
{
public:
    RangesCreator();
    QVector<QPointF> createRanges(double energy,double angle);
private:
    int size=4;
    double pi=3.14;

    QVector<double> U1;
    QVector<double> U2;

    QVector<double> l1;
    QVector<double> l2;

    double o1=pi/2;
    double o2=pi/2;
    void detExperimental();
    QVector<double>detAlfas();
    QVector<double>detIntervalsSize();
    QVector<double>detMasses();


};

#endif // RANGESCREATOR_H
