#include <QtGui>
#include <QTranslator>
#include "mainwindow.h"

MainWindow::MainWindow() {
  setWindowTitle("XControl");
  createStatusBar();
  transMatrix = new TransMatrix;
  this->setCentralWidget(transMatrix);
}

void MainWindow::createStatusBar() {
  QLabel *newLabel = new QLabel(tr("Ready"));
  statusBar()->addWidget(newLabel, 0);
}
