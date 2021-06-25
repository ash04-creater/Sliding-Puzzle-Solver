#include<bits/stdc++.h>
#include"solvability.h"
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
lli power(lli x, int y){x=x%mod; if(x==0)return 0;lli res = 1;
while(y>0){ if(y%2) res = (res*x)%mod; y = y/2; x = (x*x)%mod;}return res;}
#define N 3

struct Node{

    int **scramble;

    pair<int,int> blank;
}puzzle;

int pos[N*N][2]; int Hash[N][N][N*N];

int moves[100];

int bound; int solved;

int direcX[]={1,-1,0,0};
int direcY[]={0,0,1,-1};

int heuristic(){
    
    //manhattan heurestic
    int res=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(puzzle.scramble[i][j]!=0){
            int val=puzzle.scramble[i][j];
            res+=abs(i-pos[val][0])+abs(j-pos[val][1]);
            }
        }
    }

    return res;
}

bool safe_check(int x, int y){

return (x>=0 && x< N && y>=0 && y< N);

}

Node initial; 

void printState(int **puzzle){

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++)
        cout<<puzzle[i][j]<<" ";

        cout<<"\n";
    }
    cout<<"\n";
}

void printpath(){

    int i=0;

    printState(initial.scramble);

    int blankx=initial.blank.F;
    int blanky=initial.blank.S;

    while(moves[i]!=-1){

            if(moves[i]==1){
            swap(initial.scramble[blankx][blanky],initial.scramble[blankx-1][blanky]);
            blankx--;
            }
            else if(moves[i]==0){
            swap(initial.scramble[blankx][blanky],initial.scramble[blankx+1][blanky]);
            blankx++;
            }
            else if(moves[i]==2){
            swap(initial.scramble[blankx][blanky],initial.scramble[blankx][blanky+1]);
            blanky++;
            }
            else{
            swap(initial.scramble[blankx][blanky],initial.scramble[blankx][blanky-1]);
            blanky--;
            }

            printState(initial.scramble);
            i++;
    }

}

int ida_star(int depth , int heu){

    if(heu==0){

        solved=1;
        moves[depth]=-1;
        printpath(); 
        return depth;
    }

    if(depth + 5*heu/3 > bound)
    return depth + 5*heu/3;

    int nextbound=1e9; int val=1e9;

    for(int i=0;i<4;i++){

        int inX=puzzle.blank.F; int inY=puzzle.blank.S;

        int X=inX+ direcX[i] ; int Y=inY + direcY[i];

        int index=-1;

        if(depth)
        index=moves[depth-1];

        if(safe_check(X,Y) && ((depth==0)|| (X!=(inX-direcX[index]) && Y!=(inY-direcY[index])))){

            pair<int,int> newblank={X,Y};

            int child_heu=heu;

            child_heu-=Hash[X][Y][puzzle.scramble[X][Y]];
            child_heu+=Hash[inX][inY][puzzle.scramble[X][Y]];

            swap(puzzle.scramble[inX][inY],puzzle.scramble[X][Y]);

            puzzle.blank=newblank;

            moves[depth]=i;

            val=ida_star(depth+1,child_heu);

            swap(puzzle.scramble[inX][inY],puzzle.scramble[X][Y]);
            puzzle.blank.F=inX;
            puzzle.blank.S=inY;
            
            if(solved)
            return val;

            nextbound=min(nextbound,val);
        }
            
    }
    return nextbound;
}

int main(){
IOS;

    puzzle.scramble=(int **)malloc(N*sizeof(int *));

    for(int i=0;i<N;i++)
    puzzle.scramble[i]=(int *)malloc(N*sizeof(int));

    initial.scramble=(int **)malloc(N*sizeof(int *));

    for(int i=0;i<N;i++)
    initial.scramble[i]=(int *)malloc(N*sizeof(int));


for(int i=0;i<N;i++){

    for(int j=0;j<N;j++){
    cin>>puzzle.scramble[i][j];

    initial.scramble[i][j]=puzzle.scramble[i][j];

    if(puzzle.scramble[i][j]==0){
    puzzle.blank={i,j};
    initial.blank={i,j};
    }

    }
}

clock_t start,end;

start=clock();

for(int i=0;i<N;i++){

    for(int j=0;j<N;j++){

        if(!(i==N-1 && j==N-1)){
        pos[i*N+j+1][0]=i;
        pos[i*N+j+1][1]=j;
        }
    }
}

for(int i=0;i<N;i++){

    for(int j=0;j<N;j++){

        for(int k=1;k<N*N;k++){

            Hash[i][j][k]=abs(i-pos[k][0])+abs(j-pos[k][1]);
        }
    }
}  

  if(isSolvable(puzzle.scramble,N)){

  bound=heuristic(); solved=0;
  int initial_heu=bound;

  while(solved==0){
  bound=ida_star(0,initial_heu);
  }
 } 
 else
 cout<<"The given instance of the puzzle cannot be solved\n";

end=clock();

double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

cout<<"Time taken in execution is : "<<time_taken<<" secs\n";

}
