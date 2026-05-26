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
void Taodong(int arr[], int n) {   
for (int i = n / 2 - 1; i >= 0; i--) {   
    Vundong(arr, n, i);  
    cout << "Vun dong o nut i = " << i+1 << ":";
    Print(arr, n); 
    }
}
void Sapxep(int arr[], int n) {   
    int buoc = 1;           
    for (int i = n - 1; i > 0; i--) {   
    int b = arr[0];
    arr[0] = arr[i];   

    Vundong(arr, i, 0); 
    Print(arr, n);
    buoc++;
}
}