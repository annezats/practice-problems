#include <iostream>
#include <vector>

std::vector<int> Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
const int NUM_OF_PRIMES=167;

int Subprime_Fib(int a0, int a1){
  int n = a0 + a1;
  for (int i=0; i<NUM_OF_PRIMES; i++){
    if (Primes[i]==n){
      return n;
    }
  }
  for (int i=0; i<NUM_OF_PRIMES; i++){
    if (n%Primes[i]==0){
      return n%Primes[i];
    }
  }
}

std::vector<int> sequence_finder(int a0, int a1, int num_terms){
  //make a vector to put numbers into
  std::vector<int> main_sequence = {a0, a1};
  for (int i=2; i< num_terms; i++){
    //compute the next number
    int prev_num= main_sequence[i-1];
    int current_num=Subprime_Fib(main_sequence[i-2], prev_num);
    main_sequence.push_back(current_num);
    //loop through prev values to find if it and the one before it repeats
    for (int j=1; j<main_sequence.size()-1; j++){
      if (current_num==main_sequence[j]){
        if (prev_num==main_sequence[j-1]){
          std::vector<int> sequence_finder1 = {i, i-j};
          //add all the terms from j to i to the vector!!
          return sequence_finder1;//in theory this is what i need;
        }
      }
    }
  //what if didnt find anything
  return {num_terms, 0, current_num};
  }
}

int main(){
  std::cout << Subprime_Fib(0,1)<< std::endl;
  std::cout <<"^^ that should be 1"<< std::endl;
  std::cout << Subprime_Fib(300,301)<< std::endl;
  std::cout <<"^^ that should be 601"<< std::endl;
  std::vector<int> test1 = sequence_finder(0,1,3);
  for (int i=0; i<test1.size(); i++){
    std::cout << test1[i]<< std::endl;
  }
  std::cout <<"^^ that should be ??"<< std::endl;
  return 0;
}
