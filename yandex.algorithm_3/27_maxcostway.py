'''В левом верхнем углу прямоугольной таблицы размером 
N
×
M
 находится черепашка. В каждой клетке таблицы записано некоторое число. Черепашка может перемещаться вправо или вниз, при этом маршрут черепашки заканчивается в правом нижнем углу таблицы.
Подсчитаем сумму чисел, записанных в клетках, через которую проползла черепашка (включая начальную и конечную клетку). Найдите наибольшее возможное значение этой суммы и маршрут, на котором достигается эта сумма.'''
n,m =map(int,input().split())
dp=[]
for i in range(n):
    dp.append(list(map(int,input().split())))
pdp=[[0 for j in range(m)] for i in range(n)]
pdp[0][0]=dp[0][0]
for i in range(n):
    for j in range(m):
        if i==0 and j!=0:
            pdp[i][j]= pdp[i][j-1] + dp[i][j]
        if j==0 and i!=0:
            pdp[i][j]=pdp[i-1][j] + dp[i][j]
        if j!=0 and i!=0:
            pdp[i][j]=max(pdp[i-1][j],pdp[i][j-1])+dp[i][j]
r=[]
t =pdp[n-1][m-1]
i = n-1
j=m-1
while i!=0 or j!=0:
    if pdp[i-1][j]==t-dp[i][j]:
        r.insert(0,'D')
        t -= dp[i][j]
        i -= 1
    else:
        r.insert(0,'R')
        t -=dp[i][j]
        j -=1
print(pdp[n-1][m-1])
print(*r)
