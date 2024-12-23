#include <stdio.h>
#include <string.h>
typedef struct {
	int MaSach;
	char TenSach[50];
	char TacGia[30];
	float GiaTien;
	char TheLoai[20];
} Sach;

void addBook( Sach book[], int *n );
void showBook( Sach book[], int n);
void addBook( Sach book[], int *n );
void delBook( Sach book[], int *n );
void updateBook( Sach book[], int n);
void sortBook( Sach book[], int n );
void searchBook( Sach book[], int n );


int main(){
	Sach book[100];
	int chose;
	int count=-1;
	int n=0;
	do{
		printf("Menu\n");
		printf("1.Nhap so luong va thong tin sach\n");
		printf("2.Hien thi thong tin sach\n");
		printf("3.Them sach vao vi tri\n");
		printf("4.Xoa sach theo ma sach\n");
		printf("5.Cap nhat thong tin theo ma sach\n");
		printf("6.Sap xep sach theo gia(tang/giam)\n");
		printf("7.Tim kiem sach theo ten\n");
		printf("8.Thoat\n");
		printf("Lua chon cua ban: \n");
		scanf("%d", &chose );
		fflush(stdin);
		
		switch( chose){
			case 1:{
				addBook(book, &n);
				count=1;
				break;
			}
			case 2:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n ");
				}else{
					showBook(book, n);
				}
				break;
			}
			case 3:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n ");
				}else{
					addBook(book, &n);
				}
				break;
			}
			case 4:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n ");
				}else{
					delBook(book, &n);
				}
				break;
			}
			case 5:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n ");
				}else{
					updateBook(book, n);
				}
				break;
			}
			case 6:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n");
				}else{
					sortBook(book, n);
				}
				break;
			}
			case 7:{
				if (count==-1){
					printf("Nhap so luong va thong tin sach truoc\n");
				}else{
					searchBook(book, n);
				}
				break;
			}
			case 8:{
				printf("Ket thuc chuong trinh ");
				break;
			}
			default:{
				printf("khong thuoc menu\n");
				break;
			}
		}
	}while(chose!=8);

	return 0;
}

void addBook( Sach book[], int *n){
	printf("\nNhap so luong sach: ");
	scanf("%d", n);
	fflush(stdin);
	for ( int i=0;i<*n;i++){
		book[i].MaSach = i+1 ;
		printf("Sach thu %d: \n",i+1);
		printf("Nhap ten sach: \n");
		fgets(book[i].TenSach,50, stdin);
		book[i].TenSach[strlen(book[i].TenSach)-1] = '\0' ;
		printf("tac gia: ");
		fgets(book[i].TacGia,30,stdin);
		book[i].TacGia[strlen(book[i].TacGia)-1] = '\0' ;
		printf("the loai: ");
		fgets(book[i].TheLoai,30,stdin);
		book[i].TheLoai[strlen(book[i].TheLoai)-1] = '\0' ;
		printf("gia tien: ");
		scanf("%f", &book[i].GiaTien);
		fflush(stdin);
	}
}
void showBook( Sach book[],int n){
	for ( int i = 0; i<n ; i++){
		printf(" %d. %s\n", book[i].MaSach, book[i].TenSach);
		printf(" Tac gia: %s\n", book[i].TacGia);
		printf(" The loai: %s\n", book[i].TheLoai);
		printf(" Gia tien: %.2f\n", book[i].GiaTien);
	}
}

