#include "datamanager.h"

DataManager::DataManager()
{
}

QVector<QPointF> DataManager::getExperimentalData(){
    if(experimentalData.size()==0){
       experimentalData=
               parser.parseFile("/home/bsr/build-InstituteTask-Desktop_Qt_5_3_GCC_64bit-Debug/14kv25A3.Master.Scope");
    }
    return experimentalData;
}

QVector<GaussFunc> DataManager::buildGaussApprox(){
    filApproIntervals();
    QVector<GaussFunc>ret;
    for(int i=0;i<approxIntervals.size();i++){
        QPointF interval=approxIntervals[i];
        QPointF max=maxValue(interval);
        qDebug()<<max.x();
        GaussFunc add=GaussFunc(max.x(),max.y());
        ret.append(add);
    }
    return ret;
}

void DataManager::filApproIntervals(){
    approxIntervals.append(QPoint(654.4,655.2));
    approxIntervals.append(QPoint(652.6,654));
    approxIntervals.append(QPoint(655.2,656));
    //approxIntervals.append(QPoint(656,656.8));
    approxIntervals.append(QPoint(656,659));
}

QPointF DataManager::maxValue(QPointF interval){
    QPointF max=QPointF(0,0);
    for (int i=0;i<experimentalData.size();i++){
        QPointF p=experimentalData[i];
        if(p.x()>max.x()&&p.y()>interval.x()&&p.y()<interval.y()){
            max=p;
        }
    }
    return max;
}

QVector<double> DataManager::experimentalDataFromInterval(QPointF interval){
    QVector<double> ret;
    for(int i=0;i<experimentalData.size();i++){
        QPointF p=experimentalData[i];
        if(p.x()>interval.x()&&p.x()<interval.y())
            ret.append(p.x());
    }
    return ret;
}
