// make vector w first value being the one we don't want
// and the second being the one we want
//when you get your character loop through the array x and change to y
#include <iostream>
#include <vector>
#include <cmath>

std::vector <std::vector <int> > conversionlist = {{'A',10},{'C',11},{'D',12},{'E',13},{'F',14},{'H',15},{'J',16},{'K',17},{'L',18},{'M',19},{'N',20},{'P',21},{'R',22},{'T',23},{'V',24},{'W',25},{'X',26},{'B',8},{'G',11},{'I',1},{'O',0},{'Q',0},{'S',5},{'U',24},{'Y',24},{'Z',2}};

int convert_to_int(char letter){
  int num = -1;
  if (isalpha(letter)){
    int i=0;
    while (letter != conversionlist[i][0]){//because i forgot to put them in quotes
      i++;
    }
    num= conversionlist[i][1];
  }
  else {
    num = int(letter)-48;
    //you get a char thats a number so make it its own number
  }
  return num;
}

void read_input(std::string input, int values[8]){
  for (int i=0; i<8; i++){
      values[i]= convert_to_int(input[i]);
  }
}

int do_the_math(int values[8]){
  int check_num= 2*values[0] + 4*values[1] + 5*values[2] + 7*values[3] + 8*values[4] + 10*values[5] + 11*values[6] + 13*values[7];
  check_num = check_num %27;
  return check_num;
}

char convert_to_char(int check_num){ //
  if (check_num < 9){
    return char(check_num+48);
  }
  int i=16;
  while (check_num != conversionlist[i][1]){//
    i--;
  }
  char check_digit= conversionlist[i][0];
  return check_digit;
}

bool check(char input_check_digit, int check_digit){
  if (input_check_digit == check_digit){
    return true;
  }
  else return false;
}

double twentyseven_to_decimal(int values[8]){
  //write this code
  double decimal=0;
  for (int i=0; i<8; i++){
    decimal = decimal + values[i]*pow(27,(7-i)); //pow(base,exponent)
  }
  return decimal;
}

int main(){
  char letter = 'A';
  int num = convert_to_int(letter);//works :)
  std::cout<< num<< std::endl;
  //char check_digit = convert_to_char(check_num); doesnt work :(
  //std::cout<< check_digit<< std::endl;
  std::string input = "12345678A";
  std::cout<< "input: " << input<< std::endl;
  int values[8];
  read_input(input, values);//sticks input into values
  for (int i=0; i<8; i++){
    std::cout<< "values: " <<values[i]<< std::endl;
  }
  int check_num = do_the_math(values);
  std::cout<< "checknum: " << check_num<< std::endl;
  char check_digit= convert_to_char(check_num);
  std::cout<< "checkdigit: " <<check_digit<< std::endl;
  if (check(input[8], check_digit)){
    double decimal= twentyseven_to_decimal(values);
    std::cout<< decimal<< std::endl;
  }
  else std::cout<< "INVALID"<< std::endl;
  return 0;
}
