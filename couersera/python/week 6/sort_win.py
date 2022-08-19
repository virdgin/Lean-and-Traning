parties = []
flag = True
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.strip()
        if line == 'VOTES:':
            flag = False
            votes = [0]*len(parties)
        elif flag:
            if line == 'PARTIES:':
                continue
            parties.append(line)
        else:
            index = parties.index(line)
            votes[index] += 1
result = []
c = len(parties)
for i in range(c):
    result.append((-votes[i], parties[i]))
result.sort()
for i in range(c):
    print(result[i][1])
