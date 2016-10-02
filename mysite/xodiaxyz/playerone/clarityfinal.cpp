#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	node(){
	p=n=w=e=s=ne=nw=se=sw=0;
	}
	int p;
	bool n,w,e,s,ne,nw,se,sw;
	
	void accept(string sp)
	{
		p = sp[0]- '0';
		n = sp[1]- '0';
		ne = sp[2] - '0';
		e = sp[3] - '0';
		se = sp[4] - '0';
		s = sp[5] - '0';
		sw = sp[6] - '0';
		w = sp[7] -'0';
		nw = sp[8] - '0';
	}
};

node myarray[20][20];

bool nokill(int i,int j)
{
	if( myarray[i][j].p == 1 or myarray[i][j].p == 3 or myarray[i][j].p == 4 )
		return false;
	if( (i+i<20 and j-1>=0 and myarray[i+1][j-1].p == 2) or 
		(i+1<20 and myarray[i+1][j].p == 2) or
		(i+1<20 and j+1<20 and myarray[i+1][j+1].p == 2) or
		(j+1<20 and myarray[i][j+1].p == 2) or
		(i-1>=0 and j+1<20 and myarray[i-1][j+1].p == 2) or
		(i-1>=0 and myarray[i-1][j].p == 2) or
		(i-1>=0 and j-1>=0 and myarray[i-1][j-1].p == 2) or
		(j-1>=0 and myarray[i][j-1].p == 2)
	  )
		return false;
	return true;
}

