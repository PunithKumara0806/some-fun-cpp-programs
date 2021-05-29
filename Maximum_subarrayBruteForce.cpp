//uses brute force
#include<iostream>
#include<fstream>
using namespace std;

void Maximum_subarray(int *a,  int n){
    int i , j ;
    int ith,jth; 
    int sum , prev_sum ;
    sum = prev_sum = a[0];
    for (i = 0; i < n; i++){        // Used to find highest value in a array
        if(sum < a[i]){
            sum = a[i];
            ith = jth = i;    
        }
    }
    int max_sum = sum;
    int front = 0,back = 0;
   
    for(i = 1; i < n; i++){
        sum = prev_sum + a[i];  // used for 
        prev_sum = sum;         // removing for loop to calculate sum from 0 to ith value
        front = back = 0;
        for(j = 0; j + i < n; j++){
            sum = sum + front - back;
            front = a[j + i + 1];
            if (max_sum < sum ){
                max_sum = sum;
                ith = i + j;
                jth = j;
            }
            back = a[j];
        }
        
    }
    cout<<"\n"<<"Max Sum : "<<max_sum<<"\n start- index : "<<jth<<" \nending - index : "<<ith<<"\n";
    cout<<"The subarray is : ";
    for(int i = jth; i <= ith; i++)
        cout<<a[i]<<" ";
}
int main(){
    ifstream file;
    file.open("input_file/maximum_subarray.txt");
    if(file){
        int n, *a;
        file>>n;
        a = (int*)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++){
            file>>a[i];
        }
        
        for(int i = 0; i < n; i++){
            cout<<a[i]<<"  ";
        }
        cout<<"\n";
        Maximum_subarray(a,n);
    }
    return 0;
}