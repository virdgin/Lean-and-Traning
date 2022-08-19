synonym = dict()
a = int(input())
for i in range(a):
    t1, t2 = map(str, input().split())
    synonym[t1] = t2
    synonym[t2] = t1
print(synonym[input()])
