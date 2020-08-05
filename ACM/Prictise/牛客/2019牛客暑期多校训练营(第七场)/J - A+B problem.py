t = int(input())
for i in range(t):
	a,b = map(str,input().split())
	t1 = a[::-1]
	t2 = b[::-1]
	for i in range(len(t1)):
		if t1[i] != '0':
			num = i
			break
	t1 = t1[num:]
	for i in range(len(t2)):
			if t2[i] != '0':
				num = i
				break
	t2 = t2[num:]
	
	ans1 = int(t1)+int(t2)
	ans = str(ans1)
	ans = ans[::-1]
	for i in range(len(ans)):
		if ans[i] != '0':
			num = i
			break
	ans = ans[i:]
	print(ans)