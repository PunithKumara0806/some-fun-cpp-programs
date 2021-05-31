#include<iostream>

using namespace std;

int num[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
int cpu_i = -1, cpu_j = -1;
int prev_cpu_i = -1, prev_cpu_j = -1;
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
bool movcheck(char a[][3],int i, int j,char ply, int s){
    int hsum, vsum, rcsum, lcsum;
    hsum = vsum = rcsum = lcsum = 0;
    hsum = num[i][0] + num[i][1] +num[i][2]; // horizontal sum
    vsum = num[0][j] + num[1][j] + num[2][j];// vertical sum
    rcsum = num[0][0] + num[1][1] + num[2][2];//right cross sum
    lcsum = num[2][0] + num[1][1] + num[0][2];// left cross sum   
    if(hsum == s || vsum == s|| rcsum == s|| lcsum == s){
        display(a);

        cout<<endl<<"Player"<<" -"<<ply<<" Win !!!!!\n\n";
        exit(0);
    }
    if(s < 0)
        s = s+1;
    else{
        cout<<s<<endl;
        s = s-1;
    }
        
    if(hsum == s){
        for(int k = 0; k < 3; k++){
            if(a[i][k] == '-'){
                cout<<hsum <<" "<<s<<endl;
                cpu_i = i;
                cpu_j = k;
            }
        }
    }
    else if(vsum == s){
        for(int k = 0; k < 3; k++){
            if(a[k][j] == '-'){
                cpu_i = k;
                cpu_j = j;
            }
        }
    }
    else if(rcsum == s){
        for(int k = 0; k < 3; k++){
            if(a[k][k] == '-')
            cpu_j = cpu_i = k;

        }
    }
    else if(lcsum == s){
        for(int k = 0; k < 3; k++){
            if(a[2-k][k] == '-'){
                cpu_i = 2-k;
                cpu_j = k;
            }
        }
    } 

}

int main(){
    char a[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    int i,j , count = 10;
    bool once = true;
    bool flag = false;
    cout<<"\n\n=========Instructions=========\n\n";
    cout<<"\n\nhow to chose a position:\nits like a matrix with row = 3 and col = 3\neg: top 2nd box is given by 1 2 and so on\n\n";
    while(count){   
        display(a);
        cout<<"player - O : ";
        cin>>i>>j;
        insert(a,i-1,j-1,'O');
        movcheck(a,i-1,j-1,'O',3);
        display(a);
        
        if(once){
                if(a[1][1] == '-')
                    insert(a,1,1,'X');
                else if(a[2][0] == '-')
                    insert(a, 2, 0, 'X');
            once = false;
        }
        else if(cpu_j == -1 && !flag){
            cout<<"-1"<<endl;
            if(a[0][2] == '-'){
                insert(a,0,2,'X');
            }
            else if(a[2][2] == '-'){
                insert(a,2,2, 'X');
            }
            else if(a[0][0] == '-'){
                insert(a,0,0,'X');
            }
        }
        else if(flag){
            cout<<"hello"<<endl;
            insert(a,prev_cpu_i,prev_cpu_j,'X');
            movcheck(a,prev_cpu_i,prev_cpu_j,'X',-3);
            flag = false;
        }
        else{
            insert(a,cpu_i,cpu_j,'X');
            prev_cpu_i = cpu_i;
            prev_cpu_j = cpu_j;
            cout<<prev_cpu_i<<" "<<prev_cpu_j<<endl;
            movcheck(a,cpu_i,cpu_j,'X',-3);
            cout<<cpu_i<<" "<<cpu_j<<endl;
             if(prev_cpu_i != cpu_i || prev_cpu_j != cpu_j){
                 cout<<cpu_i<<" "<<cpu_j<<endl;
                prev_cpu_i = cpu_i;
                prev_cpu_j = cpu_j;
                flag = true;
            }
            cpu_j = cpu_i = -1;

        }
    count = count - 2;
    }    
    cout<<"\n\n!!!!!!!!!DRAW!!!!!!!\n\n";
}