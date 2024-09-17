#include <stdio.h>
#include <stdlib.h>

struct poly
{
 int coeff, expo;
 struct poly *next;
};
struct poly *exp1 = NULL;
struct poly *exp2 = NULL, *res = NULL;

void display()
{
 struct poly *tmp = res;
 while (tmp->next != NULL)
 {
  printf("%dX^%d+", tmp->coeff, tmp->expo);
  tmp = tmp->next;
 }
 if (tmp->expo == 0)
  printf("%d", tmp->coeff);
 else
  printf("%dX^%d", tmp->coeff, tmp->expo);
}

void insert(struct poly **head, int coeff, int expo)
{
 struct poly *new = malloc(sizeof(struct poly));
 new->coeff = coeff;
 new->expo = expo;
 new->next = NULL;
 if (*head == NULL)
 {
  *head = new;
  return;
 }
 struct poly *tmp = *head;
 while (tmp->next != NULL)
 {
  tmp = tmp->next;
 }
 tmp->next = new;
}
void main()
{
 int n1, n2;
 printf("NOTE: Please enter the powers of each element in polynomial in sorted order for the correctness of the output."); // This program is can not calculate add if the polynomial element's powers are in unsorted manner!!!

 printf("\nEnter the number of elements in expression 1: ");
 scanf("%d", &n1);
 printf("\nEnter the coefficient and powers for %d elements", n1);
 for (int i = 0; i < n1; i++)
 {
  int coeff, expo;
  printf("\nEnter the coefficient of the %d element in the expression: ", i + 1);
  scanf("%d", &coeff);
  printf("\nEnter the power of the %d element in the expression: ", i + 1);
  scanf("%d", &expo);
  insert(&exp1, coeff, expo);
 }

 printf("\nEnter the number of elements in expression 2: ");
 scanf("%d", &n2);
 printf("\nEnter the coefficient and powers for %d elements", n2);
 for (int i = 0; i < n2; i++)
 {
  int coeff, expo;
  printf("\nEnter the coefficient of the %d element in the expression: ", i + 1);
  scanf("%d", &coeff);
  printf("\nEnter the power of the %d element in the expression: ", i + 1);
  scanf("%d", &expo);
  insert(&exp2, coeff, expo);
 }

 struct poly *expTmp1 = exp1, *expTmp2 = exp2;

 while (expTmp1 != NULL && expTmp2 != NULL)
 {
  int coeff = 0, expo;
  if (expTmp2->expo == expTmp1->expo)
  {
   insert(&res, expTmp1->coeff + expTmp2->coeff, expTmp1->expo);
   expTmp1 = expTmp1->next;
   expTmp2 = expTmp2->next;
  }
  else if (expTmp1->expo > expTmp2->expo)
  {
   insert(&res, expTmp1->coeff, expTmp1->expo);
   expTmp1 = expTmp1->next;
  }
  else if (expTmp2->expo > expTmp1->expo)
  {
   insert(&res, expTmp2->coeff, expTmp2->expo);
   expTmp2 = expTmp2->next;
  }
 }
 display();
}