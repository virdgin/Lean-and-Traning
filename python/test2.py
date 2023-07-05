n = int(input())
a1 = [int(i) for i in input().split()]
a2 =[int(i) for i in input().split()]
m = int(input())
s =[int(i) for i in input().split()]
r=0
t = 0
f=True
for i in s:
    j = a1.index(i)
    if f:
        t=a2[j]
        f=False
    if t != a2[j]:
        r+=1
        t =a2[j]
print(r)