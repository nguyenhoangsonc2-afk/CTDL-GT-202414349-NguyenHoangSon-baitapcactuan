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
int main() {
    int arrslide[] = {4, 1, 3, 2, 16, 9, 10, 14, 8 , 7}; 
    int n= sizeof(arrslide) / sizeof(arrslide[0]);    
cout << "mang ban dau:";
Print(arrslide, n);    
cout << "\nCac trang thai luu tru : \n";
Taodong(arrslide, n);     
cout << "\nCac trang thai luu tru cho moi buoc sap xep vun dong: \n";
Sapxep(arrslide, n);
    Print(arrslide, n);


int arrbang[] = {11, 34, 32, 106, 38, 78, 203, 16, 84, 17, 39 , 15};   // Nhap 
int a= sizeof(arrbang) / sizeof(arrbang[0]);

cout << "Xet mang trong slide, mang ban dau:";
Print(arrbang, a);    // in
cout << "\nCac trang thai luu tru cho moi buoc vun dong: \n";
Taodong(arrbang, a);     
cout << "\nCac trang thai luu tru cho moi buoc sap xep vun dong: \n";
Sapxep(arrbang, a);// sap xep

cout << "\nCay sau khi sap xep:";
Print(arrbang, a);

    return 0;
}  