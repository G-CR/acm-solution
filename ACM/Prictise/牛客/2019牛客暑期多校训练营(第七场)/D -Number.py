import sys
n,a = map(int,input().split())

if n == len(str(a)):
	print(a)
	sys.exit()

if n > len(str(a)):
	print(str(a),end="")
	for i in range(n-len(str(a))):
		print("0",end = "")
	sys.exit()
	
print("T_T")