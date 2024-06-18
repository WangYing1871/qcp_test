
#include <QApplication>
//#include <QDataTime.h>
#include <QTime>
#include <QDateTime>
#include <QFont>

#include "MainWindow.h"
#include "qcustomplot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Q_INIT_RESOURCE(dockwidgets);
    //MainWindow mainWin;
    //mainWin.show();
    auto* widgets = new QWidget();
    auto* pp = new QCustomPlot(widgets);
    /*
    pp->addGraph();
    pp->graph(0)->setPen(QPen(Qt::blue));
    pp->graph(0)->setBrush(QBrush(QColor(0,0,255,20)));
    pp->addGraph();
    pp->graph(1)->setPen(QPen(Qt::red));
    QVector<double> x(251), y0(251), y1(251);
    for (int i=0; i<251; ++i){
      x[i] = i;
      y0[i] = qExp(-i/150.)*qCos(i/10.0);
      y1[i] = qExp(-i/150.);
    }

    pp->xAxis2->setVisible(true);
    pp->xAxis2->setTickLabels(false);
    pp->yAxis2->setVisible(true);
    pp->yAxis2->setTickLabels(false);
    QObject::connect(pp->xAxis,SIGNAL(rangeChanged(QCPRange)),pp->xAxis2,SLOT(setRange(QCPRange)));
    QObject::connect(pp->yAxis,SIGNAL(rangeChanged(QCPRange)),pp->yAxis2,SLOT(setRange(QCPRange)));
    pp->graph(0)->setData(x,y0);
    pp->graph(1)->setData(x,y1);
    pp->graph(0)->rescaleAxes();
    pp->graph(0)->rescaleAxes(true);
    pp->setInteractions(
        QCP::iRangeDrag
        | QCP::iRangeZoom
        | QCP::iSelectPlottables);
    */
    /*
    widgets->resize(1000,600);
    pp->resize(1000,600);
   // pp->show();

    pp->setLocale(QLocale(QLocale::English,QLocale::UnitedKingdom));
    double now = QDateTime::currentDateTime().toTime_t();
    srand(8);
    for (int i=0; i<5; ++i){
      pp->addGraph();
      QColor color(20+200/4.0*i,70*(1.6-i/4.0),150,150);
      pp->graph()->setLineStyle(QCPGraph::lsLine);
      pp->graph()->setPen(QPen(color.lighter(200)));
      pp->graph()->setBrush(QBrush(color));
      QVector<QCPGraphData> timeData(250);
      for (int j=0; j<250; ++j){
        timeData[j].key = now+24*3600*j;
        if (j==0) timeData[i].value = (i/50.0+1)*(rand()/(double)RAND_MAX-0.5);
        else timeData[j].value = qFabs(timeData[j-1].value)*(1+0.02/4.0*(4-i))+
            (j/50.+1)*(rand()/(double)RAND_MAX-0.5);
      }
      pp->graph()->data()->set(timeData);
    }
    QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
    dateTicker->setDateTimeFormat("d. MMM\nyyyy");
    pp->xAxis->setTicker(dateTicker);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTick(10,"a bit\nlow");
    textTicker->addTick(50,"quite\nhigh");
    pp->yAxis->setTicker(textTicker);

    pp->xAxis->setTickLabelFont(QFont(QFont().family(),8));
    pp->yAxis->setTickLabelFont(QFont(QFont().family(),8));

    pp->xAxis->setLabel("X");
    pp->yAxis->setLabel("Y");

    pp->xAxis->setRange(now,now+24*3600*249);
    pp->yAxis->setRange(0,60);

    pp->legend->setVisible(true);
    pp->legend->setBrush(QColor(255,255,255,150));




    widgets->show();
    */

    MainWindow mw;
    mw.show();



    return app.exec();
}
