
def validity(info):
    min=info[0]
    max=info[1]
    char=info[2]
    password=info[3]
    c = 0
    for letter in password:
        if (letter == char):
            c=c+1
    if (int(min)<=c<=int(max)):
        return True
    else: return False

def unpack(line):
    dividers=['-',' ',':',' ']
    info=[]
    i=0
    for char in line:
        if (char=="\n"):
            break
        if (i<3 and char==dividers[i]):
            i=i+1
            #print(char)
            continue
        if (len(info)>i):
            info[i]=str(info[i])+str(char)
        else: info.append(char)
    #print(info)
    return info

def validity2(info):
    #print(info)
    start=int(info[0])
    end=int(info[1])
    char=info[2]
    password=info[3]
    c = 0;
    one=False; two=False
    for letter in password:
        if (c==start and letter==char):
            one=True
        if (c== end and letter == char):
            two=True
        c=c+1
    if ((one and not(two)) or (two and not(one))):
        return True
    else: return False

def main():
    data=open('aoc20-2.txt')
    v=0
    for line in data:
        if validity2(unpack(line)):
            v=v+1
            print(line)
    print(v)
    return 0

if __name__=="__main__":
    main()
