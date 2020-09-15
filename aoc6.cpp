//put first things of line into one string var, use the ")" to separate, put the second into another var
//store all names of directs in objects
//loop through all data getting the direct pointers
//loop through all the data starting at begining, counting the relationships
#include <iostream>

class Object {
public:
  std::string Name; //
  std::string Orbiting_name; //if this is b, it is orbiting a which is orbiting_name
  int count; //num of indirect and direct orbits
  void get_orbiting(Object * array, int NUMOFLINES); // connects the orbiting pointer to the current
  Object * Orbiting; //points to what it is orbiting
  Object();
};

Object::Object(){
  count = 0;
}

void Object::get_orbiting(Object * array, int NUMOFLINES){
  for (int k=0; k< NUMOFLINES; k++){ //loops through array
    if (Orbiting_name == array[k].Name){ //matches this orbiting_name to the other's Name
      Orbiting = &array[k];//makes the pointer be the pointer
      //std::cout << (*Orbiting).Name<< std::endl;
      break;
    }
  }
}


void get_data(Object * array){
  std::string line; std::string name; std::string orbiting;int k=0;
  while (std::cin>>line){
    name=""; orbiting="";
    for (int i=0; i<3; i++){
      orbiting = orbiting + line[i]; //adds first 3 chars to name
    }
    for (int j=4; j<7; j++){ // adds last 3 chars to orbiting
      name = name + line[j];
    }
    array[k].Name= name; //sets name as Name
    array[k].Orbiting_name= orbiting; //sets orbiting as Orbiting_name
    line="";//resets variable
    k++; //line counter
  }
}


int get_one_ans(Object a, int ans){// how many connections for each thing u start w
  if (a.Orbiting_name == "COM"){ //never goes here cause segmentation fault :(
    //std::cout << "com"<< std::endl;
    return 1;
  }
  ans = get_one_ans(*(a.Orbiting), ans);
  //std::cout<< a.Name << std::endl;
  ans = ans + 1;
  return ans;
}

std::string get_list_orbiting(std::string name, Object a, std::string list1[], int & i){
  if (a.Orbiting_name == "COM"){
    //std::cout << "com"<< std::endl;
    list1[i] = "COM";
    i++;
    return a.Name;
  }
  name = get_list_orbiting(a.Orbiting_name, *(a.Orbiting), list1, i);
  //std::cout<< a.Name << std::endl;
  list1[i] = name;
  i++;
  return a.Name;
}

int main(){
  static const int NUMOFLINES=1057;//13
  //static const int NUMOFLINES=13;//13
  Object array[NUMOFLINES];
  get_data(array); //gets name of object and its Orbiting
  int YouNumber; int SanNumber;
  for (int k=0; k< NUMOFLINES; k++){
    array[k].get_orbiting(array, NUMOFLINES); //gets the pointer to orbiting for each Object
    if (array[k].Name == "YOU"){
      YouNumber = k;//gets the index of the you number in the arary
      std::cout << "the younumber is "<<k<<std::endl;
    }
    if (array[k].Name == "SAN"){
      SanNumber = k;//gets the index of the santa number in the arary
      std::cout << "the santanumber is "<<k<<std::endl;
    }
  }
  for (int k=0; k< NUMOFLINES; k++){
    array[k].count= get_one_ans(array[k], array[k].count); //this does NOT work
  }
  int sum = 0;
  for (int k=0; k< NUMOFLINES; k++){
    sum= sum + array[k].count;
  }
  std::cout << sum<< std:: endl;
  //PART TWO -----------------------------------
  //younumber works
  //.count works
  std::cout<< " the you count is " << array[YouNumber].count << std::endl;
  std::cout<< " the san count is " << array[SanNumber].count << std::endl;

  std::string listYOU[array[YouNumber].count];std::string listSAN[array[SanNumber].count]; int i=0;
  get_list_orbiting("YOU", array[YouNumber], listYOU, i);
  i=0;
  get_list_orbiting("SAN", array[SanNumber], listSAN, i);
  for (int j=0; j<array[YouNumber].count; j++){
    //std::cout<< listYOU[j] << j << std::endl;
    if (listYOU[j]!= listSAN[j]){
      std::cout<< j << std::endl;
      break;
    }
  }//f
  std::cout << "this works"<< std::endl;

  return 0;
}

/*for part 2:
array for all orbits of YOU
annother one for all orbits of SAN;

compare them to find where they first overlap
count how many to that one from YOU
then from that one to san
*/
