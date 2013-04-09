#include <QApplication>

//#include "mainwindow.h"
#include "interface.h"

int main(int argc, char* argv[]){
  QApplication app(argc, argv);

  //QMainWindow *window = new QMainWindow;
  //QWidget *window = new QWidget;

  //Interface::Interface gui( window);
  Interface ui;
  ui.show();

  /*
  qApp->setApplicationName("XControl");
  QApplication::setApplicationVersion("0.0");
  qApp->setOrganizationName("DAFE MIPT");
  */

  //window->show();
  return app.exec();
}
