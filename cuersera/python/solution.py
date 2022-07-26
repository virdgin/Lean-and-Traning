def Intersection(A, B):
    # C = []
    a, b = 0, 0
    c = len(A) if len(A) > len(B) else len(B)
    while a < c and b < c:
        if A[a] > B[b]:
            b += 1
        elif A[a] < B[b]:
            a += 1
        else:
            print(A[a], end=" ")
            a += 1
            b += 1
    # print(*C)


# Intersection([1,3,4,5,7],[2,3,6,7])
Intersection(list(map(int, input().split())), list(map(int, input().split())))
