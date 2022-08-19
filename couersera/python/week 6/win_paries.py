parties = []
flag = True
sum_votes = 0
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.strip()
        if line == 'VOTES:':
            flag = False
            votes = [0]*len(parties)
        elif flag:
            parties.append(line)
        else:
            index = parties.index(line)
            votes[index] += 1
            sum_votes += 1
victories = (sum_votes * 7)/100
c = len(parties)
for i in range(c):
    if votes[i] >= victories:
        print(parties[i])
