#include <iostream>
#include <string>

const int specializations = 20;
const int queueSize = 5;

int hospitalQueue[specializations][queueSize]{3};
std::string namesOfPatient[specializations][queueSize]{""};

void displayMenu(){
  std::cout << "Enter your choice:" << "\n";
  std::cout << "1) Add new patient" << "\n";
  std::cout << "2) Print all patient" << "\n";
  std::cout << "3) Get next patients" << "\n";
  std::cout << "4) Exit" << "\n";
}

bool checkIfQueueFull(int specialization){
  int targetSpecialization[queueSize];
  for(int i = 0; i < queueSize; i++){
    targetSpecialization[i] = hospitalQueue[specialization][i];
  }

  for(int patient : targetSpecialization){
    std::cout << patient;
    if(patient == 3){
      return true;
    }
  }
  return false;

}

void addPatient(){
  std::cout << "Enter Specialization, name, status: " <<"\n"; 
  int specialization{};
  int status{};
  std::string name{};
  std::cin >> specialization >> name >> status;
  std::cout << specialization << " " << name << " " << status << "\n";
  if(checkIfQueueFull(specialization)){
    std::cout << "Sorry the queue is full right now. Not accepting new patients" << "\n";
    return;
  }
  if(status == 1){
    //shift all elements right
    hospitalQueue[specialization][0] = 1;
  }
  else{
    // shift all elements left
  }


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
  int choice{};
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
