#include <iostream>


void displayMenu(){
  std::cout << "Enter your choice:" << "\n";
  std::cout << "1) Add new patient" << "\n";
  std::cout << "2) Print all patient" << "\n";
  std::cout << "3) Get next patients" << "\n";
  std::cout << "4) Exit" << "\n";
}



int main() {

  while(1){
  displayMenu();
  int choice;
  std::cin >> choice;
  }

  return 0;
}
