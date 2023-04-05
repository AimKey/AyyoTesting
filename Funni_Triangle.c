#include<stdio.h>
#include<math.h>

void PrintSpaces();
void PrintNum();

void PrintSpaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

// Mau chot van de
void PrintNum(int n, int MiddleValue, int MiddlePos) {
    int arr[50], count = 0;
    int j = n;
    
    for (int i = 0; i <= MiddlePos; i++) {
        if (j >= 10) {
            j = j % 10;
        }
        printf("%d ", j);
        if (i < MiddlePos) {
            arr[count] = j;
            count++;
        }
        j++;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
}

int main () {
    int n, spc;
    printf("Nhap N: ");
    scanf("%d", &n);
    spc = (n - 1) * 2;
    int num = 1, MiddleValue = 1, MiddlePos = 0, count;
    int arr[50];
    for (int i = 1; i <= n; i++) {
        PrintSpaces(spc);
        PrintNum(i, MiddleValue, MiddlePos);
        arr[0] = '\0';
        MiddlePos++;
        MiddleValue += 2;
        num += 2;
        spc -= 2;
        printf("\n");
    }
    return 0;
}
