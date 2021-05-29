// IMPLIMENTS PRIORITY QUEUE TO SOLVE NO ADJACENT CHARACTOR PROBLEM











#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char alphabet[27];// 1 space extra to start from index 1
                      
int counter(string s,int *a){
    int i = 0;
    for(; s[i] != '\0';i++){
        a[ s[i] - 96] ++; // used 96 instead of 97 because be are calculating from index 1
    }
    return i;
}
int Right(int i ) {return (2*i + 1);}

int Left(int i){return 2*i;}

void max_heapify(int *a,int i){ // some times it seems compilers do not produce efficient code for recursion// it can be done in recursion
    int largest = i;
    while(1){
        int l = Left(i);
        int r = Right(i);
        if (l <= 26 && a[l] > a[i])
            largest = l;

        if (r <= 26 && a[r] > a[largest])
            largest = r;
        
        if(largest != i){
            int temp ;
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;

            char tempc = alphabet[largest];
            alphabet[largest] = alphabet[i];
            alphabet[i] = tempc;
        }
        else{
            break;
        }
        i = largest;
    }
    
}
void build_max_heap(int *a,int n){
    for(int i = n/2; i >= 1; i--){
        max_heapify(a,i);
    }
}
string st = "";
void remove_max(int *a){
    int prev_count = a[1]-1;
    char prev_char = alphabet[1];
    st = st + prev_char;
    int rm;
    if(a[2] >= a[3]){
        rm  = 2;
        a[1] = a[2];
        alphabet[1] = alphabet[2];
    }
    else{
        rm = 3;
        a[1] = a[3];
        alphabet[1] = alphabet[3];
    }
    if(a[rm] != 0){
        a[rm] = prev_count;
        alphabet[rm] = prev_char;
        max_heapify(a,rm);
    }
}

int main(){
    ifstream file;
    file.open("input_file/string.txt");
    if(file){
        string s;
        file>>s;
        int *alpha_count;
        alpha_count = (int*)calloc(27,sizeof(int));
        int str_len = counter(s,alpha_count);
        cout<<s<<endl;
        for(int k = 1; k <= 26; k++){
            alphabet[k] = '0';
            alphabet[k] = k + 96;
        }
        build_max_heap(alpha_count,26);

        for(;alpha_count[1] != 0;)
            remove_max(alpha_count);
        if(str_len == st.length()){    
            cout<<endl<<st<<endl;
        }
        else
            cout<<"NOt possible";
    }
    return 0;
}