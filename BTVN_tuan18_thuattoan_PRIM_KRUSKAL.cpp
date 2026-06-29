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