n =int(input())
m=int(input())
metro =[[] for _ in range(n)]
for i in range(m):
    c = list(map(int,input().split()))[1:]
    for s in c:
        metro[s-1].append(i)
a,b = map(int,input().split())
a-=1
b-=1
g=[[]for _ in range(m)]
for l in metro:
    if len(l)>1:
        for cur in range(len(l)-1):
            for cur2 in range(cur+1,len(l)):
                g[l[cur]].append(l[cur2])
                g[l[cur2]].append(l[cur])
g = [set(i) for i in g]
q = [s for s in metro[a]]
d =[-1] * m
for i in q:
    d[i]=0
for line in q:
    for neig in g[line]:
        if d[neig]==-1:
            d[neig] = d[line]+1
            q.append(neig)
ans =1000000
for i in metro[b]:
    if d[i]<ans:
        ans=d[i]
print(ans)