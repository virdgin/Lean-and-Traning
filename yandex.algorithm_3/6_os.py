m = int(input())
n =int(input())
r=[]
for i in range(n):
    a,b=map(int,input().split())
    t = []
    for j in r:
        if a<=j[1] and j[0]<=b:
            continue
        else:
            t.append(j)
    t.append([a,b])
    r=t
print(len(r))