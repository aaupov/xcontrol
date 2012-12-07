/*
 * Thread-safe qjoystick singleton
 */
#pragma once

#include <QtCore>
#include <SDL/SDL.h>
#include <QMutex>

class QJoystick : public QObject {
  Q_OBJECT

public:
    /* singleton methods */
  static QJoystick* instance() {
    static QMutex mutex;
    if (!m_instance){
      mutex.lock();

      if (!m_instance)
        m_instance = new QJoystick;

      mutex.unlock();
    }

    return m_instance;
  }

  static void drop() {
    static QMutex mutex;
    mutex.lock();
    delete m_instance;
    m_instance = 0;
    mutex.unlock();
  }

  /* own methods */

  int availableJoysticks();
  int currentJoystick();
  QString joystickName(int id);
  int joystickNumAxes(int id);
  int joystickNumButtons(int id);
  QList<int> axis;
  QList<bool> buttons;
  void getdata();

public slots:
  void setJoystick(int jsNumber);

private:
  QJoystick(QWidget *parent = 0);
  ~QJoystick();
  QJoystick(const QJoystick &); //hide copy constr
  QJoystick& operator= (const QJoystick &); //hide assign
  static QJoystick* m_instance;

  SDL_Joystick* m_joystick;
};

