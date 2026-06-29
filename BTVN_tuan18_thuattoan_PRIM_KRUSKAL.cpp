#include <iostream>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;
const int MAX_TINH = 11;
const int VO_CUNG = 1e9;  
const string TEN_TINH[MAX_TINH] = { "HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST" };
// Cấu trúc lưu trữ đồ thị giao thông dưới dạng ma trận kề
struct DoThiGiaoThong {   
    int soDinh;
    int maTranKe[MAX_TINH][MAX_TINH];
};
// Khởi tạo ma trận
void khoiTaoDoThi(DoThiGiaoThong &dt, int n) { 
    dt.soDinh = n;
    for (int i = 0; i < n; i++) {     
        for (int j = 0; j < n; j++) {
            dt.maTranKe[i][j] = 0; 
        }
    }
}