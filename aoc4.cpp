#include <iostream>

int get_digits(int i, bool & doubled, bool & bigger, bool & real_doubled, int & count, int & c2);

int get_digits(int i, bool & doubled, bool & bigger, bool & real_doubled, int & count, int & c2){
  if ((i/10)==0){
    return i;
  }

  int j= get_digits(i/10, doubled, bigger, real_doubled, count, c2);

  if (j== (i%10)){
    count ++; //counting iterations
    c2++; //counting repeating doubles
    if (!doubled && count == 5) { //for last one where the other way dont work
      real_doubled = true;
    }
    doubled = true;
  }
  else {
    count ++; //counting iterations
    if (doubled && c2==1){
      real_doubled = true;
    }
    doubled = false;
    c2=0; //resets repeating doubles
  }


  if (j> (i%10)){ //j is left digit, i mod 10 is right digit
    bigger = false;
  }
  return (i%10);
}//436 front and back cases
//not 480, 494 (too low), 600, 805 (too high), 925
int main (){
  int yes = 0; bool doubled = false; bool bigger= true; bool real_doubled= false;int count = 0; int c2=0;
  for (int i=271973; i<785962; i++){
  //for (int i=4000; i<6000; i++){
    doubled = false; bigger = true; real_doubled= false; count= 0; c2=0;
    int idk = get_digits(i, doubled, bigger, real_doubled, count, c2);
    if (real_doubled && bigger ){ //
      yes ++;
      std::cout<< i <<" ";
    }
  }
  std::cout << yes;
  return 0;
}
