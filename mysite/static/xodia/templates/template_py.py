import textwrap
string=str(raw_input())
a=textwrap.wrap(string,9)
arr=[['000000000'for i in range(20)]for j in range(20)]
for i in range(20):
	for j in range(20):
		arr[i][j]=a[i*20+j]

#your code to grow

#for first move
print (str(i1)+","+str(j1)+","+str(i2)+","+str(j2))
#where (i1,j1)(i2,j2) are coordinates of the seed and leaf

#for the rest of the moves
print (str(i1)+","+str(j1)+","+str(i2)+","+str(j2)+","+str(i3)+","+str(j3))
#where (i1,j2)(i2,j2)(i3,j3) are coordinates of the seed and leaves


