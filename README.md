## TUẦN 18

### ĐỀ BÀI: Cài đặt thuật toán tìm đường đi ngắn nhất Dijkstra và cây khung PRIM , KRUSKAL cho bài toán đồ thị giao thông , in cây khung (ma trận đỉnh kề ), "THUẬT TOÁN DIJKSTRA ĐÃ LÀM Ở TUẦN 16".

* Sử dụng cấu trúc Ma trận kề (Adjacency Matrix) thông qua mảng hai chiều maTranKe[MAX_TINH][MAX_TINH] nằm trong cấu trúc DoThiGiaoThong.
* Đỉnh: Đại diện cho 11 tỉnh thành, (từ $0$ đến $10$) thông qua mảng hằng TEN_TINH:
0: HN, 1: TN, 2: BN, 3: BG, 4: UB, 5: HP, 6: HD, 7: HY, 8: PL, 9: HB, 10: ST.
* Cạnh: Đại diện cho các tuyến đường nối giữa các tỉnh. Trọng số của cạnh (trongSo) chính là khoảng cách.

#### Thuật toán Prim xây dựng cây khung nhỏ nhất bằng cách phát triển dần một cây từ một đỉnh xuất phát ban đầu (trong bài là đỉnh Hòa Bình - HB). 
Tại mỗi bước, thuật toán sẽ tìm một cạnh ngắn nhất kết nối một đỉnh đã nằm trong cây với một đỉnh chưa nằm trong cây để kết nạp đỉnh mới đó vào cây.


#### Kruskal tiếp cận theo hướng chọn cạnh. Thuật toán xem mỗi đỉnh ban đầu là một cây độc lập.
Sau đó, nó duyệt qua tất cả các cạnh của đồ thị theo thứ tự trọng số tăng dần và nhặt các cạnh này vào cây khung, miễn là cạnh được chọn không tạo thành chu trình (vòng khép kín).



## TUẦN 16

### ĐỀ BÀI: Cài đặt thuật toán tìm đường đi và tìm đường đi ngắn nhất cho đồ thị các tỉnh thành tuần 15.

* Thuật toán Warshall: Để kiểm tra tính liên thông (liệu giữa 2 tỉnh bất kỳ có tồn tại đường đi hay không).

* Thuật toán Dijkstra: Để tìm ra đường đi ngắn nhất từ một tỉnh nguồn đến các tỉnh còn lại.
  
 #### Bước 1: Khởi tạo cấu trúc dữ liệu: Định nghĩa đồ thị bằng ma trận kề matrix[][] kích thước $11 \times 11$. Toàn bộ trọng số ban đầu được gán bằng 0 (biểu thị chưa có đường nối).
 #### Bước 2: Xây dựng đồ thị : Đọc danh sách các tuyến đường (các cạnh) từ mảng dataTuyenDuong và điền trọng số tương ứng vào ma trận kề. Vì đây là đồ thị vô hướng nên nếu có đường giữa A và B, ta gán cả matrix[A][B] và matrix[B][A].
#### Bước 3: Thực hiện thuật toán Warshall: Tìm ma trận bao đóng chuyển tiếp để kiểm tra xem Hà Nội có thể đi đến Uông Bí được không.
 #### Bước 4: Thực hiện thuật toán Dijkstra: Tìm lộ trình ngắn nhất chính xác từ Hà Nội tới Uông Bí, sau đó dùng kỹ thuật truy vết (đệ quy) để in ra danh sách các tỉnh phải đi qua.





