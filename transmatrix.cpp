#include <QtGui>
#include "transmatrix.h"

TransMatrix::TransMatrix(QWidget* parent) : QWidget(parent){
  tableWidget = new QTableWidget(this);

  tableWidget->setColumnCount(NX);
  tableWidget->setRowCount(NY);

  QStringList columnHeaders;
  columnHeaders << tr("LeftRight") << tr("ForwBack") 
                << tr("Thrust") << tr("Spin");
  tableWidget->setHorizontalHeaderLabels(columnHeaders);

  QStringList rowHeaders;
  rowHeaders << tr("L Aileron") << tr("R Aileron")
             << tr("Propeller") << tr("Altitute");
  tableWidget->setVerticalHeaderLabels(rowHeaders);

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addWidget(tableWidget);
  mainLayout->setMargin(0);
  setLayout(mainLayout);
}

void TransMatrix::show(int **array) {
  for (int row = 0; row < NY; ++row)
    for (int col = 0; col < NX; ++col){
      QTableWidgetItem *item = 
        new QTableWidgetItem(QString::number(array[row][col]));
      tableWidget->setItem(row, col, item);
    }
  tableWidget->resizeColumnsToContents();
  tableWidget->resizeRowsToContents();
}
