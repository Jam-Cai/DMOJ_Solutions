import sys
from itertools import combinations, product
import collections
T = int(sys.stdin.readline())
Q = int(sys.stdin.readline())
teams = [0, 0, 0, 0]
games = list(combinations(range(len(teams)), 2))

for i in range(Q):
    line = [int(c) for c in sys.stdin.readline().rstrip().split()]
    games.remove((line[0] - 1, line[1] - 1))
    if line[2] > line[3]:
        teams[line[0] - 1] += 3
    elif line[2] < line[3]:
        teams[line[1] - 1] +=3
    else:
        teams[line[0]-1] += 1
        teams[line[1] - 1] += 1

ans = 0
stack = [(0, teams)]
while stack:
        index, score = stack.pop()
        if index == len(games):
            m = max(score)
            occurence = score.count(m)
            if occurence == 1 and score[T - 1] == m:
                ans += 1
            continue
        win = score.copy()
        lose = score.copy()
        tie = score.copy()
   
        win[games[index][0]] += 3
        lose[games[index][1]] += 3
        tie[games[index][0]] += 1
        tie[games[index][1]] += 1
        # win current game
        stack.append((index + 1, win))

        #lose current game
        stack.append((index + 1, lose))

        #tie
        stack.append((index + 1, tie))

print(ans)