#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <QVector>
class Perceptron
{
public:
    Perceptron(QVector<double> v,int compress);
    void teach (QVector<double> v);
    bool recognize(QVector<double> v);

private:
    QVector<double> weights;
    QVector<QVector<double> >weightMatrix;
    QVector<bool> matrMultiply(QVector<bool> sLayout);//special perceptron operation not ordinary multiply
    bool vectorMultiply(QVector<bool> pLayout);
    QVector<bool> convertToBools(QVector<double> ys);//y coords
    void initWeightMatrix();

    int layoutSize;


};

#endif // PERCEPTRON_H
