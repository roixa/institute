#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QVector>
#include "gaussfunc.h"

class Calculator
{
public:
    Calculator();
    QVector <double> makeConsistInPercent(QVector <GaussFunc> funcs,double e,double fon,bool isWhisMagnet);
    double E=16;//kEv
    double fon;
    bool withMagnet;
    QVector<QVector<double> > qWithMagnet;
    QVector<QVector<double> > qWithoutMagnet;
private:
    void fillQ();
    QVector <double> makeCoefs(double e, bool isWhisMagnet);//b2 b3 b4||c2 c3 c4
    int chooseEnergyLevelValues(double e,bool isWhisMagnet);


};

#endif // CALCULATOR_H
