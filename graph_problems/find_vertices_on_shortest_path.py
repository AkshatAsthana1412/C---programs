# your code goes here
from collections import defaultdict, deque
class Graph(object):
	def __init__(self, n):
		self.used = [0]*n
		self.d = [0]*n
		self.p = [0]*n
		self.G = defaultdict(list)
		self.getsize = lambda: n
	
	def add_edge(self, a, b):
		self.G[a].append(b)
		self.G[b].append(a)
	
	def bfs(self, s):
		self.used = [0]*self.getsize()
		self.d = [0]*self.getsize()
		self.p = [0]*self.getsize()
		q = deque()
		q.append(s)
		self.p[s] = None
		self.used[s] = 1
		while q:
			u = q.popleft()
			for v in self.G[u]:
				if not self.used[v]:
					self.used[v] = 1
					q.append(v)
					self.d[v] = self.d[u] + 1
					self.p[v] = u
					
def find_vertices_on_shortest_path(G, a, b):
	#run bfs from a
	G.bfs(a)
	da = G.d
	
	#run bfs from b
	G.bfs(b)
	db = G.d
	
	res = []
	for i in range(G.getsize()):
		if da[b] == da[i] + db[i]:
			res.append(i)
	return res
	
fun = find_vertices_on_shortest_path
g = Graph(9)
g.add_edge(0,6)
g.add_edge(0,1)
g.add_edge(7,6)
g.add_edge(6,8)
g.add_edge(8,4)
g.add_edge(4,5)
g.add_edge(5,2)
g.add_edge(2,3)
g.add_edge(3,1)
g.add_edge(3,4)
g.add_edge(4,6)
g.add_edge(1,2)

print('Enter the no. of test cases')
t = int(input())
print(f'Enter edges:')
for _ in range(t):
	a,b = list(map(int, input().split()))
	print(fun(g,a,b))
	