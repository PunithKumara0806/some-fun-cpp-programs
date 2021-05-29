#include<iostream>
#include<fstream>
#include<ctime>
int count = 0;
using namespace std;
void Merge(int *a,int low, int mid , int high){
    int i,j,h,*b;
    i = low;
    j = mid +1;
    h = 0;
    b = (int*)malloc(sizeof(int)*(high - low + 1));
    while(i <= mid && j <= high){
        if (a[i] > a[j]){
            count += h - j + low;
            b[h++] = a[j++];
        }
        else{
            b[h++] = a[i++];
            }
    }
    if ( i <= mid){
        for (;i<= mid;i++){
            b[h++] = a[i];
        }
    }
    else{
        for (;j<= high;j++){
            b[h++] = a[j];
        }
    }
    for (int h = 0 ; low <= high;h++){
        a[low++] = b[h];
    }
}

void Mergesort(int *a, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high)/2;
        Mergesort(a,low,mid);
        Mergesort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}

int main(){
    ifstream file;
    file.open("input_file/MergeInsertionsort.txt");

    if(file){
        int n,*a;
        file>>n;
        clock_t start,end;
        a = (int*) malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++){
            file >> a[i];
        }
        for (int i = 0; i < n; i++){
            cout<<a[i] <<" ";
        }
        cout<<"\n";
        start = clock();
        Mergesort(a,0,n-1);
        end = clock() ;
        for (int i = 0; i < n; i++){
            cout<<a[i] <<" ";
        } 
        cout<<"\n";
        double time = 1000*(end - start)/CLOCKS_PER_SEC; 
        cout<<"time  : "<<time;
        cout<<"\n Inversion count : "<<-count;
        
    }
    return 0;
}