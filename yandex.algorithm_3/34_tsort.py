n,m=map(int,input().split())
gr =[set() for i in range(n+1)]
for i in range(m):
    a,b =map(int,input().split())
    gr[a].add(b)
visit = [0 for _ in range(n+1)]
res=[]
def dfs (now,cost):
    visit[now]=cost
    for neirg in gr[now]:
        if visit[neirg]== 0:
            dfs(neirg,3 -cost)    
        elif visit[neirg] == cost:
            return True
    res.insert(0,now)
    return False
for i in range(n+1):
    if visit[i] == 0:
        f = dfs(i,1)
    if f:
        print(-1)
        break
else:
    print(*res[:-1])