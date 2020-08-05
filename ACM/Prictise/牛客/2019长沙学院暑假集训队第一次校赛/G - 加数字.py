n=int(input())
mod = 1e9+7
sum=0
h=1
for i in range(0,n):
	h = h * 10
	h = h % 1000000007
	q,x=map(int,input().split())
	if q==1:
		sum=sum*10+x
		sum=sum%1000000007
	elif q==0:
		sum=sum+x*h
		sum=sum%1000000007
	print(sum%1000000007)