import re

#Check the size of the longest word 
def max_size(arr):
    word_l = 0
    for w in arr:
        if len(w) > word_l:
            word_l = len(w)
    return word_l

#Concat 'A's to words with less length
def set_size(arr, size):
    nl = []
    for w in arr:
        n_arr = ['A'*(size-len(w))]
        nl.append(w+'A'.join(n_arr))
    return nl

#Sort by starting from the last character of each word
def radixSort(arr, size, i):
    if(i==size+1):
        return arr
    dic = []
    dict_word = {}
    #letters to check
    letter= ['A','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
             'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    letter_i = 0
    tmp = []
    #to copy the correct results

    #create dic for each letter to make comparision more easily
    for x in range(27):
        dict_word.update({letter[letter_i]:(x+1)})
        letter_i += 1
    dict_word.update({'':1000})

    for w in arr:
        if(dict_word[w[size-i].lower()]<1000):
           dic.append([w,dict_word[w[size-i].lower()]])

    #sort words in the current index by creating a new list
    for x,y in dic:
        tmp.append([x,y])
    tmp.sort(key=lambda x: x[1])
 
    #create a return list to return the sorted result
    r=[]
    for k in tmp:
        r.append(k[0])
 
    #add all remaining elements being ordered from previous recursions
    for k in arr:
        if k not in r:
            r.append(k())
 
    #call the next word recursively
    return radixSort(r, size, i+1)
	
 
if __name__ == '__main__':
        #testcase
	arr =  ["word", "category", "cat", "new", "news",
                 "world", "bear", "at", "work", "time"]
	size = max_size(arr)
	nl = set_size(arr, size)
	nl = radixSort(nl, size-1, 0)
	i = 0
	for w in nl:
            #remove A added to the words with less length
	    nl[i]= re.sub('[A]','', w)
	    i+=1
	#print the ordered list
	print(nl)
 