int main()
{
	string s;
	bool first = true;
	vector < pair<int,int> > me;
	vector < pair<int,int> > to;
	char c;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			s = "";
			for(int k=0;k<9;k++)
			{
				c = getchar();
				while(c<'0' or c>'9'){c=getchar();}
				s+=c;
				if(c!='0')
					first = false;
			}
			myarray[i][j].accept(s);
			if(myarray[i][j].p == 1)
				me.push_back(make_pair(j,i));
			else if(myarray[i][j].p == 2)
				to.push_back(make_pair(j,i));
		}
	}
	if (first or me.empty())
	{
		if(!to.empty())
		{
			if(to[0].second>10)
			{cout<<"16,0,17,0";goto end;}
			else
				{cout<<"0,0,1,1"; goto end;}
		}
		cout<<"10,0,11,0";
		goto end;
	}
	else
	{
	
		sort(me.begin(),me.end());
		sort(to.begin(),to.end());
	
		int mei = me.size()-1;
		int toi = 0;
		int i,j;
		int ni1=-1,nj1=-1,ni2=-1,nj2=-1;
		int count;
		while(mei >= 0)
		{
			i = me[mei].second;
			j = me[mei].first;
			count = 0;
			
			ni1=-1,nj1=-1,ni2=-1,nj2=-1;
			//////////////////////////////
			/* Best kill move: */
			//////////////////////////////
			
			//ne
			if(i-1 >=0 and j+1 >= 0 and myarray[i-1][j+1].p == 2 and myarray[i][j].ne != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j+1;
				}
				else{
					ni2 = i-1;	nj2 = j+1; 
				}
				count++;
			}
			//e
			if( count<2 and myarray[i][j+1].p == 2 and myarray[i][j].e != 1)
			{
				if(count==0)
				{
					ni1 = i;	nj1 = j+1;
				}
				else{
					ni2 = i;	nj2 = j+1; 
				}
				count++;
			}
			//se
			if( count<2 and i+1 <20 and j+1<20 and myarray[i+1][j+1].p == 2 and myarray[i][j].se != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j+1;
				}
				else{
					ni2 = i+1;	nj2 = j+1; 
				}
				count++;
			}
			//s
			if( count<2 and i+1<20 and myarray[i+1][j].p == 2 and myarray[i][j].s != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j;
				}
				else{
					ni2 = i+1;	nj2 = j; 
				}
				count++;
			}
			//sw
			if( count<2 and i+1<20 and j-1>=0 and myarray[i+1][j-1].p == 2 and myarray[i][j].sw != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j-1;
				}
				else{
					ni2 = i+1;	nj2 = j-1; 
				}
				count++;
			}
			//w
			if( count<2 and j-1>=0 and myarray[i][j-1].p == 2 and myarray[i][j].w != 1)
			{
				if(count==0)
				{
					ni1 = i;	nj1 = j-1;
				}
				else{
					ni2 = i;	nj2 = j-1; 
				}
				count++;
			}
			//nw
			if( count<2 and j-1 >= 20 and i-1 >= 20 and myarray[i-1][j-1].p == 2 and myarray[i][j].nw != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j-1;
				}
				else{
					ni2 = i-1;	nj2 = j-1; 
				}
				count++;
			}
			//n
			if( count<2 and i-1>=0 and myarray[i-1][j].p == 2 and myarray[i][j].n != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j;
				}
				else{
					ni2 = i-1;	nj2 = j; 
				}
				count++;
			}

			if(count == 2 and me.size()>1 )
			{
				cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
				goto end;
				break;
			}
			
			//////////////////////////////
			/* Best kill move end  */
			//////////////////////////////
			mei--;
		}


		mei = me.size()-1;
		while(mei >= 0)
		{
			i = me[mei].second;
			j = me[mei].first;
			count = 0;
			
			ni1=-1,nj1=-1,ni2=-1,nj2=-1;
			//////////////////////////////
			/* second Best kill move: */
			//////////////////////////////
			
			//ne
			if(i-1 >=0 and j+1 >= 0 and myarray[i-1][j+1].p == 2 and myarray[i][j].ne != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j+1;
				}
				else{
					ni2 = i-1;	nj2 = j+1; 
				}
				count++;
			}
			//e
			if( count<2 and myarray[i][j+1].p == 2 and myarray[i][j].e != 1)
			{
				if(count==0)
				{
					ni1 = i;	nj1 = j+1;
				}
				else{
					ni2 = i;	nj2 = j+1; 
				}
				count++;
			}
			//se
			if( count<2 and i+1 <20 and j+1<20 and myarray[i+1][j+1].p == 2 and myarray[i][j].se != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j+1;
				}
				else{
					ni2 = i+1;	nj2 = j+1; 
				}
				count++;
			}
			//s
			if( count<2 and i+1<20 and myarray[i+1][j].p == 2 and myarray[i][j].s != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j;
				}
				else{
					ni2 = i+1;	nj2 = j; 
				}
				count++;
			}
			//sw
			if( count<2 and i+1<20 and j-1>=0 and myarray[i+1][j-1].p == 2 and myarray[i][j].sw != 1)
			{
				if(count==0)
				{
					ni1 = i+1;	nj1 = j-1;
				}
				else{
					ni2 = i+1;	nj2 = j-1; 
				}
				count++;
			}
			//w
			if( count<2 and j-1>=0 and myarray[i][j-1].p == 2 and myarray[i][j].w != 1)
			{
				if(count==0)
				{
					ni1 = i;	nj1 = j-1;
				}
				else{
					ni2 = i;	nj2 = j-1; 
				}
				count++;
			}
			//nw
			if( count<2 and j-1 >= 20 and i-1 >= 20 and myarray[i-1][j-1].p == 2 and myarray[i][j].nw != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j-1;
				}
				else{
					ni2 = i-1;	nj2 = j-1; 
				}
				count++;
			}
			//n
			if( count<2 and i-1>=0 and myarray[i-1][j].p == 2 and myarray[i][j].n != 1)
			{
				if(count==0)
				{
					ni1 = i-1;	nj1 = j;
				}
				else{
					ni2 = i-1;	nj2 = j; 
				}
				count++;
			}

			if(count == 1 and me.size()>1 )
			{

				if( i-1 >= 0 and j-1>=0 and (ni1!=i-1 and nj1!=j-1) and myarray[i][j].nw ==0 and myarray[i-1][j-1].se==0 and nokill(i+1,j-1))
				{
					ni2=i-1;	nj2=j-1;					
				}
				//se
				if(ni2< 0 and i+1<20 and j+1<20 and (ni1!=i+1 and nj1!=j+1) and myarray[i][j].se ==0 and myarray[i+1][j+1].nw==0 and nokill(i+1,j+1))
				{
					ni2=i+1;	nj2=j+1;				
				}
				//s
				if( ni2<2 and i+1<20 and (ni1!= i+1 and nj1!= j) and myarray[i][j].s ==0 and myarray[i+1][j].n==0 and nokill(i+1,j))
				{
					ni2=i+1;	nj2=j;
				}
				//ne
				if( ni2<2 and i-1>=0 and j+1<20 and (ni1!=i-1 and nj1!=j+1) and myarray[i-1][j+1].sw==0 and myarray[i][j].ne ==0 and nokill(i-1,j+1))
				{
					ni2=i-1;	nj2=j+1;
				}
				//sw
				if( ni2<2 and j-1>=0 and i+1<20 and (ni1!=i+1 and nj1!=j-1) and myarray[i][j].sw ==0 and myarray[i+1][j-1].ne==0 and nokill(i+1,j-1))
				{
					ni2=i+1;	nj2=j-1;
				}
				//n
				if( ni2<2 and i-1>=0 and (ni1!=i-1 and nj1 != j) and myarray[i][j].n ==0 and myarray[i-1][j].s==0 and nokill(i-1,j))
				{
					ni2=i-1;	nj2=j;
				}
				//e
				if( ni2<2 and j+1<20 and (ni1!=i and nj1!=j+1) and myarray[i][j].e ==0 and myarray[i][j+1].w==0 and nokill(i,j+1))
				{
					ni2=i;	nj2=j+1;
				}			
				//w
				if( ni2<2 and j-1 >= 0 and (ni1!=i and nj1!=j-1) and myarray[i][j].w ==0 and myarray[i][j-1].e==0 and nokill(i,j-1))
				{
					ni2=i;	nj2=j-1;
				}
				if(ni2 > 0)
				{
					cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
					goto end;
				}
			}
			
			//////////////////////////////
			/* second Best kill move end  */
			//////////////////////////////
			mei--;
		}



		/* Normal Move */

		mei = me.size()-1;
		toi = 0;
		ni1=-1,nj1=-1,ni2=-1,nj2=-1;
		int tyachai;
		while(mei >= 0)
		{
			i = me[mei].second;
			j = me[mei].first;
			toi = 0;
			while(toi != to.size())
			{
				tyachai = to[toi].second;
				ni1=-1;ni2=-1;nj1=-1;nj2=-1;
				if(tyachai < i)
				{
					//ne
					if(i-1 >= 0 and j+1 <20 and myarray[i][j].ne!=1 and myarray[i-1][j+1].sw==0 and nokill(i-1,j+1))
					{
						ni1=i-1;	nj1=j+1;
						if(myarray[i][j].sw==1)
						{
							if(myarray[i+1][j-1].s==1)
							{
								//north
								if(ni2<0 and i-1>=0 and myarray[i][j].n!=1 and myarray[i-1][j].s==0 and nokill(i-1,j))
								{
									ni2= i-1; 	nj2= j;
								}
								//e
								if(ni2<0 and j+1<20 and myarray[i][j].e!=1 and myarray[i][j+1].w==0 and nokill(i,j+1))
								{
									ni2= i;	nj2= j+1;
								}
							}
						}
						//south
						if(ni2<0 and i+1<20 and myarray[i][j].s!=1 and myarray[i+1][j].w==0 and nokill(i+1,j))
						{
							ni2= i+1;	nj2= j;
						}
						//east
						if(ni2<0 and j+1<20 and myarray[i][j].e!=1 and myarray[i][j+1].w==0 and nokill(i,j+1))
						{
							ni2= i;	nj2= j+1;
						}
						//north
						if(ni2<0 and i-1>=0 and myarray[i][j].n!=1 and myarray[i-1][j].s==0 and nokill(i-1,j))
						{
							ni2= i-1; 	nj2= j;
						}
						//nw
						if(ni2<0 and i-1>=0 and j-1>=0 and myarray[i][j].nw!=1 and myarray[i-1][j-1].se==0 and nokill(i-1,j-1))
						{
							ni2 = i-1;	nj2=j-1;
						}
						//w
						if(ni2<0 and j-1>=0 and myarray[i][j].w!=1 and myarray[i][j-1].e==0 and nokill(i,j-1))
						{
							ni2= i;	nj2=j-1;
						}
						//se
						if(ni2<0 and i+1<20 and j+1<20 and myarray[i][j].se!=1 and myarray[i+1][j+1].nw==0 and nokill(i+1,j+1))
						{
							ni2= i+1; nj2= j+1;
						}
						//sw
						if(ni2<0 and i+1<20 and j-1>=0 and myarray[i][j].sw!=1 and myarray[i+1][j-1].ne==0 and nokill(i+1,j-1))
						{
							ni2=i+1;	nj2=j-1;
						}
						if(ni2<0)
						{
							mei--; toi++; continue;
						}
						else
						{
							cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
							goto end;
						}
					}
				}
				if(tyachai == i)
				{
					//ne
					if(i-1 >= 0 and j+1 >= 0 and myarray[i][j].ne!=1 and myarray[i-1][j+1].sw==0 and nokill(i-1,j+1))
					{
						ni1=i-1;	nj1=j+1;
						
						//se
						if(ni2<0 and i+1<20 and j+1<20 and myarray[i][j].se!=1 and myarray[i+1][j+1].nw==0 and nokill(i+1,j+1))
						{
							ni2= i+1; nj2= j+1;
						}
						//e
						if(ni2<0 and j+1<20 and myarray[i][j].e!=1 and myarray[i][j+1].w==0 and nokill(i,j+1))
						{
							ni2= i; nj2= j+1;
						}
						//n
						if(ni2<0 and i-1>=0 and myarray[i][j].n!=1 and myarray[i-1][j].s==0 and nokill(i-1,j))
						{
							ni2= i-1; nj2= j;
						}
						//s
						if(ni2<0 and i+1<20 and myarray[i][j].s!=1 and myarray[i+1][j].n==0 and nokill(i+1,j))
						{
							ni2= i+1; nj2= j;
						}

						if(ni2<0)
						{
							mei--; toi++; continue;
						}
						else
						{
							cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
							goto end;
						}
					}
				}
				if(tyachai > i)
				{
					//se
					if(i+1 < 20 and j+1<20 and myarray[i][j].se!=1 and myarray[i+1][j+1].nw ==0  and nokill(i+1,j+1))
					{
						ni1=i+1;	nj1=j+1;
						
						if(myarray[i][j].nw==1)
						{
							if(myarray[i-1][j-1].n==1)
							{
								//s
								if(ni2<0 and i+1<20 and myarray[i][j].s!=1 and myarray[i+1][j].n==0 and nokill(i+1,j))
								{
									ni2= i+1; nj2= j;
								}
								//w
								if(ni2<0 and j-1>=0 and myarray[i][j].w!=1 and myarray[i][j-1].e==0 and nokill(i,j-1))
								{
									ni2= i;	nj2=j-1;
								}
							}
						}

						//n
						if(ni2<0 and i-1>=0 and myarray[i][j].n!=1 and myarray[i-1][j].n==0 and nokill(i-1,j))
						{
							ni2= i-1; nj2= j;
						}
						//e
						if(ni2<0 and j+1<20 and myarray[i][j].e!=1 and myarray[i][j+1].w==0 and nokill(i,j+1))
						{
							ni2= i; nj2= j+1;
						}
						//s
						if(ni2<0 and i+1<20 and myarray[i][j].s!=1 and myarray[i+1][j].n==0 and nokill(i+1,j))
						{
							ni2= i+1; nj2= j;
						}
						//sw
						if(ni2<0 and i+1<20 and j-1>=0 and myarray[i][j].sw!=1 and myarray[i+1][j-1].ne==0 and nokill(i+1,j-1))
						{
							ni2=i+1;	nj2=j-1;
						}
						//ne
						if(ni2<0 and i-1 >= 0 and j+1 <20 and myarray[i][j].ne!=1 and myarray[i-1][j+1].sw==0 and nokill(i-1,j+1))
						{
							ni1=i-1;	nj1=j+1;
						}	
						//w
						if(ni2<0 and j-1>=0 and myarray[i][j].w!=1 and myarray[i][j-1].e==0 and nokill(i,j-1))
						{
							ni2= i;	nj2=j-1;
						}		
						if(ni2<0)
						{
							mei--; toi++; continue;
						}
						else
						{
							cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
							goto end;
						}
					}
				}
				toi++;
			}
			mei--;
		}

		/* Normal Move  END */

		
		mei = 0;
		while(mei != me.size())
		{
			/* I started from here onward... Alone :( */

			i = me[mei].second;
			j = me[mei].first;
			ni1=-1,nj1=-1,ni2=-1,nj2=-1;
			count = 0;
			
			//nw
			if( count<2 and i-1 >= 0 and j-1>=0 and myarray[i][j].nw ==0 and myarray[i-1][j-1].se==0)
			{
				if(count==0){ni1=i-1;	nj1=j-1;}
				else{ni2=i-1;	nj2=j-1;}
				count++;
			}
			//se
			if( count<2 and i+1<20 and j+1<20 and myarray[i][j].se ==0 and myarray[i+1][j+1].nw==0)
			{
				if(count==0){ni1=i+1;	nj1=j+1;}
				else{ni2=i+1;	nj2=j+1;}
				count++;
			}
			//s
			if( count<2 and i+1<20 and myarray[i][j].s ==0 and myarray[i+1][j].n==0)
			{
				if(count==0){ni1=i+1;	nj1=j;}
				else{ni2=i+1;	nj2=j;}
				count++;
			}
			//ne
			if( count<2 and i-1>=0 and j+1<20 and myarray[i-1][j+1].sw==0 and myarray[i][j].ne ==0 )
			{
				if(count==0){ni1=i-1;	nj1=j+1;}
				else{ni2=i-1;	nj2=j+1;}
				count++;
			}
			//sw
			if( count<2 and j-1>=0 and i+1<20 and myarray[i][j].sw ==0 and myarray[i+1][j-1].ne==0)
			{
				if(count==0){ni1=i+1;	nj1=j-1;}
				else{ni2=i+1;	nj2=j-1;}
				count++;
			}
			//n
			if( count<2 and i-1>=0 and myarray[i][j].n ==0 and myarray[i-1][j].s==0)
			{
				if(count==0){ni1=i-1;	nj1=j;}
				else{ni2=i-1;	nj2=j;}
				count++;
			}
			//e
			if( count<2 and j+1<20 and myarray[i][j].e ==0 and myarray[i][j+1].w==0)
			{
				if(count==0){ni1=i;		nj1=j+1;}
				else{ni2=i;	nj2=j+1;}
				count++;
			}			
			
			//w
			if( count<2 and j-1 >= 0 and myarray[i][j].w ==0 and myarray[i][j-1].e==0)
			{
				if(count==0){ni1=i;	nj1=j-1;}
				else{ni2=i;	nj2=j-1;}
				count++;
			}
			
			
			if(count == 2)
			{
				cout<<i<<","<<j<<","<<ni1<<","<<nj1<<","<<ni2<<","<<nj2;
				goto end;
			}
			
			mei++;
		}
	}
	
	end:
	return 0;
}