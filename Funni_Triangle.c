#include<stdio.h>
#include<math.h>

int Spaces();
int PrintSpaces();
void PrintNum();
int Return1Num();

// Cai nay dung 1 lan
int Spaces(int n) {
    int temp = 0;
    for (int i = 1; i < n; i++) {
        temp += 2;
    }
    return temp;
}

int PrintSpaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

// Cai nay quan trong
int Return1Num(int n) {
    int temp = n % 10;
    return temp;
}

// Mau chot van de
void PrintNum(int n, int MiddleValue, int MiddlePos) {
    // n la so dong, dong 1 ko in, dong 2 in 1, dong 3 in 2
    int arr[50], count = 0;
    int j = n;
    if (j >= 10) {
        j = Return1Num(j);
    }
    for (int i = 0; i < MiddlePos; i++) {
        printf("%d ", j);
        arr[count] = j;
        count++;
        j++;
        if (j >= 10) {
            j = Return1Num(j);
        }
    }
    // Sau khi in het cac cot dau
    if (MiddleValue >= 10) {
        MiddleValue = Return1Num(MiddleValue);
        printf("%d", MiddleValue);
    } else if (n > 1) {
        printf("%d", MiddleValue);
    }
    // In phan con lai cua tam giac
    for (int i = count - 1; i >= 0; i--) {
        printf(" %d", arr[i]);
    }
}


int main () {
    /*
    Cac vd can giai quyet:
    1. Khoang cach tung dong (check)
    2. In so va khoang cach giua chung (check)
    3. In cot giua (check)
    4. In theo huong nguoc lai (dung array?) (Check)
    5. Profit ???
    */
    int n, spc;
    printf("%d\n", 10 % 10);
    printf("Nhap N: ");
    scanf("%d", &n);
    spc = Spaces(n);
    printf("So khoang cach cho dong tiep theo: %d\n", spc);
    int num = 1, MiddleValue = 1, MiddlePos = 0, count;
    int arr[50];

    for (int i = 1; i <= n; i++) {
        PrintSpaces(spc);

        if (i == 1)
        printf("%d", MiddleValue);

        PrintNum(i, MiddleValue, MiddlePos);
        //Giai thich
        arr[0] = '\0'; // Reset array
        MiddlePos++; // 
        MiddleValue += 2;
        num += 2;
        spc -= 2;
        printf("\n");
    }
    return 0;
}
