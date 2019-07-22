#radix sort
from collections import deque
import math
def radixSort(arr, base, ld, td):
    #initialize buckets
    rd = 10-ld-1

    if(len(arr) <= 1):
        return arr

    #divide by the number of digits
    result = []
    bucket = [[] for _ in range(base)]
    for i in arr:
        if(ld >= td):
            #sort and print the smallest number
            print((math.log(i,base))+1)
            result.append(i)
        else:
            bucket[(i//(base**rd))%base].append(i)

    #conquer
    bucket = [radixSort(b, base, ld+1, td) for b in bucket]
    #connect all buckets to return the list
    return result+[b for blist in bucket for b in blist]
    
if __name__ == "__main__":
    arr = [1000, 88, 315, 52, 150, 80, 278, 250, 261, 353, 214]
    print(radixSort(arr,10,0,10))
