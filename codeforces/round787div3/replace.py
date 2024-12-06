def solve():
    n, k = map(int, input().split())
    s = list(input())

    mn = 'a'
    for i in range(n):
        if s[i] > mn:
            if ord(s[i]) - ord('a') > k:
                k -= ord(mn) - ord('a')
                to = ord(s[i]) - k
                for c in range(ord(s[i]), to, -1):
                    for j in range(n):
                        if s[j] == chr(c):
                            s[j] = chr(c - 1)
                break
            else:
                mn = max(mn, s[i])

    for i in range(n):
        if s[i] <= mn:
            s[i] = 'a'
    
    print("".join(s))


t = int(input())

for _ in range(t):
    solve()

