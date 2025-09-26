#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
  int n, op, x;
  int stack[MAX], top = -1;
  int queue[MAX], front = 0, back = 0;
  int pq[MAX], size = 0;
  int is_stack = 1, is_queue = 1, is_pq = 1;
  
  while (scanf("%d", &n) != EOF){
       top = -1;
       front = 0, back = 0;
       size = 0;
       is_stack = 1, is_queue = 1, is_pq = 1;
       
       for (int i = 0; i < n; i++){
           scanf("%d %d", &op, &x);
           
           if (op == 1){
               if (is_stack) stack[++top] = x;
               if (is_queue) queue[back++] = x;
               if (is_pq) pq[size++] = x;
           }else{
               if (is_stack){
                   if (top == -1 || stack[top] != x) is_stack = 0;
                   else top--;
               }
               if (is_queue) {
                   if (front == back || queue[front] != x) is_queue = 0;
                   else front++;
               }
               if (is_pq){
                   int max_idx = 0;
                   for (int j = 1; j < size; j++)
                   if (pq[j] > pq[max_idx]) max_idx = j;
                   if (size == 0 || pq[max_idx] != x) is_pq = 0;
                   else{
                       pq[max_idx] = pq[size-1];
                       size--;
                   }
               }
           }
       }
     if(is_stack + is_queue + is_pq == 0) printf("impossible\n");
     else if (is_stack + is_queue + is_pq > 1) printf("not sure\n");
     else if (is_stack) printf("stack\n");
     else if (is_queue) printf("queue\n");
     else if (is_pq) printf("priority queue\n");
   }
    return 0;
}