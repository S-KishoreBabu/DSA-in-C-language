def addEdge(i,j):
    matrix[i][j] = 1
    matrix[j][i] = 1

def display():
    for i in range(v):
        print(matrix[i])

v = int(input("Enter No. of Vertices : "))
matrix = [[0]*v for _ in range(v)]
display()
print("\n\n")
addEdge(0,1)
addEdge(0,4)
addEdge(1,4)
addEdge(1,2)
addEdge(2,3)
addEdge(3,4)
display()