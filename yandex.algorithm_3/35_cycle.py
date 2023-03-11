'''Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его. '''
n = int(input())
gr = [set() for i in range(n+1)]

for i in range(n):
    a = list(map(int, input().split()))
    for j in range(n):
        if a[j] == 1:
            gr[i+1].add(j+1)

visited = [False for _ in range(n+1)]
path = []

def dfs(now, cost = -1):
    if visited[now]:
        return now
    visited[now] = True
    for neig in gr[now]:
        if neig != cost:
            k = dfs(neig, now)
            if k!=-1:
                path.append(now)
                if k == now:
                    print('YES')
                    print(len(path))
                    print(*path)
                    exit(0)
                return k
    return -1


for i in range(1, n + 1):
    if visited[i] == 0:
        dfs(i)
else:
    print('NO')

