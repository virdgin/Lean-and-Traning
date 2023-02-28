s =input()
d = dict()
n = len(s)
for i in range(n):
    d[s[i]] = d.get(s[i], 0)+(n-i)*(i+1)
[print(f'{key}: {value}') for key, value in sorted(d.items())]