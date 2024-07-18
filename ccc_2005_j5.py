import sys

def banaRecur(word):
    if word == "A":
        return "YES"
    if "ANA" not in word and "BAS" not in word:
        return "NO"
    else:
        word = word.replace("ANA","A")
        word = word.replace("BAS","A")
        return(banaRecur(word))

while True:
    word = sys.stdin.readline().rstrip()
    if word == 'X':
        break
    print(banaRecur(word))