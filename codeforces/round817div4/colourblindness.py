def solve():
    n = int(input())
    s = input()
    t = input()
    for i in range(n):
        if s[i] == 'R':
            if t[i] != 'R':
                print("NO")
                return
        else:
            if t[i] == 'R':
                print("NO")
                return
    print("YES")

def main():
    tt = int(input())
    for _ in range(tt):
        solve()

if __name__ == "__main__":
    main()

