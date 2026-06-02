#include <iostream>
#include <cmath>
using namespace std;
// Bài tập cây nhị phân tìm kiếm, thêm node vào cây theo quy tắc, tìm 1 giá trị thỏa mãn.
// Cài đặt cây nhị phân bằng lưu trữ kế tiếp, các node rỗng được biểu diễn bởi gtri 0.
// Tính độ phức tạp
void add_nodeBST(int tree[], int max, int a) {    // Hàm thêm node vào cây nhị phân theo quy tắc 
    int i = 0;                                  
    while (i < max) {              
        if (tree[i] == 0)  // Thêm giá trị vào node rỗng
        { tree[i] = a;
            return;  }
              if (a <= tree[i])  i = 2 * i + 1;        
        else if (a > tree[i]) i = 2 * i + 2;    
        else return;
    }
}
void initial_BST(int arr[], int n, int tree[], int max) {    // Hàm dựng cây  
    for (int i = 0; i < n; i++) {
        add_nodeBST(tree, max, arr[i]);    
    }   
 }
 void search_BST(int tree[], int max, int find) {    // Hàm tìm kiếm 
    int i = 0; 
    while (i < max) {      

    if (tree[i] == 0) {  cout << "Khong thay " << find << " trong cay" <<  endl;   
            return; }
    if (tree[i] == find) { cout << "Tim thay " << find << " tai vi tri: " << i << endl;  
            return;   }


    if (find <= tree[i]) {  
        i = 2 * i + 1;  }
    else { i = 2 * i + 2; }  //sang trái
}
    cout << "Khong tim thay gia tri " << find << " trong cay tim kiem nhi phan" <<  endl;   
}


void Print_BST(int tree[], int max) {      // Hàm in 
    int p = -1;
    for (int i = max - 1; i >= 0; i--) {     
        if (tree[i] != 0) { p = i;   break;  }  } // Tìm phần tử khác rỗng cuối cùng 

    for (int i = 0; i <= p; i++) {   cout << tree[i] << " "; }       // In cây
    cout << endl;
}
int main() {
    int arr[] = {2001,2002,2006,2007,2003,2004,2005,2001,1999,2004};
    int n = sizeof(arr) / sizeof(arr[0]);    
    int max = pow(2,n)-1;    
    int tree[max] = {0};

    initial_BST(arr, n, tree, max);
    Print_BST(tree, max);

    add_nodeBST(tree, max, 1213);       
    Print_BST(tree, max);

    search_BST(tree, max, 2006); 
    search_BST(tree, max, 10);

    return 0;
}
