//Scaning improved
//Empty > merge
//node cacncesl
#include <iostream>
#include <cstdlib>

using namespace std;
void grid_scan(char [20][20][9]);
void check_around(char [20][20][9],int,int);
void pass_cord(int,int,int,int );
int scan4kill(char [20][20][9],int,int,int);
int scan4merge(char [20][20][9],int,int,int);
int scan4empty(char [20][20][9],int,int,int);
int scan4threat(char [20][20][9],int,int,int);
//int scan4node(char [20][20][9],int,int,int);

int main()
{
	char v;
	int i,j,k;
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
		for(i=0;i<20;i++)
				{
					for(j=0;j<20;j++)
					{
						for(k=0;k<1;k++)
						{
							v=array[i][j][k];
							if(v!='0')
							{
								grid_scan(array);
							}
							else
							{
								continue;
							}
						}
					}
				}
		cout<<"10,0,10,1";


	return 0;
}

    void grid_scan(char array[20][20][9])
	{   int i,j,k;
		char c;
		//cout<<"yep in grid scan";
		for(j=19;j>=0;j--)
		{
			for (i=10;i<20;i++)
						{
							for(k=0;k<1;k++)
							{
								c=array[i][j][k];
								//cout<<c;
								if (c=='1')
								{
									check_around(array,i,j);
								}
								else
								{
									continue;
								}
							}
						}
			for (i=9;i>=0;i--)
						{
									for(k=0;k<1;k++)
											{
												c=array[i][j][k];
												//cout<<c;
												if (c=='1')
												{
													check_around(array,i,j);
												}
												else
												{
													continue;
												}
											}
						}


		}
	}
    void check_around(char array[20][20][9],int i,int j)
        {
    		int l=0,m=0;
    		//cout<<"yep in check around";

            l=scan4kill(array,i,j,l);
            	if(l!=0)
            	{
            		m=scan4kill(array,i,j,l);
            			if(m!=0)
            			{
            				pass_cord(i,j,l,m);
            			}
            			else
            			{
            				m=scan4empty(array,i,j,l);
            				if(m!=0)
            				{
            					pass_cord(i,j,l,m);
            				}
            				else
            				{
            					m=scan4merge(array,i,j,l);
            					if(m!=0)
            					{
            					 pass_cord(i,j,l,m);
            					}
            					/*else
            					{
            						m=scan4node(array,i,j,l);
									 if(m!=0)
									 {
										 pass_cord(i,j,l,m);
									 }
            					}*/
            				}
            			}
            	}
            	else
            	{	//cout<<"entering from here";
            		l=scan4empty(array,i,j,l);
            		if(l!=0)
            		{	//cout<<"found one"<<l;
						m=scan4empty(array,i,j,l);

						if(m!=0)
						{
							pass_cord(i,j,l,m);
						}
						else
						{
							m=scan4merge(array,i,j,l);
							if(m!=0)
							{
							 pass_cord(i,j,l,m);
							}
							/*else
							{
								m=scan4node(array,i,j,l);
								 if(m!=0)
								 {
									 pass_cord(i,j,l,m);
								 }
							}*/
						}
            		}
            		else
            		{
            			l=scan4merge(array,i,j,l);
            			if(l!=0)
            			{	//cout<<"got one empty";
            				m=scan4merge(array,i,j,l);

            				if(m!=0)
							{
            					//cout<<"passing coordinates";
							 pass_cord(i,j,l,m);
							}
							/*else
							{
								m=scan4node(array,i,j,l);
								 if(m!=0)
								 {
									 pass_cord(i,j,l,m);
								 }
							}*/
            			}
            			/*else
            			{
            				l=scan4node(array,i,j,l);
            				if(l!=0)
            				{
            					m=scan4node(array,i,j,l);

								 if(m!=0)
								 {
									 pass_cord(i,j,l,m);
								 }
            				}
            			}*/
            		}
            	}
        }






    int scan4kill(char array[20][20][9],int i,int j,int l)
    {		int k,y1=0,y2=0,y3=0,y4=0,y5=0;
    		char c;
    		//cout<<"In csan for kill";
    		if(i==0&&j==0)
    		{
    			y1=1,y2=2,y3=6,y4=7,y5=8;

    		}
    		else if (i==0&&j==19)
    		{
    			y1=1,y2=2,y3=3,y4=4,y5=8;
    		}
    		else if (i==19&&j==0)
    		{
    			y1=4,y2=5,y3=6,y4=7,y5=8;
    		}
    		else if (i==19&&j==19)
			{
    			y1=2,y2=3,y3=4,y4=5,y5=6;
			}
    		else if (i==0)
    		{
    			y1=1,y2=2,y3=8,y4=0,y5=0;    		}
    		else if (j==0)
    		{
    			y1=6,y2=7,y3=8,y4=0,y5=0;
    		}
    		else if (i==19)
    		{
    			y1=4,y2=5,y3=6,y4=0,y5=0;
    		}
    		else if (j==19)
    		{
    			y1=2,y2=3,y3=4,y4=0,y5=0;
    		}
    		for(k=1;k<9;k++)
    		{	if(k==l||k==y1||k==y2||k==y3||k==y4||k==y5)
				{
					continue;
				}
    			c=array[i][j][k];
    			if(c=='2')
    			{
    				return k;

    			}
    			else
    			{
    				continue;
    			}


    		}
    		return 0;
    }

    int scan4merge(char array[20][20][9],int i,int j,int l)
    {
    	int k,y1=0,y2=0,y3=0,y4=0,y5=0;
    	char c;
    	//cout<<"in scan 4 merge";

    	if(i==0&&j==0)
    	    		{
    	    			y1=1,y2=2,y3=6,y4=7,y5=8;

    	    		}
    	    		else if (i==0&&j==19)
    	    		{
    	    			y1=1,y2=2,y3=3,y4=4,y5=8;
    	    		}
    	    		else if (i==19&&j==0)
    	    		{
    	    			y1=4,y2=5,y3=6,y4=7,y5=8;
    	    		}
    	    		else if (i==19&&j==19)
    				{
    	    			y1=2,y2=3,y3=4,y4=5,y5=6;
    				}
    	    		else if (i==0)
    	    		{
    	    			y1=1,y2=2,y3=8,y4=0,y5=0;    		}
    	    		else if (j==0)
    	    		{
    	    			y1=6,y2=7,y3=8,y4=0,y5=0;
    	    		}
    	    		else if (i==19)
    	    		{
    	    			y1=4,y2=5,y3=6,y4=0,y5=0;
    	    		}
    	    		else if (j==19)
    	    		{
    	    			y1=2,y2=3,y3=4,y4=0,y5=0;
    	    		}
    	    		for(k=1;k<9;k++)
    	    		{	if(k==l||k==y1||k==y2||k==y3||k==y4||k==y5)
    					{
    						continue;
    					}
						   c=array[i][j][k];
						   if(c=='1')
							{
							  // if(k==1)
							   return k;

							}
						   else
							{
								continue;
							}


    	}
    			return 0;
    }
    int scan4empty(char array[20][20][9],int i,int j,int l)
        {		int k,y1=0,y2=0,y3=0,y4=0,y5=0,x,y,z;
        		char c;
        		//cout<< "in scan for empty";
        		if(i==0&&j==0)
        		{
        			y1=1,y2=2,y3=6,y4=7,y5=8;

        		}
        		else if (i==0&&j==19)
        		{
        			y1=1,y2=2,y3=3,y4=4,y5=8;
        		}
        		else if (i==19&&j==0)
        		{
        			y1=4,y2=5,y3=6,y4=7,y5=8;
        		}
        		else if (i==19&&j==19)
    			{
        			y1=2,y2=3,y3=4,y4=5,y5=6;
    			}
        		else if (i==0)
        		{
        			y1=1,y2=2,y3=8,y4=0,y5=0;    		}
        		else if (j==0)
        		{
        			y1=6,y2=7,y3=8,y4=0,y5=0;
        		}
        		else if (i==19)
        		{
        			y1=4,y2=5,y3=6,y4=0,y5=0;
        		}
        		else if (j==19)
        		{
        			y1=2,y2=3,y3=4,y4=0,y5=0;
        		}
        		for(k=1;k<9;k++)
        		{	if(k==l||k==y1||k==y2||k==y3||k==y4||k==y5)
    				{
    					continue;
    				}
						c=array[i][j][k];
						if(c=='0')
						{
								if(k==1)
								{
									x=i-1;
									y=j;
								}
								else if(k==2)
								{
									x=i-1;
									y=j+1;
								}
								else if(k==3)
													{
														x=i;
														y=j+1;
													}
								else if(k==4)
													{
														x=i+1;
														y=j+1;
													}
								else if(k==5)
													{
														x=i+1;
														y=j;
													}
								else if(k==6)
													{
														x=i+1;
														y=j-1;
													}
								else if(k==7)
													{
														x=i;
														y=j-1;
													}
								else if(k==8)
													{
														x=i-1;
														y=j-1;
													}
							z=scan4threat(array,x,y,l);
							if(z==11)
							{
								return 0;
							}

							else
							{
								return k ;
							}


						}
					}
        		return 0;
        }

 int scan4threat(char array[20][20][9],int x,int y,int l)
 {

	 int k,y1=0,y2=0,y3=0,y4=0,y5=0;
    	char c;
    	//cout<< "in scan for threat";
    	if(x==0&&y==0)
    	    		{
    	    			y1=1,y2=2,y3=6,y4=7,y5=8;

    	    		}
    	    		else if (x==0&&y==19)
    	    		{
    	    			y1=1,y2=2,y3=3,y4=4,y5=8;
    	    		}
    	    		else if (x==19&&y==0)
    	    		{
    	    			y1=4,y2=5,y3=6,y4=7,y5=8;
    	    		}
    	    		else if (x==19&&y==19)
    				{
    	    			y1=2,y2=3,y3=4,y4=5,y5=6;
    				}
    	    		else if (x==0)
    	    		{
    	    			y1=1,y2=2,y3=8,y4=0,y5=0;    		}
    	    		else if (y==0)
    	    		{
    	    			y1=6,y2=7,y3=8,y4=0,y5=0;
    	    		}
    	    		else if (x==19)
    	    		{
    	    			y1=4,y2=5,y3=6,y4=0,y5=0;
    	    		}
    	    		else if (y==19)
    	    		{
    	    			y1=2,y2=3,y3=4,y4=0,y5=0;
    	    		}
    	    		for(k=1;k<9;k++)
    	    		{	if(k==l||k==y1||k==y2||k==y3||k==y4||k==y5)
    					{
    						continue;
    					}
    	    			c=array[x][y][k];
    	    			if(c=='2')
    	    			{
    	    				return 11;

    	    			}
    	    			else
    	    			{
    	    				continue;
    	    			}
    	    		}
    	return 12;
 }
 /*int scan4node(char array[20][20][9],int i,int j,int l)
 {	int k,y1=0,y2=0,y3=0,y4=0,y5=0;
	char c;
	//cout<< "in scan for node";
	if(i==0&&j==0)
	    		{
	    			y1=1,y2=2,y3=6,y4=7,y5=8;

	    		}
	    		else if (i==0&&j==19)
	    		{
	    			y1=1,y2=2,y3=3,y4=4,y5=8;
	    		}
	    		else if (i==19&&j==0)
	    		{
	    			y1=4,y2=5,y3=6,y4=7,y5=8;
	    		}
	    		else if (i==19&&j==19)
				{
	    			y1=2,y2=3,y3=4,y4=5,y5=6;
				}
	    		else if (i==0)
	    		{
	    			y1=1,y2=2,y3=8,y4=0,y5=0;    		}
	    		else if (j==0)
	    		{
	    			y1=6,y2=7,y3=8,y4=0,y5=0;
	    		}
	    		else if (i==19)
	    		{
	    			y1=4,y2=5,y3=6,y4=0,y5=0;
	    		}
	    		else if (j==19)
	    		{
	    			y1=2,y2=3,y3=4,y4=0,y5=0;
	    		}
	    		for(k=1;k<9;k++)
	    		{	if(k==l||k==y1||k==y2||k==y3||k==y4||k==y5)
					{
						continue;
									}
						c=array[i][j][k];
						if(c=='3'||c=='4')
						{return k;

						}
						else
						{
							return 0;
						}
	}
	return 0;
 }*/


    void pass_cord(int i,int j,int l,int m)
        {	//cout<< "in scan for pass cord";
        	int out_arr[6],h;
        	{	out_arr[0]=i;
        		out_arr[1]=j;
        				if(l==1)
    					{	out_arr[2]=i-1;
    					    out_arr[3]=j;
        				}
        				else if(l==2)
        				{	out_arr[2]=i-1;
    				    	out_arr[3]=j+1;
        				}
        				else if(l==3)
        				{	out_arr[2]=i;
        				 	out_arr[3]=j+1;
        				}
        				else if(l==4)
           				{	out_arr[2]=i+1;
         				 	out_arr[3]=j+1;
           				}
        				else if(l==5)
           				{	out_arr[2]=i+1;
          				 	out_arr[3]=j;
         				}
        				else if(l==6)
          				{	out_arr[2]=i+1;
           				 	out_arr[3]=j-1;
           				}
        				else if(l==7)
           				{	out_arr[2]=i;
        				 	out_arr[3]=j-1;
           				}
        				else if(l==8)
          				{	out_arr[2]=i-1;
        				 	out_arr[3]=j-1;
          				}

        									if(m==1)
        									{	out_arr[4]=i-1;
        									    out_arr[5]=j;
        				    				}
        				    				else if(m==2)
        				    				{	out_arr[4]=i-1;
        								    	out_arr[5]=j+1;
        				    				}
        				    				else if(m==3)
        				    				{	out_arr[4]=i;
        				    				 	out_arr[5]=j+1;
        				    				}
        				    				else if(m==4)
        				       				{	out_arr[4]=i+1;
        				     				 	out_arr[5]=j+1;
        				       				}
        				    				else if(m==5)
        				       				{	out_arr[4]=i+1;
        				      				 	out_arr[5]=j;
        				     				}
        				    				else if(m==6)
        				      				{	out_arr[4]=i+1;
        				       				 	out_arr[5]=j-1;
        				       				}
        				    				else if(m==7)
        				       				{	out_arr[4]=i;
        				    				 	out_arr[5]=j-1;
        				       				}
        				    				else if(m==8)
        				      				{	out_arr[4]=i-1;
        				    				 	out_arr[5]=j-1;
        				      				}
        		}
        	for(h=0;h<=4;h++)
        	{
        		cout<<out_arr[h]<<",";
        	}
        	cout<<out_arr[5];
        	exit (0);
        	//main();

       	}
