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
  void createMenus();
  void createActions();
  void getParameters();
  QTranslator translator;
  QTabWidget *tabWidget;
  QAction *exitAct, *aboutAct;
private slots:
  void about();
};
