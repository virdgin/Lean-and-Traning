'''
A format for expressing an ordered list of integers is to use a comma separated list of either
individual integers
or a range of integers denoted by the starting integer separated from the end integer 
in the range by a dash, '-'. The range includes all integers in the interval including 
both endpoints. It is not considered a range unless it spans at least 3 numbers. 
For example "12,13,15-17"
Complete the solution so that it takes a list of integers in increasing order and 
returns a correctly formatted string in the range format.
'''
def solution(args):
    result = []
    temp =args[0] 
    tempnext = args[0]

    for i in args[1:]+[""]:
        if i != tempnext+1:
            if temp==tempnext:
                result.append(str(temp))
            elif  temp +1 == tempnext:
                result.extend([str(temp),str(tempnext)])
            else:
                result.append(str(temp)+'-'+str(tempnext))
            temp=i
        tempnext= i
    return ','.join(result)

print(solution([-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20]))