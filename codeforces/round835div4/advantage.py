def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = sorted(a)

    for i in range(n):
        if a[i] == b[-1]:
            print(a[i] - b[-2], end=" ")
        else:
            print(a[i] - b[-1], end=" ")
    print()


t = int(input())
for _ in range(t):
    solve()

