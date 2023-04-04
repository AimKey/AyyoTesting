#include<stdio.h>
#include<math.h>

int Spaces();
int PrintSpaces();
void PrintNum();
int Return1Num();

int Return1Num(int n) {
    int temp = n % 10;
    return temp;
}

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
    int n, spc;
    printf("%d\n", 10 % 10);
    printf("Nhap N: ");
    scanf("%d", &n);
    //Tinh vi tri so o giua

    // Hướng làm bài
    /*
                  1
                2 3 2
              3 4 5 4 3
            4 5 6 7 6 5 4
              Neu nhu co 1 dong => Khoang cach = 0
              Neu nhu co 2 dong => Co 1 chu so + 1 khoang cach = 2
              3 dong => 2 chu so + 2 khoang cach = 4
              4 dong => 3 chu so + 3 khoang cach = 6
              ==> Xac dinh so space cua dong 1 = cach tinh so lan xuong dong
              ==> space += space + countRow * 2
              ==> Neu co 4 dong thi countRow di tu 1 -> 3
    */
    /*
    Cac vd can giai quyet:
    1. Khoang cach tung dong (check)
    2. In so va khoang cach giua chung (check)
    3. In cot giua ()
    4. In theo huong nguoc lai (dung array?)
    5. Profit ???
    */
    spc = Spaces(n);
    printf("So khoang cach cho dong tiep theo: %d\n", spc);
    int num = 1, MiddleValue = 1, MiddlePos = 0, count;
    int arr[50];
    for (int i = 1; i <= n; i++) {
        PrintSpaces(spc);
        if (i == 1)
        printf("%d", MiddleValue);

        PrintNum(i, MiddleValue, MiddlePos);

        
        //Undo this code if anything gone wrong
        // if (MiddleValue >= 10) {
        //     MiddleValue = Return1Num(MiddleValue);
        //     printf("%d", MiddleValue);
        // } else if (i > 1) {
        //     printf("%d", MiddleValue);
        // }
        

        //Giam khoang cach + xuong dong
        arr[0] = '\0';
        MiddlePos++;
        MiddleValue += 2;
        num += 2;
        spc -= 2;
        printf("\n");
    }
    return 0;
}