n,m=map(int,input().split())
gr =[set() for i in range(n+1)]
for i in range(m):
    a,b =map(int,input().split())
    gr[a].add(b)
visited = [0 for i in range(n+1)]
def dfs(now,cost):
    visited[now]=cost
    for neig in gr[now]:
        if  visited[neig] == 0:
            dfs(neig,3 - cost)
        elif visited[neig]== cost:
            return True
    return False
for i in range(1,n+1):
    if visited[i]==0:
        flag = dfs(i,1)
    if flag:
        print('NO')
        break
else:
    print('YES')