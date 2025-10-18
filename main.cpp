#include <iostream>


void displayMenu(){
  std::cout << "Enter your choice:" << "\n";
  std::cout << "1) Add new patient" << "\n";
  std::cout << "2) Print all patient" << "\n";
  std::cout << "3) Get next patients" << "\n";
  std::cout << "4) Exit" << "\n";
}

void addPatient(){
  std::cout << "adding patient" <<"\n"; 

}

void printAllPatients(){
  std::cout << "printing all patients" << "\n";

}

void getNextPatient(){
  std::cout << "getting next patient" << "\n";

}



int main() {

  bool exitProgram = true;
  while(exitProgram){
  displayMenu();
  int choice;
  std::cin >> choice;

  switch(choice){
    case 1:
      addPatient();
      break;
    case 2:
      printAllPatients();
      break;
    case 3:
      getNextPatient();
      break;
    default:
      exitProgram = false;
      break;
  }
  }

  return 0;
}
