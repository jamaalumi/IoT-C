#include <stdio.h>

#define MONTHS 12

int main() {
 float taxRate1, taxRate2, incomeLimit;
 float salaries[MONTHS], taxAmounts[MONTHS], totalIncome = 0;

 // Get tax information
 printf("Enter tax rate: ");
 scanf("%f", &taxRate1);

 printf("Enter income limit: ");
 scanf("%f", &incomeLimit);

 printf("Enter tax rate for income over the limit: ");
 scanf("%f", &taxRate2);

 // Get monthly salaries
 for (int i = 0; i < MONTHS; i++) {
  printf("Enter income for month %d: ", i + 1);
  scanf("%f", &salaries[i]);
 }

 // Calculate tax per month
 for (int i = 0; i < MONTHS; i++) {
  totalIncome += salaries[i];
  if (totalIncome <= incomeLimit) {
   taxAmounts[i] = salaries[i] * (taxRate1 / 100);
  } else {
   float taxableOver = totalIncome - incomeLimit;
   float taxBefore = (salaries[i] - taxableOver) * (taxRate1 / 100);
   float taxAfter = taxableOver * (taxRate2 / 100);
   taxAmounts[i] = taxBefore + taxAfter;
  }
 }

 // Print results
 printf("Month    Income    Tax\n");
 for (int i = 0; i < MONTHS; i++) {
  printf("%-8d %-8.2f %.2f\n", i + 1, salaries[i], taxAmounts[i]);
 }

 return 0;
}
//
// Created by jamaa on 27.3.2025.
//

#include "teht2.h"
