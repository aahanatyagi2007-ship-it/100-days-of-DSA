//Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include <stdio.h>
int main() {
int arr[10] = {10,20,30,40,50};
int size = 5;
int pos = 2;
int value = 25;

for(int i = size; i>pos; i--) {
arr[i] = arr[i-1];
}
arr[pos] = value;
size++;
for(int i=0; i < size; i++) {
printf("%d ", arr[i]);
  }
}
