n = int(input())
x, y = map(int, input().split())
maxx, miny, minx, maxy = x, y, x, y
for i in range(n - 1):
    x, y = map(int, input().split())
    maxy = max(maxy, y)
    miny = min(miny, y)
    maxx = max(maxx, x)
    minx = min(minx, x)
print(minx, miny, maxx, maxy)
