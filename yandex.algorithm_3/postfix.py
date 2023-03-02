s=list(input().split())
t=[]
for i in s:
    if i.isdigit():
        t.append(int(i))
    elif i == '+':
        t[-2]= t[-2] + t[-1]
        t.pop()
    elif i =='-':
        t[-2] = t[-2] - t[-1]
        t.pop()
    elif i =='*':
        t[-2]=t[-2] * t[-1]
        t.pop()
print(t[0])