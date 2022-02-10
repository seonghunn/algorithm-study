import sys

def quadTree(row, col, size):
    if size==1:
        print(a[row][col],end='')
        return
    isCompressible =True
    for i in range (row,row+size):
        for j in range(col,col+size):
            breaker=False
            if a[i][j]!=a[row][col]:
                isCompressible=False
                breaker=True
                break
        if breaker==True:
            break
    if isCompressible==True:
        print(a[row][col],end='')
        return
    else:
        print('(',end='')##루프에 들어갈 때 ( 추가
        for m in range (row,row+size,size//2):
            for n in range (col,col+size,size//2):
                quadTree(m,n,size//2)
        print(')',end='')##한 루프가 끝날 때 ) 추가
                
N=int(sys.stdin.readline())
a=[list(map(int,input())) for i in range (N)]
quadTree(0,0,N)