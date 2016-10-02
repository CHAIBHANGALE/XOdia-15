#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<time.h>
char array[20][20][9];
char nodesNLeafs[20][20];
struct Node {
	int r, c;
} myLeafs[400];
int noMyLeafs = 0;
int firstCol;
void
printAsString()
{
	int i,j,k;
	printf("\n");
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<9;k++)
			{
				printf("%c",array[i][j][k]);
			}

		}
	}
	printf("\n");
}

struct Node dirCode[9] = { {0,0}, {-1, 0}, {-1, 1}, {0, 1}, {1,1}, {1,0},{1,-1},{0,-1},{-1,-1}};
struct Node forwardDir[8] = { {1,1}, {-1,1},{0,1},{-1,0},{1,0},{-1,-1},{1,-1},{0,-1}};
struct Node reverseDir[8] = { {1,-1}, {-1,-1},{0,-1},{1,0},{-1,0},{-1,1},{1,1},{0,1}};
struct Node *currDir;


int 
isAnEdge(int i1, int j1, int i2, int j2)
{
	int k;
	for(k = 1; k < 9; k++ )
	{
		if (array[i2][j2][k] != '0')
		{
			if ( i2 + dirCode[k].r == i1 && j2 + dirCode[k].c == j1 ) return 1;
		}
	}
	return 0;
}
void 
Exit()
{
	//printAsString();
	exit(0);
}
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

shuffleDirs()
{
	int n = 8;
	
	while ( n > 0 )
	{
		int i;
		i = rand() % n;
		struct Node temp;
		copyNode(&temp , &currDir[i]);
		copyNode(&currDir[i], &currDir[n-1]);
		copyNode(&currDir[n-1],&temp);
		n--;
	}
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
		n--;
	}
}
printFirstMove(int i1, int j1, int i2, int j2)
{
	int i,j;
	for (i = 0; i < 20; i++)
		for( j=0; j < 20; j++)
			switch(array[i][j][0]) {
				case '1': array[i][j][0] = '2'; break;
				case '2': array[i][j][0] = '1'; break;
				case '3': array[i][j][0] = '4'; break;
				case '4': array[i][j][0] = '3'; break;
			}
	array[i1][j1][0] = '4';
	array[i2][j2][0] = '2';
	printf("%d,%d,%d,%d\n",i1,j1,i2,j2);
}
printMove(int i1, int j1, int i2, int j2, int i3, int j3)
{
	int i,j;
	for (i = 0; i < 20; i++)
		for( j=0; j < 20; j++)
			switch(array[i][j][0]) {
				case '1': array[i][j][0] = '2'; break;
				case '2': array[i][j][0] = '1'; break;
				case '3': array[i][j][0] = '4'; break;
				case '4': array[i][j][0] = '3'; break;
			}
	array[i1][j1][0] = '4';
	array[i2][j2][0] = '2';
	array[i3][j3][0] = '2';
	printf("%d,%d,%d,%d,%d,%d\n",i1,j1,i2,j2,i3,j3);
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
				if (i == 0 && j == 0 ) continue;
				if (!validNode(cn.r + i,cn.c+j)) continue;
				if (nodesNLeafs[cn.r + i][cn.c+j] == '2') {
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
			copyNode(&la1[0], &la[0]);
		}
	}

	if (f1n == 0 ) return 0;
	int d = 0;	
	for (d = 0; d <8; d++)
	{
		i = currDir[d].r;
		j = currDir[d].c;
		struct Node cn;
		copyNode(&cn,&myLeafs[f1l]);
		if (!validNode(cn.r + i,cn.c+j)) continue;
		if (nodesNLeafs[cn.r + i][cn.c+j] == '0') {
			la1[1].r = cn.r+i;
			la1[1].c = cn.c + j;
			f1n++;
			goto done;
		}
	}
	for (d = 0; d <8; d++)
	{
		i = currDir[d].r;
		j = currDir[d].c;
		struct Node cn;
		copyNode(&cn,&myLeafs[f1l]);
		if (!validNode(cn.r + i,cn.c+j)) continue;
		if (isAnEdge(cn.r,cn.c, cn.r+i,cn.c+j)) continue;
		if (nodesNLeafs[cn.r + i][cn.c+j] != '2' && nodesNLeafs[cn.r + 1][cn.c+j] != '3') {
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
	printMove(cn.r,cn.c, la1[0].r,la1[1].c,la1[1].r,la1[1].c);
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
	struct Node la[2], la1[2] = {{-10, -10}, {-20,-20}};
	int f1l, f1n = 0;
	int i,j;
	int d;
	f1l = rand() % noMyLeafs; 
	for (l =0 ; l< noMyLeafs; l++ )
	{
		fn = 0;
		struct Node cn;
	        copyNode(&cn,&myLeafs[l]);
		for (d = 0; d <8; d++)
		{
			i = currDir[d].r;
			j = currDir[d].c;
			if (!validNode(cn.r + i,cn.c+j)) continue;
			if (nodesNLeafs[cn.r + i][cn.c+j] == '0') {
				fl  =l;
				la[fn].r = cn.r+i;
				la[fn].c = cn.c + j;
				fn++;
				if (fn == 2 )
				{
					f1n = fn;
					f1l = fl;
					copyNode(&la1[0], &la[0]);
					copyNode(&la1[1], &la[1]);
					goto done;
				}
			}
		}
		if ( fn == 1) {
			f1n = 1; 
			f1l = fl;
			copyNode(&la1[0],&la[0]);
		}
	}

	
	struct Node cn;
	copyNode(&cn,&myLeafs[f1l]);
	for (d = 0; d <8; d++)
	{
		i = currDir[d].r;
		j = currDir[d].c;
		if (!validNode(cn.r + i,cn.c+j)) continue;
		if (isAnEdge(cn.r,cn.c, cn.r+i,cn.c+j)) continue;
		if ( f1n == 0 || ((cn.r + i) != la1[0].r) || ((cn.c + j) != la1[0].c)) {
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
	printMove(cn.r,cn.c, la1[0].r,la1[0].c,la1[1].r,la1[1].c);
	return 1;
	}
}
int main()
{	int i,j,k;
	char s[3601];
	int firstmove = 1, oppfirstmove = 1, oppfirstcol = 19;
	scanf("%s",s);
	srand(time(NULL));
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			int sbase = i*9*20 + j*9;
			char ntype = s[sbase];
			nodesNLeafs[i][j] = ntype;
			for(k=0;k<9;k++)
			{
				array[i][j][k]=s[sbase+k];
			}
			if (ntype == '4' ) {
				oppfirstmove = 0;
				if ( j == 0 ) oppfirstcol = 0;
			}
			if (ntype == '3' ) {
				firstmove = 0;
			}
			else if (ntype == '1') {
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
		printFirstMove(9, 0 ,9 ,1);
		Exit();
	}
	if (firstmove == 1 && oppfirstmove == 0)
	{
		if (oppfirstcol == 19)
			printFirstMove(9, 0 ,9 ,1);
		else
			printFirstMove(9, 19 ,9 ,18);
		Exit();
	}

	if ( s[9*9*20] == '3') {firstCol =  0; currDir = forwardDir;}
	else {firstCol = 19;currDir = reverseDir;}

	shuffleMyLeafs();
	shuffleDirs();
	//if (canFreezeOpponent()) Exit();
	//if (moveTowardsEdge()) Exit();
	if (makeAnyValidMove()) Exit();
	
	//where (i1,j1)(i2,j2) are coordinates of the seed and leaf

	//for the rest of the moves
	//where (i1,j1) (i2,j2) (i3,j3) are coordinates of the seed and leaves
}

