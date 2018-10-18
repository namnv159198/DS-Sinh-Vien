#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct {
    char name[100];
    char msv [6];
    char phone [20] ;
}Sinhvien;

Sinhvien sv[10];
void menu(){
    printf("-------------------------MENU-------------------------\n");
    printf("1.Them moi sinh vien.\n");
    printf("2.Hien thi danh sach sinh vien.\n");
    printf("3.Luu danh sach sinh vien ra FILE.\n");
    printf("4.Doc sach sinh vien tu FILE.\n");
    printf("5.Thoat khoi chuong trinh.\n");
}

void nhap (Sinhvien sv[],int n){
    for(int i = 0;i<n;i++){
        printf("Nhap thong tin sinh vien thu %d \n",i+1);
        do{
            printf("Nhap ma sinh vien : ");
            fgets(sv[i].msv,6,stdin);
            if( strlen(sv[i].msv) !=5 ){
                printf("Ma sinh vien khong du 5 ky tu.Hay nhap lai!\n");
            }
        } while(strlen(sv[i].msv )!= 5);
        fflush(stdin);
        printf("Nhap ten sinh vien: ");
        fgets(sv[i].name,sizeof(sv[i].name),stdin);
        strlen(sv[i].name);
        sv[i].name[strlen(sv[i].name) - 1] =' ';
        fflush(stdin);
        printf("Nhap so dien thoai : ");
        fgets(sv[i].phone,sizeof(sv[i].phone),stdin);
        sv[i].phone[strlen(sv[i].phone) -1] =' ';
        fflush(stdin);
    }
    if(n==10){
        printf("Danh sach sinh vien da du .\n");
    }

}

void xuat(Sinhvien sv[],int n){
    printf("--------------------Danh sach sinh vien--------------------\n");
    printf("%-20s  | %-20s  | %-20s \n","- Ma sinh vien "," Ten "," So dien thoat");
    for(int i = 0;i<n;i++){
        printf("- %-20s|  %-20s |  %-20s\n",sv[i].msv,sv[i].name,sv[i].phone);
    }

}

void luufile(const char *p,Sinhvien sv[],int n){
    FILE *fp;
    fp = fopen(p,"w");
    if(fp != NULL){
        fprintf(fp,"--------------------Danh sach sinh vien--------------------\n");
        fprintf(fp,"%-20s  | %-20s  | %-20s \n","- Ma sinh vien "," Ten "," So dien thoat");
        for(int i = 0;i<n;i++){
            fprintf(fp,"- %-20s|  %-20s |  %-20s\n",sv[i].msv,sv[i].name,sv[i].phone);
        }
        fclose(fp);
        printf("Da luu danh sach sinh vien vao file : Danhsachsinhvien.txt\n");
    }
    else printf("Tap tin chua duoc mo\n");
}

void docfile(const char *p,Sinhvien sv[],int n){
    FILE *fp;
    fp = fopen(p,"r");
    fscanf(fp,"--------------------Danh sach sinh vien--------------------\n");
    fscanf(fp,"%-20s  | %-20s  | %-20s \n","- Ma sinh vien "," Ten "," So dien thoat");
    printf("--------------------Danh sach sinh vien--------------------\n");
    printf("%-20s  | %-20s  | %-20s \n","- Ma sinh vien "," Ten "," So dien thoat");
    for(int i = 0;i<n;i++){
        fscanf(fp,"- %-20s|  %-20s |  %-20s\n",sv[i].msv,sv[i].name,sv[i].phone);
        printf("- %-20s|  %-20s |  %-20s\n",sv[i].msv,sv[i].name,sv[i].phone);
    }
    printf("\n");
    fclose(fp);
}



int main(){
    int n,choice;
    do{
        printf("Nhap so luong sinh vien : ");
        scanf("%d",&n);
        if(n<=0 || n > 10){
            printf("So luong sinh vien khong the nho hon 0 hoac lon hon 10.\n");
        }
    } while(n > 10);
    fflush(stdin);
    while(1==1){
        menu();
        printf("Nhap lua chon chua ban : \n");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice){
            case 1:
                nhap(sv,n);
                break;
            case 2:
                xuat(sv,n);
                break;
            case 3:
                luufile("Danhsachsinhvien.txt",sv,n);
                break;
            case 4:
                printf("In danh sach sinh vien tu file: \n");
                docfile("Danhsachsinhvien.txt",sv,n);
                break;
            case 5:
                printf("Xin cam on. Hen gap lai !\n");
                exit(1);
            default :
                printf("Ban da nhap sai lua chon. Hay nhap lai!\n");
                break;
        }
    }
}






