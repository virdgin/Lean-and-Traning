'''Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую первую вершину.
'''
n,m =map(int,input().split())
gr = [set() for i in range(n+1)]
for i in range(m):
    a,b = map(int,input().split())
    gr[a].add(b)
    gr[b].add(a)
t=set()    
t|=gr[1]
if len(t)>0 and  m>0 :
    while True:
        g=len(t)
        temp = set()
        for i in t:
            for j in gr[i]:
                temp.add(j)
        t|=temp
        if g == len(t):
            break
    print(len(t))
    print(*sorted(t))
else:
    print(1,1,sep='\n')
