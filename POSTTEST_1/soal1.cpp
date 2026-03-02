#include <iostream>
using namespace std; 

void nilaimin(int arr[], int n){
    int fibonacci[8]={1,1,2,3,5,8,13,1};
    int min = fibonacci[0];
    int index = 0;
    for(int i=1; i < n ; i++){
        if(fibonacci[i] < min){
            min = fibonacci[i];
            index = i;
        }
    }
    cout << "nilai minimum yaitu : " << min << endl;
    cout << "dengan indeks ke : ";
    for(int i = 0; i < n; i++){
        if(fibonacci[i] == min){
            cout << i << " " ;
        }
    }
    cout << endl;
}

int main(){
    int fibonacci[8]={1,1,2,3,5,8,13,1};
    cout << "nilai fibonacci : " << endl;
    for(int i=0; i<8; i++){
        cout << fibonacci[i] << " " ;
    }
    cout << "\n================================================";
    cout << endl;
    nilaimin(fibonacci, 8);
    
}
