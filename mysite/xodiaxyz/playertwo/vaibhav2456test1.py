import textwrap
from random import randint
flag=0
string=str(raw_input())
a=textwrap.wrap(string,9)
arr=[['000000000'for i in range(20)]for j in range(20)]
for i in range(20):
	for j in range(20):
		arr[i][j]=a[i*20+j]
for i in range(20):
	for j in range(20):
		flag=0
		if(arr[i][j][0]!='0' and arr[i][j][0]!='2' and arr[i][j][0]!='4'):
			flag=1
			break
	if flag==1:
		break
if flag==0:
	k=randint(3,16)
	print str(k)+','+'0'+','+str(k+randint(-1,1))+','+'1'
else:
	for i in range(20):
		for j in range(20):
			if(arr[i][j][0]=='1'):
				if(i!=0 and i!=19):
					print str(i)+','+str(j)+','+str(int(i-1))+','+str(j+1)+','+str(i+randint(0,1))+','+str(j+1)
					exit(0)
				elif(i==0):
					print str(i)+','+str(j)+','+str(i+1)+','+str(j)+','+str(i+1)+','+str(j+1)
					exit(0)
				elif(i==19):
					print str(i)+','+str(j)+','+str(i-1)+','+str(j)+','+str(i-1)+','+str(j+1)
					exit(0)