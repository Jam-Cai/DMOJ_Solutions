import sys
L = int(sys.stdin.readline())
def getGraphDepth(inp):
    messageDep = 0
    values = []
    visited = [inp[-1]]
    for i in inp:
        values.append(messageDep)
        if i in visited:
            messageDep -= 1
            visited.pop()
            continue
        visited.append(i)
        messageDep += 1
    return len(inp) * 10 - max(values) * 20
for i in range(L):
    inp = []
    n = int(sys.stdin.readline())
    for i in range(n):
        inp.append(sys.stdin.readline().rstrip())
    print(getGraphDepth(inp))