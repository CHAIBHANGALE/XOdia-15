#include<stdio.h>
int arr[20][20][9];
int a,b,c,d,e,f,me;

int main()
{	int i,j,k,nbranch=0,maxval=6,count=1,n=0;
	char s[3600];
	void initialise(int n);
	int value(int i,int j);
	void leafselect(int* base,int cnt);
	scanf("%s",s);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<9;k++)
			{
				arr[i][j][k]=s[i*9*20+j*9+k]-48;
			}
		}
	}
	for(i=0;i<20;i++)
	{
		if(arr[i][0][0]==0||arr[i][0][0]==3)
			me=1;
		else
		{
			me=2;
			break;
		}
	}

	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(arr[i][j][0]==1||arr[i][j][0]==3)
			for(k=1;k<9;k++)
			{
				if(arr[i][j][k]==1)
					nbranch++;
			}
		}
	}
	nbranch/=2;
	if(nbranch<=19)
		initialise(nbranch);
	else
	{
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				if(arr[i][j][0]==1)
				{
					arr[i][j][0]=value(i,j);
					if(arr[i][j][0]>maxval)
					{	maxval=arr[i][j][0];
						count=1;
					}
					else if(arr[i][j][0]==maxval)
						count++;
				}

		int indbox[count][2];
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
			{
				if(arr[i][j][0]==maxval)
				{
					indbox[n][0]=i;
					indbox[n][1]=j;
					n++;
				}
			}
		leafselect(indbox,count);
	}
	if(nbranch==0)
		printf("%d,%d,%d,%d",a,b,c,d);
	else
		printf("%d,%d,%d,%d,%d,%d",a,b,c,d,e,f);

}

void initialise(int n)
{
	switch(n)
	{
	case 0:
		if(me==1)
		{a=10;b=0;c=10;d=1;}
		else if(me==2)
		{a=10;b=19;c=10;d=18;}
		break;
	case 1:
		if(me==1)
		{a=10;b=1;c=9;d=2;e=11;f=2;}
		else if(me==2)
		{a=10;b=18;c=9;d=17;e=11;f=17;}
		break;
	case 3:
		if(me==1)
		{a=9;b=2;c=8;d=3;e=9;f=3;}
		else if(me==2)
		{a=9;b=17;c=8;d=16;e=9;f=16;}
		break;
	case 5:
		if(me==1)
		{a=11;b=2;c=11;d=3;e=12;f=3;}
		else if(me==2)
		{a=11;b=17;c=11;d=16;e=12;f=16;}
		break;
	case 7:
		if(me==1)
		{a=8;b=3;c=7;d=3;e=7;f=2;}
		else if(me==2)
		{a=8;b=16;c=7;d=16;e=7;f=17;}
		break;
	case 9:
		if(me==1)
		{a=12;b=3;c=13;d=3;e=13;f=2;}
		else if(me==2)
		{a=12;b=16;c=13;d=16;e=13;f=17;}
		break;
	case 11:
		if(me==1)
		{a=9;b=3;c=8;d=4;e=10;f=4;}
		else if(me==2)
		{a=9;b=16;c=8;d=15;e=10;f=15;}
		break;
	case 13:
		if(me==1)
		{a=11;b=3;c=11;d=4;e=12;f=4;}
		else if(me==2)
		{a=11;b=16;c=11;d=15;e=12;f=15;}
		break;
	case 15:
		if(me==1)
		{a=8;b=4;c=7;d=5;e=9;f=5;}
		else if(me==2)
		{a=8;b=15;c=7;d=14;e=9;f=14;}
		break;
	case 17:
		if(me==1)
		{a=12;b=4;c=12;d=5;e=13;f=5;}
		else if(me==2)
		{a=12;b=15;c=12;d=14;e=13;f=14;}
		break;
	case 19:
		if(me==1)
		{a=9;b=5;c=9;d=6;e=10;f=6;}
		else if(me==2)
		{a=9;b=14;c=9;d=13;e=10;f=13;}
	}
}

