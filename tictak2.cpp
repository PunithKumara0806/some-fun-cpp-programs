#include<iostream>
using namespace std;
int scor[9] = {0,0,0,0,0,0,0,0,0};
char array[9] = {'-','-','-','-','-','-','-','-','-'};
void display(){
    cout<<"----------tictak-----------"<<endl;
    cout<<"      1     2     3   "<<endl;
    for(int i = 0; i < 3; i++){
        cout<<i+1<<"     "<<array[i*3+0]<<"     "<<array[i*3+1]<<"     "<<array[i*3+2]<<endl;
    }
}
void insert(int i , char s){
    if(array[i] == '-'){
        array[i] = s;
        scor[i] = s;
    }
    else{
        cout<<"Invalid move - "<<s<<endl;
    }
}
int wincheck(int i ,int j, int s){
    i = i + j/3;
    j = j%3;
    int hsum , vsum, lcsum , rcsum;
    int mov = -1;

    s = s*3;
    hsum = scor[3*i + 0] + scor[3*i + 1] +scor[ 3*i + 2]; // horizontal sum
    vsum = scor[0 + j] + scor[3 + j] + scor[6 + j];// vertical sum
    rcsum = scor[0] + scor[4] + scor[8];//right cross sum
    lcsum = scor[6] + scor[4] + scor[2];// left cross sum 

    if(hsum == s || vsum == s|| rcsum == s|| lcsum == s){
        display();
        cout<<endl<<"You    "<< ((s/3 == 'X')? "win":"lose") ;
        exit(0);
    }
    s = 2*s/3;
         
    if(hsum == s){
        for(int k = 0; k < 3; k++){
            if(array[ 3*i + k] == '-'){
                mov = 3*i+k;
            }
        }
    }
    else if(vsum == s){
        for(int k = 0; k < 3; k++){
            if(array[3*k + j] == '-'){
                mov = 3*k + j;
            }
        }
    }
    else if(rcsum == s){
        for(int k = 0; k < 3; k++){
            if(array[4*k] == '-')
                mov = 4*k;
        }
    }
    else if(lcsum == s){
        for(int k = 0; k < 3; k++){
            if(array[6 - 2*k] == '-'){
                mov = 6 - 2*k;
            }
        }
    } 
    return mov;
}
int main(){
    int player,player_next = -1, i , j, cpu,cpu_next = -1;
    int count = 10;
    while(count){
        display();
        cin>>i>>j;
        i -= 1;
        j -= 1; 
        player = i*3 + j;
        insert(player , 'X');
        player_next = wincheck(i,j, 'X');

        if(cpu_next != -1 && array[cpu_next] == '-' ){ 
 
            insert(cpu_next,'O');
            wincheck(0,cpu_next,'O');
        }
        else if( player_next != -1){
           
            insert(player_next,'O');
            cpu_next = wincheck(0,player_next,'O');
        }
        else{
            int m;
            if(array[0] == '-'){
                m = 0; 
            }
            else if(array[2] == '-'){
                m = 2;
            }
            else if(array[4] == '-'){
                m = 4;
            }
            else if(array[6] == '-'){
                m = 6;
            }
            else if(array[8] == '-'){
                m = 8;
            }
            insert(m,'O');
            cpu_next = wincheck(0,m,'O');
        }
       
        count -= 2;
    }
    cout<<"DRAW !!!!!!!!!!!!";
}