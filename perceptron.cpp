#include "perceptron.h"

Perceptron::Perceptron(QVector<double> teached, int compress)
{
    QVector <bool> v=convertToBools(teached);
    layoutSize=v.size();
    initWeightMatrix();
}

void Perceptron::initWeightMatrix(){
    for(int i=0;i<layoutSize;i++){
        QVector <double> colomn;
        for(int j=0;j<layoutSize;j++){
            colomn.append(0);
        }
        weightMatrix.append(colomn);
    }
}

void Perceptron::teach(QVector<double> v){
    QVector <bool> teached=convertToBools(v);
    int n=teached.size();
    for(int i=0;i<layoutSize;i++){
            QVector <double> colomn;
            for(int j=0;j<layoutSize;j++){
                if(i==j) continue;
                double wij=weightMatrix[i][j];
                wij+=teached[i]*teached[j]/n;
                weightMatrix[i][j]=wij;
            }
        }
}

QVector <bool> Perceptron::convertToBools(QVector<double> ys){
    QVector <bool> ret;
    for(int i=0;i<ys.size();i++){
        int integer=ys[i];
        while(integer!=1){
            bool add=integer%2;
            integer=(integer-add)/2;
            ret.append(add);
        }
    }
    return ret;

}
