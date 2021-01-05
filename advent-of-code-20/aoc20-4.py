def main():
    data=open('aoc20-4.txt')
    f=0
    myline=""
    for line in data:#doesnt work for last line
        #print(myline)
        if (line != "\n"):
            myline=myline+ " " + line[:-1]
        else:
            d=dostuff(myline)
            #print(d)
            myline=""
            if d: f+=1
    d=dostuff(myline)
    myline=""
    if d: f+=1
    print(f)

def zero(myline,i):
    if (len(myline)>=5 and myline[i+4]==" " and 1920<= int(myline[i:i+4]) <=2002):
        return True
    else: return False

def one(myline,i):
    if (len(myline)>=5 and myline[i+4]==" " and 2010<= int(myline[i:i+4]) <=2020):
        return True
    else: return False

def two(myline,i):
    if (len(myline)>=5 and myline[i+4]==" " and 2020<= int(myline[i:i+4]) <=2030):
        return True
    else: return False

def three(myline,i):
    if (len(myline)>=6 and myline[i+3:i+5]=="cm" and 150<=int(myline[i:i+3])<=193):
        return True
    elif(len(myline)>=5 and myline[i+2:i+4]=="in" and 59<=int(myline[i:i+2])<=76):
        return True
    else: return False

def four(myline,i):
    if (len(myline)>=8 and myline[i+7]==" " and myline[i]=="#"):#theres more but dont want
        return True
    else: return False

def five(myline,i):
    list=['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']
    if (len(myline)>=4 and myline[i+3]==" "):
        for j in list:
            if myline[i:i+3]== j:
                return True
    else: return False

def six(myline,i):
    if (len(myline)>=10 and myline[i+9]==" " and myline[i:i+9].isdigit()):
        return True
    else: return False

def validity(j,myline,i):
    switcher={
        0: zero(myline,i),
        1: one(myline,i),
        2: two(myline,i),
        3: three(myline,i),
        4: four(myline,i),
        5: five(myline,i),
        6: six(myline,i),
    }
    return switcher.get(j,False)

def dostuff(myline):
    #print(myline)
    list=['byr','iyr','eyr','hgt','hcl','ecl','pid','cid']

    c=0
    for i in range(0,len(myline)):
        for j in range(0,8):
            thing=myline[i:i+4]
            category=list[j]+":"
            if (thing == category and validity(j,myline[i+4:],i+4)):
                #lets put some switch cases
                c+=1
                i+=6
                break
    #print(c)
    if (c==7): return True
    else: return False

if __name__ == '__main__':
    main()
