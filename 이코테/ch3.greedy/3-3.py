import sys

N,M=map(int,sys.stdin.readline().split())
card=[list(map(int,sys.stdin.readline().split())) for i in range(N)]
for i in range (N):
    card[i].sort()
    
minlist=[card[i][0] for i in range(N)]
print(max(minlist))