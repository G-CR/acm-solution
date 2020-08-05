def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b, a%b)
 
x,y,z = map(int,input().split())
p = x * y // gcd(max(x,y), min(x,y))
q = p * z // gcd(max(p,x), min(p,z))
print(q//x + q//y + q//z)