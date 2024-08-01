import cmath
def find_roots(a,b,c):
	d = cmath.sqrt(determination(a,b,c));	
	if d!=0:
		return (-1*b+d)/2*a,(-1*b+d)/2*a;
	elif d ==0:
		return (-1*b+d)/2*a;
	# else :
	# 	return None;

def determination(a,b,c):
	return b**2 - 4*a*c;

T = int(input());
for i in range(T):
	N = int(input());
	for j in range(N):
		a,b,c = map(float,input().split());
		roots = set();
		if(a==0):
			if(b==0):
				continue;
			else:
				roots.add(-(c/b));
		else:
			roots.add(find_roots(a,b,c));
			for i in roots:
				print(i);
	print(len(roots));		