## TUẦN 15
### ĐỀ BÀI :
Cài đặt bài đồ thị giao thông, theo 2 cấu trúc lưu trữ mảng đỉnh kề và danh sách liên két, duyệt theo chiều rộng (BFS) và in theo thứ tự duyệt từ đỉnh Hà nội.
* Cài đặt thuật toán duyệt đồ thị theo chiều rộng dựa trên sơ đồ mạng lưới giao thông gồm 11 đỉnh (tương ứng với 11 tỉnh/thành phố phía Bắc) bằng hai cấu trúc lưu trữ dữ liệu khác nhau: Ma trận kề và Danh sách liên kết.
* 1. Ý Tưởng: Đỉnh nào có khoảng cách (số cạnh) gần đỉnh gốc hơn sẽ được ưu tiên thăm trước. Để kiểm soát thứ tự duyệt, thuật toán sử dụng cấu trúc dữ liệu Hàng đợi (Queue).
* 2. Cài Đặt Bằng Ma Trận Kề (Mảng 2 Chiều), sử dụng một mảng hai chiều cố định int a[11][11] khởi tạo toàn bộ bằng 0. Khi có đường đi giữa u và v, ta gán a[u][v] = a[v][u]=1.
* 3. Cài Đặt Bằng Danh Sách Liên Kết: Định nghĩa một cấu trúc struct Node tự liên kết bằng con trỏ để lưu trữ thông tin đỉnh đích và con trỏ trỏ tới node tiếp theo (next). Sử dụng mảng quản lý head[11] và tail[11].
### TUẦN 14
## ĐỀ BÀI :
Cài đặt cây cân bằng AVL với đầu vào là dãy số sau , thực hiện các thêm và duyệt cây để in ra giá trị của các phần tử trên cây :
32, 51, 27, 83, 96, 11, 45, 75, 66.
1. Hàm tính độ lệch: doLech(goc)Lấy chiều cao nhánh trái trừ đi chiều cao nhánh phải.Nếu kết quả trả về bằng 2 $\rightarrow$ Cây đang bị lệch trái.Nếu kết quả trả về bằng -2 $\rightarrow$ Cây đang bị lệch phải.
2. Các hàm xoay để cân bằng cây: Khi có hiện tượng mất cân bằng, giải thuật chia làm 4 trường hợp xử lý dựa trên vị trí của phần tử mới chèn:
* Xoay đơn phải (xoayPhai - Trường hợp LL): Xảy ra khi nhánh trái lệch và phần tử mới lại nằm bên trái của con trái. Nút con trái sẽ được kéo lên làm gốc mới thay thế nút hiện tại.
* Xoay đơn trái (xoayTrai - Trường hợp RR): Xảy ra khi nhánh phải lệch và phần tử mới nằm bên phải của con phải. Nút con phải được kéo lên làm gốc mới.
* Xoay kép Trái - Phải (xoayKepTraiPhai - Trường hợp LR): Xảy ra khi nhánh trái lệch nhưng phần tử mới lại nằm bên phải của con trái. Giải thuật tiến hành xoayTrai ở nút con trước, biến nó thành trường hợp LL, sau đó xoayPhai ở nút gốc.
* Xoay kép Phải - Trái (xoayKepPhaiTrai - Trường hợp RL): Xảy ra khi nhánh phải lệch nhưng phần tử mới nằm bên trái của con phải. Giải thuật tiến hành xoayPhai ở nút con trước, đưa về trường hợp RR, rồi mới xoayTrai ở nút gốc.
3. Thêm, duyệt cây.
4. In cây.

  
## TUẦN 13

### ĐỀ BÀI: 
* Cài đặt cây NP tìm kiếm của bài toán dưới đây , tính độ phức tạp thuật toán của thuật toán tìm kiếm trên cây NP tìm kiếm.
## Độ phức tạp: Độ phức tạp tìm kiếm trên Cây nhị phân tìm kiếm (BST) không cố định mà phụ thuộc hoàn toàn vào hình dạng (chiều cao) của cây:
*Trường hợp trung bình / tốt nhất:*
 $O(\log_2 n)$, Điều kiện: Cây phân bố đều, cân bằng ở cả 2 nhánh trái và phải. Chiều cao cây lúc này đạt mức tối thiểu là $\approx \log_2 n$.
 
*Trường hợp xấu nhất:*
 $O(n)$, Điều kiện: Khi mảng dữ liệu đầu vào có thứ tự (tăng dần hoặc giảm dần), cây dựng lên sẽ bị suy biến lệch hoàn toàn về một phía (như một danh sách liên kết). Chiều cao cây lúc này bằng chính số phần tử $n$.

## TUẦN 12:
### ĐỀ BÀI: Cài đặt giải thuật sắp xếp vun đống cho các cây ví dụ trong slide và trên bảng, in ra từng trạng thái lưu trữ cho mỗi bước vun đống và sắp xếp.

## TUẦN 11: 
### ĐỀ BÀI: 
* Cài đặt cây đầy đủ, cây lệch trái, cây lệch phải, cây zigzac cho trên bảng theo 2 cấu trúc lưu trữ: tuần tự và móc nối.
* Cài đặt cây biểu thức và in biểu thức theo thứ tự duyệt trước, sau, giữa.

## TUẦN 9
### I. Bài cơ bản( quản lý dssv)  
**Các Test case:**  
* DS sinh viên rỗng, in ra rỗng.   
* DS sinh viên không rỗng, không có svien trùng ngày tháng năm sinh, in ra danh sách.   
* DS sinh viên không rỗng, có sinh viên trùng ngày tháng năm sinh, xóa sinh viên, in lại danh sách sinh viên.   
* Thêm một sinh viên mới vào danh sách ListSV đã sắp xếp và SV được sắp xếp theo đúng thứ tự ở DS mới( tích hợp chung với case3)
### II. Bài nâng cao(Bài toán Josephus)

