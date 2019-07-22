#insertion sort 
def insertionSort(arr):
        print("call insertion sort for {}".format(arr))
        for i in range(1, len(arr)): 
                key = arr[i] 
                j = i-1
                #compare with left adjacent element
                while j>=0 and arr[j]>key: 
                        arr[j+1] = arr[j] 
                        j-= 1
                arr[j+1] = key	 
        return arr	 

#bucket sort		
def bucketSort(arr):
    #set the range for size of buckets
    maxx = 1.0
    minn = 0.0
    count = len(arr)
    r = [[]for _ in range(count)]
    s = (maxx-minn)/float(count)
    for i in range(count): 
        r.append([])
    print("Set empty buckets")
    print(r)

    #search bucket for each element
    def searchBucket(j):
        print("search bucket for {}".format(j))
        return int(j/s)
    
    #put elements in different buckets  
    for j in arr: 
        b = searchBucket(j)
        print("put in bucket {}".format(b))
        r[b].append(j)
        print("current elements in buckets: {}".format(r))

    print("After putting values to buckets...")
    print(r)

    #sort values in each bucket  
    for i in range(count): 
        r[i] = insertionSort(r[i])

    #concatenate results from sorted buckets
    k = 0
    for i in range(count): 
        for j in range(len(r[i])): 
            arr[k] = r[i][j] 
            k += 1
    return arr

if __name__ == "__main__":
        arr = [0.9,0.1,0.6,0.7,0.6,0.3,0.1] 
        print(bucketSort(arr)) 
