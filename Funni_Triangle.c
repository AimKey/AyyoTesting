#include<stdio.h>
#include<math.h>

void PrintSpaces();
void PrintNum();

void PrintSpaces(int n) {
    // Note la int n nay KHAC HOAN TOAN voi cai n user nhap vao nhe (hoc ham)
    // n dang co gia tri cua spc
    // In ra so khoang cach cua dong (vd nhu 10 row thi dong dau tien so 1 no cach bao nhieu spc do)
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

// Mau chot van de
void PrintNum(int n, int MiddleValue, int MiddlePos) {
    int arr[50], count = 0;
    int j = n;
    // Nen nho n KHAC HOAN TOAN voi n cua user, n day dang mang gia tri cua i
    // Ham nay sinh ra de viet cac so cua tung dong (vd i = 2 thi ham nay viet so cua dong 2)
    for (int i = 0; i <= MiddlePos; i++) {
        if (j >= 10) {
            // Neu j >= 10 thi ta chi lay phan don vi (phan du)
            j = j % 10;
        }
        printf("%d ", j); // In ra cac so ben trai VA truc mid
        /*
        Ly do cai dong nay ton tai la de cho Array (cai mang ghi phan doi) ko nhan gia tri truc chinh
        (VD 1 2 1, Array se chi nhan toi gia tri 1. Neu nhan truc giua (gia tri 2) thi no thanh 1221)
        */
       // Noi chung hieu don gian la Array co nhiem vu in cac gia tri doi ben phai (ko bao gom truc mid)
        if (i < MiddlePos) {
            arr[count] = j; // Array lay gia tri ben trai truc mid
            count++; // Tang bien dem cho Array
        }
        j++;
    }
    // In ra gia tri ben phai (theo huong nguoc lai)
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

int main () {
    /*
    Huong lam cua PMK:
    1. In ra khoang cach dau tien
    2. In cho toi so o giua (goi la in ra cho truc mid)
    3. In nguoc lai
    4. Profit
    */
    int n, spc;
    printf("Nhap N: ");
    scanf("%d", &n);
    // Space nay la khoang cach de chua ra cho so (giong voi so 11 ben bai cua @An)
    spc = (n - 1) * 2;
    int MiddleValue = 1, MiddlePos = 0, count;
    //Array nay ti nua se giai thich
    int arr[50];
    for (int i = 1; i <= n; i++) {
        // 1 cai ham nhan spc duoc tinh o tren vao (luot len de xem giai thich)
        PrintSpaces(spc);
        
        // In ra so cua tam giac (luot len tren)
        PrintNum(i, MiddleValue, MiddlePos);

        arr[0] = '\0'; // Reset array
        MiddlePos++; // Tang vi tri cua truc giua
        MiddleValue += 2; // Cai nay chac ez r ha
        spc -= 2; // Moi dong them mot xuong duoi thi ta chua it di 2 spc (1 cua so moi, 1 spc giua 2 so)
        printf("\n");// Xuong dong.
    }
    return 0;
}
