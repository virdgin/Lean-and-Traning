# Отсортируйте данный массив. Используйте пирамидальную сортировку.
from queue import PriorityQueue


n = int(input())
m = map(int, input().split())
heap = PriorityQueue(n)
for item in m:
    heap.put(item)
for i in range(n):
    print(heap.get(), end=' ')
