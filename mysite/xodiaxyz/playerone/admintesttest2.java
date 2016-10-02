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



void spread_val(int array[r][c][9],int **temp_arr,int val,int x,int y)
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

double get_priority(int array[r][c][9],int w_cnt[r][c],int h_cnt[r][c],int f_cnt[r][c],int l_cnt[r][c],int weightage[r][c],int x,int y)
{
	double priority=0;
	if(array[x][y][0]==2 or array[x][y][0]==6)
	{
		priority+=1e6;
	}
	else if(array[x][y][0]==1 or array[x][y][0]==5)
	{
		priority+=1e4;
	}
	else if(array[x][y][0]==3 or array[x][y][0]==4)
	{
		priority+=1;
	}
	else if(array[x][y][0]==0)
	{
		priority+=1e5;
	}
	priority+=weightage[x][y]*100;
	priority+=h_cnt[x][y]*1000;
	priority+=f_cnt[x][y];
	priority+=(10-w_cnt[x][y])*1000;


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

	int edge_cnt=0;

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


	if(edge_cnt==0)
	{
		srand(time(NULL));
		int seed_node=rand()%4+9;
		printf("%d,0,%d,1",seed_node,seed_node);
	}
	else if(edge_cnt==2)
	{
		srand(time(NULL));
		int seed_node=rand()%4+9;
		printf("%d,19,%d,18",seed_node,seed_node);
	}
	else if(edge_cnt==4)
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
	else if(edge_cnt==8)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][18][0]==2)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,18,leaf-1,17,leaf+1,17);
	}
	else if(edge_cnt==12)
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
	else if(edge_cnt==16)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][17][0]==2)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,17,leaf-1,16,leaf-1,17);
	}
	else if(edge_cnt==20)
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
	else if(edge_cnt==24)
	{
		int leaf;
		for(int i=19;i<r;--i)
		{
			if(array[i][17][0]==2)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,17,leaf+1,16,leaf+1,17);
	}
	else if(edge_cnt==28)
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
	else if(edge_cnt==32)
	{
		int leaf;
		for(int i=0;i<r;++i)
		{
			if(array[i][16][0]==2)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,16,leaf+1,15,leaf-1,15);
	}
	else if(edge_cnt==36)
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
	else if(edge_cnt==40)
	{
		int leaf;
		for(int i=r-1;i>=0;--i)
		{
			if(array[i][16][0]==2)
			{
				leaf=i;
				break;
			}
		}
		printf("%d,%d,%d,%d,%d,%d",leaf,16,leaf+1,15,leaf-1,15);
	}
	else if(edge_cnt>40)
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
					for(int z=i-1;z<=i+1;++z)
					{
						for(int y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<r and z>=0 and z<c)
							{
								f_cnt[i][j]+=1;
							}
						}
					}
					f_cnt[i][j]-=1;
				}
				else if(array[i][j][0]==1 or array[i][j][0]==5)
				{
					for(int z=i-1;z<=i+1;++z)
					{
						for(int y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<r and z>=0 and z<c)
							{
								l_cnt[i][j]+=1;
							}
						}
					}
					l_cnt[i][j]-=1;
				}
				else if(array[i][j][0]==2 or array[i][j][0]==6)
				{
					for(int z=i-2;z<=i+2;++z)
					{
						for(int y=j-2;y<=j+2;++y)
						{
							if(y>=0 and y<r and z>=0 and z<c)
							{
								h_cnt[i][j]+=1;
							}
						}
					}


					for(int z=i-1;z<=i+1;++z)
					{
						for(int y=j-1;y<=j+1;++y)
						{
							if(y>=0 and y<r and z>=0 and z<c)
							{
								h_cnt[i][j]-=1;
								w_cnt[i][j]+=1;
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
							temp_weightage[y][z]=0;
						}
					}


					for(int z=0;z<r;++z)
					{
						for(int y=0;y<c;++y)
						{
							weightage[z][y]+=temp_weightage[z][y];
						}
					}

				}
			}
		}

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
						if(array[i][j][k]==0)
						{
							free_edge_cnt+=1;
						}
					}
					if(free_edge_cnt>=2)
					{

						int temp_starter_weightage=w_cnt[i][j]*100+16-h_cnt[i][j];

						if(temp_starter_weightage>max_starter_weightage)
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

		int fx,fy,sx,sy,parent_x,parent_y;
		double max_priority=0;


		for(int i=0;i<leaf_x_list.size();++i)
		{
			int temp_x=leaf_x_list[i],temp_y=leaf_y_list[i];
			double first_priority=0,second_priority=0;
			int fx_temp,fy_temp,sx_temp,sy_temp;

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

			if(first_priority+second_priority>max_priority)
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




