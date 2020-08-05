#https://ac.nowcoder.com/acm/contest/5902/A
n, m = map(int, input().split())
l = 2**n
r = 2**m
r -= 1
while r%7 != 1:
	r -= 1
ans = r//7 - l//7
if l%7 == 1:
	ans += 1
print(ans)