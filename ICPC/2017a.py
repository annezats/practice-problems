

def sum(n):
    sum=0
    for i in range(1,n+1):
        sum=sum+i+1
    return sum


def main():
    list=["1 8", '2 2']#open('filename.txt')
    #m=readline(list) #first line
    output=[]
    for n in list:
        f=n.split()
        print(f)
        output.append(sum(int(f[1])))
    print output

if __name__ == '__main__':
    main()
