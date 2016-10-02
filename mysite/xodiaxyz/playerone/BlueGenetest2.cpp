//============================================================================
// Name        : cpp.cpp
// Author      : Niranjan Ketkar
// Version     :1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "cstdio"
#include <algorithm>
#include <vector>
#include <cstring>
#include <time.h>
#include "cstdlib"

#define r 20
#define c 20

using namespace std;

vector<int>x_list,y_list,val_list;

int edge_cnt=0;


void spread_val(int array[r][c][9],int **temp_arr,int val,int x,int y)
{
	if(val>0)
	{
		for(int i=x-1;i<=x+1;++i)
		{
			for(int j=y-1;j<=y+1;++j)
			{
				if(i>=0 and i<r and j>=0 and j<c)
				{
					if(array[i][j][0]==0 and temp_arr[i][j]==-1)
					{
						temp_arr[i][j]=val;
						x_list.push_back(i);
						y_list.push_back(j);
						val_list.push_back(val-1);
					}
				}
			}
		}
	}
}

double get_priority(int array[r][c][9],int w_cnt[r][c],int h_cnt[r][c],int f_cnt[r][c],int l_cnt[r][c],int weightage[r][c],int x,int y)
{
	double priority=0;

	//cout<<"\n\nMaking priorities; x:"<<x<<"y:"<<y;
	if(array[x][y][0]==2 or array[x][y][0]==6)
	{
		priority+=8e6;
	}
	else if(array[x][y][0]==1 or array[x][y][0]==5)
	{
		if(edge_cnt>400)
		{
			priority+=1e4;
		}
		else
		{
			priority+=1e3;
		}
	}
	else if(array[x][y][0]==3 or array[x][y][0]==4)
	{
		priority+=1;
	}
	else if(array[x][y][0]==0)
	{
		if(edge_cnt>400)
		{
			priority+=1e4;
		}
		else
		{
			priority+=1e6;
		}
	}

	//cout<<"\t\t\t"<<priority;
	if(edge_cnt<=400)
	{
		if(priority<5e6)
		{
			priority+=(weightage[x][y]*5e4);
		}
		else
		{
			priority+=(weightage[x][y]*2e4);
		}
	}
	else
	{
		priority+=(weightage[x][y]*1e4);
	}
	//cout<<"\t\t\t"<<priority;

	priority+=(h_cnt[x][y]*1e6);

	//cout<<"\t\t\t"<<priority;

	if(edge_cnt<=400)
	{
		priority+=(f_cnt[x][y]*5e2);
	}
	if(edge_cnt<=400)
	{
		priority+=((10-l_cnt[x][y])*5e2);
	}
	priority+=((10-w_cnt[x][y])*5e2);

	//cout<<"\t\t\t"<<priority;


	return priority;

}



