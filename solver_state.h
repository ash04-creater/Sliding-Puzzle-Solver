#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define F first
#define S second
#define pb push_back

struct Node{

    int **scramble;

    pair<int,int> blank;

    Node *parent;

    lli cost;

    lli level;
};


Node* newNode(int **puzzle,pair<int,int> blank,pair<int,int> newblank,int level,Node *parent, int N){

    Node* state=new Node;

    state->parent=parent;

    state->scramble=(int **)malloc(N*sizeof(int *));

    for(int i=0;i<N;i++)
    state->scramble[i]=(int *)malloc(N*sizeof(int));

    for(int i=0;i<N;i++){

       for(int j=0;j<N;j++)
       state->scramble[i][j]=puzzle[i][j];
    }

    swap(state->scramble[blank.F][blank.S], state->scramble[newblank.F][newblank.S]);

    state->blank=newblank;

    state->level=level;

    state->cost=INT32_MAX;
    
    return state;

}

void printState(int **puzzle, int N){

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++)
        cout<<puzzle[i][j]<<" ";

        cout<<"\n";
    }
    cout<<"\n";
}

void printPath(Node *root , int N){

    if(root==NULL)
    return ;
    printPath(root->parent,N);
    printState(root->scramble,N);
}

long long int heuri_misplaced( int **puzzle, int **sol_puzzle, int N){

    //misplaced tiles heuristic
  
    lli bound_lower=0;

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

            if(puzzle[i][j]&&puzzle[i][j]!=sol_puzzle[i][j])
            bound_lower++;
        }
    }

    return bound_lower;

}

long long int heuristic( int **puzzle, int **pos, int N){

    //manhattan heurestic

    int res=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(puzzle[i][j]!=0){
            int val=puzzle[i][j];
            res+=abs(i-pos[val][0])+abs(j-pos[val][1]);
            }
        }
    }

    return res;
}

struct cmp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->level + lhs->cost ) > (rhs->level + rhs->cost);
	}
};

bool safe_check(int x, int y,int N){

return (x>=0 && x< N && y>=0 && y< N);

}




