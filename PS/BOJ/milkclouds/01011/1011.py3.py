for _ in range(int(input())):
    a, b = map(int,input().split())
    print( int((b-a-.5)**.5*2) )