#include<iostream>
#include<fstream>

using namespace std;

void nbitadd(int *a,int *b, int *c, int n){
    int carry = 0, j = 0;
    for(int i = n-1; i > -1;i--){

        c[j] = (a[i] + b[i] + carry) % 2 ;

        carry =  (a[i] + b[i] + carry) / 2 ;

        j++;
    }
    c[j] = carry;
}

int main(){
    int n, *a, *b ,*c;
    ifstream file;
    file.open("input_file/nbit.txt");
    if (file){
        file >> n;
        a = (int *)malloc(sizeof(int)*n);
        b = (int *)malloc(sizeof(int)*n);
        for (int i = 0; i < n; i++)
            file >> a[i];
        for (int i = 0; i < n; i++)
            file >> b[i];
        c = (int *)malloc(sizeof(int)*(n + 1));
        nbitadd(a,b,c,n);
        cout<<" ";
        for (int i = 0; i < n; i++)
            cout<<" "<<a[i];
        cout<<"\n";
        cout<<" ";
        for (int i = 0; i < n; i++)
            cout<<" "<<b[i];
        cout<<"\n";

        for (int i = n; i > -1; i--)
            cout<<c[i]<<" ";
        cout<<"\n";
    }
    return 0;
}