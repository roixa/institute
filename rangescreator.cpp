#include "rangescreator.h"
#include <math.h>

RangesCreator::RangesCreator()
{
}

QVector<QPointF> RangesCreator::createRanges(double energy, double angle){
    QVector<QPointF> ret;
    QVector<double> m=detMasses();
    QVector<double> a=detAlfas();
    for(int i=0;i<size;i++){
        double l=l1[i]*(1+a[i]);
        //ret.append(l);
    }
    return ret;
}

QVector<double> RangesCreator::detIntervalsSize(){
    QVector<double> ret;
    for(int i=0;i<size;i++){
        ret.append(1);
    }
}

QVector<double> RangesCreator::detMasses(){
    QVector<double> ret;
    ret.append(1);
    ret.append(2);
    ret.append(3);
    ret.append(18);
    return ret;
}

QVector<double> RangesCreator::detAlfas(){
    QVector<double> m=detMasses();
    QVector<double> in=detIntervalsSize();
    QVector<double> ret;
    for(int i=0;i<size;i++){
        double val=(l1[i]-l2[i])/(pow((U1[i]/m[i]),0.5)*cos(o1)-pow((U2[i]/m[i])*cos(o2),0.5));
        ret.append(val);
    }
    return ret;
}


void RangesCreator::detExperimental(){
    U1.append(1);
    U1.append(1);
    U1.append(1);
    U1.append(1);

    U2.append(1);
    U2.append(1);
    U2.append(1);
    U2.append(1);

    l1.append(1);
    l1.append(1);
    l1.append(1);
    l1.append(1);

    l2.append(1);
    l2.append(1);
    l2.append(1);
    l2.append(1);
}

