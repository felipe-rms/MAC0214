def solve():
    n = int(input())
    a = []
    
    for i in range(n):
        x = int(input())
        if i == 0 or x != a[-1]:
            a.append(x)
    
    num_valley = 0
    for i in range(len(a)):
        if (i == 0 or a[i-1] > a[i]) and (i == len(a)-1 or a[i] < a[i+1]):
            num_valley += 1
    
    if num_valley == 1:
        print("YES")
    else:
        print("NO")

t = int(input())
for _ in range(t):
    solve()

