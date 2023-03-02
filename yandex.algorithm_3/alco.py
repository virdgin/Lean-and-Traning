f = list(map(int, input().split()))
s = list(map(int, input().split()))
n = 0
while True:
    a, b = f[0], s[0]
    del f[0]
    del s[0]
    if a == 0 and b == 9:
        f += [a, b]
    elif b == 0 and a == 9:
        s += [a, b]
    elif a > b:
        f += [a, b]
    elif b > a:
        s += [a, b]
    n += 1
    if len(f) == 0:
        print('second', n)
        break
    elif len(s) == 0:
        print('first', n)
        break
    elif n == 1000000:
        print('botva')
        break
