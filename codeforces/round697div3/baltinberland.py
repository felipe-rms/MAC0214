def solve():
    A, B, k = map(int, input().split())
    a = [0] * A
    b = [0] * B
    edges = [tuple(map(int, input().split())) for _ in range(k)]
    
    for x, y in edges:
        a[x - 1] += 1
        b[y - 1] += 1
    
    ans = 0
    for x, y in edges:
        ans += k - a[x - 1] - b[y - 1] + 1
    
    print(ans // 2)

t = int(input())
for _ in range(t):
    solve()

