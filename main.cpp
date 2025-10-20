#include <iostream>
#include <string>

const int specializations = 20;
const int queueSize = 5;

int hospitalQueue[specializations][queueSize]{};
std::string namesOfPatient[specializations][queueSize];

void displayMenu(){
  std::cout << "Enter your choice:" << "\n";
  std::cout << "1) Add new patient" << "\n";
  std::cout << "2) Print all patient" << "\n";
  std::cout << "3) Get next patients" << "\n";
  std::cout << "4) Exit" << "\n";
  std::cout << "5) Print current queue" << "\n";
}

bool checkIfQueueFull(int specialization){
  int targetSpecialization[queueSize];
  for(int i = 0; i < queueSize; i++){
    targetSpecialization[i] = hospitalQueue[specialization][i];
  }

  for(int patient : targetSpecialization){
    if(patient == 3){
      return false;
    }
  }
  return true;
}

void initializeHospitalSystem() {
  for(int i = 0; i < specializations; i++){
    for(int j = 0; j < queueSize; j++){
      hospitalQueue[i][j] = 3;
    }
  }
}

void addPatient(){
  std::cout << "Enter Specialization, name, status: " <<"\n"; 
  int specialization{};
  int status{};
  std::string name{};
  std::cin >> specialization >> name >> status;
  int start = 0;
  int end = queueSize - 1;
  if(checkIfQueueFull(specialization)){
    std::cout << "Sorry the queue is full right now. Not accepting new patients" << "\n";
    return;
  }
  if(status == 1){
    while(hospitalQueue[specialization][start] != 3){
      start++;
    }
    if(start > 0){
     for(int i = start; i > 0; i--){
        hospitalQueue[specialization][i] = hospitalQueue[specialization][i - 1];
        namesOfPatient[specialization][i] = namesOfPatient[specialization][i -1];
      }
    }
    hospitalQueue[specialization][0] = status;
    namesOfPatient[specialization][0] = name;
  }
  else{
    while(hospitalQueue[specialization][end] != 3){
      end--;
    }
    if(end < queueSize - 1){
      for (int i = end; i < queueSize - 1; i++){
        hospitalQueue[specialization][i] = hospitalQueue[specialization][i + 1];
        namesOfPatient[specialization][i] = namesOfPatient[specialization][i + 1];
        }
    }
    hospitalQueue[specialization][queueSize -  1] = status;
    namesOfPatient[specialization][queueSize - 1] = name;
  }
  start = 0;
  end = queueSize - 1;


}

int numberOfPatientsInSpecialization(int specialization){
  int numberOfPatients = 0;
  for(int i = 0; i < queueSize; i++){
    if(hospitalQueue[specialization][i] != 3){
        numberOfPatients++;
    }
  }
  
  return numberOfPatients;
}

void printAllPatients(){
  std::cout << "********************************************************************" << "\n";
  for(int i = 0; i < specializations; i++){
    if(numberOfPatientsInSpecialization(i) > 0){
      std::cout << "There are " << numberOfPatientsInSpecialization(i) << " patients in specialization " << i << "\n";
    }
    for(int j = 0; j < queueSize; j++){
      std::cout << namesOfPatient[i][j];
      if(hospitalQueue[i][j] == 1){
        std::cout << " Urgent" << "\n";
        
      }
      else if(hospitalQueue[i][j] == 0){
        std::cout << " Regular" << "\n";
      }
    }
  }
  std::cout << "\n";

}

void getNextPatient(){
  std::cout << "getting next patient" << "\n";

}

// This function is only for debugging purposes 
void printCurrentQueue() {
  for(int i = 0; i < 5; i++){
    std::cout << hospitalQueue[0][i] << " ";
    std::cout << namesOfPatient[0][i] << " " << "\n";
  }
  std::cout << "\n";
}



int main() {

  bool exitProgram = true;
  initializeHospitalSystem();
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
    case 5:
      printCurrentQueue();
      break;
    default:
      exitProgram = false;
      break;
  }
  }

  return 0;
}
