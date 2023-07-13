from itertools import product
OPERATORS = {'not': (4, lambda x:  int(x < 1)), 'and': (3, lambda x, y: x & y), 'or': (2, lambda x, y: x | y), '^': (
    2, lambda x, y: x ^ y),  '->': (1, lambda x, y: int(x <= y)), '~': (1, lambda x, y: int(x == y))}
s = input()
tab = dict()
n = []
s = s.replace('(', '( ')
s = s.replace(')', ' )')

for i in range(len(s)):
    if s[i].isupper():
        tab[s[i]] = None
        if s[i] not in n:
            n.append(s[i])
print(*sorted(n), 'F')


def my_eval(formula):
    def yard(infex):
        stack = []
        for token in infex:
            if token in OPERATORS:
                while stack and stack[-1] != '(' and OPERATORS[token][0] <= OPERATORS[stack[-1]][0]:
                    yield stack.pop()
                stack.append(token)
            elif token == ')':
                while stack:
                    h = stack.pop()
                    if h == '(':
                        break
                    yield h
            elif token == '(':
                stack.append(token)
            else:
                yield int(token)
        while stack:
            yield stack.pop()

    def calc(polish):
        stack = []
        for token in polish:
            if token in OPERATORS:
                if token != 'not':
                    y, x = stack.pop(), stack.pop()
                    stack.append(OPERATORS[token][1](x, y))
                else:
                    x = stack.pop()
                    stack.append(OPERATORS[token][1](x))

            else:
                stack.append(token)
        return stack[0]
    return int(calc(yard(formula)))


for i in product([0, 1], repeat=len(n)):
    t = s
    for j in range(len(n)):
        tab[n[j]] = i[j]
        t = t.replace(n[j], str(i[j]))
    print(*[k for k in i], my_eval(t.split()))
