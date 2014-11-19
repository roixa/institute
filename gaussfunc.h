#ifndef GAUSSFUNC_H
#define GAUSSFUNC_H

#include <math.h>

class GaussFunc
{
public:
    GaussFunc(double a,double e,double d);
    GaussFunc(double a,double e);
    GaussFunc();

    double valueOf(double x);
    double area();//area under the unc curve

private:
    double ampl;//max func value
    double dispers;//sigma,dispersion
    double expeval;//expected value, average value, x0
};

#endif // GAUSSFUNC_H
