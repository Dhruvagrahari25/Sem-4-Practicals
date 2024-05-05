#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int bufferSize(0), curr(0);
bool mutex = false;

void produce(){
  if(!mutex){
    mutex=true;
    if(curr<bufferSize){
      curr++;
      std::cout << "Producer produced item"<< curr << '\n';
    }else std::cout << "Buffer Full!" << '\n';
  }
  mutex=false;
}
void consume(){
  if(!mutex){
    mutex=true;
    if(curr>0){
      curr--;
      std::cout << "Consumer consumed item"<< curr << '\n';
    }else std::cout << "Buffer Empty!" << '\n';
  }
  mutex=false;
}
int main(){
  cout<<"Enter buffer Size: ";
  cin>>bufferSize;

  while(1){
    std::cout << "\n\n" << '\n';
    std::cout << "1. Produce" << '\n';
    std::cout << "2. Consume" << '\n';
    std::cout << "3. Exit" << '\n';
    int choice(0);
    cin>>choice;
    switch (choice) {
      case 1: produce();
        break;

      case 2: consume();
        break;

      case 3:
        exit(1);

      default: std::cout << "Invalid Choice!" << '\n';
    }
  }

  return 0;
}
