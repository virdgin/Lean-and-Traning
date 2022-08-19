max_ball = [0]*3
school, bal = 0, 0
max9, max10, max11 = 0, 0, 0
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.split()
        school, bal = int(line[-2]), int(line[-1])
        if school == 9:
            if max9 < bal:
                max_ball[0] = max9
                max9 = bal
            elif bal > max_ball[0] and bal != max9:
                max_ball[0] = bal
        if school == 10:
            if max10 < bal:
                max_ball[1] = max10
                max10 = bal
            elif bal > max_ball[1] and bal != max10:
                max_ball[1] = bal
        if school == 11:
            if max11 < bal:
                max_ball[2] = max11
                max11 = bal
            elif bal > max_ball[2] and bal != max11:
                max_ball[2] = bal
print(*max_ball)
