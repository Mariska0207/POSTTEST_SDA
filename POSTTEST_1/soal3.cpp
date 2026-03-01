#include <iostream>
using namespace std;

void reverse(int* arr, int n){
    int temp = 0;
    int *a = arr;
    int *b = arr+n-1;
    for(int i=0; i<n/2; i++){
        temp = *a;
        *a = *b;
        *b = temp;
        a++;
        b--;
    }
}

int main(){
    int bilprima[7]={2,3,5,7,11,13,17};
    cout << "\nbilangan prima sebelum : " << endl;
    for(int i=0; i<7; i++){
        cout << bilprima[i] << " ";
    }
    reverse(bilprima, 7);
    cout << "\nbilangan prima sesudah : " << endl;  
    for(int i=0; i<7; i++){
        cout << bilprima[i] << " ";
    }

    cout << "\n================================================" << endl;
    cout << "alamat memori bilangan prima : " << endl;
    cout << "elemen 1 (2) : " << &bilprima[0] << endl;
    cout << "elemen 2 (3): " << &bilprima[1] << endl;
    cout << "elemen 3 (5): " << &bilprima[2] << endl;
    cout << "elemen 4 (7): " << &bilprima[3] << endl;
    cout << "elemen 5 (11): " << &bilprima[4] << endl;
    cout << "elemen 6 (13): " << &bilprima[5] << endl;
    cout << "elemen 7 (17): " << &bilprima[6] << endl;   
    cout << "\n================================================";
    return 0;

}