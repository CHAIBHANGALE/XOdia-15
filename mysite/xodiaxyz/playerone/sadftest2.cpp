    //ALL HAIL MEGATRON

using namespace std;

#include<bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

char mat[20][20][9];

int kill()
{
	int ix[2],iy[2],flag=0,i,j;
	fl(i,0,20)
	{
		fl(j,0,20)
		{
			if(mat[i][j][0]=='1')
			{
				if(flag<2 && i>0 && mat[i-1][j][0]=='2')
				{
					ix[flag] = i-1;	iy[flag++] = j;
					//flag++;
				}
				if(flag<2 && i>0 && j>0 && mat[i-1][j-1][0]=='2')
				{
					ix[flag] = i-1;	iy[flag++] = j-1;
				}
				if(flag<2 && i<19 && j>0 && mat[i+1][j-1][0]=='2')
				{
					ix[flag] = i+1;	iy[flag++] = j-1;
				}
				if(flag<2 && i<19 && mat[i+1][j][0]=='2')
				{
					ix[flag] = i+1;	iy[flag++] = j;
				}
				if(flag<2 && j>0 && mat[i][j-1][0]=='2')
				{
					ix[flag] = i;	iy[flag++] = j-1;
				}
				if(flag<2 && j<19 && mat[i][j+1][0]=='2')
				{
					ix[flag] = i;	iy[flag++] = j+1;
				}
				if(flag<2 && i>0 && j<19 && mat[i-1][j+1][0]=='2')
				{
					ix[flag] = i-1;	iy[flag++] = j+1;
				}
				if(flag<2 && j<19 && i<19 && mat[i+1][j+1][0]=='2')
				{
					ix[flag] = i+1;	iy[flag++] = j+1;
				}

				if(flag>1)
				{
					cout<<i<<","<<j<<","<<ix[0]<<","<<iy[0]<<","<<ix[1]<<","<<iy[1];
					return 1;
				}
				else
				flag = 0;			
			}
		}
	}
	return 0;
}

