//2007118

#include <iostream>
//#include<bits/stdc++.h>
using namespace std;

int ans;

const int N = 8;

bool board[N][N];

bool isSafe(int row,int col){

    
    for(int k=0;k<N;k++){
        if(board[row][k]==true) return false;
    }


    for(int k=0;k<8;k++){
        if(board[k][col]==true) return false;
    }

 

    for(int i=row,j=col;i>=0 and j>=0;i--,j--){
        if(board[i][j]==true) return false;
    }

    for(int i=row,j=col;i<N and j>=0;i++,j--){
        if(board[i][j]==true) return false;
    }
   
    return true;
}
bool placeQueen(int col){
    if(col==8){
       // ans++;
        return true;
    }

    for(int i=0;i<8;i++){
        if(isSafe(i,col)){
            board[i][col] = true;

            if(placeQueen(col+1)){
                return true;
            }
            board[i][col] = false;
        }
    }
    return false;
}
void printQueens(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(board[i][j]==0) cout<<".";
            else cout<<"*";
        }
        cout<<endl;
    }
}
int main(){
    placeQueen(0);
    printQueens();
//cout<<ans<<endl;

}
