a,b=map(int,input().split())
print(*[i-a*b for i in map(int,input().split())])