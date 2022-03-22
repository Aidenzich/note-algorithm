def mergeSortInversions(arr):
    if len(arr) == 1:
        return arr, 0
    else:
        a = arr[:len(arr)//2]
        b = arr[len(arr)//2:]
        a, ai = mergeSortInversions(a)
        b, bi = mergeSortInversions(b)
        c = []
        i = 0
        j = 0
        inv = 0 + ai + bi

        while i < len(a) and j < len(b):
            if int(a[i]) <= int(b[j]):
                c.append(a[i])
                i += 1
            else:
                c.append(b[j])
                j += 1
                inv += (len(a)-i)
        c += a[i:]
        c += b[j:]
        return c, inv


N = input()
arr = input().split(" ")


# print(mergeSortInversions(arr)[1])