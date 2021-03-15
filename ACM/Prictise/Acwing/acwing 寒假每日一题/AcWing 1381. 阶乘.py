#!/usr/bin/env python3
n = int(input())
a = 1
for i in range(1, n+1):
	a *= i
b = a
while b%10==0:
	b //= 10
print(b%10)