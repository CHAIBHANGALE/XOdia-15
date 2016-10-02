//Author : pakhandi
//
using namespace std;

#include<bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)
#define scan(n) scanf("%d", &n)
#define scans(s) scanf("%s", s)
#define scanc(c) scanf("%c", &c)
#define scanp(f) scanf("%f", &f)
#define print(n) printf("%d\n", n)
#define prints(s) printf("%s\n", s)
#define printc(c) printf("%c\n", c)
#define printp(f) printf("%f\n", f)
#define nline printf("\n")
#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define PB push_back
#define SZ size
#define MP make_pair

string mat[20][20];

bool is_on_board(int x, int y)
{
	if(x>=0 && x<20 && y>=0 && y<20)
		return 1;
	return 0;
}

bool is_safe(int x, int y)
{
	if(mat[x][y][0]=='1' || mat[x][y][0]=='0')
		return 1;
	return 0;
}

bool can_attack(int x, int y)
{
	if(mat[x][y][0]=='2')
		return 1;
	return 0;
}

bool is_node(int x, int y)
{
	if(mat[x][y][0]=='3' || mat[x][y][0]=='4')
		return 1;
	return 0;
}

void out(int x1, int y1, int x2, int y2, int x3, int y3)
{
	cout<<x1<<","<<y1<<","<<x2<<","<<y2<<","<<x3<<","<<y3;
}
//right, right-down, down, right-up, up, left-up, left, left-down
//(0,+1) ; (+1,+1) ; (+1,0) ; (-1,+1) ; (-1,0) ; (-1,-1) ; (0,-1) ; (+1,-1);
int dx[]={0,+1,+1,-1,-1,-1,0,+1};
int dy[]={+1,+1,0,+1,0,-1,-1,-1};

int repdx[]={+1,-1,-1,-1,0,+1,0,+1};
int repdy[]={0,+1,0,-1,-1,-1,+1,+1};


int main()
{
    
	int loop1, loop2, loop3, loop4;

	int move_dec=0;

	fl(loop1, 0, 20)
	{
		fl(loop2, 0, 20)
		{
			string temp;
			fl(loop3, 0, 9)
			{
				char ch;
				cin>>ch;
				temp+=ch;
			}
			mat[loop1][loop2]=temp;
			if(mat[loop1][loop2][0]=='1')
			{
				move_dec=1;
			}
		}
	}

	//The first move
	if(move_dec==0)
	{
		cout<<"3,0,2,1";
		return 0;
	}

	//If subsequent move

	int my_occ=0;

	fl(loop1, 0, 20)
	{
		fl(loop2, 0, 20)
		{
			if(mat[loop1][loop2][0]=='1' || mat[loop1][loop2][0]=='3')
			{
				my_occ++;
			}
		}
	}
	
	if(my_occ<=2)
	{
	    cout<<"2,1,2,0,2,2";
	    return 0;
	}

	
	int his_root_x=-1;
	int his_root_y=-1;

	fl(loop2, 0, 20)
	{
		if(mat[loop2][19][0]=='4')
		{
			his_root_x=loop2;
			his_root_y=19;
			break;
		}
	}

	if(his_root_x!=-1 && his_root_y!=-1 )
	{	
		if(his_root_x<=10)
		{
			rev(loop1, 19, 0)	//col
			{
				rev(loop2, 19, 0)
				{
					if(mat[loop2][loop1][0]=='1' && my_occ<=25)
					{
						int x1=loop2+1, y1=loop1 , x2=loop2+1, y2=loop1+1;
						if(is_on_board(x1,y1) && is_on_board(x2,y2) && is_safe(x1,y1) && is_safe(x2,y2) )
						{
							out(loop2,loop1,x1,y1,x2,y2);
							return 0;
						}
					}
				}
			}
		}
		else
		{
			rev(loop1, 19, 0)	//col
			{
				rev(loop2, 19, 0)
				{
					if(mat[loop2][loop1][0]=='1' && my_occ<=35)
					{
						int x1=loop2+1, y1=loop1 , x2=loop2+1, y2=loop1+1;
						if(is_on_board(x1,y1) && is_on_board(x2,y2) && is_safe(x1,y1) && is_safe(x2,y2) )
						{
							out(loop2,loop1,x1,y1,x2,y2);
							return 0;
						}
					}
				}
			}
		}
	}	


	

	//search for a leaf node and branch
	
	fl(loop1, 0, 20)
	{
		fl(loop2, 0, 20)
		{
			if(mat[loop1][loop2][0]=='1')	//My leaf found here
			{
				fl(loop3, 0, 8)
				{
					int x1=loop1+dx[loop3], y1=loop2+dy[loop3]; 

					fl(loop4, 0 , 8)
					{
						
						int x2=loop1+repdx[loop4], y2=loop2+repdy[loop4];

						if(x1==x2 && y1==y2)
							continue;

						if( is_on_board(x1,y1) && is_on_board(x2,y2) && (( can_attack(x1,y1) && (is_safe(x2,y2)) ) || ( can_attack(x2,y2) && (is_safe(x1,y1)) ) || ( can_attack(x1,y1) && (can_attack(x2,y2)) ) ) )
						{
							out(loop1,loop2,x1,y1,x2,y2);
							return 0;
						}
					}
				}
			}
		}
	}
	
	fl(loop1, 0, 20)
	{
		fl(loop2, 0, 20)
		{
			if(mat[loop1][loop2][0]=='1')	//My leaf found here
			{
				fl(loop3, 0, 8)
				{
					int x1=loop1+dx[loop3], y1=loop2+dy[loop3];


					fl(loop4, 0 , 8)
					{
						int x2=loop1+repdx[loop4], y2=loop2+repdy[loop4];

						if(x1==x2 && y1==y2)
							continue;

						if(is_on_board(x1,y1) && is_on_board(x2,y2) && is_safe(x1,y1) && is_safe(x2,y2))
						{
							out(loop1,loop2,x1,y1,x2,y2);
							return 0;
						}
					}
				}
			}
		}
	}

	fl(loop1, 0, 20)
	{
		fl(loop2, 0, 20)
		{
			if(mat[loop1][loop2][0]=='1')	//My leaf found here
			{
				fl(loop3, 0, 8)
				{
					int x1=loop1+dx[loop3], y1=loop2+dy[loop3];


					fl(loop4, 0 , 8)
					{
						int x2=loop1+repdx[loop4], y2=loop2+repdy[loop4];

						if(x1==x2 && y1==y2)
							continue;

						if(is_on_board(x1,y1) && is_on_board(x2,y2) && is_node(x1,y1) && is_node(x2,y2))
						{
							out(loop1,loop2,x1,y1,x2,y2);
							return 0;
						}
					}
				}
			}
		}
	}


	return 1;

}