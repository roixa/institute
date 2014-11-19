#include "gaussfunc.h"
#include <QDebug>

GaussFunc::GaussFunc(double a,double e,double d)
{
    ampl=a;
    expeval=e;
    dispers=d;
}

GaussFunc::GaussFunc(double a,double e)
{
    ampl=a;
    expeval=e;
    dispers=0.1;
    qDebug()<<a<<e;
}

GaussFunc::GaussFunc()
{
    ampl=10;
    expeval=700;
    dispers=10;
}


double GaussFunc::valueOf(double x){

    double ret=ampl*exp( pow((x-expeval),2)/(-2*dispers*dispers) );

    return ret;
}

double GaussFunc::area(){
    return ampl/(dispers);
}


