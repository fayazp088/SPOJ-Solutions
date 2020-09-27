


def facto(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    return ans

for _ in range(int(input())):
    n = int(input())
    print(facto(n))