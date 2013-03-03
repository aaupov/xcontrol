#include <QtGui>
#include <QDebug>
#include "joytab.h"

TransMatrix::TransMatrix(QWidget* parent) : QWidget(parent){
  QJoystick *j = QJoystick::instance();
  TransMatrix::NX = j->joystickNumAxes( j->currentJoystick( ));

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

  QHBoxLayout *buttons = new QHBoxLayout;
  QPushButton *loadButton = new QPushButton(tr("Load"));
  QPushButton *saveButton = new QPushButton(tr("Save"));
  loadButton->setToolTip(tr("Load transformation matrix from file"));
  saveButton->setToolTip(tr("Save current matrix to file"));
  loadButton->setMaximumWidth(100);
  saveButton->setMaximumWidth(100);
  connect(loadButton, SIGNAL(clicked()), SLOT(loadMatrix()));
  connect(saveButton, SIGNAL(clicked()), SLOT(saveMatrix()));
  buttons->addWidget(loadButton);
  buttons->addWidget(saveButton);

  show(QVector<int>(NX*NY,0));

  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(buttons);
  mainLayout->addWidget(tableWidget);
  setLayout(mainLayout);
}

void TransMatrix::show(QVector<int> array) {
  for (int row = 0; row < NY; ++row)
    for (int col = 0; col < NX; ++col){
      QTableWidgetItem *item = 
        new QTableWidgetItem(QString::number(array[row*NX+col]));
      tableWidget->setItem(row, col, item);
    }
  tableWidget->resizeColumnsToContents();
  tableWidget->resizeRowsToContents();
}

void TransMatrix::loadMatrix() {
  QString fileName = QFileDialog::getOpenFileName(this);
  if (!fileName.isEmpty()){
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
      QMessageBox::warning(this, "XControl", 
          tr("File open error: %1").arg(file.errorString()));
      return;
    }
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QTextStream in(&file);
    QVector<int> array;
    QString line;
    while (!(line = in.readLine()).isEmpty()){
      QStringList nums = line.simplified().split(" "); //trim all extra whitespaces
      foreach(QString str, nums)
        array.push_back(str.toInt());
    }
    file.close();
    if (array.size() != NX*NY){
      QMessageBox::warning(this, tr("XControl"), 
          tr("Invalid dimensions: NX*NY=%1 size=%2").arg(NX*NY).arg(array.size()), 
          QMessageBox::Ok);
      array = QVector<int>(NX*NY,0);
    } 
    show(array);

    QApplication::restoreOverrideCursor();
  }
}

void TransMatrix::saveMatrix() {
  QString fileName = QFileDialog::getSaveFileName(this);
  QFile file(fileName);
  if (!fileName.isEmpty()){
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
      QMessageBox::warning(this, "XControl", 
          tr("File open error: %1").arg(file.errorString()));
      return;
    }
    QTextStream out(&file);
    for (int row = 0; row < NY; ++row) {
      for (int col = 0; col < NX; ++col)
        out << tableWidget->item(row, col)->text() << " ";
      out << QString("\n");
    }
    file.close();
  }
}

JoystickTab::JoystickTab(QWidget* parent) : QWidget(parent){
  joystick = QJoystick::instance();

  QVBoxLayout *mainLayout = new QVBoxLayout;
//mainLayout->
}
