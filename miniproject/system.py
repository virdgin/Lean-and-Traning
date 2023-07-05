a=513
n=1
r=''
while a>0:
    r+=str(a%2)
    a=a//2
print(r[::-1])