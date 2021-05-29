#include<iostream>
#include<fstream>
using namespace std;

// Did it as with suggestion from Introduction to Algorithms

void Maximum_subarraLinear(int *a,int n){
    int i_start, i_end, max_sum = 0,sum = 0; // coolest names i came up with lol
    int i_temp = 0;
    for(int i = 0; i < n; i++){
        if(sum <= 0 && a[i] > 0){
            sum = 0;
            i_temp = i;
        }
        sum = sum + a[i];
        if (sum > max_sum){
            max_sum = sum;
            i_end = i;
            i_start = i_temp;
        }
    }
    cout<<"Max sum : "<<max_sum<<" \nStarting index : "<<i_start<<" \nEnding index : "<<i_end<<"\n";
    cout<<"The Maximum subarray is : ";
    for(int i = i_start; i <= i_end; i++){
        cout << a[i]<< " ";
    }
    cout<<"\n";
}


int main(){
    ifstream file;
    file.open("input_file/maximum_subarray.txt");
    if(file){
        int n, *a;
        file>>n;
        a = (int*)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++)
            file>>a[i];
        cout<<"Given array is : ";
        for(int i = 0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        Maximum_subarraLinear(a,n);
    }
    return 0;
}