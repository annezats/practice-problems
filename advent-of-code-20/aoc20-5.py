def determine(char):
  if (char == 'F') or (char == 'L'):
    return True
  else: return False

def rec(arr, whichhalf):
    #print(whichhalf)
    which=determine(whichhalf[0])
    start=arr[0]; end=arr[1]
    if start==end: #or if whichhalf is empty
        #print(type(start))
        return start #base case
    else:
        length=end-start+1
        half=length/2
        if which==True:
            end=end-half
        else: start=start+half
        f= rec([start,end],whichhalf[1:])
        return f



def main():
    data=open('aoc20-5.txt')
    seatids=[]
    for line in data:
        rowdet=line[:8]+" "
        coldet=line[7:-1]+" "
        row=rec([0,127],rowdet)
        col=rec([0,7],coldet)
        #print(row,col)
        seatids.append(row*8+col)
    print(max(seatids))
    seatids.sort()
    for i in range(0,len(seatids)):
        if (seatids[i+1] - seatids[i])==2 :
            print(seatids[i]+1)
            break


if __name__ == '__main__':
    main()
