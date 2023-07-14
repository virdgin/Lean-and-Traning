def merge_sort(numbers):
    if len(numbers) == 1:
        return numbers
    left = merge_sort(numbers[:len(numbers) // 2])
    right = merge_sort(numbers[len(numbers) // 2:])
    result = []
    i, j = 0, 0
    while i < len(left) or j < len(right):
        if not i < len(left):
            result.append(right[j])
            j += 1
        elif not j < len(right):
            result.append(left[i])
            i += 1
        elif left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    return result


print(merge_sort([3, 1, 5, 3]))
