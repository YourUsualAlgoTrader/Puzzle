'''
By using the fact that I can point at the same object with different variable using list in Python.
We can reproduce the figure by separating the different square and taking into acount that some square have common edge.
For example Square1 and Square2 have a common edge it's the third edge for Square1 and the first for Square2.
So we use list to make Square1[2] (the third edge of Square1) pointing at the same object as Square2[0] (the first edge of Square2)
'''


from tqdm import tqdm


#list of all the edges
Edges=[]


#Initialization of all the edges with value 0 for red and 1 for green
for i in range(24):
    Edges.append([0])

#Initialization of all the Square object define by 4 squares from the Edges list
Square1=[Edges[0],Edges[1],Edges[2],Edges[3]]
Square2=[Square1[2],Edges[4],Edges[5],Edges[6]]
Square3=[Square2[2],Edges[7],Edges[8],Edges[9]]

Square4=[Edges[10],Square1[3],Edges[11],Edges[12]]
Square5=[Square4[2],Square2[3],Edges[13],Edges[14]]
Square6=[Square5[2],Square3[3],Edges[15],Edges[16]]

Square7=[Edges[17],Square4[3],Edges[18],Edges[19]]
Square8=[Square7[2],Square5[3],Edges[20],Edges[21]]
Square9=[Square8[2],Square6[3],Edges[22],Edges[23]]

#Set of all the square
SetOfSquare=[Square1,Square2,Square3,Square4,Square5,Square6,Square7,Square8,Square9]

#Verify if a Square have all his edges with the same color. Return True or False
def testSquare(Square):
    return(((Square[0]==Square[1]) & (Square[1]==Square[2]) & (Square[2]==Square[3])))

#Verify if a Square have all his edges with the same color in a set of square. Return True or False
def testSetofSquare(SetofSquare):
    SquareMonochrome=False
    for Square in SetOfSquare:

        if testSquare(Square):
            SquareMonochrome=True
            break
    return(SquareMonochrome)

#Count the number of possibility with at least a square which has all his edges with the same color
count=0

#Loop with all possible combinations of color
for i in tqdm(range(2**24)):
    #Use bijectivity if binary transformation to get the color of each edge, 0 for red and 1 for green
    binaryCode=bin(i)[2:]

    #Change the color of the edge according to the binary code
    for index,color in enumerate(binaryCode):
        Edges[index][0]=int(color)

    #Add 1 if there is a square which has all his edges with the same color combination of color we're looking
    count+=testSetofSquare(SetOfSquare)


print("The probability to is : ",1-count/2**24)

