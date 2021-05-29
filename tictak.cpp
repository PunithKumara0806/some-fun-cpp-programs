#include<iostream>

using namespace std;

int num[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

void display(char a[][3]){
    cout<<"----------tictak-----------"<<endl;
    cout<<"         1   2   3   "<<endl;
    for(int i = 0 ; i < 3; i++)
        cout<<"      "<<i+1<<"  "<<a[i][0]<<"   "<<a[i][1]<<"   "<<a[i][2]<<"   "<<endl;
}
void insert(char a[][3] , int i , int j , char token){
    if(a[i][j] == '-'){
        a[i][j] = token;
        if(token == 'O')
            num[i][j] = 1;
        else
            num[i][j] = -1;
    }
    else {  
        cout<<endl<<"Invalid move !!!!!!!!!!!!!!!!!!!!!!!!!\n\n";
        getchar();
        getchar();
    }
}
void winner(char a[][3],int i, int j,char ply, int s){
    int hsum, vsum, rcsum, lcsum;
    hsum = vsum = rcsum = lcsum = 0;
    hsum = num[i][0] + num[i][1] +num[i][2]; // horizontal sum
    vsum = num[0][j] + num[1][j] + num[2][j];// vertical sum
    rcsum = num[0][0] + num[1][1] + num[2][2];//right cross sum
    lcsum = num[2][0] + num[1][1] + num[0][2];// left cross sum
        
    if(hsum == s || vsum == s|| rcsum == s|| lcsum == s){
        cout<<endl<<"Player"<<" -"<<ply<<" Win !!!!!\n\n";
        display(a);
        exit(0);
    }

}
int main(){
    char a[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int i,j , count = 9;
    cout<<"\n\n=========Instructions=========\n\n";
    cout<<"\n\nhow to chose a position:\nits like a matrix with row = 3 and col = 3\neg: top 2nd box is given by 1 2 and so on\n\n";
    while(count--){   
        display(a);
        cout<<"player - O : ";
        cin>>i>>j;
        insert(a,i-1,j-1,'O');
        winner(a,i-1,j-1,'O',3);
        display(a);
        cout<<"player - X : ";
        cin>>i>>j;
        insert(a,i-1,j-1,'X');
        winner(a,i-1,j-1,'X',-3);
    }    
    cout<<"\n\n!!!!!!!!!DRAW!!!!!!!\n\n";
}