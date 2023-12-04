#include <stdio.h>
#include <string.h>
struct SinhVien
{
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};
struct SinhVien studentList[100];
typedef struct SinhVien std;
void output(std studentList[], int i)
{
    printf("ID: %d  Name: %s  Birthday: %s   Address: %s   Status:%d\n\n",
           studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
}
void input(std studentList[], int i)
{
    printf("Nhap ma sinh vien ");
    scanf("%d", &studentList[i].id);
    printf("Nhap ten sinh vien ");
    getchar();
    gets(studentList[i].name);
    printf("Nhap ngay thang nam sinh ");

    gets(studentList[i].birthday);

    printf("Nhap dia chi cu tru ");
    gets(studentList[i].address);

    printf("Nhap trang thai ");
    scanf("%d", &studentList[i].status);
    printf("\n");
}
int main()
{
    int lenStdList = 2;
    int count;
    struct SinhVien studentList[2] =
        {
            {1, "Nam", "5/2/2004", "15 tran phu", 1},
            {2, "Dung", "7/9/2001", "25 tran phu", 0}};
    do
    {
        printf("-------------------MENU----------------------\n");
        printf("1.In ra toan bo danh sach sinh vien co trong mang\n");
        printf("2.Them sinh vien moi\n");
        printf("3.Cap nhap thong tin sinh vien\n");
        printf("4.Xoa thong tin cua sinh vien\n");
        printf("5.Sap xep\n");
        printf("6.Tim kiem sinh vien theo ten\n");
        printf("7.Tim kiem sinh vien theo Status\n");
        printf("8.Thoat\n");
        int choice;
        printf("Nhap lua chon cua ban ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            for (int i = 0; i < lenStdList; i++)
            {
                output(studentList, i);
            }

            break;
        case 2:
            int n;
            printf("Nhap so sinh vien can them ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                input(studentList, lenStdList);
                lenStdList++;
            }
            break;
        case 3:
            printf("Nhap ten sinh vien muon thay doi thong tin ");
            count = 0;
            char update_name[50];
            getchar();
            gets(update_name);
            for (int i = 0; i < lenStdList; i++)
            {
                if (strcmp(update_name, studentList[i].name) == 0)
                {
                    input(studentList, i);
                    count = 1;
                }
            }
            if (count == 0)
            {
                printf("Khong tim thay");
            }
            break;
        case 4:
            printf("Nhap ten sinh vien muon xoa ");
            count = 0;
            char delete_name[50];
            getchar();
            gets(delete_name);
            for (int i = 0; i < lenStdList; i++)
            {
                if (strcmp(delete_name, studentList[i].name) == 0)
                {
                    for (int j = i; j < lenStdList ; j++)
                    {
                        studentList[j] = studentList[j + 1];
                    }
                    count = 1;
                    lenStdList--;
                }
            }
            if (count == 0)
            {
                printf("Khong tim thay");
            }
            break;
        case 5:
            for (int i = 0; i < lenStdList - 1; i++)
            {
                for (int j = 0; j < lenStdList - i - 1; j++)
                {
                    if (studentList[j].name[0] > studentList[j + 1].name[0])
                    {
                        std temp = studentList[j];
                        studentList[j] = studentList[j + 1];
                        studentList[j + 1] = temp;
                    }
                }
            }
            break;
        case 6:
            char find_name[50];
            printf("nhap ten can tim kiem:");
            getchar();
            gets(find_name);
            int start = 0;
            int end = lenStdList;
            int mid;
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (strcmp(studentList[mid].name, find_name) == 0)
                {
                    break;
                }
                else if (studentList[mid].name < find_name)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            if (strcmp(studentList[mid].name, find_name) == 0)
            {
                output(studentList, mid);
            }
            else
            {
                printf("Khong tim thay ");
            }
            break;
        case 7:
            printf("Nhap so trang thai can tim ");
            int find_status;
            scanf("%d", &find_status);
            for (int i = 0; i < lenStdList; i++)
            {
                if (studentList[i].status == find_status)
                {
                    output(studentList, i);
                }
            }
            break;
        case 8:
            return 0;
        default:
            printf("vui long nhap 1-8");
            break;
        }
    } while (1 == 1);
}