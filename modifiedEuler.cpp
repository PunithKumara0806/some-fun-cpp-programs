#include<iostream>
#include<fstream>
using namespace std;
void Eulermodified(long long int a,long long int b){ // ax + by = z
    long long int x1,y1,x2,y2,z1,z2,t,k,xt,yt;
    x1 = 0;
    y1 = 1;
    z1 = b;
    x2 = 1;
    y2 = -a/b;
    z2 = a%b;
    if(z2 != 0){

        for(;z1%z2 != 0  ; ){ // Now i dont even know the logic lol
            k = z1/z2;            // i just patched all the logical flaws for some output 
            xt = x2;
            yt = y2;
            y2 = -k*y2 + y1;
            x2 = -k*x2 + x1;
            cout<<x2<<" "<<y2<<" "<<z2<<"\n";
            x1 = xt;
            y1 = yt;
            t = z2;
            z2 = z1%z2;
            z1 = t;
            
            if( z2 < 2){
                if(z2 == 1)
                    z1 = z2;
                break;
            }

        }
    }
    else {
        x2 = 1;
        y2 = y2 + 1;
        z2 = z1;
    }
    cout<<a<<" * "<<x2<<" + "<<b<<" * "<<y2<<" = "<<z2;
}

int gcd(long long int a,long long int b){
    if (b == 0){
        cout <<"\n"<<a;
        return 0;
    }
    gcd(b,a%b);
}


int main(){
    ifstream file;
    file.open("input_file/modifiedEuler");
    if(file){
        long long int a,b;
        file>>a;
        file>>b;
        if (a < b){
         b = a + b;
         a = b - a;
         b = b - a;       
        }
        Eulermodified(a,b);
        gcd(a,b);
    }
    return 0;
}