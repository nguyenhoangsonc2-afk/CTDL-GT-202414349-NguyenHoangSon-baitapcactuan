### TUẦN 9
## I. Bài cơ bản( quản lý dssv)  
**Các Test case:**  
* DS sinh viên rỗng, in ra rỗng.   
* DS sinh viên không rỗng, không có svien trùng ngày tháng năm sinh, in ra danh sách.   
* DS sinh viên không rỗng, có sinh viên trùng ngày tháng năm sinh, xóa sinh viên, in lại danh sách sinh viên.   
* Thêm một sinh viên mới vào danh sách ListSV đã sắp xếp và SV được sắp xếp theo đúng thứ tự ở DS mới( tích hợp chung với case3)
## II. Bài nâng cao(Bài toán Josephus)

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



### TUẦN 6
## I. Phân tích sơ bộ bài toán
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
## II. Mô tả cấu trúc dữ liệu
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
 ## III. Mô tả các hàm cần thực hiện
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
## IV. Phân tích giải thuật chi tiết
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

