#include<bits/stdc++.h>
using namespace std;

char barr[20][20][9];

int dx[]={-1,-1,-1,0,0,+1,+1,+1};
int dy[]={-1,0,+1,-1,+1,-1,0,+1};

vector<vector<string> > inp;

int safe(int a, int b, vector<vector<string> > v)
{
    if(a>19 || b>19 || a<0 || b<0)
        return 0;
    if(v[a][b][0]=='0' || v[a][b][0]=='1')
        return 1;
    return 0;
}

int count1;

int poo(int x, int y, int c, int d, vector<vector<string> > v, bool flag)
{
    //return 1;
	count1++;
	if(count1>=10)
		return 0;
	char leaf = char(flag+'1');
	int ans=0;
	if(flag)
	{
		ans = -1;
	}
	else
		ans = 1000000;
	int i=x, j=y;
    if(v[i][j][0]==leaf)
    {
        for(int k=0; k<8; k++)
        {
            int a=i+dx[k], b=j+dy[k];
            
            for(int l=0; l<8; l++)
            {
                if(l==k)
                    continue;
                int c=i+dx[l], d=j+dy[l];
                
                if(!safe(a,b,v) || !safe(c,d,v))
                    continue;
                
                v[i][j][0]=char(flag*2 + '2');
                if(flag==0)
                	v[i][j][0] = '3';
                else
                	v[i][j][0] = '4';
                char t1=v[a][b][0];
                char t2=v[c][d][0];
                v[a][b][0]='1';
                v[c][d][0]='1';
                int ret=poo(a, b,c,d,v, !flag);
                
                if(!flag && ret<ans)
                {
                    ans=ret;
                }
                else if(flag)
                {
                	ans = max(ans, ret);
                }

                if(flag==0)
                	v[i][j][0] = '1';
                else
                	v[i][j][0] = '2';
                v[a][b][0]=t1;
                v[c][d][0]=t2;
            }
        }
    }

        /*------------------------------*/
    i=x, j=y;

    if(v[i][j][0]==leaf)
    {
        for(int k=0; k<8; k++)
        {
            int a=i+dx[k], b=j+dy[k];
            
            for(int l=0; l<8; l++)
            {
                if(l==k)
                    continue;
                int c=i+dx[l], d=j+dy[l];
                
                if(!safe(a,b,v) || !safe(c,d,v))
                    continue;
                
                v[i][j][0]=char(flag*2 + '2');
                if(flag==0)
                	v[i][j][0] = '3';
                else
                	v[i][j][0] = '4';
                char t1=v[a][b][0];
                char t2=v[c][d][0];
                v[a][b][0]='1';
                v[c][d][0]='1';
                int ret=poo(a, b,c,d,v, !flag);
                
                if(!flag && ret<ans)
                {
                    ans=ret;
                }
                else if(flag)
                {
                	ans = max(ans, ret);
                }

                if(flag==0)
                	v[i][j][0] = '1';
                else
                	v[i][j][0] = '2';
                v[a][b][0]=t1;
                v[c][d][0]=t2;
            }
        }

       }

        return ans;
}






int main()
{  
    
	int i,j,k;
     string s;
     cin>>s;
     
      for(i=0;i<20;i++)
     {
       for(j=0;j<20;j++)
       {
         for(k=0;k<9;k++)
          {
           barr[i][j][k]=s[i*9*20+j*9+k];
         }
       }
     }
 
    string temp;
    int flag=0;
    int i1 = 0, j1 = 0, i2 =1, j2 = 1;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            if(barr[i][j][0]=='1')
            {
                flag=1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
    {
        cout<<"0,0,1,1";
        return 0;
        cout<<i1<<","<<j1<<","<<i2<<","<<j2;
        return 0;
    }
    
    for(int i=0;i<20;i++)
    {
        vector<string> vt;
        vt.clear();
    	for(int j=0;j<20;j++)
    	{
    		string temp="";
    		for(int k=0;k<9;k++)
    			temp += barr[i][j][k];
    		vt.push_back(temp);
    	}
    	inp.push_back(vt);
    }
    
    //return 0;
  //where (i1,j1)(i2,j2) are coordinates of the seed and leaf
     int maxx=-1; 
     int fx, fx1, fx2, fy, fy1, fy2;
     
     //cout<<0<<","<<1<<","<<1<<","<<1<<","<<1<<","<<0;
     //return 0;
     
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(inp[i][j][0]=='1')
            {
                
                for(int k=0; k<8; k++)
                {
                    int a=i+dx[k], b=j+dy[k];
                    
                    for(int l=0; l<8; l++)
                    {
                        if(l==k)
                            continue;
                        int c=i+dx[l], d=j+dy[l];
                        
                        if(!safe(a,b,inp) || !safe(c,d,inp))
                            continue;
                            
                        
                        
                        inp[i][j][0]='3';
                        char t1=inp[a][b][0];
                        char t2=inp[c][d][0];
                        inp[a][b][0]='1';
                        inp[c][d][0]='1';
                        int ret=poo(a,b,c,d,inp,1);
                        
                        if(ret>maxx)
                        {
                            fx=i;
                            fy=j;
                            fx1=a;
                            fy1=b;
                            fx2=c;
                            fy2=d;
                            maxx=ret;
                        }
                        
                        inp[i][j][0]='1';
                        inp[a][b][0]=t1;
                        inp[c][d][0]=t2;
                    }
                }
            }
        }
        
        //cout<<0<<","<<1<<","<<1<<","<<1<<","<<1<<","<<0;
        //                    return 0;
        
        
        //cout<<0<<","<<1<<","<<1<<","<<1<<","<<1<<","<<0;
        
        cout<<fx<<","<<fy<<","<<fx1<<","<<fy1<<","<<fx2<<","<<fy2<<"\n";

        return 0;
       
    }
    return 0;
  //where (i1,j2)(i2,j2)(i3,j3) are coordinates of the seed and leaves

}
