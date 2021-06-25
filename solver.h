#include<bits/stdc++.h>
#include"solver_state.h"
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define F first
#define S second
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void a_star(int **puzzle, int **sol_puzzle, pair<int,int> blank , int **pos, int N){


    Node *root=newNode(puzzle,blank,blank,0,NULL,N);
    root->cost=heuristic(puzzle ,pos,N);

    map< vector<int> , int> mp;  
    priority_queue<Node*, std::vector<Node*>, cmp> pq;

    pq.push(root);  

    int direcX[]={1,-1,0,0};
    int direcY[]={0,0,1,-1};

    while(!pq.empty()){

        Node *state=pq.top();

        pq.pop();
        
        if(state->cost ==0){

            printPath(state,N);
            break;
        }

        for(int i=0;i<4;i++){

            int X=state->blank.F+ direcX[i] ; int Y=state->blank.S + direcY[i];

            if(safe_check(X,Y,N) && ((state->parent== NULL )|| (X!=state->parent->blank.F && Y!=state->parent->blank.S))){

                pair<int,int> newblank={X,Y};

                    vector<int> v;
                  
                Node *child=newNode(state->scramble,state->blank,newblank,state->level+1,state,N);
                child->cost=heuristic(child->scramble,pos,N);

                  for(int i=0;i<N;i++){

                  for(int j=0;j<N;j++)
                  v.pb(child->scramble[i][j]);
                  }

                   if(mp.find(v)!=mp.end())
                   delete child;
                   else{
                   mp[v]++;
                   pq.push(child);
                   }

            }
        }

    }

}

void bfs(int **puzzle, int **sol_puzzle, pair<int,int> blank, int N){


    Node *root=newNode(puzzle,blank,blank,0,NULL,N);

    queue<Node *> pq;

    pq.push(root);  

    map< vector<int> , int> mp;  

    int direcX[]={1,-1,0,0};
    int direcY[]={0,0,1,-1};

    while(!pq.empty()){

        Node *state=pq.front();

        pq.pop();

        int c=0;

        for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

        if(state->scramble[i][j]==sol_puzzle[i][j])
                c++;
        }
        }

        if(c== N*N){
        printPath(state,N);
        break;
        }

        for(int i=0;i<4;i++){

            int X=state->blank.F+ direcX[i] ; int Y=state->blank.S + direcY[i];

            if(safe_check(X,Y,N)){

                pair<int,int> newblank={X,Y};

                Node *child=newNode(state->scramble,state->blank,newblank,state->level+1,state,N);

                vector<int> v;

              for(int i=0;i<N;i++){

              for(int j=0;j<N;j++)
              v.pb(child->scramble[i][j]);
              }

             if(mp.count(v))
             delete child;
             else{
             mp[v]++; 
             pq.push(child);
            }
            }
        }

    }

}