int value(int i,int j)
{
	int lweight(int i,int j);
	int l;
	int weight=0;
	if(i<=18&&i>=1&&j<=18&&j>=1)
	{
		for(l=1;l<9;l++)
			if(arr[i][j][l]==0)
			switch(l)
			{
			case 1:
				weight+=lweight(i-1,j);
				break;
			case 2:
				weight+=lweight(i-1,j+1);
				break;
			case 3:
				weight+=lweight(i,j+1);
				break;
			case 4:
				weight+=lweight(i+1,j+1);
				break;
			case 5:
				weight+=lweight(i+1,j);
				break;
			case 6:
				weight+=lweight(i+1,j-1);
				break;
			case 7:
				weight+=lweight(i,j-1);
				break;
			case 8:
				weight+=lweight(i-1,j-1);
				break;
			}
	}
	else if(i==0&&j>=1&&j<=18)
	{
		for(l=3;l<8;l++)
		if(arr[i][j][l]==0)
		switch(l)
		{
		case 3:
			weight+=lweight(i,j+1);
			break;
		case 4:
			weight+=lweight(i+1,j+1);
			break;
		case 5:
			weight+=lweight(i+1,j);
			break;
		case 6:
			weight+=lweight(i+1,j-1);
			break;
		case 7:
			weight+=lweight(i,j-1);
			break;
		}

	}
	else if(i==19&&j>=1&&j<=18)
	{
		if(arr[i][j][7]==0)
			weight+=lweight(i,j-1);
		if(arr[i][j][8]==0)
			weight+=lweight(i-1,j-1);
		if(arr[i][j][1]==0)
			weight+=lweight(i-1,j);
		if(arr[i][j][2]==0)
			weight+=lweight(i-1,j+1);
		if(arr[i][j][3]==0)
			weight+=lweight(i,j+1);
	}
	else if(j==0&&i>=1&&i<=18)
		{
			for(l=1;l<6;l++)
			if(arr[i][j][l]==0)
			switch(l)
			{
			case 1:
				weight+=lweight(i-1,j);
				break;
			case 2:
				weight+=lweight(i-1,j+1);
				break;
			case 3:
				weight+=lweight(i,j+1);
				break;
			case 4:
				weight+=lweight(i+1,j+1);
				break;
			case 5:
				weight+=lweight(i+1,j);
				break;
			}

		}
	else if(j==19&&i<=18&&i>=1)
	{
		for(l=5;l<9;l++)
			if(arr[i][j][l]==0)
			switch(l)
			{case 5:
				weight+=lweight(i+1,j);
				break;
			case 6:
				weight+=lweight(i+1,j-1);
				break;
			case 7:
				weight+=lweight(i,j-1);
				break;
			case 8:
				weight+=lweight(i-1,j-1);
				break;
			}
		if(arr[i][j][1]==0)
			weight+=lweight(i-1,j);
	}
	else if(i==0&&j==0)
	{if(arr[i][j][3]==0)
		weight+=lweight(i,j+1);
	if(arr[i][j][4]==0)
			weight+=lweight(i+1,j+1);
	if(arr[i][j][5]==0)
			weight+=lweight(i+1,j);
	}
	else if(i==0&&j==19)
	{if(arr[i][j][5]==0)
		weight+=lweight(i+1,j);
	if(arr[i][j][6]==0)
			weight+=lweight(i+1,j-1);
	if(arr[i][j][7]==0)
			weight+=lweight(i,j-1);
	}
	else if(i==19&&j==0)
	{if(arr[i][j][1]==0)
		weight+=lweight(i-1,j);
	if(arr[i][j][2]==0)
			weight+=lweight(i-1,j+1);
	if(arr[i][j][3]==0)
			weight+=lweight(i,j+1);
	}
	else if(i==19&&j==19)
	{if(arr[i][j][7]==0)
		weight+=lweight(i,j-1);
	if(arr[i][j][8]==0)
			weight+=lweight(i-1,j-1);
	if(arr[i][j][1]==0)
			weight+=lweight(i-1,j);
	}
	return weight;
}

int lweight(int i,int j)
{
	int weight;
	switch(arr[i][j][0])
			{
			case 0:
				weight=10;
				break;
			case 1:
				weight=9;
				break;
			case 2:
				weight=11;
				break;
			case 3:
				weight=8;
				break;
			case 4:
				weight=8;
				break;
			case 5:
				weight=7;
				break;
			case 6:
				weight=7;
				break;
			}
	return weight;
}

