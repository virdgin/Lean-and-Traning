def mround(x, n=0):
    posneg = 1 if x > 0 else -1
    z = (int(abs(x) * 10 ** n + 0.5))  / 10 ** n
    return(z * posneg)
A = list(map(int, input().split(":")))
B = list(map(int, input().split(":")))
C = list(map(int, input().split(":")))
a = A[0] * 60 * 60 + A[1] * 60 + A[2]
b = B[0] * 60 * 60 + B[1] * 60 + B[2]
c = C[0] * 60 * 60 + C[1] * 60 + C[2]
if c<a:
    c+=24*3600 
b = b + mround((c - a)/2)
h = b//60//60%24
m = b // 60%60
s = b% 60
print(f'{int(h):0>2}:{int(m):0>2}:{int(s):0>2}')