#pragma once
#include <QtCore>
#include <QtGui>
#include "transmatrix.h"
#include "xcontrol.h"

class TransMatrix;
class InfoView;

class MainWindow : public QMainWindow {
  Q_OBJECT
  public:
    MainWindow();
  private:
    QTranslator translator;

};
