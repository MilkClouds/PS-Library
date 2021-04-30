from collections import deque
from bisect import insort
import sys;input=sys.stdin.readline;INF=sys.maxsize
V,E=map(int,input().split())
inp=lambda x:int(x)-1
K=inp(input())
graph=[{} for _ in range(V)]
for _ in range(E):
	u,v,w=map(inp,input().split())
	graph[u][v]=min(graph[u].get(v,INF),w+1)

def dijkstra(K,V,graph):
	d=[INF]*V
	d[K]=0
	Q=deque([[0,K]])
	while Q:
		dist,i=Q.popleft()
		for v in graph[i]:
			new=d[i]+graph[i][v]
			if d[v]>new:
				d[v]=new
				insort(Q,[d[v],v])
	return d

for i in dijkstra(K,V,graph):
	print(i if i!=INF else 'INF')