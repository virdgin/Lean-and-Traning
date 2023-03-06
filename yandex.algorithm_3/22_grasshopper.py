N, k = map(int, input().split()) 
A = [1] * N 
for i in range(1, N): A[i] = sum(A[max(0, i - k):i]) 
print(A[-1])