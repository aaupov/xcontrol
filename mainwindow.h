#pragma once
#include <QtCore>
#include <QtGui>
#include "xcontrol.h"
#include "transmatrix.h"
#include "infoview.h"

class TransMatrix;
class InfoView;

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  MainWindow();
private:
  void createTabWidget();
  void createStatusBar();
  void getParameters();
  QTranslator translator;
  QTabWidget *tabWidget;
};
