def ssd(s):
    sum=0
    for char in s:
        sum=sum+int(char)**2
    return sum

def main():
    a=3
    b='98765'
    c=int(b,a) #why does this not WORK
    print (ssd(str(c)))

if __name__ == '__main__':
    main()
