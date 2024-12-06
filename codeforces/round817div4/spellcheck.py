def main():
    name = "Timur"
    name = ''.join(sorted(name))

    n = int(input())
    for _ in range(n):
        m = int(input())
        s = input()
        s = ''.join(sorted(s))
        print("YES" if s == name else "NO")

if __name__ == "__main__":
    main()

