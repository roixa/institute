#include "datamanager.h"

DataManager::DataManager()
{
}

QVector<QPointF> DataManager::getExperimentalData(){
    if(experimentalData.size()==0){
       experimentalData=
               parser.parseFile("ll");
    }
    return experimentalData;
}

QVector<QPointF> DataManager::getExperimentalData(QString file){

       experimentalData=
               parser.parseFile(file);

    return experimentalData;
}

QVector<GaussFunc> DataManager::buildGaussApprox(){
    //filApproIntervals();
    QVector<GaussFunc>ret;
    for(int i=0;i<approxIntervals.size();i++){
        QPointF interval=approxIntervals[i];
        QPointF max=maxValue(interval);


        QVector<QPointF> expirementalValues=experimentalDataFromInterval(interval);

        GaussFunc add=varyApprox(expirementalValues,70,QPointF(0,1));


        ret.append(add);
    }
    calc.makeConsistInPercent(ret,16,0,true);

    return ret;
}

void DataManager::filApproIntervals(){
    approxIntervals.append(QPoint(654.4,655.2));
    approxIntervals.append(QPoint(652.6,654));
    approxIntervals.append(QPoint(655.2,656));
    //approxIntervals.append(QPoint(656,656.8));
    approxIntervals.append(QPoint(656,659));
}

GaussFunc DataManager::varyApprox(QVector<QPointF> expimental, int count, QPointF varyInterval){
    double start=varyInterval.x();
    double end=varyInterval.y();
    double step=(end-start)/count;
    qDebug()<<"varyApprox: size"<<expimental.size();
    QPointF varIntegrAndParam=QPointF(10000,0);
    double expirementIntegr=integrieren(expimental);
    for(double param=start;param<end;param+=step){
        double testTeorIntegr=integrieren(buildTeoriticalDataGaussFunc(expimental,param));
        double deltaTeorIntegr=testTeorIntegr-expirementIntegr;
        double min=varIntegrAndParam.x()-expirementIntegr;
        int signd=deltaTeorIntegr>0?1:-1;
        int signm=min>0?1:-1;
        if(min*signm>deltaTeorIntegr*signd){
            varIntegrAndParam=QPointF(testTeorIntegr,param);

        }
        //

    }
    qDebug()<<"varyApprox: "<<varIntegrAndParam.y();
    return buildGaussFuncFromDataAndParams(expimental,varIntegrAndParam.y());
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

double DataManager::integrieren(QVector<QPointF> func){
    double ret=0;
    for (int i=0;i<func.size();i++){
        ret+=func[i].x();
    }
    return ret;
}


QVector<QPointF> DataManager::experimentalDataFromInterval(QPointF interval){
    QVector<QPointF> ret;
    for(int i=0;i<experimentalData.size();i++){
        QPointF p=experimentalData[i];
        if(p.y()>interval.x()&&p.y()<interval.y())
            ret.append(p);
    }
    return ret;
}

GaussFunc DataManager::buildGaussFuncFromDataAndParams(QVector<QPointF> expimental, double param){
    double x=0;
    double y=0;
    for(int i=0;i<expimental.size();i++){
        if(expimental[i].x()>x){
            x=expimental[i].x();
            y=expimental[i].y();
        }

    }
    //qDebug()<<"buildGaussFuncFromDataAndParams"<<expimental.size();
    return GaussFunc(x,y,param);
}

QVector <QPointF> DataManager::buildTeoriticalDataGaussFunc(QVector<QPointF> expimental, double param){
    GaussFunc teorFunc=buildGaussFuncFromDataAndParams(expimental,param);
    QVector <QPointF> ret;
    for(int i=0;i<expimental.size();i++){
        double y=expimental[i].y();
        double x=teorFunc.valueOf(y);
        ret.append(QPointF(x,y));
    }
    return ret;

}
