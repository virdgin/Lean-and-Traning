from unittest.util import safe_repr


'''В обувном магазине продается обувь разного размера. Известно, что одну пару обуви можно надеть на другую, если она
хотя бы на три размера больше. В магазин пришел покупатель.Требуется определить, какое наибольшее количество пар обуви
сможет предложить ему продавец так, чтобы он смог надеть их все одновременно.
Формат ввода
Сначала вводится размер ноги покупателя (обувь меньшего размера он надеть не сможет), в следующей строке — размеры каждой
пары обуви в магазине через пробел. Размер — натуральное число, не превосходящее 100.
Формат вывода
Выведите единственное число — максимальное количество пар обуви, которое сможет надеть покупатель.'''
s = int(input())
p = sorted(list(map(int, input().split())))
s = s - 3
c = len(p)
res = 0
for i in range(c):
    if p[i] - s >= 3:
        res += 1
        s = p[i]
print(res)
