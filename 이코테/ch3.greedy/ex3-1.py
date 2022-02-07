import sys

ans=[500,100,50,10]
cnt=0
num = int(sys.stdin.readline())

for i in ans:
    cnt+=num//i
    num%=i
    
print(cnt)