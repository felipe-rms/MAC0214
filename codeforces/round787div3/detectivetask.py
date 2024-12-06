def solve():
    s = input()
    n = len(s)
    a = [False] * (n + 1)
    a[0] = True
    for i in range(n):
        a[i + 1] = a[i] and (s[i] == '1' or s[i] == '?')
    
    b = [False] * (n + 1)
    b[0] = True
    for i in range(n - 1, -1, -1):
        b[n - i] = b[n - i - 1] and (s[i] == '0' or s[i] == '?')
    
    result = 0
    for i in range(n):
        if a[i] and b[n - i - 1]:
            result += 1
    
    print(result)

t = int(input())
for _ in range(t):
    solve()

