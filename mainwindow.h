#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datamanager.h"
#include "qcustomplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
signals:
    void sendParam(int &i);

public slots:
    void pageButtonListener();
    void sendedPageButton(int &i);
private slots:
    void on_pushButton_clicked();

    void on_loadFileButton_clicked();

    void on_buildButton_clicked();



private:
    QString fileName;
    void drawPlot();
    void drawAppox();
    void drawPageButton();
    void fillApproxIntervalsOnSpinboxes();
    void readApproxIntervalsFromSpinboxes();
    void showConsist(QVector<GaussFunc> funcs);

    DataManager mainManager;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