void leafselect(int* base,int cnt)
{
	void leavesselect(int i,int j);
	int value(int i,int j);
	int i, j=(cnt-1),i1,j1,i2,j2,weight1,weight2;

	i1=(*base); base++; j1=(*base); base++;
	for(i=0;i<j;i++)
	 {if(i!=(j-1))
	  {i2=(*base); base++; j2=(*base); base++;}
	  else {i2=(*base); base++; j2=(*base);}

	  weight1=value(i1,j1);
	  weight2=value(i2,j2);
	  if(weight2>weight1)
	  {i1=i2; j1=j2;}
	 }
	leavesselect(i1, j1);
}

void leavesselect(int i,int j)
{
	a=i;
	b=j;
	int x,y,z,tempnum,temp1;
	void cdbranch(int m,int n,int dir);
	void efbranch(int m,int n,int dir);
	int lweight(int i,int j);
	if(i<=18&&i>=1&&j>=1&&j<=18)
	{
		int temp[8]={0,0,0,0,0,0,0,0},tempsort[8]={0,0,0,0,0,0,0,0};
		for(x=1;x<9;x++)
		if(arr[i][j][x]==0)
			{switch(x)
			{
			case 1:
				temp[x-1]=lweight(i-1,j);
				tempsort[x-1]=lweight(i-1,j);
				break;
			case 2:
				temp[x-1]=lweight(i-1,j+1);
				tempsort[x-1]=lweight(i-1,j+1);
				break;
			case 3:
				temp[x-1]=lweight(i,j+1);
				tempsort[x-1]=lweight(i,j+1);
				break;
			case 4:
				temp[x-1]=lweight(i+1,j+1);
				tempsort[x-1]=lweight(i+1,j+1);
				break;
			case 5:
				temp[x-1]=lweight(i+1,j);
				tempsort[x-1]=lweight(i+1,j);
				break;
			case 6:
				temp[x-1]=lweight(i+1,j-1);
				tempsort[x-1]=lweight(i+1,j-1);
				break;
			case 7:
				temp[x-1]=lweight(i,j-1);
				tempsort[x-1]=lweight(i,j-1);
				break;
			case 8:
				temp[x-1]=lweight(i-1,j-1);
				tempsort[x-1]=lweight(i-1,j-1);
				break;
			}
			}

		for(y=7;0<y;y--)
		 for(z=0;z<y;z++)
		 if(tempsort[z]<tempsort[z+1])
		 {tempnum=tempsort[z]; tempsort[z]=tempsort[z+1]; tempsort[z+1]=tempnum;}

		for(y=0;y<8;y++)
			if(tempsort[0]==temp[y])
				{cdbranch(i,j,y+1); temp1=y; break;}
		for(y=0;y<8;y++)
			if(tempsort[1]==temp[y]&&y!=temp1)
				{efbranch(i,j,y+1); break;}

	}
	else if(i=0&&j>=1&&j<=18)
	{
		int temp[5]={0,0,0,0,0},tempsort[5]={0,0,0,0,0};
				for(x=3;x<8;x++)
				if(arr[i][j][x]==0)
					{switch(x)
					{
					case 3:
						temp[x-1]=lweight(i,j+1);
						tempsort[x-1]=lweight(i,j+1);
						break;
					case 4:
						temp[x-1]=lweight(i+1,j+1);
						tempsort[x-1]=lweight(i+1,j+1);
						break;
					case 5:
						temp[x-1]=lweight(i+1,j);
						tempsort[x-1]=lweight(i+1,j);
						break;
					case 6:
						temp[x-1]=lweight(i+1,j-1);
						tempsort[x-1]=lweight(i+1,j-1);
						break;
					case 7:
						temp[x-1]=lweight(i,j-1);
						tempsort[x-1]=lweight(i,j-1);
						break;
					}}

				for(y=4;0<y;y--)
				 for(z=0;z<y;z++)
				 if(tempsort[z]<tempsort[z+1])
				 {tempnum=tempsort[z]; tempsort[z]=tempsort[z+1]; tempsort[z+1]=tempnum;}

				for(y=0;y<5;y++)
					if(tempsort[0]==temp[y])
						{cdbranch(i,j,y+3); temp1=y; break;}
				for(y=0;y<5;y++)
					if(tempsort[1]==temp[y]&&y!=temp1)
						{efbranch(i,j,y+3); break;}
	}
	else if(i=19&&j>=1&&j<=18)
	{
		int temp[5]={0,0,0,0,0},tempsort[5]={0,0,0,0,0};
				if(arr[i][j][7]==0)
					tempsort[0]=temp[0]=lweight(i,j-1);
				if(arr[i][j][8]==0)
					temp[1]=tempsort[1]=lweight(i-1,j-1);
				if(arr[i][j][1]==0)
					temp[2]=tempsort[2]=lweight(i-1,j);
				if(arr[i][j][2]==0)
					temp[3]=tempsort[3]=lweight(i-1,j+1);
				if(arr[i][j][3]==0)
					temp[4]=tempsort[4]=lweight(i,j+1);

				for(y=4;0<y;y--)
				 for(z=0;z<y;z++)
				 if(tempsort[z]<tempsort[z+1])
				 {tempnum=tempsort[z]; tempsort[z]=tempsort[z+1]; tempsort[z+1]=tempnum;}

				for(y=0;y<5;y++)
					if(tempsort[0]==temp[y])
						{
							switch(y)
							{
							case 0:
								cdbranch(i,j,7);
								temp1=y;
								break;
							case 1:
								cdbranch(i,j,8);
								temp1=y;
								break;
							case 2:
								cdbranch(i,j,1);
								temp1=y;
								break;
							case 3:
								cdbranch(i,j,2);
								temp1=y;
								break;
							case 4:
								cdbranch(i,j,3);
								temp1=y;
								break;
							}
						}
				for(y=0;y<5;y++)
					if(tempsort[1]==temp[y]&&y!=temp1)
						{switch(y)
						{
						case 0:
							efbranch(i,j,7);
							break;
						case 1:
							efbranch(i,j,8);
							break;
						case 2:
							efbranch(i,j,1);
							break;
						case 3:
							efbranch(i,j,2);
							break;
						case 4:
							efbranch(i,j,3);
							break;
						}
						}
	}
	else if(j=0&&i>=1&&i<=18)
	{
		int temp[5]={0,0,0,0,0},tempsort[5]={0,0,0,0,0};
				for(x=1;x<6;x++)
				if(arr[i][j][x]==0)
					switch(x)
					{
					case 1:
						temp[x-1]=lweight(i-1,j);
						tempsort[x-1]=lweight(i-1,j);
						break;
					case 2:
						temp[x-1]=lweight(i-1,j+1);
						tempsort[x-1]=lweight(i-1,j+1);
						break;
					case 3:
						temp[x-1]=lweight(i,j+1);
						tempsort[x-1]=lweight(i,j+1);
						break;
					case 4:
						temp[x-1]=lweight(i+1,j+1);
						tempsort[x-1]=lweight(i+1,j+1);
						break;
					case 5:
						temp[x-1]=lweight(i+1,j);
						tempsort[x-1]=lweight(i+1,j);
						break;
					}

				for(y=4;0<y;y--)
				 for(z=0;z<y;z++)
				 if(tempsort[z]<tempsort[z+1])
				 {tempnum=tempsort[z]; tempsort[z]=tempsort[z+1]; tempsort[z+1]=tempnum;}

				for(y=0;y<5;y++)
					if(tempsort[0]==temp[y])
						{cdbranch(i,j,y+1); temp1=y; break;}
				for(y=0;y<5;y++)
					if(tempsort[1]==temp[y]&&y!=temp1)
						{efbranch(i,j,y+1); break;}
	}
	else if(j=19&&i>=1&&i<=18)
	{
		int temp[5]={0,0,0,0,0},tempsort[5]={0,0,0,0,0};
				if(arr[i][j][5]==0)
					tempsort[0]=temp[0]=lweight(i,j-1);
				if(arr[i][j][6]==0)
					temp[1]=tempsort[1]=lweight(i-1,j-1);
				if(arr[i][j][7]==0)
					temp[2]=tempsort[2]=lweight(i-1,j);
				if(arr[i][j][8]==0)
					temp[3]=tempsort[3]=lweight(i-1,j+1);
				if(arr[i][j][1]==0)
					temp[4]=tempsort[4]=lweight(i,j+1);

				for(y=4;0<y;y--)
				 for(z=0;z<y;z++)
				 if(tempsort[z]<tempsort[z+1])
				 {tempnum=tempsort[z]; tempsort[z]=tempsort[z+1]; tempsort[z+1]=tempnum;}

				for(y=0;y<5;y++)
					if(tempsort[0]==temp[y])
						{
							switch(y)
							{
							case 0:
								cdbranch(i,j,5);
								temp1=y;
								break;
							case 1:
								cdbranch(i,j,6);
								temp1=y;
								break;
							case 2:
								cdbranch(i,j,7);
								temp1=y;
								break;
							case 3:
								cdbranch(i,j,8);
								temp1=y;
								break;
							case 4:
								cdbranch(i,j,1);
								temp1=y;
								break;
							}
						}
				for(y=0;y<5;y++)
					if(tempsort[1]==temp[y]&&y!=temp1)
						{switch(y)
						{
						case 0:
							efbranch(i,j,5);
							break;
						case 1:
							efbranch(i,j,6);
							break;
						case 2:
							efbranch(i,j,7);
							break;
						case 3:
							efbranch(i,j,8);
							break;
						case 4:
							efbranch(i,j,1);
							break;
						}
						}
	}
	else if(i==0&&j==0)
	{
		if(arr[i][j][3]==1)
		{
			cdbranch(i,j,4); efbranch(i,j,5);
		}
		else if(arr[i][j][4]==1)
		{
			cdbranch(i,j,3); efbranch(i,j,5);
		}
		else
		{
			cdbranch(i,j,3); efbranch(i,j,4);
		}

	}
	else if(i==19&&j==0)
	{
		if(arr[i][j][1]==1)
	{
		cdbranch(i,j,2); efbranch(i,j,3);
	}
	else if(arr[i][j][2]==1)
	{
		cdbranch(i,j,1); efbranch(i,j,3);
	}
	else
	{
		cdbranch(i,j,1); efbranch(i,j,2);
	}
	}
	else if(i==0&&j==19)
	{
		if(arr[i][j][5]==1)
				{
					cdbranch(i,j,6); efbranch(i,j,7);
				}
				else if(arr[i][j][6]==1)
				{
					cdbranch(i,j,5); efbranch(i,j,7);
				}
				else
				{
					cdbranch(i,j,5); efbranch(i,j,6);
				}

	}
	else if(i==19&&j==19)
	{if(arr[i][j][1]==1)
	{
		cdbranch(i,j,7); efbranch(i,j,8);
	}
	else if(arr[i][j][7]==1)
	{
		cdbranch(i,j,1); efbranch(i,j,8);
	}
	else
	{
		cdbranch(i,j,1); efbranch(i,j,7);
	}

	}
}

void cdbranch(int m,int n,int dir)
{
	switch(dir)
	{
	case 1:
		c=m-1;d=n;
		break;
	case 2:
		c=m-1;d=n+1;
		break;
	case 3:
		c=m;d=n+1;
		break;
	case 4:
		c=m+1;d=n+1;
		break;
	case 5:
		c=m+1;d=n;
		break;
	case 6:
		c=m+1;d=n-1;
		break;
	case 7:
		c=m;d=n-1;
		break;
	case 8:
		c=m-1;d=n-1;
		break;
	}
}
void efbranch(int m,int n,int dir)
{
	switch(dir)
	{
	case 1:
		e=m-1;f=n;
		break;
	case 2:
		e=m-1;f=n+1;
		break;
	case 3:
		e=m;f=n+1;
		break;
	case 4:
		e=m+1;f=n+1;
		break;
	case 5:
		e=m+1;f=n;
		break;
	case 6:
		e=m+1;f=n-1;
		break;
	case 7:
		e=m;f=n-1;
		break;
	case 8:
		e=m-1;f=n-1;
		break;
	}
}
