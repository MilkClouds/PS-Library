

n,m=map(int,input().split())
mod=int(1e9+7)

d=[[0]*m for _ in range(n)]

for i in range(n):
	d[i][0]=1
for i in range(m):
	d[0][i]=1

for i in range(1,n):
	for j in range(1,m):
		if j<n and i<m and d[j][i]:d[i][j]=d[j][i]
		else:d[i][j]=(d[i-1][j]+d[i][j-1]+d[i-1][j-1])%mod
		
print(d[n-1][m-1])