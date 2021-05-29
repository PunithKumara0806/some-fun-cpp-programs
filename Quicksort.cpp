#include<iostream>
#include<fstream>
using namespace std;

void display(int *a,int j, int n){
    cout<<endl;
    for(int i = j; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void swap(int *a,int i ,int j){
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}
int partition(int *a,int l, int h){
    int p = a[h];
    int i = l-1;
    display(a,l,h+1);
    for(int j = l; j <= h-1; j++ ){
        if(a[j] <= p){
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,h);
    return i+1;
}
void quicksort(int *a,int l, int h){
    if(l < h){    
        cout<<h<<" "<<l<<endl;
        int pat = partition(a,l,h);
        quicksort(a,l,pat-1);
        quicksort(a,pat+1,h);
    }
}
int main(){
    ifstream file;
    file.open("input_file/mergesort.txt");
    if(file){
        int *a,n;
        file>>n;
        a = (int*)malloc(sizeof(int)*n);
        for(int i = n-1; i >=0 ; i--){
            file>>a[i];
        }
        display(a,0,n);
        quicksort(a,0,n-1);
        display(a,0 ,n);
    }
    return 0;
}