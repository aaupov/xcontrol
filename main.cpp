#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]){
  QApplication app(argc, argv);

  qApp->setApplicationName("XControl");
  QApplication::setApplicationVersion("0.0");
  qApp->setOrganizationName("DAFE MIPT");

  MainWindow window;
  window.show();
  return app.exec();
}
