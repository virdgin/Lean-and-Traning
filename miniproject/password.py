import random


digits = "0123456789"
lowercase_letters = "abcdefghijklmnopqrstuvwxyz"
uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
punctuation = "!#$%&*+-=?@^_"
chars = ""
simbols = "il1Lo0O"


def password(t):
    a = input(t)
    if a.isdigit():
        return int(a)
    else:
        print("Введите число!")
        return password(t)


def valid(t):
    if t.lower() == "да":
        return True
    return False

def generate_password(l,t):
    pas=''
    for i in range(l):
        pas += random.choice(t)
    return pas

a = password("Сколько паролей сгенерировать?: ")
l = password("Введите длину пароля: ")
p_digits = valid(input("Включать в пароль числа?(да/нет): "))
p_l_letters = valid(input("Включать в пароль строчные буквы?(да/нет): "))
p_u_letters = valid(input("Включать в пароль заглавные буквы?(да/нет): "))
p_punctuations = valid(input("Включать в пароль спецсимволы?(да/нет): "))
p_symbols = valid(input("Включать в пароль неоднозначные символы?(да/нет): "))
if p_digits:
    chars += digits
if p_l_letters:
    chars += lowercase_letters
if p_u_letters:
    chars += uppercase_letters
if p_punctuations:
    chars += punctuation
if not p_symbols:
    for i in simbols:
        chars.replace(i, "")
result=[]
for i in range(a):
    result.append(generate_password(l,chars))

print(*result,sep='\n')