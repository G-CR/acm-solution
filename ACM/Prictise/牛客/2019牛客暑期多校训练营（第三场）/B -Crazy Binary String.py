def lengest01SubStr(s):
	count = [0, 0]
	B = [0] * len(s)
	dic = {} 
	lengest = 0
	for i in range(len(s)):
		count[int(s[i])] += 1
		B[i] = count[0] - count[1]
		if B[i] == 0:
			lengest = i + 1
			continue
		if B[i] in dic:
			lengest = max(lengest, i - dic[B[i]])
		else:
			dic[B[i]] = i
	return lengest
N = int(input())
a = input()
sum1 = 0
sum0 = 0
for i in range(len(a)):
	if a[i] == '1':
		sum1 += 1
	if a[i] == '0':
		sum0 += 1

print(lengest01SubStr(a),min(sum1,sum0)*2)