### 1. Thiết kế giải thuật
* **Cấu trúc dữ liệu:** Sử dụng cấu trúc liên kết vòng, mỗi nút gồm STT người chơi và link (trỏ đến người kế tiếp).
* **Quy trình thực hiện:**
    * **B1:** Tạo danh sách liên kết, sau đó nối tạo danh sách liên kết vòng.
    * **B2:** Khai báo 2 con trỏ liên tiếp để thực hiện dò tìm và xóa.
    * **B3:** Lặp danh sách đến khi chỉ còn 1 người. Trong đó, 2 con trỏ $q$ và $p$ được dịch chuyển lên trước liên tục để tìm vị trí thứ $M$. Thực hiện xóa nút $p$ bằng lệnh `q->link = p->link`, sau đó lặp lại với $p$ mới.

### 2. Phân tích độ phức tạp và Thời gian chạy

**A. Độ phức tạp thuật toán (Xét trường hợp $M = 1$)**
* Mỗi lượt loại bỏ cần thực hiện $M$ bước nhảy con trỏ, tổng cộng có $N-1$ người bị loại.
* **Tổng số thao tác:** $M(N - 1) = (N - 1)$.
* **Độ phức tạp thời gian:** $O(n-1)$ hay xấp xỉ $O(n)$.

**B. Tính toán thời gian chạy với $N > 100.000$**
* **Phương pháp:** Sử dụng thư viện `<chrono>` để lấy một mốc thời gian ngay trước khi gọi hàm xử lý và một mốc ngay sau khi chạy xong. Hiệu của hai mốc này chính là thời gian thực thi.
* **Kết quả:** Với $N > 100.000$, thời gian thực hiện dao động khoảng **0.04s – 4s**.

### C. Test case
  * $N = 1, M = 0$
  * $N = 5, M = 0$
  * $N = 5, M = 1$
  * $N = 18, M = 2$
  * $N = 181.111, M = 1$
  * $N = 999.999, M = 1$

**Link Test case: https://docs.google.com/document/d/1-mD5z7hNUZU9Txs2ppGg89gG0k3W-ysY/edit?usp=sharing&ouid=112831662732966303492&rtpof=true&sd=true



## TUẦN 6
### I. Phân tích sơ bộ bài toán
1. Mô tả bài toán
Cần quản lý các file trong thư mục bằng danh sách liên kết đơn, trong đó:
-Mỗi file có: tên (name), thời gian (timestamp), kích thước (size).
-Danh sách được sắp xếp theo thời gian tăng dần.
Các thao tác:
1.	Thêm file mới (giữ thứ tự thời gian).
2.	Tính tổng dung lượng.
3.	Loại bỏ các file nhỏ nhất để tổng ≤ 32GB. 
2. Lý do chọn danh sách liên kết đơn
-Dễ chèn đúng vị trí (không cần dịch phần tử như mảng).
-Phù hợp với dữ liệu thay đổi liên tục (thêm/xóa file).
### II. Mô tả cấu trúc dữ liệu
1. Cấu trúc File
struct File {
    string name;
    long timestamp;
    double size;
};
-timestamp: xác định thứ tự file.
-size:dung lượng.
2. Cấu trúc Node
struct Node {
    File data;
    Node* next;
};
3. Danh sách
-Con trỏ đầu: Node* head 
-Ban đầu: head = NULL 
 ### III. Mô tả các hàm cần thực hiện
1. Tạo node
-Input: File 
-Output: Node mới 
2. Chèn file theo thứ tự thời gian
-Input: danh sách + file mới.
-Output: danh sách đã chèn.
-Yêu cầu: giữ thứ tự tăng dần theo timestamp.
3. Tính tổng dung lượng
-Input: danh sách.
-Output: tổng size.
4. Xóa file nhỏ nhất
•	Input: danh sách.
•	Output: danh sách sau khi xóa. 
•	Cách: 
-duyệt tìm node có size nhỏ nhất.
-xóa node đó.
5. Tối ưu dung lượng (≤ 32GB)
•	Lặp: nếu tổng > 32 → xóa file nhỏ nhất 
### IV. Phân tích giải thuật chi tiết
1. Chèn có thứ tự
-Nếu danh sách rỗng thì chèn đầu.
-Nếu nhỏ hơn head thì chèn đầu .
-Ngược lại: 
+tìm vị trí phù hợp.
+chèn vào giữa.
Độ phức tạp: O(n).
2. Tính tổng dung lượng
-Duyệt toàn bộ danh sách.
-Cộng dồn size.
Độ phức tạp: O(n).
3. Tìm và xóa file nhỏ nhất
-Duyệt danh sách: 
-tìm node có size nhỏ nhất.
-Xóa node đó.
Độ phức tạp:O(n).
4. Tối ưu dung lượng
-Tính tổng ban đầu 
-While tổng > 32: 
+tìm file nhỏ nhất.
+xóa file đó.
+cập nhật tổng.
Độ phức tạp:O(n²)

