#include <iostream>

int main(){
  //read all the numbers into an array0, then array is the one that changes
  int array0[121]; int j=0; int array[121]; bool break1= false;
  while(std::cin>>array0[j]){
    j++;
  }

  for (int a=0; a<100; a++){
    for (int b=0; b<100; b++){

      //resets array values
      for (int c=0; c<121; c++){
        array[c]= array0[c];
      }
      //changes values to the ones for this loop
      array[1] = a;
      array[2] = b;

      //does the thing
      int sum=0; int mult=0;
      for (int i=0; i<j; i = i+4){
        if (array[i]==1){
          sum= array[array[i+1]] + array[array[i+2]];
          //std::cout <<sum<< " ";
          array[(array[i+3])]= sum;
        }
        if (array[i]==2){
          mult= array[array[i+1]] * array[array[i+2]];
          //std::cout <<mult<< " ";
          array[(array[i+3])]= mult;
        }
        if (array[i]==99){
          //std::cout<< i;
          break;
        }
      } // end of for loop doing the main thing
      if (array[0]== 19690720 ){
        // end everything and return a and b
        break1= true;
        std::cout << "RESULT FOUND AND A IS "<< a << " b is " << b<< std:: endl;
        break;
      }
    }// end of b
    if (break1) break;
  }// end of a
  return 0;
}
