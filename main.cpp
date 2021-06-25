#include<bits/stdc++.h>
#include"solver.h"
#include"solvability.h"
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
IOS;

clock_t start,end;

int N;

cin>>N;

int **puzzle; pair<int,int> blank;

puzzle=(int **)malloc(N*sizeof(int *));

for(int i=0;i<N;i++)
puzzle[i]=(int *)malloc(N*sizeof(int));


for(int i=0;i<N;i++){

    for(int j=0;j<N;j++){
    cin>>puzzle[i][j];
    if(puzzle[i][j]==0)
    blank={i,j};
    }
}

start=clock();

int **sol_puzzle,**pos;
sol_puzzle=(int **)malloc(N*sizeof(int *));

for(int i=0;i<N;i++)
sol_puzzle[i]=(int *)malloc(N*sizeof(int));

pos=(int **)malloc(N*N*sizeof(int *));

for(int i=0;i<N*N;i++)
pos[i]=(int *)malloc(2*sizeof(int));


for(int i=0;i<N;i++){

    for(int j=0;j<N;j++){

        if(i==N-1 && j==N-1)
        sol_puzzle[i][j]=0;
        else{
        sol_puzzle[i][j]=i*N+j+1;
        pos[i*N+j+1][0]=i;
        pos[i*N+j+1][1]=j;
        }
    }
}

if(isSolvable(puzzle,N)){

a_star(puzzle, sol_puzzle, blank, pos,N);
bfs(puzzle, sol_puzzle, blank,N);
}
else
cout<<"The given instance of the puzzle cannot be solvable\n";

end=clock();
 
double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

cout<<time_taken<<"\n";

}
