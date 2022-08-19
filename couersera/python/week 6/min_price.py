from audioop import reverse


people = list(map(int, input().split()))
taxi = list(map(int, input().split()))
people.sort()
taxi.sort(reverse=True)
result = 0
for i in range(len(taxi)):
    result += taxi[i]*people[i]
print(result)
