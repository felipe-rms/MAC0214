def solve():
    n, m = map(int, input().split())
    a, b = [], []
    v = list(map(int, input().split()))
    x = list(map(int, input().split()))
    
    for i in range(n):
        if x[i] == 1:
            a.append(v[i])
        else:
            b.append(v[i])

    a.sort(reverse=True)
    b.sort(reverse=True)
    
    cur_sum_a = 0
    r = len(b)
    cur_sum_b = sum(b)
    ans = float('inf')
    
    for l in range(len(a) + 1):
        while r > 0 and cur_sum_a + cur_sum_b - b[r - 1] >= m:
            r -= 1
            cur_sum_b -= b[r]
        if cur_sum_a + cur_sum_b >= m:
            ans = min(ans, 2 * r + l)
        if l < len(a):
            cur_sum_a += a[l]
    
    print(-1 if ans == float('inf') else ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()

