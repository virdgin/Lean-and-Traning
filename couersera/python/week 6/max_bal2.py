sum_bal = []
one, two, free = 0, 0, 0
k = 0
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.split()
        if (len(line)) == 1:
            k = int(line[0])
        else:
            one, two, free = int(line[-3]), int(line[-2]), int(line[-1])
            if one >= 40 and two >= 40 and free >= 40:
                sum_bal.append(one+two+free)
result = [0]*301
index = -1
flag = 1
if len(sum_bal) <= k:
    print(0)
else:
    for i in range(len(sum_bal)):
        result[sum_bal[i]] += 1
    while k - result[index] >= 0:
        if result[index] != 0:
            flag = 301 + index
        k = k - result[index]
        index -= 1
    print(flag)
