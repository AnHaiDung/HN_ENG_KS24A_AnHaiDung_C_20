#include <stdio.h>

 struct Product {
 	int maSanPham;
 	char tenSanPham[50];
 	float giaNhap;
 	float giaBan;
 	int soLuong;
 };
 
 void addProduct(struct Product sp[],int *size);
 void showProduct(struct Product sp[],int size);
 void addOneProduct(struct Product sp[],int *size,float *revenue);
 void updateProduct(struct Product sp[],int size);
 void sortProduct(struct Product sp[],int size);
 void findProduct(struct Product sp[],int size);
 void sellProduct(struct Product sp[],int size,float *revenue);
 void revenueProduct(struct Product sp[],float revenue);

int main(){	
	struct Product sp[100];
	int check=0;
	int size=0;
	float revenue=0;
	int chose;
	do {
		printf("MENU\n");
		printf("1.nhap so luong va thong tin san pham\n");
		printf("2.hien thi danh sach san pham\n");
		printf("3.nhap san pham\n");
		printf("4.cap nhat thong tin san pham\n");
		printf("5.sap xep san pham theo gia\n");
		printf("6.tim kiem san pham\n");
		printf("7.ban san pham\n");
		printf("8.doanh thu hien tai\n");
		printf("9.thoat\n");
		scanf("%d",&chose);
		switch(chose){
			case 1:
				check=1;
				addProduct(sp,&size);
				break;
			case 2:
				if (check==0){
					printf("nhap so luong va thong tin san pham\n");
				} else {
					showProduct(sp,size);
				}
				break;
			case 3:
				if (check==0){
					printf("nhap so luong va thong tin san pham\n");
				} else {
					addOneProduct(sp,&size,&revenue);
				}
				break;
			case 4:
				if (check==0){
					printf("nhap so luong va thong tin san pham \n");
				} else {
					updateProduct(sp,size);
				}
				break;
			case 5:
				if (check==0){
					printf("nhap so luong va thong tin san pham \n");
				} else {
					sortProduct(sp,size);
				}
				break;
			case 6:
				if (check==0){
					printf("nhap so luong va thong tin san pham \n");
				} else {
					findProduct(sp,size);
				}
				break;
			case 7:
				if (check==0){
					printf("nhap so luong va thong tin san pham \n");
				} else {
					sellProduct(sp,size,&revenue);
				}
				break;
			case 8:
				if (check==0){
					printf("nhap so luong va thong tin san pham \n");
				} else {
					revenueProduct(sp,revenue);
				}
				break;
			case 9:
				printf("chuong trinh ket thuc");
				break;
			default :
			printf("khong thuoc menu\n");								
		}
	} while (chose!=9);
	

	return 0;
}
void addProduct(struct Product sp[],int *size){
	printf("nhap so luong san pham ");
	scanf("%d",size);
	getchar();
	for (int i=0;i<*size;i++){
		sp[i].maSanPham=i+1;
		printf("thong tin san pham thu %d\n",i+1);
		printf("ten san pham ");
		fgets(sp[i].tenSanPham,50,stdin);
		sp[i].tenSanPham[strcspn(sp[i].tenSanPham, "\n")] ='\0';
		printf("gia nhap ");
		scanf("%f",&sp[i].giaNhap);
		printf("gia ban ");
		scanf("%f",&sp[i].giaBan);
		printf("so luong ");
		scanf("%d",&sp[i].soLuong);
		getchar();
	}	
}
void showProduct(struct Product sp[],int size){
	for (int i=0;i<size;i++){
		printf("san pham thu %d \n",i+1);
		printf("ma san pham: %d \n",sp[i].maSanPham);
		printf("ten san pham: %s \n",sp[i].tenSanPham);
		printf("gia nhap: %.2f \n",sp[i].giaNhap);
		printf("gia ban: %.2f \n",sp[i].giaBan);
		printf("so luong: %d \n",sp[i].soLuong);
	}
}
void addOneProduct(struct Product sp[],int *size,float *revenue){
	int check=0;
	char add[50];
	getchar();
	printf("nhap ten san pham ");
	fgets(add,50,stdin);
	add[strlen(add) -1] = '\0' ;
	for (int i=0;i<*size;i++){
		if (strcmp(sp[i].tenSanPham,add)==0){
			check=1;
			sp[i].soLuong+=1;
			*revenue -= sp[i].giaNhap;
		}
	}
	if (check==0){
		strcpy( sp[*size].tenSanPham, add);
		sp[*size].maSanPham = (*size)+1;
		printf("Gia nhap: ");
		scanf("%f", &sp[*size].giaNhap);
		printf("Gia ban: ");
		scanf("%f", &sp[*size].giaBan);
		printf("So luong: ");
		scanf("%d", &sp[*size].soLuong);
		*revenue -= sp[*size].giaNhap;
		(*size)++ ;
	}
} 	
void updateProduct(struct Product sp[],int size){
	int check=0;
	int index;
	printf("nhap ma san pham muon sua ");
	scanf("%d",&index);
	for (int i=0;i<size;i++){
		if (sp[i].maSanPham==index){
			check=1;
			getchar();
			printf("ten san pham ");
		    fgets(sp[i].tenSanPham,50,stdin);
		    sp[i].tenSanPham[strcspn(sp[i].tenSanPham, "\n")] = '\0';
	 	    printf("gia nhap ");
		    scanf("%f",&sp[i].giaNhap);
		    printf("gia ban ");
		    scanf("%f",&sp[i].giaBan);
		    printf("so luong ");
		    scanf("%d",&sp[i].soLuong);
		    getchar();
		}
	}
	if (check==0){
		printf("khong co san pham\n");
	}
}
void sortProduct(struct Product sp[],int size){
	int index;
	struct Product temp;
	printf("1.tang dan \n");
	printf("2.giam dan \n");
	scanf("%d",&index);
	if (index==1){
		for (int i=0;i<size;i++){
			for (int j=0;j<size-i-1;i++){
				if (sp[j].giaBan>sp[j+1].giaBan){
					temp=sp[j];
					sp[j]=sp[j+1];
					sp[j+1]=temp;
				}
			}
	    }
	}
	if (index==2){
		for (int i=0;i<size;i++){
			for (int j=0;j<size-i-1;i++){
				if (sp[j].giaBan<sp[j+1].giaNhap){
					temp=sp[j];
					sp[j]=sp[j+1];
					sp[j+1]=temp;
				}
			}
	    }
	}
	if (index>2 || index<1){
		printf("lua chon khong ton tai\n");
	}
}
void findProduct(struct Product sp[],int size){
	char find[50];
	int check=0;
	getchar();
	printf("nhap ten san pham muon tim ");
	fgets(find,50,stdin);
	find[strlen(find)-1] = '\0';
	for (int i=0;i<size;i++){
		if (strcmp(sp[i].tenSanPham,find)==0){
			check=1;
			printf("ma san pham : %d \n",sp[i].maSanPham);
			printf("ten san pham : %s \n",sp[i].tenSanPham);
			printf("gia nhap : %f \n",sp[i].giaNhap);
			printf("gia ban : %f \n",sp[i].giaBan);
			printf("so luong : %d \n",sp[i].soLuong);
		}
	}
	if (check==0){
		printf("khong tim thay san pham\n");
	}
}
void sellProduct(struct Product sp[],int size,float *revenue){
	int id,quantity,check=0;
	printf("nhap ma san pham muon ban ");
	scanf("%d",&id);
	for (int i=0;i<size;i++){
		if (sp[i].maSanPham==id){
			check=1;
			printf("nhap so luong muon ban ");
			scanf("%d",&quantity);
			if (sp[i].soLuong==0){
				printf("san pham da het hang !\n");
			} else if (sp[i].soLuong<quantity){
				printf("so luong san pham khong du !\n");
			} else {
				sp[i].soLuong-=quantity;
				*revenue += sp[i].giaBan * quantity ;
			}
		}
	}
	if (check==0){
		printf("khong tim thay san pham ! \n");
	}
}
void revenueProduct(struct Product products[],float revenue){
	printf("doanh thu hien tai : %f \n",revenue);
}


