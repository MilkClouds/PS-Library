N=int(input())
# N=5

[print(" "*(i-1)+"*"*(N-i+1)) for i in range(1,N+1)]
# [print(" "*(N-i)+"*"*i) for i in range(1,N+1)]