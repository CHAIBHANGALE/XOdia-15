#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{	int i,j,k;
	char s[3600];
	cin>>s;
	char array[20][20][9];
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<9;k++)
			{
				array[i][j][k]=s[i*9*20+j*9+k];
			}
		}
	}
	int i1,j1,i2,j2;
	//your code to grow
	bool first=true;
	for(int i=0;i<20;i++)
	{
		if(array[i][0][0]!='0')
		{
			first=false;
			break;
		}
	}
	if(first) //For first move
	{
		cout<<"19,0,18,1";
	}
	else //for rest
	{
		int leafs[400][2];
		int leaf_count=0;
		for(int i=19;i>-1;i--)
		{
			for(int j=19;j>-1;j--)
			{
				if(array[i][j][0]=='1')
				{
					leafs[leaf_count][0]=i;
					leafs[leaf_count][1]=j;
					leaf_count++;
				}
			}
		}
		int best[400][2];
		int best_count=0;
		for(int i=0;i<leaf_count;i++)
		{
			int x,y;
			x=leafs[i][0];
			y=leafs[i][1];
			int opponent=0;
			if(x+1<20 && array[x+1][y][0]=='2')
				opponent++;
			if(y+1<20 && array[x][y+1][0]=='2')
				opponent++;
			if(x-1>=0 && array[x-1][y][0]=='2')
				opponent++;
			if(y-1>=0 && array[x][y-1][0]=='2')
				opponent++;
			if(x+1<20 && y+1<20 && array[x+1][y+1][0]=='2')
				opponent++;
			if(x-1>-1 && y-1>-1 && array[x-1][y-1][0]=='2')
				opponent++;
			if(x+1<20 && y-1>-1 && array[x+1][y-1][0]=='2')
				opponent++;
			if(x-1>-1 && y+1<20 && array[x-1][y+1][0]=='2')
				opponent++;
			if(opponent>0)
			{
				best[best_count][0]=x;
				best[best_count][1]=y;
				best_count++;
			}
		}
		if(best_count>0) //move to block opponents leaf
		{
			int valid_moves[9]={-1};
			int x,y,p2[2],p3[2];
			x=best[0][0];
			y=best[0][1];
			if(x+1<20 && array[x+1][y][0]=='2') //5
				valid_moves[5]=1;
			if(y+1<20 && array[x][y+1][0]=='2') //3
				valid_moves[3]=1;
			if(x-1>=0 && array[x-1][y][0]=='2') //1
				valid_moves[1]=1;
			if(y-1>=0 && array[x][y-1][0]=='2') //7
				valid_moves[7]=1;
			if(x+1<20 && y+1<20 && array[x+1][y+1][0]=='2') //4
				valid_moves[4]=1;
			if(x-1>-1 && y-1>-1 && array[x-1][y-1][0]=='2') //8
				valid_moves[8]=1;
			if(x+1<20 && y-1>-1 && array[x+1][y-1][0]=='2') //6
				valid_moves[6]=1;
			if(x-1>-1 && y+1<20 && array[x-1][y+1][0]=='2') //2
				valid_moves[2]=1;
			int temp1=0;
			for(int i=1;i<9;i++)
			{
				if(valid_moves[i]==1)
					temp1++;
			}
			if(temp1<2)
			{
				if(x+1<20) //5
				{
					valid_moves[5]=1;
					goto done;
				}
				if(y+1<20) //3
				{
					valid_moves[3]=1;
					goto done;
				}	
				if(x-1>=0) //1
				{
					valid_moves[1]=1;
					goto done;
				}	
				if(y-1>=0) //7
				{
					valid_moves[7]=1;
					goto done;
				}	
				if(x+1<20 && y+1<20) //4
				{
					valid_moves[4]=1;
					goto done;
				}	
				if(x-1>-1 && y-1>-1) //8
				{
					valid_moves[8]=1;
					goto done;
				}	
				if(x+1<20 && y-1>-1) //6
				{
					valid_moves[6]=1;
					goto done;
				}	
				if(x-1>-1 && y+1<20) //2
					valid_moves[2]=1;
			}
			done:
			int valid_count=0;
			for(int i=1;i<9;i++)
			{
				if(valid_moves[i]!=-1)
					valid_count++;
			}
			int dir[2];
			int dir_got_count=0;
			for(int i=1;i<9;i++)
			{
				if(valid_moves[i]!=-1)
				{
					int direction=i;
					if(array[x][y][direction]=='0') //no branch
					{
						if(dir_got_count<2)
						{
							dir[dir_got_count]=direction;
							dir_got_count++;
						}
						else
							break;
					}
				}
			}
			//for p2
			int temp=dir[0];
			if(temp==1)
			{
				p2[0]=x-1;
				p2[1]=y;
			}
			else if(temp==2)
			{
				p2[0]=x-1;
				p2[1]=y+1;
			}
			else if(temp==3)
			{
				p2[0]=x;
				p2[1]=y+1;
			}
			else if(temp==4)
			{			
				p2[0]=x+1;
				p2[1]=y+1;

			}
			else if(temp==5)
			{
				p2[0]=x+1;
				p2[1]=y;
			}
			else if(temp==6)
			{
				p2[0]=x+1;
				p2[1]=y-1;
			}
			else if(temp==7)
			{
				p2[0]=x;
				p2[1]=y-1;
			}
			else
			{
				p2[0]=x-1;
				p2[1]=y-1;
			}
			temp=dir[1];
			if(temp==1)
			{
				p3[0]=x-1;
				p3[1]=y;
			}
			else if(temp==2)
			{
				p3[0]=x-1;
				p3[1]=y+1;
			}
			else if(temp==3)
			{
				p3[0]=x;
				p3[1]=y+1;
			}
			else if(temp==4)
			{			
				p3[0]=x+1;
				p3[1]=y+1;

			}
			else if(temp==5)
			{
				p3[0]=x+1;
				p3[1]=y;
			}
			else if(temp==6)
			{
				p3[0]=x+1;
				p3[1]=y-1;
			}
			else if(temp==7)
			{
				p3[0]=x;
				p3[1]=y-1;
			}
			else
			{
				p3[0]=x-1;
				p3[1]=y-1;
			}
			cout<<x<<","<<y<<","<<p2[0]<<","<<p2[1]<<","<<p3[0]<<","<<p3[1];

		}
		else //normal leaf
		{
			int valid_moves[9]={-1};
			int x,y,p2[2],p3[2];
			x=leafs[0][0];
			y=leafs[0][1];
			if(x+1<20) //5
				valid_moves[5]=1;
			if(y+1<20) //3
				valid_moves[3]=1;
			if(x-1>=0) //1
				valid_moves[1]=1;
			if(y-1>=0) //7
				valid_moves[7]=1;
			if(x+1<20 && y+1<20) //4
				valid_moves[4]=1;
			if(x-1>-1 && y-1>-1) //8
				valid_moves[8]=1;
			if(x+1<20 && y-1>-1) //6
				valid_moves[6]=1;
			if(x-1>-1 && y+1<20) //2
				valid_moves[2]=1;
			int valid_count=0;
			for(int i=1;i<9;i++)
			{
				if(valid_moves[i]!=-1)
					valid_count++;
			}
			int dir[2];
			int dir_got_count=0;
			for(int i=1;i<9;i++)
			{
				if(valid_moves[i]!=-1)
				{
					int direction=i;
					if(array[x][y][direction]=='0') //no branch
					{
						if(dir_got_count<2)
						{
							dir[dir_got_count]=direction;
							dir_got_count++;
						}
						else
							break;
					}
				}
			}
			//for p2
			int temp=dir[0];
			if(temp==1)
			{
				p2[0]=x-1;
				p2[1]=y;
			}
			else if(temp==2)
			{
				p2[0]=x-1;
				p2[1]=y+1;
			}
			else if(temp==3)
			{
				p2[0]=x;
				p2[1]=y+1;
			}
			else if(temp==4)
			{			
				p2[0]=x+1;
				p2[1]=y+1;

			}
			else if(temp==5)
			{
				p2[0]=x+1;
				p2[1]=y;
			}
			else if(temp==6)
			{
				p2[0]=x+1;
				p2[1]=y-1;
			}
			else if(temp==7)
			{
				p2[0]=x;
				p2[1]=y-1;
			}
			else
			{
				p2[0]=x-1;
				p2[1]=y-1;
			}
			temp=dir[1];
			if(temp==1)
			{
				p3[0]=x-1;
				p3[1]=y;
			}
			else if(temp==2)
			{
				p3[0]=x-1;
				p3[1]=y+1;
			}
			else if(temp==3)
			{
				p3[0]=x;
				p3[1]=y+1;
			}
			else if(temp==4)
			{			
				p3[0]=x+1;
				p3[1]=y+1;

			}
			else if(temp==5)
			{
				p3[0]=x+1;
				p3[1]=y;
			}
			else if(temp==6)
			{
				p3[0]=x+1;
				p3[1]=y-1;
			}
			else if(temp==7)
			{
				p3[0]=x;
				p3[1]=y-1;
			}
			else
			{
				p3[0]=x-1;
				p3[1]=y-1;
			}
			cout<<x<<","<<y<<","<<p2[0]<<","<<p2[1]<<","<<p3[0]<<","<<p3[1];
		}	
	}
	return 0;
}
