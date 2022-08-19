max_ball = [0]*101
school, bal = 0, 0
k = 0
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.split()
        school, bal = int(line[-2]), int(line[-1])
        max_ball[school] += 1
mball = max(max_ball)
resultIndex = []
for i in range(len(max_ball)):
    if max_ball[i] == mball:
        resultIndex.append(i)
print(*resultIndex)
