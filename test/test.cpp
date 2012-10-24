#include <iostream>
#include "SDL.h"

#ifdef _WIN32
  #include <windows.h> \
  #define __sleep(n) Sleep(1000*n)
#elif __linux__
  #include <unistd.h> \
  #define __sleep(n) sleep(n)
#endif

#define fi(i,a,b) for (int i=a; i<b; ++i)

using namespace std;

int main(){
  SDL_Joystick *joystick;
  if (SDL_Init(SDL_INIT_JOYSTICK) == -1){
    std::cerr << SDL_GetError() << std::endl;
    return 2;
  }
  if (SDL_NumJoysticks() == 0){
    std::cerr << "No joysticks found\n";
    return 1;
  }
  cout << "Using joystick " << SDL_JoystickName(0) << endl;
  joystick = SDL_JoystickOpen(0);

  cout << "Num axes: " << SDL_JoystickNumAxes(joystick) << endl;
  cout << "Num buttons: " << SDL_JoystickNumButtons(joystick) << endl;
  cout << "Num trackballs: " << SDL_JoystickNumBalls(joystick) << endl;
  cout << "Num hats: " << SDL_JoystickNumHats(joystick) << endl;

  while (1){
    SDL_JoystickUpdate();
    cout << "Buttons\n";
    fi(i,0,6) cout << (int)SDL_JoystickGetButton(joystick, i) << " ";
    cout << endl;

    cout << "Axis\n";
    fi(i,0,6) cout << SDL_JoystickGetAxis(joystick, i) << " ";
    cout << endl;
    __sleep(1);
  }

  SDL_Quit();
  return 0;
}
