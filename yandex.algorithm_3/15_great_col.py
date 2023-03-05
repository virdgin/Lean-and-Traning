#индекс ближайшего меньшего правого
n = int(input())
m = list(map(int,input().split()))
r = [-1] * n
t=[0]
for i in range(1,n):
    while len(t)>0 and  m[t[-1]]>m[i]:
        r[t.pop()]=i
    t.append(i) 
print(*r)