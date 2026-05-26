#include <iostream>
#include <string>
using namespace std;

void Print(int arr[], int n ){          //Hàm in ra mảng 
    cout <<  " [ ";
    for (int i = 0; i < n; i++) {  
    cout << arr[i];
    if (i < n - 1) cout << ", ";    }
    cout << " ]\n"; }
    // Vun đống 
void Vundong(int arr[], int n, int i) {   
    int Nutcha = i;            
    int contrai = 2 * i + 1;    
    int conphai = 2 * i + 2;

if (contrai < n && arr[contrai] > arr[Nutcha])   
        Nutcha = contrai;             // Cập nhật nút cha 
if (conphai < n && arr[conphai] > arr[Nutcha])
        Nutcha = conphai;

    if (Nutcha != i) {  
        int b = arr[i];           
        arr[i] = arr[Nutcha];    
        arr[Nutcha] = b;
        Vundong(arr, n, Nutcha); 
    }

}