int main()
{
	char s[3600];
	cin>>s;
	int array[r][c][9];
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			for(int k=0;k<9;++k)
			{
				array[i][j][k]=((int)s[i*9*20+j*9+k])-(int)'0';
			}
		}
	}

	for(int i=0;i<c;++i)
	{
		array[0][i][8]=0;
		array[0][i][1]=0;
		array[0][i][2]=0;

		array[r-1][i][4]=0;
		array[r-1][i][5]=0;
		array[r-1][i][6]=0;
	}

	for(int i=0;i<r;++i)
	{
		array[i][0][6]=0;
		array[i][0][7]=0;
		array[i][0][8]=0;

		array[i][c-1][2]=0;
		array[i][c-1][3]=0;
		array[i][c-1][4]=0;
	}


	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			for(int k=1;k<9;++k)
			{
				if(array[i][j][k]!=0)
				{
					edge_cnt+=1;
					//cout<<i<<"\t"<<j<<endl;
				}
			}
		}
	}

	//cout<<edge_cnt<<endl;



	if(edge_cnt==0 or edge_cnt==2)
	{
		srand(time(NULL));
		int seed_node=rand()%4+9;
		printf("%d,0,%d,1",seed_node,seed_node);
	}
	else if(edge_cnt==4 or edge_cnt==8)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][1][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,1,leaf-1,2,leaf+1,2);
	}
	else if(edge_cnt==12 or edge_cnt==16)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][2][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,2,leaf-1,3,leaf-1,2);
	}
	else if(edge_cnt==20 or edge_cnt==24)
	{
		int leaf;
		for(int i=r-1;i>=0;--i)
		{
			if(array[i][2][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,2,leaf+1,3,leaf+1,2);
	}
	else if(edge_cnt==28 or edge_cnt==32)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][3][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,3,leaf+1,4,leaf-1,4);
	}
	else if(edge_cnt==36 or edge_cnt==40)
	{
		int leaf;
		for(int i=r-1;i>=0;--i)
		{
			if(array[i][3][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,3,leaf+1,4,leaf-1,4);
	}
	else if(edge_cnt==44 or edge_cnt==48)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][4][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,4,leaf-1,5,leaf,5);
	}
	else if(edge_cnt==52 or edge_cnt==56)
	{
		int leaf;
		for(int i=r-1;i>=0;--i)
		{
			if(array[i][4][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,4,leaf+1,5,leaf,5);
	}
	else if(edge_cnt==60 or edge_cnt==64)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][5][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf+1,5,leaf,6,leaf+2,6);
	}
	else if(edge_cnt==68 or edge_cnt==72)
	{
		int leaf;
		for(int i=r;i>=0;--i)
		{
			if(array[i][5][0]==1)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf-1,5,leaf-2,6,leaf,6);
	}
	else if(edge_cnt>72)
	{



		int w_cnt[r][c],h_cnt[r][c],f_cnt[r][c],l_cnt[r][c],weightage[r][c];

		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				w_cnt[i][j]=h_cnt[i][j]=f_cnt[i][j]=l_cnt[i][j]=weightage[i][j]=0;
			}
		}



		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				if(array[i][j][0]==0)
				{
					int z,y;
					for(z=i-1;z<=i+1;++z)
					{
						for(y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<c and z>=0 and z<r)
							{
								f_cnt[z][y]+=1;
							}
						}
					}
					f_cnt[i][j]-=1;
				}
				else if(array[i][j][0]==1 or array[i][j][0]==5)
				{
					int z,y;
					for(int z=i-1;z<=i+1;++z)
					{
						for(int y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<c and z>=0 and z<r)
							{
								l_cnt[z][y]+=1;
							}
						}
					}
					l_cnt[i][j]-=1;
				}
				else if(array[i][j][0]==2 or array[i][j][0]==6)
				{
					int z,y;
					for(int z=i-2;z<=i+2;++z)
					{
						for(int y=j-2;y<=j+2;++y)
						{
							if(y>=0 and y<c and z>=0 and z<r)
							{
								h_cnt[z][y]+=1;
							}
						}
					}


					for(int z=i-1;z<=i+1;++z)
					{
						for(int y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<c and z>=0 and z<r)
							{
								h_cnt[z][y]-=1;
								w_cnt[z][y]+=1;
							}
						}
					}
					w_cnt[i][j]-=1;

					int **temp_weightage=new int*[r];
					for(int z=0;z<r;++z)
					{
						temp_weightage[z]=new int[c];
						for(int y=0;y<c;++y)
						{
							temp_weightage[z][y]=-1;
						}
					}

					temp_weightage[i][j]=0;
					x_list.clear();
					y_list.clear();
					val_list.clear();

					x_list.push_back(i);
					y_list.push_back(j);
					val_list.push_back(r);

					while(!x_list.empty())
					{
						spread_val(array,temp_weightage,val_list[0],x_list[0],y_list[0]);
						x_list.erase(x_list.begin());
						y_list.erase(y_list.begin());
						val_list.erase(val_list.begin());
					}

					for(int z=i-2;z<=i+2;++z)
					{
						for(int y=j-2;y<=j+2;++y)
						{
							if(z>=0 and y>=0 and z<r and y<c)
							{

								temp_weightage[z][y]=0;
							}
						}
					}


					for(int z=0;z<r;++z)
					{
						for(int y=0;y<c;++y)
						{
							if(temp_weightage[z][y]>=0)
							weightage[z][y]+=temp_weightage[z][y];
						}
					}

				}
			}
		}

		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				//cout<<weightage[i][j]<<"\t";
			}
			//cout<<endl;
		}
		//cout<<endl<<endl;

		vector<int>leaf_x_list,leaf_y_list;
		int max_starter_weightage=0;

		for(int i=0;i<r;++i)
		{
			for(int j=0;j<c;++j)
			{
				if(array[i][j][0]==1)
				{
					int free_edge_cnt=0;
					for(int k=1;k<9;++k)
					{
						if(array[i][j][k]!=3 or array[i][j][k]!=4)
						{
							free_edge_cnt+=1;
						}
					}
					if(free_edge_cnt>=2)
					{

						int temp_starter_weightage=w_cnt[i][j]*100+16-h_cnt[i][j];

						if(temp_starter_weightage > max_starter_weightage)
						{
							leaf_x_list.clear();
							leaf_y_list.clear();

							leaf_x_list.push_back(i);
							leaf_y_list.push_back(j);

							max_starter_weightage=temp_starter_weightage;
						}
						else if(temp_starter_weightage==max_starter_weightage)
						{
							leaf_x_list.push_back(i);
							leaf_y_list.push_back(j);
						}

					}
				}
			}
		}

		//cout<<endl<<leaf_x_list.size()<<endl;

		int fx,fy,sx,sy,parent_x,parent_y;
		double max_priority=0;


		for(int i=0;i<leaf_x_list.size();++i)
		{
			int temp_x=leaf_x_list[i],temp_y=leaf_y_list[i];
			double first_priority=0,second_priority=0;
			int fx_temp,fy_temp,sx_temp,sy_temp;
			//cout<<"\t\t\t\t\t\tProcessing on leaf node:"<<temp_x<<"\t\t\t\t"<<temp_y<<endl;

			if(array[temp_x][temp_y][1]==0)
			{
				if(temp_x-1>=0)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x-1,temp_y);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x-1;
						fy_temp=temp_y;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x-1;
						sy_temp=temp_y;
					}
				}
			}
			if(array[temp_x][temp_y][2]==0)
			{
				if(temp_x-1>=0 and temp_y+1<c)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x-1,temp_y+1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x-1;
						fy_temp=temp_y+1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x-1;
						sy_temp=temp_y+1;
					}
				}
			}
			if(array[temp_x][temp_y][3]==0)
			{
				if(temp_y+1<c)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x,temp_y+1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x;
						fy_temp=temp_y+1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x;
						sy_temp=temp_y+1;
					}
				}
			}
			if(array[temp_x][temp_y][4]==0)
			{
				if(temp_x+1<r and temp_y+1<c)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x+1,temp_y+1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x+1;
						fy_temp=temp_y+1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x+1;
						sy_temp=temp_y+1;
					}
				}
			}
			if(array[temp_x][temp_y][5]==0)
			{
				if(temp_x+1<r)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x+1,temp_y);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x+1;
						fy_temp=temp_y;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x+1;
						sy_temp=temp_y;
					}
				}
			}
			if(array[temp_x][temp_y][6]==0)
			{
				if(temp_y-1>=0 and temp_x+1<r)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x+1,temp_y-1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x+1;
						fy_temp=temp_y-1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x+1;
						sy_temp=temp_y-1;
					}
				}
			}
			if(array[temp_x][temp_y][7]==0)
			{
				if(temp_y-1>=0)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x,temp_y-1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x;
						fy_temp=temp_y-1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x;
						sy_temp=temp_y-1;
					}
				}
			}
			if(array[temp_x][temp_y][8]==0)
			{
				if(temp_x-1>=0 and temp_y-1>=0)
				{
					double temp_priority=get_priority(array,w_cnt,h_cnt,f_cnt,l_cnt,weightage,temp_x-1,temp_y-1);
					if(temp_priority>first_priority)
					{
						second_priority=first_priority;
						sx_temp=fx_temp;
						sy_temp=fy_temp;
						first_priority=temp_priority;
						fx_temp=temp_x-1;
						fy_temp=temp_y-1;
					}
					else if(temp_priority>second_priority)
					{
						second_priority=temp_priority;
						sx_temp=temp_x-1;
						sy_temp=temp_y-1;
					}
				}
			}

			//cout<<"\t\t\tThe max priority is:"<<max_priority<<"\t\t\t"<<"The current priority is:"<<first_priority+second_priority<<endl;

			if(first_priority+second_priority>=max_priority)
			{
				fx=fx_temp;
				fy=fy_temp;
				sx=sx_temp;
				sy=sy_temp;
				parent_x=temp_x;
				parent_y=temp_y;
			}
		}

		printf("%d,%d,%d,%d,%d,%d",parent_x,parent_y,fx,fy,sx,sy);

	}



	return 0;
}







