#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pagebutton.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    fillApproxIntervalsOnSpinboxes();

    //drawPlot();


}

void MainWindow::drawPlot(){


    QVector<QPointF> experimentalPoints=mainManager.getExperimentalData();
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
    double e=ui->energyLineEdit->text().toDouble();
    mainManager.refreshPage(e);
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

void MainWindow::drawPageButton(){
    int i=mainManager.navigator.getPageCount();
    //mainManager.createNewPage();
    double e=ui->energyLineEdit->text().toDouble();

    PageButton *newButton=new PageButton(QString::number(e)+" keV "+QString::number(i+1));
    newButton->setMinimumWidth(40);
    newButton->setMaximumWidth(60);
    newButton->page=i-1;
    newButton->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    int &u=i;
    connect(newButton, SIGNAL(clicked()),
         newButton, SLOT (onClicked()));
    connect(newButton, SIGNAL(onClick(int&)),
         this, SLOT (sendedPageButton(int &)));

    ui->pagesLayout->addWidget(newButton);
}

void MainWindow::fillApproxIntervalsOnSpinboxes(){
    mainManager.filApproIntervals();
    QVector <QPointF> intervals=mainManager.approxIntervals;
    if(intervals.size()!=4)return;
    ui->doubleSpinBox->setValue(intervals[0].x()*100);
    ui->doubleSpinBox_2->setValue(intervals[0].y()*100);
    ui->doubleSpinBox_3->setValue(intervals[1].x()*100);
    ui->doubleSpinBox_4->setValue(intervals[1].y()*100);
    ui->doubleSpinBox_5->setValue(intervals[2].x()*100);
    ui->doubleSpinBox_6->setValue(intervals[3].y()*100);
    ui->doubleSpinBox_7->setValue(intervals[3].x()*100);
    ui->doubleSpinBox_8->setValue(intervals[3].y()*100);
}

void MainWindow::readApproxIntervalsFromSpinboxes(){
    QVector <QPointF> intervals;
    double x,y;
    x=ui->doubleSpinBox->value()/100;
    y=ui->doubleSpinBox_2->value()/100;
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_3->value()/100;
    y=ui->doubleSpinBox_4->value()/100;
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_5->value()/100;
    y=ui->doubleSpinBox_6->value()/100;
    intervals.append(QPointF(x,y));

    x=ui->doubleSpinBox_7->value()/100;
    y=ui->doubleSpinBox_8->value()/100;
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
    QString fileN = QFileDialog::getOpenFileName(this, tr("Open File"),"/home",tr("DATA (*)"));
       QFile file(fileN);
       if (!file.open(QIODevice::ReadOnly)) {

           return;
       }
       double energy=ui->energyLineEdit->text().toDouble();
       mainManager.getExperimentalData(fileN);
       mainManager.createNewPage(energy);
       drawPlot();
       drawPageButton();

}


void MainWindow::on_buildButton_clicked()
{
    drawAppox();

}

void MainWindow::pageButtonListener(){

    //mainManager.setPage(u);
    //drawPlot();
    drawAppox();
}
void MainWindow::sendedPageButton(int &i){

    mainManager.setPage(i);

    drawAppox();
}
