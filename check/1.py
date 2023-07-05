from curses.ascii import isdigit


n, m, s = map(int, input().split())
a = [0] * max(n, m)
b = [0] * max(n, m)
for i in range(max(n, m)):
    f, d = input().split()
    if f.isdigit():
        a[i] = int(f)
    if d.isdigit():
        b[i] = int(d)
result1 = []
result2=[]
i = 0
j = 0
if sum(a) <= s:
    result1 += a
    while sum(result1) < s:
        result1.append(b[i])
        i += 1
        if i==len(b):
            break
elif sum(b) <= s:
    result1 += b
    while sum(result1) < s:
        result1.append(a[i])
        i += 1
        if i==len(a):
            break
i = 0
j = 0
while sum(result2) < s:
    if a[i] <= b[j] and a[i] != 0:
        result2.append(a[i])
        a[i] = 0
        i += 1
    elif a[i] >= b[j] and b[j] != 0:
        result2.append(b[j])
        b[j] = 0
        j += 1
    elif a[i] == 0 and i != len(a) and b[j] !=0:
        result2.append(b[j])
        j += 1
    elif b[j] == 0 and j != len(b) and a[i]!=0:
        result2.append(a[i])
        i += 1
    if j==len(b)-1 and i==len(a)-1:
        break
result= result1 if len(result1)>len(result2) else result2
print(len(result)-result.count(0) if sum(result) <= s else len(result) - 1-result.count(0))