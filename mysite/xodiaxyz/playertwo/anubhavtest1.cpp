#include<iostream>
using namespace std;

int num(char ch)
{
    return ch-'0';
}

int opp(int n)
{
    switch(n)
    {
        case 1: return 5;
        case 2: return 6;
        case 3: return 7;
        case 4: return 8;
        case 5: return 1;
        case 6: return 2;
        case 7: return 3;
        case 8: return 4;
    }
}

pair<int,int> printleaf(int i,int j,int n)
{
    pair<int,int> pii;
    switch(n)
    {
        case 1: pii.first = i-1;
                pii.second = j;
                break;
        case 2: pii.first = i-1;
                pii.second = j+1;
                break;
        case 3: pii.first = i;
                pii.second = j+1;
                break;
        case 4: pii.first = i+1;
                pii.second = j+1;
                break;
        case 5: pii.first = i+1;
                pii.second = j;
                break;
        case 6: pii.first = i+1;
                pii.second = j-1;
                break;
        case 7: pii.first = i;
                pii.second = j-1;
                break;
        case 8: pii.first = i-1;
                pii.second = j-1;
                break;
    }
    return pii;
}

bool checkValidity(char array[20][20][9],int i,int j,int n1,int n2)
{
    if(n1 == n2) return 0;

    pair<int,int> pii = printleaf(i,j,n1);
    if(pii.first < 0 || pii.first >19) return 0;
    if(pii.second < 0 || pii.second >19) return 0;
    if(array[pii.first][pii.second][opp(n1)] == '1') return 0;

    pii = printleaf(i,j,n2);
    if(pii.first < 0 || pii.first >19) return 0;
    if(pii.second < 0 || pii.second >19) return 0;
    if(array[pii.first][pii.second][opp(n1)] == '1') return 0;

    return 1;
}

int calculateScore(char array[20][20][9],int i,int j,int n1,int n2)
{
    return 1;
}

int main()
{
    int i,j,k,n1,n2;
    char s[3600];
    cin>>s;
    char array[20][20][9];
    for(i=0;i<20;i++)
        for(j=0;j<20;j++)
            for(k=0;k<9;k++)
                array[i][j][k]=s[i*9*20+j*9+k];
    bool firstmove = 1;
    for(i=0;i<20;++i)
    {
        for(j=0;j<20;++j)
        {
            if(num(array[i][j][0])%2 == 1)
                firstmove = 0;
        }
    }
    if(firstmove)
    {
        bool p1 = 1;
        for(i=0;i<20;++i)
        {
            for(j=0;j<20;++j)
            {
                if(num(array[i][j][0]) > 0)
                {
                    p1 = 0;
                }
            }
        }
        if(p1)
        {
            cout << "10,0,10,1";
        }
        else
        {
            cout << "10,19,10,18";
        }
    }
    else
    {
        int fi,fj,fn1,fn2, maxScore = -1;
        for(i=0;i<20;++i)
        {
            for(j=0;j<20;++j)
            {
                if(array[i][j][0] == '1')
                {
                    for(n1 = 1; n1 < 9; ++n1)
                    {
                        for(n2 = 1; n2 < 9; ++n2)
                        {
                            bool valid = checkValidity(array, i,j,n1,n2);
                            if(valid)
                            {
                                int score = calculateScore(array, i, j, n1, n2);
                                if(score > maxScore)
                                {
                                    maxScore = score;
                                    fi = i;
                                    fj = j;
                                    fn1 = n1;
                                    fn2 = n2;
                                }
                            }
                        } // end of n2 loop
                    } // end of n1 loop
                } // end of if to check leaf
            } // end of j loop
        } // end of i loop
    cout << fi << "," <<fj << ",";
    pair<int,int> pii;
    pii = printleaf(fi,fj,fn1);
    //cout << fn1 << "," << fn1<< ",";
    cout << pii.first << "," << pii.second << ",";
    pii = printleaf(fi,fj,fn2);
    //cout << fn2 << "," << fn2;
    cout << pii.first << "," << pii.second;
    } // end of else
} // end of program

