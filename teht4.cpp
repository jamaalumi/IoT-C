 #include <stdio.h>

int read_integer(void) {
 int num;
 while (1) {
  printf("Enter positive numbers or negative to stop: ");
  if (scanf("%d", &num) == 1) return num;
  else {
   while (getchar() != '\n');
   printf("Invalid input\n");
  }
 }
}

int main() {
 int count = 0, sum = 0, num;

 while ((num = read_integer()) >= 0) {
  sum += num;
  count++;
 }

 if (count > 0)
  printf("You entered %d positive numbers. The average is: %.3f\n", count, (float)sum / count);
 else
  printf("No positive numbers entered.\n");

 return 0;
}
//
// Created by jamaa on 27.3.2025.
//

#include "teht4.h"
