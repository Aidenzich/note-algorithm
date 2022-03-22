def print_all(arr, n, r):
    data = [0]*r;    
    combine_all(arr, data, 0, n - 1, 0, r)
 
recur_time = 0
def combine_all(arr, data, start,end, index, r):
    global recur_time
    recur_time+=1
    print(recur_time, index)
    print(data)
    if (index == r):
        
        
        for j in range(r):
            print(data[j], end = " ")
        print()     
        
        return
     
    i = start
    while(i <= end and end - i + 1 >= r - index):
        # change output data value
        data[index] = arr[i];

        combine_all(arr, data, i + 1, end, index + 1, r)
        i += 1
 


arr = input().split(" ")
newarr = []
for i in arr:
    newarr.append(int(i))

newarr = list(set(newarr))
newarr.sort()

r = 6
n = len(newarr)
print_all(newarr, n, r)