int main()
{
	string s;
	cin>>s;
	int i,j,k,flag=1;
	FILE *fp;
	fl(i,0,20)
	{
		fl(j,0,20)
		{
			fl(k,0,9)
			{
				mat[i][j][k] = s[i*9*20 + j*9 + k];
			}
		}
	}


	//CHECKING IF FIRST MOVE
	fl(i,0,20)
	{
		fl(j,0,20)
		{
			if(mat[i][j][0]!='0')
			{
				flag = 0;
				break;
			}
		}
	}

	if(flag)	//FIRST MOVE
	{
		cout<<"8,0,9,0";
		fp = fopen("l.txt","w");
		fprintf(fp,"0 0");
	}
	else
	{
		int i1,i2,j1,j2,f2=0;
		int ix[2], iy[2];
		fp = fopen("l.txt","r");

		int x,y;
		fscanf(fp,"%d%d",&x,&y);
		fclose(fp);
		y++;

		if(y<20)
		{
			if(x==0)
			{
				fl(i,0,20)
				{
					fl(j,0,20)
					{
						if(mat[i][j][0]=='1' && i>0)
						{	
							cout<<i<<","<<j<<","<<i-1<<","<<j+1<<","<<i+1<<","<<j+1;
							fp = fopen("l.txt","w");
							fprintf(fp,"1 %d",y);
							fclose(fp);
							return 0;
						}
					}
				}
				x = 1;
			}
			if(x==1)
			{
				rev(i,19,0)
				{
					rev(j,19,0)
					{
						if(mat[i][j][0]=='1' && i<19)
						{	
							cout<<i<<","<<j<<","<<i+1<<","<<j+1<<","<<i-1<<","<<j+1;
							fp = fopen("l.txt","w");
							fprintf(fp,"0 %d",y);
							fclose(fp);
							return 0;
						}
					}
				}
			}
		}
		else
		{
			if(kill())
				return 0;
			int i1,i2,j1,j2,f2=0;
			int ix[2], iy[2];

			rev(i,19,0)
			{
				rev(j,19,0)
				{
					if(mat[i][j][0]=='1')
					{
						i1 = i; j1 = j;
						if(flag<2 && i>0 && mat[i-1][j][0]!='3' && mat[i-1][j][0]!='4')
						{
							ix[flag] = i-1;	iy[flag++] = j;
							//flag++;
						}
						else if(flag<2 && i>0 && j>0 && mat[i-1][j-1][0]!='3' && mat[i-1][j-1][0]!='4')
						{
							ix[flag] = i-1;	iy[flag++] = j-1;
						}
						else if(flag<2 && i<19 && j>0 && mat[i+1][j-1][0]!='3' && mat[i+1][j-1][0]!='4')
						{
							ix[flag] = i+1;	iy[flag++] = j-1;
						}
						else if(flag<2 && i<19 && mat[i+1][j][0]!='3' && mat[i+1][j][0]!='4')
						{
							ix[flag] = i+1;	iy[flag++] = j;
						}
						else if(flag<2 && j>0 && mat[i][j-1][0]!='3' && mat[i][j-1][0]!='4')
						{
							ix[flag] = i;	iy[flag++] = j-1;
						}

						if(flag<2 && i1<19 && j1<19 && mat[i1+1][j1+1][0]!='3' && mat[i1+1][j1+1][0]!='4')
						{
							ix[flag] = i1+1;	iy[flag++] = j1+1;
						}
						if(flag<2 && i1>0 && j1<19 && mat[i1-1][j1+1][0]!='3' && mat[i1-1][j1+1][0]!='4')
						{
							ix[flag] = i1-1;	iy[flag++] = j1+1;
						}
						if(flag<2 && j1<19 && mat[i1][j1+1][0]!='3' && mat[i1][j1+1][0]!='4')
						{
							ix[flag] = i1;	iy[flag++] = j1+1;
						}
						if(flag>1)
						{
							cout<<i<<","<<j<<","<<ix[0]<<","<<iy[0]<<","<<ix[1]<<","<<iy[1];
							return 0;
						}
						else
							flag = 0;
					}
					
				}
			}
			flag = 0;

			rev(i,19,0)
			{
				rev(j,19,0)
				{
					if(mat[i][j][0]=='1')
					{
						i1 = i; j1 = j;
						if(flag<2 && i>0 && mat[i-1][j][0]!='3' && mat[i-1][j][0]!='4')
						{
							ix[flag] = i-1;	iy[flag++] = j;
							//flag++;
						}
						if(flag<2 && i>0 && j>0 && mat[i-1][j-1][0]!='3' && mat[i-1][j-1][0]!='4')
						{
							ix[flag] = i-1;	iy[flag++] = j-1;
						}
						if(flag<2 && i<19 && j>0 && mat[i+1][j-1][0]!='3' && mat[i+1][j-1][0]!='4')
						{
							ix[flag] = i+1;	iy[flag++] = j-1;
						}
						if(flag<2 && i<19 && mat[i+1][j][0]!='3' && mat[i+1][j][0]!='4')
						{
							ix[flag] = i+1;	iy[flag++] = j;
						}
						if(flag<2 && j>0 && mat[i][j-1][0]!='3' && mat[i][j-1][0]!='4')
						{
							ix[flag] = i;	iy[flag++] = j-1;
						}
						if(flag>1)
						{
							cout<<i<<","<<j<<","<<ix[0]<<","<<iy[0]<<","<<ix[1]<<","<<iy[1];
							return 0;
						}
						else
							flag = 0;
					}
					
				}
			}
			

			flag=0;
			if(flag<2 && i1<19 && j1<19 && mat[i1+1][j1+1][0]!='3' && mat[i1+1][j1+1][0]!='4')
			{
				ix[flag] = i1+1;	iy[flag++] = j1+1;
			}
			if(flag<2 && i1>0 && j1<19 && mat[i1-1][j1+1][0]!='3' && mat[i1-1][j1+1][0]!='4')
			{
				ix[flag] = i1-1;	iy[flag++] = j1+1;
			}
			if(flag<2 && j1<19 && mat[i1][j1+1][0]!='3' && mat[i1][j1+1][0]!='4')
			{
				ix[flag] = i1;	iy[flag++] = j1+1;
			}
			cout<<i1<<","<<j1<<","<<ix[0]<<","<<iy[0]<<","<<ix[1]<<","<<iy[1];
		}
	}
	return 0;
}