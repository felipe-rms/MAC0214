def solve():
    n = int(input())
    s = input()
    tot = 0
    v = []

    for i in range(n):
        if s[i] == 'L':
            v.append((n - 1 - i) - i)
            tot += i
        else:
            v.append(i - (n - 1 - i))
            tot += n - 1 - i

    v.sort(reverse=True)
    
    for i in range(n):
        if v[i] > 0:
            tot += v[i]
        print(tot, end=' ')
    print()

def main():
    tt = int(input())
    for _ in range(tt):
        solve()

if __name__ == "__main__":
    main()

