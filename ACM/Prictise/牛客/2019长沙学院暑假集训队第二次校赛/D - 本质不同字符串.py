def cut(s: str):
	results = []
	n = len(s)
	for x in range(n):
		for i in range(n - x):
			results.append(s[i:i + x + 1])
	return results

s = input()
li = list(set(cut(s)))
print(len(li))