
def insert_end(list,elem):
    list.append(elem)
    return list

def insert_start(list,elem):
    newlist = [elem]
    for i in list:
        newlist.append(i)
    return newlist

def swap (list,ind1,ind2):
    tmp = list[ind1]
    list[ind1] = list[ind2]
    list[ind2] = tmp

def insert_naive(list,elem):
    newlist=[]
    ln = len(list)
    is_inserted = False
    for i in range(ln):
        if (list[i]>=elem and not(is_inserted)):
            newlist.append(elem)
            newlist.append(list[i])
            is_inserted = True
        else:
            newlist.append(list[i])
    return newlist

def search_naive(list,elem):
    index = False;
    ln = len(list)
    for i in range (ln):
        if list[i] == elem:
            index = i
    return index

def bin_search_rec(list,left,right,elem):
    if left >= right:
        return right
    mid = left + (right - left)//2
    if list[mid] == mid:
        return mid
    if elem < list[mid]:
        return bin_search_rec(list, left,mid,elem)
    return bin_search_rec(list,mid+1,right,elem)

def bin_search(list,elem):
    return bin_search_rec(list,0,len(list),elem)

def bubble_sort(list):
    ln = len(list)-1
    for i in range (ln):
        for j in range (ln):
            if list[j]>list[j+1]:
                swap (list,j,j+1)

def quicksort(list,sortlist):
    if len(list)<=1:
        return
    pivot = list[0] 
    swap(list,0,len(list)//2)
    a=[]
    b=[]
    for i in range(len(list)):
        if list[i]<=pivot:
            a.append(list[i])
        else:
            b.append(list[i])
    print (a)
    print (b)
    if len(a)>1:
        quicksort(a,sortlist)
    elif len(a)==1:
        sortlist.append(a[0])
    if len(b)>1:
        quicksort(b,sortlist)
    elif len(b)==1:
        sortlist.append(b[0])
    return


def test ():
    list = [5,3,4,6,8,9,1,7,2]
    print (list)
    sortlist = []
    quicksort (list,sortlist)
    print(sortlist)
    

test();
