#pragma once

#include <QWidget>
#include "xcontrol.h"
#include "mainwindow.h"

class QTableWidget;

class TransMatrix : public QWidget {
  Q_OBJECT
public:
  TransMatrix(QWidget* parent = 0);
  QTableWidget *tableWidget;
private slots:
  void show(int *array);
public slots:
  void loadMatrix();
  void saveMatrix();
};
