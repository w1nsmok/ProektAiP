#define _CRT_SECURE_NO_WARNINGS
#include "ln.h"
void samolet() {
    double v, L;
    printf("Enter the aircraft speed in km/h: ");
    scanf("%lf", &v);
    printf("Enter the distance the plane will travel when braking in km: ");
    scanf("%lf", &L);
    double v1 = v * 1000 / 3600;
    double L1 = L * 1000;
    double t = L1 / v1;
    printf("Braking time: %.2f seconds\n", t);
    system("pause");
}

void stroka() {
    double s;
    double a;
    double c;
    double b;
    double x;
    double d;
    double eps;
    int i;
    int sign;

    printf("Enter x value: ");
    scanf("%lf", &x);
    printf("Enter threshold eps value:");
    scanf("%lf", &eps);
    s = 0;
    sign = 1;
    i = 0;
    c = 1;
    b = 1;
    d = 1;
    while (i < eps) {
        a = c / b;
        s += a * sign;
        sign *= -1;
        c *= x;
        b *= d;
        d++;
        i++;
    }
    printf("Sum of the first elements of the series: %.0f\n", s);
    system("pause");
}

void slova() {
    char c;
    int cnt = 0;
    int w = 0;

    printf("Enter text :\n");

    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!w) {
                w = 1;
                cnt++;
            }
        }
        else {
            if (c == '.') {
                printf("Words: %d\n", cnt);
                cnt = 0;
            }
            w = 0;
        }
    }
    system("pause");
}
void string() {
    char prefix[100];
    char input_string[MAXLINE];

    printf("Enter the specified prefix: ");
    scanf("%s", prefix);
    printf("Enter the string: ");
    getchar();
    fgets(input_string, MAXLINE, stdin);

    char c;
    int prev_c;
    int flag;
    int found;
    int i;
    int pos;
    int start;
    flag = NO;
    found = NO;
    prev_c = ' ';
    start = 0;
    i = 0;
    pos = 0;

    do {
        c = input_string[i];
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {

            if (flag == YES) {

                int match = YES;
                for (int k = start; prefix[k - start] != '\0'; k++) {
                    if (input_string[k] != prefix[k - start]) {
                        match = NO;
                        break;
                    }
                }
                if (!match) {

                    for (int j = start; j < i; j++) {
                        input_string[pos++] = input_string[j];
                    }
                }
            }
            flag = NO;
            input_string[pos++] = c;
        }
        else {

            if (flag == NO) {
                start = i;
                int match = YES;
                for (int k = 0; prefix[k] != '\0'; k++) {
                    if (input_string[i + k] != prefix[k]) {
                        match = NO;
                        break;
                    }
                }
                if (match) {
                    found = YES;
                }
                else {
                    found = NO;
                }
            }
            flag = YES;
        }
        prev_c = c;
        i++;
    } while (c != '\0');

    printf("Result: %s\n", input_string);
    system("pause");
}

void slova_lL() {
    char c;
    int cnt = 0;
    int w = 0;
    int contains_l = 0;
    printf("Enter text :\n");

    while ((c = getchar()) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!w) {
                w = 1;
                contains_l = 0;
            }
            if (c == 'l' || c == 'L') {
                contains_l = 1;
            }
        }
        else {
            if (c == '.') {
                if (!contains_l && w) {
                    cnt++;
                }
                printf("Words without 'l' or 'L': %d\n", cnt);
                cnt = 0;
            }
            w = 0;
        }
    }
    system("pause");
}
int massiv() {
    int arr[10];
    int isPalindrome = 1;  // Предполагаем, что массив является палиндромом

    // Ввод 10 чисел
    printf("Enter 10 nubmers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    // Проверка, является ли массив палиндромом
    for (int i = 0; i < 10 / 2; i++) {
        if (arr[i] != arr[10 - 1 - i]) {
            isPalindrome = 0;  // Найдено несоответствие, массив не палиндром
            break;
        }
    }

    // Вывод результата
    if (isPalindrome) {
        printf("Sequency is mirrored.\n");
    }
    else {
        printf("Sequency is not mirrored.\n");
    }
    system("pause");
    return 0;
}




void glasn() {
    char str[100];
    int count = 0;
    int word = 0;
    int vow = 1;

    printf("Enter a string of words: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            if (!word) {
                word = 1;
                vow = 1;
            }

            if (!(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' ||
                str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')) {
                vow = 0;
            }
        }
        else {
            if (word) {
                if (vow) {
                    count++;
                }
                vow = 1;
                word = 0;
            }
        }
    }

    printf("Number of words containing only vowels: %d\n", count);
    system("pause");


}

void posled() {
    int n;
    printf("Enter the number of sequence elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of elements must be greater than zero.\n");
        return;
    }

    int* seq = (int*)malloc(n * sizeof(int));
    if (seq == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    printf("Enter sequence elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    int peak = 0, valley = 0;
    for (int i = 1; i < n - 1; i++) {
        if (seq[i] > seq[i - 1] && seq[i] > seq[i + 1]) {
            peak++;
        }
        else if (seq[i] < seq[i - 1] && seq[i] < seq[i + 1]) {
            valley++;
        }
    }

    if (peak > 0 && valley == 0) {
        printf("Mountain sequence.\n");
    }
    else if (valley > 0 && peak == 0) {
        printf("Acorn sequence.\n");
    }
    else {
        printf("Sequence is not a mountain not an acorn.\n");
    }

    free(seq);
    system("pause");
}
void massivny(int arr[N][K]) {
    int pCount = 0;
    int nCount = 0;

    printf("Enter Array Elements %d x %d:\n", N, K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] > 0) {
                pCount++;
            }
            else if (arr[i][j] < 0) {
                nCount++;
            }
        }
    }
    if (nCount < pCount) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                if (arr[i][j] < 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                if (arr[i][j] > 0) {
                    arr[i][j] = 0;
                }
            }
        }
    }

    printf("Processed array:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    system("pause");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int arr[], int low, int high, int* pi) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    *pi = i + 1;
}

void qSort(int arr[], int low, int high) {
    if (low < high) {
        int pi;
        partition(arr, low, high, &pi);
        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

void inputmass(int** arr, int rows, int cols) {
    printf("Enter Array Elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printmass(int** arr, int rows, int cols) {
    printf("Sorted array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void sortmass() {
    int rows, cols;
    printf("Enter number of lines: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("The number of rows and columns must be greater than zero.\n");
        return;
    }
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    if (arr == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    inputmass(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        qSort(arr[i], 0, cols - 1);
    }

    printmass(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
    system("pause");
}

int bitovy (void) {
    unsigned long long z; 
    unsigned long long y; 
    unsigned long long result; 
    unsigned long long mask; 
    int count; 
    int i;
    printf("z = ");
    scanf("%llu", &z); 
    y = z;
    result = z;
    count = 0;
    int bit_length = sizeof(z) * 8;

    for (i = 0; i < bit_length; i++) {
        if (y & 1) { 
            count++;
        }
        else {
            if (count >= 3) {
                mask = (1ULL << count) - 1;
                result &= ~(mask << (i - count));
            }
            count = 0;
        }
        y >>= 1; 
    }
    if (count >= 3) {
        mask = (1ULL << count) - 1;
        result &= ~(mask << (i - count));
    }
    printf("result: %llu\n", result);
    system("pause");
}