import sys

N,M,K=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))
a.sort(reverse=True) #내림차순 정렬

res=0

for i in range (1,M+1):
    if(i%(K+1)==0):
        res+=a[1]
    else:
        res+=a[0]
        
print(res)