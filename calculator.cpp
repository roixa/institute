#include "calculator.h"
#include <QDebug>
Calculator::Calculator()
{
}

QVector <double> Calculator::makeConsistInPercent(QVector<GaussFunc> funcs, double e, double fon, bool isWhisMagnet){


    QVector <double> consists;
    if(funcs.size()!=4)return consists;
    QVector <double> squares;
    fillQ();
    QVector <double> coefs=makeCoefs(e,isWhisMagnet);


    for(int i=0;i<funcs.size();i++){
        squares.append(funcs[i].area()-fon);
    }

    double divide=(squares[0]+squares[1]*coefs[0]+squares[2]*coefs[1]+squares[3]*coefs[2]);
    for(int i=0;i<squares.size();i++){
        double coef=i==0?1:coefs[i-1];
        double consist=squares[i]*coef/divide;

        consists.append(consist*100);
    }
    return consists;
}

QVector <double> Calculator::makeCoefs(double e,bool isWhisMagnet){
    QVector<double>ret;
    int j=chooseEnergyLevelValues(e,isWhisMagnet);
    QVector<QVector<double> > mat=isWhisMagnet?qWithMagnet:qWithoutMagnet;
    for (int i=0;i<3;i++){

        double q=mat[j][i+1]+(e-mat[j][i])*(mat[j+1][i+1]-mat[j][i+1])/(mat[j+1][i]-mat[j][i]);

        ret.append(q);
    }
    return ret;
}

int Calculator::chooseEnergyLevelValues(double e, bool isWhisMagnet){
    int i=0;
    QVector<QVector<double> > mat=isWhisMagnet?qWithMagnet:qWithoutMagnet;
    while(e>mat[i][0]){
        i++;
    }
    return i;
}

void Calculator::fillQ(){
    QVector <double> c;
    c.append(10); c.append(0.41); c.append(0.23); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(15); c.append(0.52); c.append(0.27); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(20); c.append(0.42); c.append(0.32); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(25); c.append(0.38); c.append(0.28); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(27.5); c.append(0.36); c.append(0.27); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(30); c.append(0.33); c.append(0.21); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(35); c.append(0.32); c.append(0.17); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(40); c.append(0.27); c.append(0.15); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(50); c.append(0.23); c.append(0.13); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    c.append(60); c.append(0.21); c.append(0.13); c.append(0.105);
    qWithMagnet.append(c); c.clear();
    ///////////////////////////////////
    c.append(10); c.append(0.42); c.append(0.25); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(15); c.append(0.56); c.append(0.3); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(20); c.append(0.51); c.append(0.38); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(25); c.append(0.53); c.append(0.4); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(27.5); c.append(0.52); c.append(0.39); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(30); c.append(0.53); c.append(0.36); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(35); c.append(0.52); c.append(0.32); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(40); c.append(0.48); c.append(0.3); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(50); c.append(0.4); c.append(0.28); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    c.append(60); c.append(0.32); c.append(0.21); c.append(0.26);
    qWithoutMagnet.append(c); c.clear();
    
    
}
