def mymin(a, b):
    if(a<0):
        return b
    if(b<0):
        return a
    return min(a, b)

def main():
    n, q = map(int, input().split())
    res = [[-1] * 200000 for _ in range(200000)]
    x = list(map(int, input().split()))
    for i in range(n):
        res[i][i] = x[i]
    for i in range(n):
        for j in range(i+1, n):
            res[i][j] = mymin(res[i][j-1], x[j])
    for _ in range(q):
        a, b = map(int, input().split())
        print(res[a-1][b-1])

main()

