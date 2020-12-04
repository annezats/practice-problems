def slopes(data,x,y):
    a=0
    t=0
    b=0
    for line in data:
        if ((a%y) !=0):#handles the down
            a=a+1
            continue
        list=[]
        for char in line:
            if (char!="\n"):#doesn't add this
                list.append(char)
        #print(list)
        if (list[int(x*(a/y))%len(list)]=="#"):
            t=t+1
        a=a+1
    return t

def main():


    s=[[1,1],[3,1],[5,1],[7,1],[1,2]]
    m=1
    for cord in s:
        data=open('aoc20-3.txt')
        t=slopes(data,cord[0],cord[1])
        print(t)
        m=m*t
        data.close()
    print(m)
    return 0

if __name__=="__main__":
    main()
