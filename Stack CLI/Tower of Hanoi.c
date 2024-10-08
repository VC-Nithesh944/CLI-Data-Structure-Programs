#include <stdio.h>

void ToH(int n, char a, char b, char c){
  if ( n == 1 ){
    printf("Move Disk %d from rod %c to rod %c\n", n,a,c);
    return;
  }
  ToH(n-1,a,c,b);
  printf("Move Disk %d from rod %c to rod %c\n", n,a,c);
  ToH(n-1,b,a,c);
}

int main(){
  int n;
  printf("Enter the Number of Disks in your Tower of Hanoi: ");
  scanf("%d",&n);
  ToH(n,'A','B','C');
  return 0;
}
