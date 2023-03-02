def preprocess(mat, _n,_m):
    s = [[0 for j in range(_m)] for i in range(_n)]  # новая матрица
    # первый аргумент новой матрицы равен первому аргументу начальной
    s[0][0] = mat[0][0]
    for i in range(1, _m):  # заполнение первой строки значениями
        s[0][i] = mat[0][i]+s[0][i-1]
    for i in range(1, _n):  # заполнение первого столбца значениями
        s[i][0] = mat[i][0]+s[i-1][0]
    for i in range(1, _n):  # заполнение оставшейся матрицы
        for j in range(1, _m):
            s[i][j] = mat[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]
    return s


matrix = []
n, m, k = map(int, input().split())
for i in range(n):
    matrix.append(list(map(int, input().split())))
# получили уже новую матрицу с нужными значениями
matrix = preprocess(matrix, n, m)
for i in range(k):
    a, b, c, d = map(int, input().split())
    # total равен mat[c][d] - mat[c][b-1] - mat[a-1][d] + mat[a-1][b-1] так как значение указываются абсолютные вычитаем ещё по единице отовсюду
    total = matrix[c-1][d-1]
    # проверка границ
    if b - 2 >= 0:
        total -= matrix[c-1][b-2]
    if a - 2 >= 0:
        total -= matrix[a-2][d-1]
    if a-2 >= 0 and b-2 >= 0:
        total += matrix[a-2][b-2]
    print(total)
