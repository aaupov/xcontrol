#include <QtGui>
#include <QTranslator>
#include "mainwindow.h"

MainWindow::MainWindow() {
  setWindowTitle("XControl");
  createTabWidget();
  createStatusBar();
}

void MainWindow::createStatusBar() {
  QLabel *newLabel = new QLabel(tr("Ready"));
  statusBar()->addWidget(newLabel, 0);
}

void MainWindow::createTabWidget() {
  tabWidget = new QTabWidget;
  tabWidget->addTab(new InfoView, tr("Info"));
  tabWidget->addTab(new TransMatrix, tr("Matrix"));
  this->setCentralWidget(tabWidget);
}

void MainWindow::getParameters(){
  //stub
}
