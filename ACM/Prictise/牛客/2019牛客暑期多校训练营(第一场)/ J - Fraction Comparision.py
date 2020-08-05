while(1):
	try:
		x,a,y,b = map(int, input().split())
		if(x*b > y*a):
			print('>')
		elif(x*b < y*a):
			print('<')
		else:
			print('=')
	except:
		break