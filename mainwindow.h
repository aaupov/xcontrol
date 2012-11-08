#pragma once
#include <QtCore>
#include <QtGui>
#include "transmatrix.h"

class TransMatrix;
//class InfoView;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow();
private:
  TransMatrix *transMatrix;
  void createStatusBar();
  QTranslator translator;
};
