import sys
input=sys.stdin.readline
for i in range(int(input())):
	if eval(input().replace('=','==')):
		print('correct')
	else: print('wrong answer')