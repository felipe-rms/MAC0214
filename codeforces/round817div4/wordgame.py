from collections import defaultdict

def solve():
    n = int(input())
    mp = defaultdict(int)
    a = [[], [], []]
    
    for i in range(3):
        a[i] = input().split()
        for word in a[i]:
            mp[word] += 1
    
    for i in range(3):
        tot = 0
        for word in a[i]:
            if mp[word] == 1:
                tot += 3
            elif mp[word] == 2:
                tot += 1
        print(tot, end=' ')
    print()

def main():
    tt = int(input())
    for _ in range(tt):
        solve()

if __name__ == "__main__":
    main()

