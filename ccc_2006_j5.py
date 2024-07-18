import sys
N,M,S = [int(i) for i in sys.stdin.readline().rstrip().split()]

strings = [[0] for i in range(N)]
ranges = [[0] for i in range(M)]
street = 0

for i in range(N):
    strings[i] = sys.stdin.readline().rstrip()

for i in range(M):
    ranges[i] = tuple([int(i) for i in sys.stdin.readline().rstrip().split()])

ranges = set(ranges)
for string in strings:
    fits = True
    for L,R in ranges:
        palindrome = string[L-1:R]
        for i in range(len(palindrome)//2 + 1):
            if palindrome[i] != palindrome[-1-i]:
                fits = False
                break
        if not fits: break
    if fits:
        street += 1

print(street)