class Graph:
    def __init__ (self):
        self.dic = { }
    
    def addEdges(self, u, v):
        self.dic.setdefault(u,[]).append(v)
        self.dic.setdefault(v,[]).append(u)
    def display(self):
        for vertex,edges in self.dic.items():
            print(f"\n {vertex}-> {edges}")
    def BFS(self):
        visited = queue = []
        keys = list(self.dic.keys())
        queue.extend(keys[0])
        visited.append(keys[0])
        while(len(queue)>0):
            ou = list(filter(lambda x : x not in visited,self.dic[queue[0]]))
            queue.extend(ou)
            visited.extend(ou)
            queue.pop(0)
        print(visited)

g = Graph()

g.addEdges('a','g')
g.addEdges('a','e')
g.addEdges('a','b')
g.addEdges('g','b')
g.addEdges('e','f')
g.addEdges('e','d')
g.addEdges('f','b')
g.addEdges('b','c')
g.addEdges('b','h')
g.addEdges('d','c')
g.addEdges('c','h')

g.display()
g.BFS()