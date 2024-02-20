#include <stdio.h>

void move(int n, char source, char destination, char intermediate) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    move(n - 1, source, intermediate, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    move(n - 1, intermediate, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    return 0;
} 

