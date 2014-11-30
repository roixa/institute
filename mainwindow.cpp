#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    fillApproxIntervalsOnSpinboxes();

    //drawPlot();


}

void MainWindow::drawPlot(){


    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData(fileName);
    QCustomPlot *customPlot=ui->widget;
    QVector<double> x, y;
    for (int i=0; i<experimentalPoints.size(); i++)
    {
      QPointF p=experimentalPoints[i];
      x.append(p.y());
      y.append(p.x());
    }
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(652, 657);
    customPlot->yAxis->setRange(0, 300);
    customPlot->replot();
}

void MainWindow::drawAppox(){
    QCustomPlot *customPlot=ui->widget;

    customPlot->clearItems();
    drawPlot();
    readApproxIntervalsFromSpinboxes();
    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData();
    QVector<GaussFunc> funcs=mainManager.buildGaussApprox();
    showConsist(funcs);
    for (int i=0; i<funcs.size(); i++)
    {
        GaussFunc func=funcs[i];
        QVector<double> x, y;
        for (int i=0; i<experimentalPoints.size(); i++)
        {
            QPointF p=experimentalPoints[i];
            x.append(p.y());
            y.append(func.valueOf(p.y()));
        }
        customPlot->addGraph();
        customPlot->graph(i+1)->setData(x, y);

    }



    customPlot->replot();
}

void MainWindow::fillApproxIntervalsOnSpinboxes(){
    mainManager.filApproIntervals();
    QVector <QPointF> intervals=mainManager.approxIntervals;
    if(intervals.size()!=4)return;
    ui->doubleSpinBox->setValue(intervals[0].x());
    ui->doubleSpinBox_2->setValue(intervals[0].y());
    ui->doubleSpinBox_3->setValue(intervals[1].x());
    ui->doubleSpinBox_4->setValue(intervals[1].y());
    ui->doubleSpinBox_5->setValue(intervals[2].x());
    ui->doubleSpinBox_6->setValue(intervals[3].y());
    ui->doubleSpinBox_7->setValue(intervals[3].x());
    ui->doubleSpinBox_8->setValue(intervals[3].y());
}

void MainWindow::readApproxIntervalsFromSpinboxes(){
    QVector <QPointF> intervals;
    double x,y;
    x=ui->doubleSpinBox->value();
    y=ui->doubleSpinBox_2->value();
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_3->value();
    y=ui->doubleSpinBox_4->value();
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_5->value();
    y=ui->doubleSpinBox_6->value();
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_7->value();
    y=ui->doubleSpinBox_8->value();
    intervals.append(QPointF(x,y));
    mainManager.approxIntervals=intervals;
}

void MainWindow::showConsist(QVector<GaussFunc> funcs){
    double energy=ui->energyLineEdit->text().toDouble();
    bool isWithMagnet=ui->radioButton->isChecked();
    QVector<double>consist=mainManager.calc.makeConsistInPercent(funcs,energy,0,isWithMagnet);
    QString text="E="+QString::number(consist[0])+" E/2="+QString::number(consist[1])
            +" E/3="+QString::number(consist[2])+" E/8="+QString::number(consist[3]);
    ui->label_6->setText(text);
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_loadFileButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("DATA (*)"));
       QFile file(fileName);
       if (!file.open(QIODevice::ReadOnly)) {

           return;
       }
       drawPlot();

}

void MainWindow::on_buildButton_clicked()
{
    drawAppox();
}
