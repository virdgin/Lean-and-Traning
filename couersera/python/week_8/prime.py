'''Выведите все простые на отрезке [2;n].
Формат ввода
Вводится число 2≤n≤100000.
Формат вывода
Выведите все простые числа из отрезка [2,n] в порядке возрастания
Примечания
Напомним, что проверить число на то, простое ли оно можно за количество операций порядка √(N). Также напомним, что функция math.sqrt работает значительно быстрее, чем (x ** 1/2).'''
from math import sqrt


print(*filter(lambda i: all(map(lambda x: i %
      x, range(2, round(sqrt(i))+1))), range(2, int(input())+1)))