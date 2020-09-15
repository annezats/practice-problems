#include <iostream>
#include <cmath>
/*
WHAT HAPPENED:
first i spent too long on the actual setup as opposed to the tiny bit of
program that is the main math thing
THEN i did a whole thing w strings because i forgot i can do things mod ten
and then i was stressed and anxious because i have to do setup for an event after this
so i left
*/
int octal( int decimal){
  /*std::string startnum= std::to_string(decimal);
  std::cout<< startnum<< " length: "<<startnum.length()<< std::endl;
  int octal=0; int thisone=0;
  for (int i=0; i< startnum.length(); i++){
    thisone= int(startnum[i]) * pow(8,(startnum.length()-i));
    octal = octal + thisone;
    std::cout<< thisone<< std::endl;
    if (int(startnum[i]) == 9){
      std::cout<<"equals 9"<<std::endl;
      octal = 0;
      i= startnum.length();
    }
  }*/
  return octal;
}

int main(){
  /*int dataset; std::string line; std::string num; std::string space=" ";
  std::cin>> dataset;
  for (int k=0; k<dataset; k++){
    std::cin>>line;
    int i = 0;
    while (!isspace(line[i])){
      i++;
      continue;
    }
    for (int j=(i+1); j<(line.length()-i); j++){
      num= num + line[i];
    }
    std::cout<< num;

    //std::
  }*/
  int num;
  std::cin>>num;
  std::cout<<octal(num);
  return 0;
}
