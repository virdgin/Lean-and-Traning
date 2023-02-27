matrix = []
n,m,k=map(int,input().split())
for i in range(n):
    matrix.append(list(map(int,input().split())))
for i in range(k):
    a,b,c,d=map(int,input().split())
    sum = 0
    for j in range(a-1,c):
        for l in range(b-1,d):
            sum+=matrix[j][l]
    print(sum)