def countingSort(arr):
    
    x = max(arr)
    count = [0] * (x + 1)
    # initiate a list with zeros
    b = [-1] * len(arr)
    # initialize a result sorted array
    for i in arr:
        print("count of {} is increased".format(i))
        count[i] += 1
        #increment
    print("count: {}".format(count))

    
    print("second stage...")
    for j in range(len(count) - 1):
        count[j+1] += count[j]
        #increment the countings
        
    print("count: {}".format(count))
    print("store the sorted result")
    for i in arr:
        # build the result
        b[count[i]-1] = i
        print("put {} at index {}".format(i, count[i]-1))
        count[i] -= 1
        #decrement after printing

    print("Sorted Result...")
    return b

if __name__ == "__main__":
    arr = arr = [9, 1, 6, 7, 6, 2, 1]
    print(countingSort(arr))
