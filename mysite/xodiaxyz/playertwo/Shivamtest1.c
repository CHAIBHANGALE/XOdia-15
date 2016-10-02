#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
char array[20][20][9];
char nodesNLeafs[20][20];
struct Node {
	int r, c;
} myLeafs[400];
int noMyLeafs = 0;
int i1,j1,i2,j2,i3,j3;
int firstCol;
int
validNode (int r, int c)
{
	return r >=0 && r < 20 && c >=0 && c < 20 ;

}
copyNode( struct Node *t, struct Node *s)
{
	t->r = s->r;
	t->c = s->c;
}

shuffleMyLeafs()
{
	int n = noMyLeafs;
	
	while ( n > 0 )
	{
		int i;
		i = rand() % n;
		struct Node temp;
		copyNode(&temp , &myLeafs[i]);
		copyNode(&myLeafs[i], &myLeafs[n-1]);
		copyNode(&myLeafs[n-1],&temp);
	}
}
printMove()
{
	printf("%d,%d,%d,%d,%d,%d",i1,j1,i2,j2,i3,j3);
}

int 
canFreezeOpponent()
{
	int l;
	int fl, fn = 0;
	struct Node la[2], la1[2];
	int f1l, f1n = 0;
	int i,j;
	for (l =0 ; l< noMyLeafs; l++ )
	{
		fn = 0;
		struct Node cn;
	        copyNode(&cn,&myLeafs[l]);
		for ( i = -1; i <=1; i++)
			for (j = -1; j <= 1;  j++) {
				if (!validNode(cn.r + i,cn.c+j)) continue;
				if (nodesNLeafs[cn.r + i][cn.c+j] == 2) {
					fl  =l;
					la[fn].r = cn.r+i;
					la[fn].c = cn.c + j;
					fn++;
					if (fn == 2 )
					{
						f1n = fn;
						f1l = fl;
						memcpy(&la1, &la, sizeof (struct Node) * fn );
						goto done;
					}
				}
			}
		if ( fn == 1) {
			f1n = 1; 
			f1l = fl;
			la1[0] = la[0];
		}
	}

	if (f1n == 0 ) return 0;
	
	for ( i = -1; i <=1; i++)
		for (j = -1; j <= 1;  j++) {
			struct Node cn;
			copyNode(&cn,&myLeafs[f1l]);
			if (!validNode(cn.r + i,cn.c+j)) continue;
			if (nodesNLeafs[cn.r + i][cn.c+j] == 0) {
				la1[1].r = cn.r+i;
				la1[1].c = cn.c + j;
				f1n++;
				goto done;
			}
		}
	for ( i = -1; i <=1; i++)
		for (j = -1; j <= 1;  j++) {
			struct Node cn;
			copyNode(&cn,&myLeafs[f1l]);
			if (!validNode(cn.r + i,cn.c+j)) continue;
			if (nodesNLeafs[cn.r + i][cn.c+j] != 2 && nodesNLeafs[cn.r + 1][cn.c+j] != 3) {
				la1[1].r = cn.r+i;
				la1[1].c = cn.c + j;
				f1n++;
				goto done;
			}
		}
done :
	{
	struct Node cn;
	copyNode(&cn,&myLeafs[f1l]);
	printf("%d,%d,%d,%d,%d,%d",cn.r,cn.c, la1[0].r,la1[1].c,la1[1].r,la1[1].c);
	return 1;
	}
}
	
int
moveTowardsEdge()
{
	return 0;
}
makeAnyValidMove()
{
	int l;
	int fl, fn = 0;
	struct Node la[2], la1[2];
	int f1l, f1n = 0;
	int i,j;
	for (l =0 ; l< noMyLeafs; l++ )
	{
		fn = 0;
		struct Node cn;
	        copyNode(&cn,&myLeafs[l]);
		for ( i = -1; i <=1; i++)
			for (j = -1; j <= 1;  j++) {
				if (!validNode(cn.r + i,cn.c+j)) continue;
				if (nodesNLeafs[cn.r + i][cn.c+j] == 0) {
					fl  =l;
					la[fn].r = cn.r+i;
					la[fn].c = cn.c + j;
					fn++;
					if (fn == 2 )
					{
						f1n = fn;
						f1l = fl;
						memcpy(&la1, &la, sizeof (struct Node) * fn );
						goto done;
					}
				}
			}
		if ( fn == 1) {
			f1n = 1; 
			f1l = fl;
			la1[0] = la[0];
		}
	}

	
	for ( i = -1; i <=1; i++)
		for (j = -1; j <= 1;  j++) {
			struct Node cn;
			copyNode(&cn,&myLeafs[f1l]);
			if (!validNode(cn.r + i,cn.c+j)) continue;
			if (nodesNLeafs[cn.r + i][cn.c+j] != 3  && ( f1n == 0 || cn.r + i != la1[0].r || cn.c + j != la1[0].c)) {
				la1[f1n].r = cn.r+i;
				la1[f1n].c = cn.c + j;
				f1n++;
				if (f1n == 2 )
					goto done;
			}
		}
done :
	{
	struct Node cn;
        copyNode(&cn, &myLeafs[f1l]);
	printf("%d,%d,%d,%d,%d,%d",cn.r,cn.c, la1[0].r,la1[1].c,la1[1].r,la1[1].c);
	return 1;
	}
}
int main()
{	int i,j,k;
	char s[3601];
	int firstmove = 1, oppfirstmove = 1, oppfirstcol = 19;
	scanf("%s",s);
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			int sbase = i*9*20 + j*9;
			int ntype = s[sbase];
			nodesNLeafs[i][j] = ntype;
			for(k=0;k<9;k++)
			{
				array[i][j][k]=s[sbase+k];
			}
			if (ntype == 4 ) {
				oppfirstmove = 0;
				if ( j == 0 ) oppfirstcol = 0;
			}
			if (ntype == 3 ) {
				firstmove = 0;
			}
			else if (ntype == 1) {
				myLeafs[noMyLeafs].r = i;
				myLeafs[noMyLeafs].c = j;
				noMyLeafs++;
			}

		}
	}
				
	//your code to grow

	//for first move
	if (firstmove == 1 && oppfirstmove == 1)
	{
		printf("%d,%d,%d,%d",9, 0 ,9 ,1);
		exit(0);
	}
	if (firstmove == 1 && oppfirstmove == 0)
	{
		if (oppfirstcol == 19)
			printf("%d,%d,%d,%d",9, 0 ,9 ,1);
		else
			printf("%d,%d,%d,%d",9, 19 ,9 ,18);
		exit(0);
	}

	if ( s[9*9*20] == 3) firstCol =  0;
	else firstCol = 19;

	shuffleMyLeafs();
	if (canFreezeOpponent()) exit(0);
	if (moveTowardsEdge()) exit(0);
	if (makeAnyValidMove()) exit(0);
	
	//where (i1,j1)(i2,j2) are coordinates of the seed and leaf

	//for the rest of the moves
	//where (i1,j1) (i2,j2) (i3,j3) are coordinates of the seed and leaves
}
