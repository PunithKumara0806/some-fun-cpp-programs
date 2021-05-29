#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void Merge(int *a,int low, int mid , int high){
    int i,j,h,*b;
    i = low;
    j = mid + 1;
    h = 0;
    b = (int*)malloc(sizeof(int)*(high - low + 1));
    while(i <= mid && j <= high){
        if (a[i] > a[j]){
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
void Insertionsort(int *a,int low, int high){
    int j,i,key;
    for(int j = low + 1; j < high; j++){
        key = a[j];
        i = j-1;
        while(i >= low && a[i] > key){
            a[i+1] = a[i];
            i = i - 1;
        }
        a[i+1] = key;
    }

}
void Mergesort(int *a, int low, int high){
    int mid;
    int h = 2;

    if(low + h < high){          // h = k - 1
        mid = (low + high)/2;
        Mergesort(a,low,mid);
        Mergesort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
    if (low < high){
        Insertionsort(a,low,high);
    }
}


int main(){
    ifstream file;
    file.open("input_file/MergeInsertionsort.txt");

    if(file){
        int n;
        file>>n;
        clock_t start,end;
        int *a = (int*) malloc(sizeof(int)*n);
        for (int i = n-1; i > -1; i--){
            file >> a[i];
        }
        for (int o = 0; o < n; o++){
            cout<<a[o] <<" ";
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
    }
    return 0;
}