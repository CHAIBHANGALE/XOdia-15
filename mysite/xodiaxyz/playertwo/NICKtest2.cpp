#include <iostream>
#include <cstdlib>

using namespace std;
void grid_scan(char [20][20][9]);
void pass_cord(int,int,int,int );
int scan4kill(char [20][20][9],int,int,int);
int scan4merge(char [20][20][9],int,int,int);
int scan4empty(char [20][20][9],int,int,int);
int scan4threat(char [20][20][9],int,int);
int scan4node(char [20][20][9],int,int,int);

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
		for(j=0;j<1;j++)
				{
					for(i=0;i<20;i++)
					{
						//for(k=0;k<1;k++)
						//{
							v=array[i][j][0];
							if(v!='0')
							{
								grid_scan(array);
							}
							else
							{
								continue;
							}
						//}
					}
				}
		cout<<"10,0,10,1";


	return 0;
}

    void grid_scan(char array[20][20][9])
	{   int i,j,k,l,m;
		char c;
		for(j=19;j>=0;j--)
		{
			for (i=10;i<20;i++)
						{
							for(k=0;k<1;k++)
							{
								c=array[i][j][k];
								if (c=='1')
								{
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
									            					else
									            					{
									            						m=scan4node(array,i,j,l);
																		 if(m!=0)
																		 {
																			 pass_cord(i,j,l,m);
																		 }
									            					}
									            				}
									            			}
									            	}


													else
													{
														continue;
													}
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
									if (c=='1')
									{
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
										            					else
										            					{
										            						m=scan4node(array,i,j,l);
																			 if(m!=0)
																			 {
																				 pass_cord(i,j,l,m);
																			 }
										            					}
										            				}
										            			}
										            	}


														else
														{
															continue;
														}
									}
									else
									{
										continue;
									}
						}


		}
	}
		for(j=19;j>=0;j--)
				{
					for (i=10;i<20;i++)
								{
									for(k=0;k<1;k++)
									{
										c=array[i][j][k];
										if (c=='1')
										{

											l=scan4empty(array,i,j,l);
											            		if(l!=0)
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
																		else
																		{
																			m=scan4node(array,i,j,l);
																			 if(m!=0)
																			 {
																				 pass_cord(i,j,l,m);
																			 }
																		}
																	}
											            		}



															else
															{
																continue;
															}
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

											if (c=='1')
											{
												l=scan4empty(array,i,j,l);
												            		if(l!=0)
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
																			else
																			{
																				m=scan4node(array,i,j,l);
																				 if(m!=0)
																				 {
																					 pass_cord(i,j,l,m);
																				 }
																			}
																		}

												            	}


																else
																{
																	continue;
																}
										}
											else
											{
												continue;
											}
								}


				}
			}
		for(j=19;j>=0;j--)
						{
							for (i=10;i<20;i++)
										{
											for(k=0;k<1;k++)
											{
												c=array[i][j][k];
												if (c=='1')
												{
													l=scan4merge(array,i,j,l);
													            			if(l!=0)
													            			{
													            				m=scan4merge(array,i,j,l);

													            				if(m!=0)
																				{

																				 pass_cord(i,j,l,m);
																				}
																				else
																				{
																					m=scan4node(array,i,j,l);
																					 if(m!=0)
																					 {
																						 pass_cord(i,j,l,m);
																					 }
																				}
													            			}




																	else
																	{
																		continue;
																	}
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

													if (c=='1')
													{
														l=scan4merge(array,i,j,l);
														            			if(l!=0)
														            			{
														            				m=scan4merge(array,i,j,l);

														            				if(m!=0)
																					{

																					 pass_cord(i,j,l,m);
																					}
																					else
																					{
																						m=scan4node(array,i,j,l);
																						 if(m!=0)
																						 {
																							 pass_cord(i,j,l,m);
																						 }
																					}
														            			}





																		else
																		{
																			continue;
																		}
													}
													else
													{
														continue;
													}
										}


						}
					}

		for(j=19;j>=0;j--)
								{
									for (i=10;i<20;i++)
												{
													for(k=0;k<1;k++)
													{
														c=array[i][j][k];

														if (c=='1')
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




																			else
																			{
																				continue;
																			}
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

															if (c=='1')
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






																				else
																				{
																					continue;
																				}
															}
															else
															{
																continue;
															}
												}


								}
							}


	}

    int scan4kill(char array[20][20][9],int i,int j,int l)
        {
        		char c;
        		if(i==0&&j==0)
             	 {
                   c=array[i][j+1][0];
                   if(c=='2'&&l!=3)
                    {
                	   return 3;
                   	}
                    c=array[i+1][j+1][0];
                    if(c=='2'&&l!=4)
                    {
                    	return 4;
                  	}
                    c=array[i+1][j][0];
                    if(c=='2'&&l!=5)
                  	{
                    	return 5;
              		}
                    return 0;

              	}
               else if (i==0&&j==19)
                    {
						c=array[i+1][j][0];
						if(c=='2'&&l!=5)
						{
							return 5;
						}
						c=array[i+1][j-1][0];
						if(c=='2'&&l!=6)
						{
						return 6;
						}
						c=array[i][j-1][0];
						if(c=='2'&&l!=7)
						{
						return 7;
						}
						return 0;
                   }
                   else if (i==19&&j==0)
        			{   c=array[i-1][j][0];
        				if(c=='2'&&l!=1)
        				{
        				return 1;
        				}
        				c=array[i-1][j+1][0];
                    	if(c=='2'&&l!=2)
                   		{
                    		return 2;
                   		}
                    	c=array[i][j+1][0];
                    	if(c=='2'&&l!=3)
                    	{
                    		return 3;
                    	}
                    	return 0;
                    }
                    else if (i==19&&j==19)
                			{
								c=array[i][j-1][0];
								if(c=='2'&&l!=7)
								{
								return 7;
								}
								c=array[i-1][j-1][0];
								if(c=='2'&&l!=8)
								{
									return 8;
								}
								c=array[i-1][j][0];
								if(c=='2'&&l!=1)
								{
								return 1;
								}
								return 0;
                			}
                    		else if (i==0)
                    		{
                    			c=array[i][j+1][0];
								if(c=='2'&&l!=3)
								{
									return 3;
								}
								c=array[i+1][j+1][0];
								if(c=='2'&&l!=4)
								{
									return 4;
								}
								c=array[i+1][j][0];
								if(c=='2'&&l!=5)
								{
									return 5;
								}
								c=array[i+1][j-1][0];
								if(c=='2'&&l!=6)
								{
									return 6;
								}
								c=array[i][j-1][0];
								if(c=='2'&&l!=7)
								{
									return 7;
								}
								return 0;
                    		}
                    		else if (j==0)
                    		{
                    			c=array[i-1][j][0];
                    			if(c=='2'&&l!=1)
								{
									return 1;
								}
								c=array[i-1][j+1][0];
								if(c=='2'&&l!=2)
								{
									return 2;
								}
								c=array[i][j+1][0];
								if(c=='2'&&l!=3)
								{
									return 3;
								}
								c=array[i+1][j+1][0];
								if(c=='2'&&l!=4)
								{
									return 4;
								}
								c=array[i+1][j][0];
								if(c=='2'&&l!=5)
								{
									return 5;
								}
								return 0;
                    		}
                    		else if (i==19)
                    		{
                    			c=array[i-1][j][0];
								if(c=='2'&&l!=1)
								{
									return 1;
								}
								c=array[i-1][j+1][0];
								if(c=='2'&&l!=2)
								{

									return 2;
								}
								c=array[i][j+1][0];
								if(c=='2'&&l!=3)
								{
									return 3;
								}c=array[i][j-1][0];
								if(c=='2'&&l!=7)
								{
									return 7;
								}
								c=array[i-1][j-1][0];
								if(c=='2'&&l!=8)
								{
									return 8;
								}
								return 0;
                    		}
                    		else if (j==19)
                    		{
                    			c=array[i+1][j][0];
								if(c=='2'&&l!=5)
								{
									return 5;
								}
								c=array[i+1][j-1][0];
								if(c=='2'&&l!=6)
								{
									return 6;
								}
								c=array[i][j-1][0];
								if(c=='2'&&l!=7)
								{
									return 7;
								}
								c=array[i-1][j-1][0];
								if(c=='2'&&l!=8)
								{
									return 8;
								}
								c=array[i-1][j][0];
								if(c=='2'&&l!=1)
								{
									return 1;
								}
								return 0;
                    		}
                    		else
                    		{
                    			c=array[i-1][j+1][0];
        		                if(c=='2'&&l!=2)
								{
									return 2;
								}
								c=array[i][j+1][0];
								if(c=='2'&&l!=3)
								{
									return 3;
								}
								c=array[i+1][j+1][0];
									if(c=='2'&&l!=4)
								{
									return 4;
								}
								c=array[i+1][j][0];
								if(c=='2'&&l!=5)
								{
									return 5;
								}
								c=array[i+1][j-1][0];
								if(c=='2'&&l!=6)
								{
									return 6;
								}
								c=array[i][j-1][0];
								if(c=='2'&&l!=7)
								{
									return 7;
								}
								c=array[i-1][j-1][0];
								if(c=='2'&&l!=8)
								{
									return 8;
								}
								c=array[i-1][j][0];
								if(c=='2'&&l!=1)
								{
									return 1;
								}

                    		}
        		return 0 ;
        }
     int scan4empty(char array[20][20][9],int i,int j,int l)
     {		int x;
        	char c;
        	if(i==0&&j==0)
			 {
        		c=array[i][j+1][0];
        									if(c=='0'&&l!=3&&array[i][j][3]!='1')
        									{	x=scan4threat(array,i,j+1);
													if(x!=11)
												{
													return 3;
												}

        									}
        									c=array[i+1][j+1][0];
        										if(c=='0'&&l!=4&&array[i][j][4]!='1')
        									{	x=scan4threat(array,i+1,j+1);
        										if(x!=11)
        										{
        										return 4;
        										}

        									}
        									c=array[i+1][j][0];
        									if(c=='0'&&l!=5&&array[i][j][5]!='1')
        									{	x=scan4threat(array,i+1,j);
        										if(x!=11)
        										{
        											return 5;
        										}

        									}
				return 0;

			}
		   else if (i==0&&j==19)
				{
			   c=array[i+1][j][0];
			   							if(c=='0'&&l!=5&&array[i][j][5]!='1')
			   							{	x=scan4threat(array,i+1,j);
			   								if(x!=11)
			   								{
			   									return 5;
			   								}

			   							}
			   							c=array[i+1][j-1][0];
			   							if(c=='0'&&l!=6&&array[i][j][6]!='1')
			   								{	x=scan4threat(array,i+1,j-1);
			   								if(x!=11)
			   								{
			   									return 6;
			   								}

			   								}
			   							c=array[i][j-1][0];
			   							if(c=='0'&&l!=7&&array[i][j][7]!='1')
			   								{x=scan4threat(array,i,j-1);
			   								if(x!=11)
			   								{
			   									return 7;
			   								}

			   								}
					return 0;
			   }
			   else if (i==19&&j==0)
				{   c=array[i-1][j][0];
					if(c=='0'&&l!=1&&array[i][j][1]!='1')
					{
						x=scan4threat(array,i-1,j);

						if(x!=11)
						{
							return 1;
						}

					}
						c=array[i-1][j+1][0];
						if(c=='0'&&l!=2&&array[i][j][2]!='1')
						{
							x=scan4threat(array,i-1,j+1);
							if(x!=11)
							{
								return 2;
							}

						}
						c=array[i][j+1][0];
						if(c=='0'&&l!=3&&array[i][j][3]!='1')
						{	x=scan4threat(array,i,j+1);
								if(x!=11)
							{
								return 3;
							}

						}
					return 0;
				}
				else if (i==19&&j==19)
						{
					c=array[i][j-1][0];
												if(c=='0'&&l!=7&&array[i][j][7]!='1')
													{x=scan4threat(array,i,j-1);
													if(x!=11)
													{
														return 7;
													}

													}
												c=array[i-1][j-1][0];
												if(c=='0'&&l!=8&&array[i][j][8]!='1')
													{	x=scan4threat(array,i-1,j-1);
														if(x!=11)
														{
															return 8;
														}

													}
												c=array[i-1][j][0];
												if(c=='0'&&l!=1&&array[i][j][1]!='1')
												{	x=scan4threat(array,i-1,j);
													if(x!=11)
													{
														return 1;
													}

												}
							return 0;
						}
						else if (i==0)
						{
							c=array[i][j+1][0];
														if(c=='0'&&l!=3&&array[i][j][3]!='1')
														{	x=scan4threat(array,i,j+1);
															if(x!=11)
														{
															return 3;
														}

														}
														c=array[i+1][j+1][0];
															if(c=='0'&&l!=4&&array[i][j][4]!='1')
														{	x=scan4threat(array,i+1,j+1);
															if(x!=11)
															{
															return 4;
															}

														}
														c=array[i+1][j][0];
														if(c=='0'&&l!=5&&array[i][j][5]!='1')
														{	x=scan4threat(array,i+1,j);
															if(x!=11)
															{
																return 5;
															}

														}
														c=array[i+1][j-1][0];
														if(c=='0'&&l!=6&&array[i][j][6]!='1')
															{	x=scan4threat(array,i+1,j-1);
															if(x!=11)
															{
																return 6;
															}

															}
														c=array[i][j-1][0];
														if(c=='0'&&l!=7&&array[i][j][7]!='1')
															{x=scan4threat(array,i,j-1);
															if(x!=11)
															{
																return 7;
															}

															}
							return 0;
						}
						else if (j==0)
						{	c=array[i-1][j][0];
									if(c=='0'&&l!=1&&array[i][j][1]!='1')
									{	x=scan4threat(array,i-1,j);
										if(x!=11)
										{
											return 1;
										}

									}
										c=array[i-1][j+1][0];
														if(c=='0'&&l!=2&&array[i][j][2]!='1')
														{
															x=scan4threat(array,i-1,j+1);
															if(x!=11)
															{
																return 2;
															}

														}
														c=array[i][j+1][0];
														if(c=='0'&&l!=3&&array[i][j][3]!='1')
														{	x=scan4threat(array,i,j+1);
															if(x!=11)
														{
															return 3;
														}

														}
														c=array[i+1][j+1][0];
															if(c=='0'&&l!=4&&array[i][j][4]!='1')
														{	x=scan4threat(array,i+1,j+1);
															if(x!=11)
															{
															return 4;
															}

														}
														c=array[i+1][j][0];
														if(c=='0'&&l!=5&&array[i][j][5]!='1')
														{	x=scan4threat(array,i+1,j);
															if(x!=11)
															{
																return 5;
															}

														}
							return 0;
						}
						else if (i==19)
						{
							c=array[i-1][j][0];
												if(c=='0'&&l!=1&&array[i][j][1]!='1')
												{
													x=scan4threat(array,i-1,j);

													if(x!=11)
													{
														return 1;
													}

												}
													c=array[i-1][j+1][0];
													if(c=='0'&&l!=2&&array[i][j][2]!='1')
													{
														x=scan4threat(array,i-1,j+1);
														if(x!=11)
														{
															return 2;
														}

													}
													c=array[i][j+1][0];
													if(c=='0'&&l!=3&&array[i][j][3]!='1')
													{	x=scan4threat(array,i,j+1);
																if(x!=11)
															{
																return 3;
															}

													}
														c=array[i][j-1][0];
														if(c=='0'&&l!=7&&array[i][j][7]!='1')
															{x=scan4threat(array,i,j-1);
															if(x!=11)
															{
																return 7;
															}

															}
														c=array[i-1][j-1][0];
														if(c=='0'&&l!=8&&array[i][j][8]!='1')
															{	x=scan4threat(array,i-1,j-1);
																if(x!=11)
																{
																	return 8;
																}

															}
							return 0;
						}
						else if (j==19)
						{
							c=array[i+1][j][0];
														if(c=='0'&&l!=5&&array[i][j][5]!='1')
														{	x=scan4threat(array,i+1,j);
															if(x!=11)
															{
																return 5;
															}

														}
														c=array[i+1][j-1][0];
														if(c=='0'&&l!=6&&array[i][j][6]!='1')
															{	x=scan4threat(array,i+1,j-1);
															if(x!=11)
															{
																return 6;
															}

															}
														c=array[i][j-1][0];
														if(c=='0'&&l!=7&&array[i][j][7]!='1')
															{x=scan4threat(array,i,j-1);
															if(x!=11)
															{
																return 7;
															}

															}
														c=array[i-1][j-1][0];
														if(c=='0'&&l!=8&&array[i][j][8]!='1')
															{	x=scan4threat(array,i-1,j-1);
																if(x!=11)
																{
																	return 8;
																}

															}
														c=array[i-1][j][0];
														if(c=='0'&&l!=1&&array[i][j][1]!='1')
														{	x=scan4threat(array,i-1,j);
															if(x!=11)
															{
																return 1;
															}

														}
							return 0;
						}
						else
						{
							c=array[i-1][j+1][0];
							if(c=='0'&&l!=2&&array[i][j][2]!='1')
							{
								x=scan4threat(array,i-1,j+1);
								if(x!=11)
								{
									return 2;
								}

							}
							c=array[i+1][j+1][0];
								if(c=='0'&&l!=4&&array[i][j][4]!='1')
							{	x=scan4threat(array,i+1,j+1);
								if(x!=11)
								{
								return 4;
								}

							}
							c=array[i][j+1][0];
							if(c=='0'&&l!=3&&array[i][j][3]!='1')
							{	x=scan4threat(array,i,j+1);
								if(x!=11)
							{
								return 3;
							}

							}

							c=array[i+1][j][0];
							if(c=='0'&&l!=5&&array[i][j][5]!='1')
							{	x=scan4threat(array,i+1,j);
								if(x!=11)
								{
									return 5;
								}

							}
							c=array[i+1][j-1][0];
							if(c=='0'&&l!=6&&array[i][j][6]!='1')
								{	x=scan4threat(array,i+1,j-1);
								if(x!=11)
								{
									return 6;
								}

								}
							c=array[i][j-1][0];
							if(c=='0'&&l!=7&&array[i][j][7]!='1')
								{x=scan4threat(array,i,j-1);
								if(x!=11)
								{
									return 7;
								}

								}
							c=array[i-1][j-1][0];
							if(c=='0'&&l!=8&&array[i][j][8]!='1')
								{	x=scan4threat(array,i-1,j-1);
									if(x!=11)
									{
										return 8;
									}

								}
							c=array[i-1][j][0];
							if(c=='0'&&l!=1&&array[i][j][1]!='1')
							{	x=scan4threat(array,i-1,j);
								if(x!=11)
								{
									return 1;
								}

							}
						}

		return 0;
     }

     int scan4threat(char array[20][20][9],int i,int j)
     {		char c;

			c=array[i-1][j+1][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i][j+1][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i+1][j+1][0];
				if(c=='2')
			{
				return 11;
			}
			c=array[i+1][j][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i+1][j-1][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i][j-1][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i-1][j-1][0];
			if(c=='2')
			{
				return 11;
			}
			c=array[i-1][j][0];
			if(c=='2')
			{
				return 11;
			}
			return 0;
		}
     int scan4merge(char array[20][20][9],int i,int j,int l)
     {	char c;
		if(i==0&&j==0)
		{
        c=array[i][j+1][0];
        if(c=='1'&&l!=3&&array[i][j][3]!='1')
         {
     	   return 3;
        	}
         c=array[i+1][j+1][0];
         if(c=='1'&&l!=4&&array[i][j][4]!='1')
         {
         	return 4;
       	}
         c=array[i+1][j][0];
         if(c=='1'&&l!=5&&array[i][j][5]!='1')
       	{
         	return 5;
   		}
         return 0;

   	}
    else if (i==0&&j==19)
         {
				c=array[i+1][j][0];
				if(c=='1'&&l!=5&&array[i][j][5]!='1')
				{
					return 5;
				}
				c=array[i+1][j-1][0];
				if(c=='1'&&l!=6&&array[i][j][6]!='1')
				{
				return 6;
				}
				c=array[i][j-1][0];
				if(c=='1'&&l!=7&&array[i][j][7]!='1')
				{
				return 7;
				}
				return 0;
        }
        else if (i==19&&j==0)
			{   c=array[i-1][j][0];
				if(c=='1'&&l!=1&&array[i][j][1]!='1')
				{
				return 1;
				}
				c=array[i-1][j+1][0];
         	if(c=='1'&&l!=2&&array[i][j][2]!='1')
        		{
         		return 2;
        		}
         	c=array[i][j+1][0];
         	if(c=='1'&&l!=3&&array[i][j][3]!='1')
         	{
         		return 3;
         	}
         	return 0;
         }
         else if (i==19&&j==19)
     			{
						c=array[i][j-1][0];
						if(c=='1'&&l!=7&&array[i][j][7]!='1')
						{
						return 7;
						}
						c=array[i-1][j-1][0];
						if(c=='1'&&l!=8&&array[i][j][8]!='1')
						{
							return 8;
						}
						c=array[i-1][j][0];
						if(c=='1'&&l!=1&&array[i][j][1]!='1')
						{
						return 1;
						}
						return 0;
     			}
         		else if (i==0)
         		{
         			c=array[i][j+1][0];
						if(c=='1'&&l!=3&&array[i][j][3]!='1')
						{
							return 3;
						}
						c=array[i+1][j+1][0];
						if(c=='1'&&l!=4&&array[i][j][4]!='1')
						{
							return 4;
						}
						c=array[i+1][j][0];
						if(c=='1'&&l!=5&&array[i][j][5]!='1')
						{
							return 5;
						}
						c=array[i+1][j-1][0];
						if(c=='1'&&l!=6&&array[i][j][6]!='1')
						{
							return 6;
						}
						c=array[i][j-1][0];
						if(c=='1'&&l!=7&&array[i][j][7]!='1')
						{
							return 7;
						}
						return 0;
         		}
         		else if (j==0)
         		{
         			c=array[i-1][j][0];
         			if(c=='1'&&l!=1&&array[i][j][1]!='1')
						{
							return 1;
						}
						c=array[i-1][j+1][0];
						if(c=='1'&&l!=2&&array[i][j][2]!='1')
						{
							return 2;
						}
						c=array[i][j+1][0];
						if(c=='1'&&l!=3&&array[i][j][3]!='1')
						{
							return 3;
						}
						c=array[i+1][j+1][0];
						if(c=='1'&&l!=4&&array[i][j][4]!='1')
						{
							return 4;
						}
						c=array[i+1][j][0];
						if(c=='1'&&l!=5&&array[i][j][5]!='1')
						{
							return 5;
						}
						return 0;
         		}
         		else if (i==19)
         		{
         			c=array[i-1][j][0];
						if(c=='1'&&l!=1&&array[i][j][1]!='1')
						{
							return 1;
						}
						c=array[i-1][j+1][0];
						if(c=='1'&&l!=2&&array[i][j][2]!='1')
						{

							return 2;
						}
						c=array[i][j+1][0];
						if(c=='1'&&l!=3&&array[i][j][3]!='1')
						{
							return 3;
						}c=array[i][j-1][0];
						if(c=='1'&&l!=7&&array[i][j][7]!='1')
						{
							return 7;
						}
						c=array[i-1][j-1][0];
						if(c=='1'&&l!=8&&array[i][j][8]!='1')
						{
							return 8;
						}
						return 0;
         		}
         		else if (j==19)
         		{
         			c=array[i+1][j][0];
						if(c=='1'&&l!=5&&array[i][j][5]!='1')
						{
							return 5;
						}
						c=array[i+1][j-1][0];
						if(c=='1'&&l!=6&&array[i][j][6]!='1')
						{
							return 6;
						}
						c=array[i][j-1][0];
						if(c=='1'&&l!=7&&array[i][j][7]!='1')
						{
							return 7;
						}
						c=array[i-1][j-1][0];
						if(c=='1'&&l!=8&&array[i][j][8]!='1')
						{
							return 8;
						}
						c=array[i-1][j][0];
						if(c=='1'&&l!=1&&array[i][j][1]!='1')
						{
							return 1;
						}
						return 0;
         		}
         		else
         		{
         			c=array[i-1][j+1][0];
		                if(c=='1'&&l!=2&&array[i][j][2]!='1')
						{
							return 2;
						}
						c=array[i][j+1][0];
						if(c=='1'&&l!=3&&array[i][j][3]!='1')
						{
							return 3;
						}
						c=array[i+1][j+1][0];
							if(c=='1'&&l!=4&&array[i][j][4]!='1')
						{
							return 4;
						}
						c=array[i+1][j][0];
						if(c=='1'&&l!=5&&array[i][j][5]!='1')
						{
							return 5;
						}
						c=array[i+1][j-1][0];
						if(c=='1'&&l!=6&&array[i][j][6]!='1')
						{
							return 6;
						}
						c=array[i][j-1][0];
						if(c=='1'&&l!=7&&array[i][j][7]!='1')
						{
							return 7;
						}
						c=array[i-1][j-1][0];
						if(c=='1'&&l!=8&&array[i][j][8]!='1')
						{
							return 8;
						}
						c=array[i-1][j][0];
						if(c=='1'&&l!=1&&array[i][j][1]!='1')
						{
							return 1;
						}

         		}
		return 0 ;
     }
     int scan4node(char array[20][20][9],int i,int j,int l)
          {	char c;
     		if(i==0&&j==0)
       	 {
             c=array[i][j+1][0];
             if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
              {
          	   return 3;
             	}
              c=array[i+1][j+1][0];
              if((c=='3'||c=='4')&&l!=4&&array[i][j][4]!='1')
              {
              	return 4;
            	}
              c=array[i+1][j][0];
              if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
            	{
              	return 5;
        		}
              return 0;

        	}
         else if (i==0&&j==19)
              {
     				c=array[i+1][j][0];
     				if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
     				{
     					return 5;
     				}
     				c=array[i+1][j-1][0];
     				if((c=='3'||c=='4')&&l!=6&&array[i][j][6]!='1')
     				{
     				return 6;
     				}
     				c=array[i][j-1][0];
     				if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     				{
     				return 7;
     				}
     				return 0;
             }
             else if (i==19&&j==0)
     			{   c=array[i-1][j][0];
     				if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     				{
     				return 1;
     				}
     				c=array[i-1][j+1][0];
              	if((c=='3'||c=='4')&&l!=2&&array[i][j][2]!='1')
             		{
              		return 2;
             		}
              	c=array[i][j+1][0];
              	if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
              	{
              		return 3;
              	}
              	return 0;
              }
              else if (i==19&&j==19)
          			{
     						c=array[i][j-1][0];
     						if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     						{
     						return 7;
     						}
     						c=array[i-1][j-1][0];
     						if((c=='3'||c=='4')&&l!=8&&array[i][j][8]!='1')
     						{
     							return 8;
     						}
     						c=array[i-1][j][0];
     						if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     						{
     						return 1;
     						}
     						return 0;
          			}
              		else if (i==0)
              		{
              			c=array[i][j+1][0];
     						if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
     						{
     							return 3;
     						}
     						c=array[i+1][j+1][0];
     						if((c=='3'||c=='4')&&l!=4&&array[i][j][4]!='1')
     						{
     							return 4;
     						}
     						c=array[i+1][j][0];
     						if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
     						{
     							return 5;
     						}
     						c=array[i+1][j-1][0];
     						if((c=='3'||c=='4')&&l!=6&&array[i][j][6]!='1')
     						{
     							return 6;
     						}
     						c=array[i][j-1][0];
     						if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     						{
     							return 7;
     						}
     						return 0;
              		}
              		else if (j==0)
              		{
              			c=array[i-1][j][0];
              			if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     						{
     							return 1;
     						}
     						c=array[i-1][j+1][0];
     						if((c=='3'||c=='4')&&l!=2&&array[i][j][2]!='1')
     						{
     							return 2;
     						}
     						c=array[i][j+1][0];
     						if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
     						{
     							return 3;
     						}
     						c=array[i+1][j+1][0];
     						if((c=='3'||c=='4')&&l!=4&&array[i][j][4]!='1')
     						{
     							return 4;
     						}
     						c=array[i+1][j][0];
     						if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
     						{
     							return 5;
     						}
     						return 0;
              		}
              		else if (i==19)
              		{
              			c=array[i-1][j][0];
     						if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     						{
     							return 1;
     						}
     						c=array[i-1][j+1][0];
     						if((c=='3'||c=='4')&&l!=2&&array[i][j][2]!='1')
     						{

     							return 2;
     						}
     						c=array[i][j+1][0];
     						if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
     						{
     							return 3;
     						}c=array[i][j-1][0];
     						if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     						{
     							return 7;
     						}
     						c=array[i-1][j-1][0];
     						if((c=='3'||c=='4')&&l!=8&&array[i][j][8]!='1')
     						{
     							return 8;
     						}
     						return 0;
              		}
              		else if (j==19)
              		{
              			c=array[i+1][j][0];
     						if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
     						{
     							return 5;
     						}
     						c=array[i+1][j-1][0];
     						if((c=='3'||c=='4')&&l!=6&&array[i][j][6]!='1')
     						{
     							return 6;
     						}
     						c=array[i][j-1][0];
     						if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     						{
     							return 7;
     						}
     						c=array[i-1][j-1][0];
     						if((c=='3'||c=='4')&&l!=8&&array[i][j][8]!='1')
     						{
     							return 8;
     						}
     						c=array[i-1][j][0];
     						if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     						{
     							return 1;
     						}
     						return 0;
              		}
              		else
              		{
              			c=array[i-1][j+1][0];
     		                if((c=='3'||c=='4')&&l!=2&&array[i][j][2]!='1')
     						{
     							return 2;
     						}
     						c=array[i][j+1][0];
     						if((c=='3'||c=='4')&&l!=3&&array[i][j][3]!='1')
     						{
     							return 3;
     						}
     						c=array[i+1][j+1][0];
     							if((c=='3'||c=='4')&&l!=4&&array[i][j][4]!='1')
     						{
     							return 4;
     						}
     						c=array[i+1][j][0];
     						if((c=='3'||c=='4')&&l!=5&&array[i][j][5]!='1')
     						{
     							return 5;
     						}
     						c=array[i+1][j-1][0];
     						if((c=='3'||c=='4')&&l!=6&&array[i][j][6]!='1')
     						{
     							return 6;
     						}
     						c=array[i][j-1][0];
     						if((c=='3'||c=='4')&&l!=7&&array[i][j][7]!='1')
     						{
     							return 7;
     						}
     						c=array[i-1][j-1][0];
     						if((c=='3'||c=='4')&&l!=8&&array[i][j][8]!='1')
     						{
     							return 8;
     						}
     						c=array[i-1][j][0];
     						if((c=='3'||c=='4')&&l!=1&&array[i][j][1]!='1')
     						{
     							return 1;
     						}

              		}
     		return 0 ;
          }


     void pass_cord(int i,int j,int l,int m)
             {
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


            	}



