n= int(input())
P = []
for i in range(n):
    P.append(int(input()))
P.insert(0,0)
dp = []

for i in range(n+1):
    t=[]
    if i == 0:
        t += [0]+[400]*(n)
    else:
        t+=[P[i]]*(n+1)
    dp.append(t)
for i in range(n+1):
    for j in range(n+1):
        if j+1 == n+1:
            dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+P[i])  
        elif P[i]<=100:
            dp[i][j]=min(dp[i-1][j+1],dp[i-1][j]+ P[i])
        else:
            dp[i][j]=min (dp[i-1][j+1],dp[i-1][j-1]+P[i])
[print(i) for i in dp]