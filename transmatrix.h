#pragma once

#include <QWidget>
#include "xcontrol.h"

class QTableWidget;

class TransMatrix : public QWidget {
  Q_OBJECT
  public:
    TransMatrix(QWidget* parent);
    QTableWidget *tableWidget;
  private slots:
    void show(int **array);
};
