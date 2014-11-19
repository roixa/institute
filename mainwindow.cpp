#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData();




    drawPlot();


}

void MainWindow::drawPlot(){
    QCustomPlot *customPlot=ui->widget;
    QVector<double> x, y;
    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData();
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
    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData();
    QVector<GaussFunc> funcs=mainManager.buildGaussApprox();
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



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    drawAppox();
}
