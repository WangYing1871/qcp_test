#include "QMainWindow"

#include "qcustomplot.h"

#include "axis_tag.h"

namespace Ui{
class MainWindow;
}

class MainWindow :public QMainWindow{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent=0);
  ~MainWindow();

private slots:
  void timerSlot();

private:
  Ui::MainWindow* ui;
  QCustomPlot* mPlot;
  QPointer<QCPGraph> mGraph1;
  QPointer<QCPGraph> mGraph2;
  axis_tag* mtag1,* mtag2;
  QTimer mtimer;
};
