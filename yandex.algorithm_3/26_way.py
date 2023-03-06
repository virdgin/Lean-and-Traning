n, m = map(int, input().split())
'''В каждой клетке прямоугольной таблицы N×M записано некоторое число. Изначально игрок находится в левой верхней клетке. За один ход ему разрешается перемещаться в соседнюю клетку либо вправо, либо вниз (влево и вверх перемещаться запрещено). При проходе через клетку с игрока берут столько килограммов еды, какое число записано в этой клетке (еду берут также за первую и последнюю клетки его пути).

Требуется найти минимальный вес еды в килограммах, отдав которую игрок может попасть в правый нижний угол. '''
dp = []
for i in range(n):
    dp.append(list(map(int, input().split())))
temp = [[0 for i in range(m)] for j in range(n)]
temp[0][0] = dp[0][0]
for i in range(n):
    for j in range(m):
        if i == 0 and j != 0:
            temp[i][j] = dp[i][j]+temp[i][j-1]
        if i != 0 and j == 0:
            temp[i][j] = dp[i][j]+temp[i-1][j]
        if i != 0 and j != 0:
            temp[i][j] = min(temp[i-1][j], temp[i][j-1])+dp[i][j]
print(temp[n-1][m-1])
