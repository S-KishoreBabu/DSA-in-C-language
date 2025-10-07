class Graph:
    def __init__(self):
        self.list = {}

    def addEdge(self,i,j):
        self.list.setdefault(i,[]).append(j)
        self.list.setdefault(j,[]).append(i)

    def display(self):
        for vertex,edges in self.list.items():
            print(f"[{vertex}]-> {edges}")

graph = Graph()
graph.display()
graph.addEdge(0,1)
graph.addEdge(2,3)
graph.addEdge(1,2)
graph.addEdge(3,4)
graph.addEdge(0,4)
graph.addEdge(1,4)
graph.display()