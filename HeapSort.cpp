#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
void display(int*);

int arr_heap_size,n;

int Right(int i ) {return (2*i + 1);}

int Left(int i){return 2*i;}

void max_heapify(int *a,int i){ // some times it seems compilers do not produce efficient code for recursion// it can be done in recursion
    int largest = i;
    while(1){
        int l = Left(i);
        int r = Right(i);
        if (l <= arr_heap_size && a[l] > a[i])
            largest = l;

        if (r <= arr_heap_size && a[r] > a[largest])
            largest = r;
        
        if(largest != i){
            int temp ;
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
        }
        else{
            break;
        }
        i = largest;
    }
    
}
void build_max_heap(int *a){
    arr_heap_size = n;
    for(int i = n/2; i >= 1; i--){
        max_heapify(a,i);
    }
}
void heapsort(int *a){
    build_max_heap(a);
    display(a);
    for(int i = n; i >= 2; i--){
        int temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        arr_heap_size = arr_heap_size - 1;
        max_heapify(a,1);
    }
}


void display(int *a){
    for(int i = 1; i <= n; i++)
            cout<<a[i]<<" ";
    cout<<"\n";
}


int main(){
    ifstream file;
    file.open("input_file/Heapsort.txt");
    if(file){
        int *a;
        file>>n;
        arr_heap_size = n;
        a = (int*)malloc(sizeof(int)*(n+1));
        for(int i = 1; i <= n; i++)
            file>>a[i];

        display(a);
        clock_t start,end;
        start = clock();
        heapsort(a);
        end = clock();
        display(a);
        double time = 1000*(end - start)/CLOCKS_PER_SEC;
        cout<<"time - "<<time;
        
    }
    return 0;
}




