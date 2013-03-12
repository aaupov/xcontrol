#include "qjoystick.h"
#include <QDebug>
#include <QMessageBox>

QJoystick* QJoystick::m_instance = 0;

QJoystick::QJoystick(QWidget *parent){
  if (SDL_Init(SDL_INIT_JOYSTICK) == -1){
    QMessageBox::critical(parent, tr("XControl"), tr("SDL Init error"), 
        QMessageBox::Close);
  }
  if (SDL_NumJoysticks() == 0){
    QMessageBox::critical(parent, tr("XControl"), tr("No joysticks found"),
        QMessageBox::Close);
  }
  m_joystick = 0;
  setJoystick(0);
}

int QJoystick::availableJoysticks(){
  //return 1;
  return SDL_NumJoysticks();
}

int QJoystick::currentJoystick(){
  return SDL_JoystickIndex(m_joystick);
}

QString QJoystick::joystickName(int js){
  Q_ASSERT(js < availableJoysticks());
  Q_ASSERT(js >= 0);
  return QString(SDL_JoystickName(js));
}

int QJoystick::joystickNumAxes(int js){
  Q_ASSERT(js < availableJoysticks());
  Q_ASSERT(js >= 0);
  return (SDL_JoystickNumAxes(m_joystick));
}

int QJoystick::joystickNumButtons(int js){
  Q_ASSERT(js < availableJoysticks());
  Q_ASSERT(js >= 0);
  return (SDL_JoystickNumButtons(m_joystick));
}

void QJoystick::setJoystick(int js){
  Q_ASSERT(js < availableJoysticks());
  Q_ASSERT(js >= 0);

  if (m_joystick) SDL_JoystickClose(m_joystick);
  m_joystick = SDL_JoystickOpen(js);
}

QJoystick::~QJoystick(){
  axis.clear();
  buttons.clear();
  SDL_JoystickClose(m_joystick);
  SDL_QuitSubSystem(SDL_INIT_JOYSTICK);
  this->deleteLater();
}

void QJoystick::getdata(){
  axis.clear();
  buttons.clear();

  SDL_Event event;
  SDL_PollEvent(&event);

  for (int i = 0; i < SDL_JoystickNumAxes(m_joystick); ++i){
    axis.append(SDL_JoystickGetAxis(m_joystick, i));
  }

  for (int i = 0; i < SDL_JoystickNumButtons(m_joystick); ++i){
    buttons.append(SDL_JoystickGetButton(m_joystick, i));
  }
}
