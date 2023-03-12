'''В неориентированном графе требуется найти длину минимального пути между двумя вершинами.'''

from queue import Queue
n = int(input())
graph = [[0 for i in range(n)] for j in range(n)]
d = [0 for _ in range(n)]
for i in range(n):
    d[i] = 1000000
    a = list(map(int, input().split()))
    for j in range(n):
        graph[i][j] = a[j]
x, y = map(int, input().split())
x, y = x-1, y-1
q = Queue()
d[x] = 0
q.put(x)
while (not q.empty()):
    i = q.get()
    for j in range(n):
        if graph[i][j] and d[j] > d[i]+1:
            d[j] = d[i]+1
            q.put(j)
if d[y] < 1000000:
    print(d[y])
else:
    print(-1)
