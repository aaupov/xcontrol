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

  QMenu *helpMenu = menuBar()->addMenu(tr("About"));
  helpMenu->addAction(aboutAct);
}

void MainWindow::createActions() {
  exitAct = new QAction(tr("Exit"), this);
  exitAct->setShortcut(tr("Ctrl+Q"));
  connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit())); 

  aboutAct = new QAction(tr("&About"), this);
  connect(aboutAct, SIGNAL(triggered()), SLOT(about()));
}

void MainWindow::about() {
  QMessageBox::about(this, tr("About XControl"),
      tr("<p align='center'><b>XControl</b> program<br>"
        "Kobtsev Vitaly, Kashin Dmitry, Khvostov Artem, Aupov Amir, et al.<br>"
        "Special thanks to Ledovskiy Alexey<br>"
        "DAFE MIPT 2011-2012</p>"));
}
