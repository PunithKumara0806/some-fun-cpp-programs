#include<iostream>
#include<fstream>

using namespace std;

void Merge(int *a,int st,int end1, int end2){
    int *b,i,j,h;
    int bsize = end2 - st + 1;
    b = (int*)malloc(sizeof(int)*bsize);
    i = st;
    j = end1 + 1;
    h = 0;
    
    while(i <= end1 && j <= end2){
        if(a[i] > a[j]){
            b[h++] = a[j++];}
        else{
            b[h++] = a[i++];}
    }
    if(i <= end1){
        for(;i<=end1;i++){
            b[h++] = a[i];

            }
    }
    else{

        for(;j<=end2;j++){
            b[h++] = a[j];

        }
    }
    for(int h = 0; h < bsize; h++){
        a[st + h] = b[h];
    }

}

void Mergesort3(int *a, int low, int high){
    int mid1,mid2;
    if(low + 1 == high){
        if(a[low] > a[high]){
            int temp; 
            temp = a[low];
            a[low] = a[high];
            a[high] = temp;
        }
    }
    else if(low + 1 < high  ){
        mid1 = low + ( high - low + 1)/3;
        mid2 =  low + 2 * (mid1-low);

        Mergesort3( a, low, mid1);

        Mergesort3( a, mid1+1,mid2);

        if(mid2 == high)
            Mergesort3(a,mid2,high);
        else
            Mergesort3( a, mid2+1, high);
        Merge(a,low,mid1,mid2);
        Merge(a,low,mid2,high);
    }
}
int main(){
    ifstream file;
    file.open("input_file/MergeInsertionsort.txt");
    if(file){
        int n,*a;
        file>>n;
        a = (int*)malloc(sizeof(int)*n);
        for(int i = n-1; i > -1; i--)
            file >> a[i];
        for(int j = 0; j < n; j++)
            cout<<a[j]<<" ";
        cout<<"\n";
        Mergesort3(a,0,n-1);
        for(int i = 0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        


    }


return 0;
}