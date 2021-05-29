#include<iostream>
#include<fstream>
using namespace std;
void display(int *a, int n){
    for(int i = 1; i <= n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void countingsort(int *a, int n){
    int max,*c;
    max = a[1];
    for(int i = 1; i <= n; i++){
        if(a[i] > max)
            max = a[i];
    }
    c = (int*)malloc(sizeof(int)*(max+1));
    for(int i = 0; i <= max; i++){
        c[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        c[a[i]]++;
    }
    int *b;
    b = (int*)malloc(sizeof(int)*n);
    for(int i = 1; i <= max; i++){
        c[i] = c[i-1] + c[i];
    }
    for(int i = 1; i<=n; i++){
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    for(int i = 1; i<=n; i++){
        a[i] = b[i];
    }
}
int main(){
    ifstream file;
    file.open("input_file/countingsort.txt");
    if(file){
        int n;
        file>>n;
        int *a;
        a = (int*)malloc(sizeof(int)*(1+n));
        for(int i = 1 ; i <= n; i++){
            file>>a[i];
        }
        display(a,n);
        countingsort(a,n);
        display(a,n);
    }
    file.close();
}                               