void addItem( Sach book[], int *n ){
	int index;
	do{
		printf("Nhap vi tri muon them: \n");
		scanf("%d", &index);
	}while(index<1 || index> (*n)+1);
	fflush(stdin);
	for ( int i = *n; i>= index ; i--){
		book[i] = book[i-1];
		book[i].MaSach  = book[i-1].MaSach + 1 ;
	}
	book[index-1].MaSach = index ;
	printf("Nhap ten sach: \n");
	fgets(book[index-1].TenSach , 50, stdin);
	book[index-1].TenSach[strlen(book[index-1].TenSach)-1] = '\0' ;
	printf("Nhap tac gia: \n");
	fgets(book[index-1].TacGia , 30, stdin);
	book[index-1].TacGia[strlen(book[index-1].TacGia) -1] = '\0' ;
	printf("Nhap the loai: \n");
	fgets(book[index-1].TheLoai , 30, stdin);
	book[index-1].TheLoai[strlen(book[index-1].TheLoai) -1] = '\0' ;
	printf("Nhap gia tien: \n");
	scanf("%f", &book[index-1].GiaTien);
	fflush(stdin);
	(*n)++;
	for ( int i = 0; i< *n ; i++){
		printf("%d. %s\n", book[i].MaSach, book[i].TenSach);
		printf("Tac gia: %s\n", book[i].TacGia);
		printf("The loai: %s\n", book[i].TheLoai);
		printf("Gia tien: %.2f\n", book[i].GiaTien);
	}
}
void updateBook( Sach book[], int n ){
	int index;
	int input;
	int check=-1;
	printf("Nhap ma sach muon sua: \n");
	scanf("%d", &input);
	fflush(stdin);
	for ( int i =0; i< n; i++){
		if ( book[i].MaSach==input ) {
			check = 1;
			index = i;
			break;
		}
	}
	if (check==-1 ){
		printf("Khong co ma sach can sua\n");
	}else{
		printf("\nNhap ten sach: ");
		fgets(book[index].TenSach , 50, stdin);
		book[index].TenSach[strlen(book[index].TenSach) -1] = '\0' ;
		printf("Nhap tac gia: ");
		fgets(book[index].TacGia , 30, stdin);
		book[index].TacGia[strlen(book[index].TacGia) -1] = '\0' ;
		printf("Nhap the loai: ");
		fgets(book[index].TheLoai , 30, stdin);
		book[index].TheLoai[strlen(book[index].TheLoai) -1] = '\0' ;
		printf("Nhap gia tien: ");
		scanf("%f", &book[index].GiaTien);
		fflush(stdin);
		for ( int i = 0; i<n ; i++){
			printf("%d. %s\n", book[i].MaSach, book[i].TenSach);
			printf("Tac gia: %s\n", book[i].TacGia);
			printf("The loai: %s\n", book[i].TheLoai);
			printf("Gia tien: %.2f\n", book[i].GiaTien);
		}
	}
}

void delBook( Sach book[], int *n ){
	int index;
	int input;
	int check=-1;
	printf("Nhap ma sach muon xoa: ");
	scanf("%d", &input);
	fflush(stdin);
	for(int i=0;i<*n;i++){
		if(book[i].MaSach==input){
			index = i;
			check = 1;
			break;
		} 
	}
	if(check==-1){
		printf("Khong co ma sach can sua\n");
	}else{
		for(int i=index;i<*n;i++){
			book[i].MaSach=book[i+1].MaSach-1 ;
			book[i]=book[i+1];
		}
		(*n)--;	
		for ( int i = 0; i< *n ; i++){
			printf("%d. %s\n", book[i].MaSach, book[i].TenSach);
			printf("Tac gia: %s\n", book[i].TacGia);
			printf("The loai: %s\n", book[i].TheLoai);
			printf("Gia tien: %.2f\n", book[i].GiaTien);
		}
	}
}

void sortBook( Sach book[], int n){
	char chose;
	do{
		printf("a. Gia tang dan\n");
		printf("b. Gia giam dan\n");
		printf("Lua chon cua ban: \n");
		scanf("%c", &chose );
		fflush(stdin);
	}while(chose!='a'&&chose!='b' );
	fflush(stdin);
	if (chose =='a'){
		for(int i=0;i<n;i++){
			for ( int j=0;j<n-1-i;j++){
				if ( book[j].GiaTien > book[j+1].GiaTien ){
					Sach temp = book[j];
	                book[j] = book[j+1];
	                book[j+1] = temp;
				}
			}
		}
	}else{
		for( int i = 0; i< n; i++){
			for ( int j = 0; j< n-1-i; j++){
				if ( book[j].GiaTien < book[j+1].GiaTien  ){
					Sach temp = book[j];
	                book[j] = book[j+1];
	                book[j+1] = temp;
				}
			}
		}
	}
	for ( int i = 0; i<n ; i++){
		printf("%d. %s\n", book[i].MaSach, book[i].TenSach);
		printf("Tac gia: %s\n", book[i].TacGia);
		printf("The loai: %s\n", book[i].TheLoai);
		printf("Gia tien: %.2f\n", book[i].GiaTien);
	}
}
void searchBook( Sach book[], int n){
	char input[50];
	int count = 0;
	fflush(stdin);
	printf("Nhap ten sach can tim: \n");
	fgets( input, 50, stdin);
	input[strlen(input) -1] = '\0';
	for ( int i = 0; i< n; i++){
		if ( strstr(book[i].TenSach, input) != NULL ){
			count = 1;
			printf("%d. %s\n", book[i].MaSach, book[i].TenSach);
		    printf("Tac gia: %s\n", book[i].TacGia);
		    printf("The loai: %s\n", book[i].TheLoai);
		    printf("Gia tien: %.2f\n", book[i].GiaTien);
		}
	}
	if (count==0) printf("\n Khong tim thay sach!");
}

