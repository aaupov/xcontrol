#pragma once

#include <QWidget>
#include "xcontrol.h"
#include "qjoystick.h"

class QTableWidget;

class TransMatrix : public QWidget {
  Q_OBJECT
  int NX;
public:
  TransMatrix(QWidget* parent = 0);
  QTableWidget *tableWidget;
private slots:
  void show(QVector<int> array);
public slots:
  void loadMatrix();
  void saveMatrix();
};

class JoystickTab : public QWidget {
  Q_OBJECT
  QJoystick* joystick;
public:
  JoystickTab(QWidget* parent = 0);
};

/*class JoystickSelection : public QWidget {
  Q_OBJECT
public:
  JoystickSelection(QWidget* parent = 0);

  // per-joystick data
  struct joyData {
    int axes, buttons;
    QList<int> axis;
    QList<bool> button;
  };
  
  int available, current; //total number and dynamically set current
  QList<joyData*> joystick;
};
*/
