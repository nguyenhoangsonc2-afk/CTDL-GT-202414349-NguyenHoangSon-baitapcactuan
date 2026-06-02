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