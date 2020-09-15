doesnt have to be recursive
two-steps >= one steps

1. find all different step type combos
- divide by 2 to find for each leg

note- total num steps to be run is only up to 100
and even w 50 steps theres only four combos of 2 and 1 steptype
so that is easy even to hardcode

then for each combo of typetwo and typeone the different order of it is already step 2->

2. math for each one for the combos of steps
- this is combinatorics which we learn later on in discrete
- (combinations nCr formula)

!idea: set it as four different numbers so you're not confused by the different 1s and 2s
!important how to control that it is left right??->
do a combinations for one leg then do the combinations for the 2 legs
like,,, for six steps its 1 two-step and 1 one-step, so each leg is 2,1 or 1,2
so for both its 2,two,1,one 2,one,1,two 1,two,2,one & 1,one,2,two
so that would be 2*2=4 combos
