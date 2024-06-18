#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* p):
  QMainWindow(p)
  ,ui(new Ui::MainWindow)
  ,mPlot(0)
  ,mtag1(0)
  ,mtag2(0){
  ui->setupUi(this);
  mPlot = new QCustomPlot(this);
  setCentralWidget(mPlot);
  mPlot->yAxis->setTickLabels(false);
  connect(mPlot->yAxis2,SIGNAL(rangeChanged(QCPRange)),mPlot->yAxis,SLOT(setRange(QCPRange)));
  mPlot->yAxis2->setVisible(true);
  mPlot->axisRect()->addAxis(QCPAxis::atRight);
  mPlot->axisRect()->axis(QCPAxis::atRight,0)->setPadding(30);
  mPlot->axisRect()->axis(QCPAxis::atRight,1)->setPadding(30);

  mGraph1 = mPlot->addGraph(mPlot->xAxis,mPlot->axisRect()->axis(QCPAxis::atRight,0));
  mGraph2 = mPlot->addGraph(mPlot->xAxis,mPlot->axisRect()->axis(QCPAxis::atRight,1));
  mGraph1->setPen(QPen(QColor(250,120,0)));
  mGraph2->setPen(QPen(QColor(0,180,60)));

  mtag1 = new axis_tag(mGraph1->valueAxis()); mtag1->setPen(mGraph1->pen());
  mtag2 = new axis_tag(mGraph2->valueAxis()); mtag2->setPen(mGraph2->pen());
  connect(&mtimer,SIGNAL(timeout()),this,SLOT(timerSlot()));
  mtimer.start(40);
}

MainWindow::~MainWindow(){ delete ui; }

void MainWindow::timerSlot(){
  mGraph1->addData(mGraph1->dataCount(),
      qSin(mGraph1->dataCount()/50.0)+qSin(mGraph1->dataCount()/50.0/0.3843)*0.25);
  mGraph2->addData(mGraph2->dataCount(),
      qCos(mGraph2->dataCount()/50.0)+qSin(mGraph2->dataCount()/50.0/0.4364)*0.15);

  mPlot->xAxis->rescale();
  mGraph1->rescaleValueAxis(false,true);
  mGraph2->rescaleValueAxis(false,true);
  mPlot->xAxis->setRange(mPlot->xAxis->range().upper,100,Qt::AlignRight);

  double g1v = mGraph1->dataMainValue(mGraph1->dataCount()-1);
  double g2v = mGraph2->dataMainValue(mGraph2->dataCount()-1);
  mtag1->updatePosition(g1v);
  mtag2->updatePosition(g2v);
  mtag1->setText(QString::number(g1v,'f',2));
  mtag2->setText(QString::number(g2v,'f',2));
  mPlot->replot();
}
