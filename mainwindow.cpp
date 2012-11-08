#include <QtGui>
#include <QTranslator>
#include "mainwindow.h"

MainWindow::MainWindow() {
  setWindowTitle("XControl");
  createActions();
  createMenus();
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

void MainWindow::createMenus() {
  QMenu *fileMenu = menuBar()->addMenu(tr("File"));
  fileMenu->addAction(exitAct);
}

void MainWindow::createActions() {
  exitAct = new QAction(tr("Exit"), this);
  exitAct->setShortcut(tr("Ctrl+Q"));
  connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit())); 
}
