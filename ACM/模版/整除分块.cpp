ans = 0;
for(i = 1,r = 0;i <= n; i = r+1)
{
	r = n/(n/i);
	ans += (r-i+1)*(n/i);
}