t = int(input())
for i in range(0,t):
	x, y = map(int, input().split())
	if(x == 0 or y == 0 or x == 1):
		print("-1")
		continue
	k = 70
	while(x**k > y):
		k -= 1
		if(k < 0):
			break
	print(k)