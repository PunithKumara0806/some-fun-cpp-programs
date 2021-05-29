#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

void Insertionsort(int *a,int n){// sorting function
    int j, i = 0, key;
    for (j = 1; j < n; j++){
        key = a[j];
        i = j - 1;
        while(i > -1 && key < a[i]){
            a[i + 1] = a[i];
            i-= 1;
        }
        a[i + 1] = key;
    }
}

int main(){

    int n ,*a = NULL;

    ifstream file;      // Used to create a file pointer for input files

    file.open("input_file/MergeInsertionsort.txt",ios::in);
    if(file){
        clock_t start,end;
        file >> n;
        a = (int*)malloc(n*sizeof(int));
        for(int i = n-1; i > -1; i--)
            file >> a[i];
        for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        //clock
        start = clock();
        Insertionsort(a,n);
        end = clock() ;
        //end
        double time = 1000*(end - start)/CLOCKS_PER_SEC; 
        for(int i = 0; i < n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        cout<<"time  : "<<time;

    }

    return 0;

}