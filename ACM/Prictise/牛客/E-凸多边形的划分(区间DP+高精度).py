#https://ac.nowcoder.com/acm/contest/5902/D
n = int(input())
a = []
dp = [([999999999999999999999999999] * (n+10)) for i in range(n+10)]
for i in range(n):
	num = list(map(int, input().split()))
	a.append(0)
	for i in num:
		a.append(i)
	for i in range(n, 0, -1):
		for j in range(i+1, n+1):
#			print(i, j)
			if j-i == 1:
				dp[i][j] = 0;
			elif j-i == 2:
				dp[i][j] = a[i]*a[i+1]*a[i+2]
			else:
				for k in range(i+1, j):
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+a[i]*a[j]*a[k])
	print(dp[1][n])
	exit()