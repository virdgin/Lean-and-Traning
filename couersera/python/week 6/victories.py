result = [[0, 0], [0, 0], [0, 0]]
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        curs = int(line.split()[2])-9
        bal = int(line.split()[3])
        if bal > result[curs][1]:
            result[curs] = [1, bal]
        elif bal == result[curs][1]:
            result[curs][0] += 1
for i in result:
    print(i[0], end=' ')
