#include<stdio.h.>
int main(){
	int i=1;
	while(i<=10){
	printf("%d\n",i);
	i++;
}
printf("\n");
printf("gia tri cua bien i sau vong lap i: %d",i);
  return 0;
}
// while được dùng khi mà không biết vòng lặp nó sẽ chạy đến bao nhiêu
// một số dạng while hay gặp là 
// đếm số chữ số
// tính tổng các chữ số
// đếm số chẵn,đếm số lẻ
// tìm số thuận nghịch 




// ví dụ nhập một số từ bàn phím, tính xem nó có bao nhiêu chữ số 
// ví dụ ta nhập 1234
    
    int main(){
    	int n;
    	scanf("%d",&n);
	    int ans = 0; // đếm số lượng chữ số ta dùng biến ans
	    while(n!=0){
	    	++ans;   // tăng số lượng chữ số cua n lên 1 đơn vị
	    n/=10 ;	
		}
	}

// bây giờ nhập n bằng 1234, lập tức nó nhảy vào trong while nó check điều kiện
// điều kiện thỏa thì nó thực hiện cái câu lệnh bên trong while
// ban đầu ans khởi tạo bằng không thì nó tăng ans lên 1 
// lấy n chia cho 10 ta được 123 vì int, 
// sau đó nó quay trở lại check tiếp cái điều kiện
// thỏa thì nó lại tăng ans lên 1 đơn vị 
// lấy n chia cho 10 ta được 12
// ta cứ chia đến khi n còn bằng 1
// lấy 1 chia cho 10 thì bằng 0, check điều kiện không thỏa vòng lặp dừng 
// lúc này ta đếm đc 4 chữ số
// giá trị của biến n sau vong lap là băng 0



// dạng 2 tính tổng số của các chữ số 
int main(){
    	int n;
    	scanf("%d",&n);
	    int sum  = 0;
	    while(n!=0){
	    sum += n % 10;    // cong chu so hang don vi vao sum 
	    n/=10 ;	
	}
	printf("%d", sum);
	
	
	
	
// Cú pháp do while 
int main(){
	int i=1 
	do {
		printf ("in ra gia tri cua i:%d",i);
		
	}while (i==5);
	return 0;
}	
   
// rồi nó sẽ hoạt động như sau
// nó không có check điều kiện trước,nó sẽ in ra biến i trước, rồi nó mới check điều kiện
// khi ta in ra thì vẫn i ra giá trị của i bằng 1
// sau đó nó mới check rồi thấy điều kiện sai nó mới dừng vòng lặp
// nó cứ thực hiện câu lệnh bên trong nó đã

int main(){
	int i=1 
	do {
		printf ("in ra gia tri cua i:%d\n",i);
		i++;
	}while (i<=5);
	return 0;

// gia tri cua bien i sau vòng lặp này sẽ là sau
// ban đầu nó in ra 1 
// sau đó nó tăng i lên 1 đơn vị là i=2 sau đó nó kiểm tra điều kiên
// điều kiện thỏa vì i nó nhỏ hơn 5, nó lại tiêps tục in ra i = 2 
// sẽ chạy như thế đến khi i = 6 thì nó kiểm tra điều kiện thấy sai nó mới dừng vòng lặp


// nhap gia tri cua n la so nguyen khong am, neu so am vui long nhap lai
   int main (){
   	int n;
   	do{
   		scanf("%d",n);
	  if (n<0) printf ("gia tri nhap khong hop le vui long nhap lai \n");
	   }while (n<0);
	   return 0;
   }
   
   
   
   
   
   
   
   
   