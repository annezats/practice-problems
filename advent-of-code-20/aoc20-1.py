
#open the file and get the input
def accounting(listofyears, mainyear):
    listofpairs=[]
    for year in listofyears:
        year=int(year)
        pair=mainyear-year
        listofpairs.append(pair)
        for item in listofpairs:
            if item==year:
                print([item, mainyear-item])
                return year*(mainyear-year)
    return(0)

def main():
    data=open('aoc20-1.txt')
    listofyears=[]
    for line in data:
        listofyears.append(line)
    #this is for part 2
    for year in listofyears:
        year=int(year)
        answer=accounting(listofyears,2020-year)
        if (answer !=0):
            print(year,answer*year)
            break
    return 0

if __name__ == "__main__":
    main()
