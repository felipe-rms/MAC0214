n, q = map(int, input().split())

s = [0]*(n+1)
x = list(map(int, input().split()))

for i in range(1, n+1):
    s[i] = x[i-1] + s[i-1]
for i in range(q):
    a, b = map(int, input().split())
    print(s[b] - s[a-1])

