#include <iostream>

int main(){
  int mass; int fuel1; int sum_fuel=0;
  while (std::cin>>mass){
    fuel1= (mass/3)-2;
    sum_fuel = sum_fuel + fuel1;
    std::cout<<mass << " " << fuel1 << " "<< sum_fuel<< std::endl;
    int extrafuel= fuel1;
    while (extrafuel>0){ //PART TWO
      mass = extrafuel; //the mass is the initial fuel
      extrafuel= (mass/3)-2; //the fuel needed is from mass of fuel
      sum_fuel = sum_fuel + extrafuel; //new total
      std::cout<<mass << " " << extrafuel << " "<< sum_fuel<< std::endl;
    }
    sum_fuel= sum_fuel - extrafuel; //gets rid of last extra fuel, lazy i know
  }
  std::cout << sum_fuel << "  < before fuel added"<< std::endl;


  return 0;
}
