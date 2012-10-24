#include <iostream>

int main(){
#ifdef _WIN32 
  std::cout << "Windows\n";
#elif __linux__
  std::cout << "Linux\n";
#endif
  return 0;
}
