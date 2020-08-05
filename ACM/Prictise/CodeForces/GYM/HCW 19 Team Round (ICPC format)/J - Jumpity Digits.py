s = input()
n = len(s)
ans = 0
s1 = list(s)
for i in range(0,n):
	for j in range(i,n):
		if s1[j] < s1[i]:
#			print(i," ",j)
			if i == 0 and s[j] == '0':
				continue
			t = s1[j]
			s1[j] = s1[i]
			s1[i] = t
			r = ''.join(s1)
			ans = max(ans,int(r))
			s1 = list(s)
if ans == 0:
	print('-1')
else:
	print(ans)