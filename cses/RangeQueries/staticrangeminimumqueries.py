n, q = map(int, input().split())
x = list(map(int, input().split()))
segtree = [-1]*(4*200000)

def mymin(a, b):
    if(a<0):
        return b
    elif(b<0):
        return a
    else:
        return min(a, b)

def mid(a, b):
    return int((a+b)/2)

def buildtree(left, right, node):
    if(left == right):
        segtree[node] = x[left]
        return x[left]
    else:
        segtree[node] = mymin(buildtree(left, mid(left, right), 2*node+1),
                            buildtree(mid(left, right)+1, right, 2*node+2))
#        print("min[" + str(left) + ", " + str(right) + "]=" +str(segtree[node]))
        return segtree[node]

def query(a, b, na, nb, node):
    if(a <= na and b >= nb):
        return segtree[node]
    elif(b < na or nb < a):
        return -1
    else:
        return mymin(query(a, b, na, mid(na, nb), node*2+1),
                     query(a, b, mid(na, nb)+1, nb, node*2+2))

buildtree(0, n-1, 0)
for _ in range(q):
    a, b = map(int, input().split())
    print(query(a-1, b-1, 0, n-1, 0))

