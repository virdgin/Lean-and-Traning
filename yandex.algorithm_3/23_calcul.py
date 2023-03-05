'''

Имеется калькулятор, который выполняет следующие операции:

    умножить число X на 2;
    умножить число X на 3;
    прибавить к числу X единицу.

Определите, какое наименьшее количество операций требуется, чтобы получить из числа 1 число N.
'''
n = int(input())
a = [0] * (n + 1)
for i in range(2, n+1):
    minimal = a[i-1]+1
    if i % 2 == 0:
        minimal = min(minimal, a[i//2]+1)
    if i % 3 == 0:
        minimal = min(minimal, a[i//3]+1)
    a[i] = minimal
oper = [n]
i = n
while i > 1:
    if a[i] == (a[i-1]+1):
        i -= 1
        oper.insert(0, i) 
    elif i % 2 == 0 and a[i] == a[i//2] + 1:
        i //= 2
        oper.insert(0, i)
    else:
        i //= 3
        oper.insert(0, i)
print(len(oper)-1)
print(*oper)
