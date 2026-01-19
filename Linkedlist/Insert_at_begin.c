#include <stdio.h>
#include <stdlib.h>

struct stud{
    int val;
    struct stud *ptr;
}*start,*newptr,*save;

struct stud *create(int n){
    struct stud *pt;
    pt = (struct stud*)malloc(sizeof(struct stud));
    pt->val = n;
    pt->ptr = NULL;
    return pt;
}
void ins_beg(struct stud *np){
    if(start == NULL)
      start = np;
    else{
        save = start;
        start = np;
        np->ptr = save;
    }  
}
void display(struct stud *np){
    while(np!=NULL){
        printf("%d",np->val);
        if(np->ptr!=NULL)
           printf("-->");
        np = np->ptr;
    }
}
int main()
{
   start = NULL;
   newptr = create(72);
   ins_beg(newptr);
   newptr = create(19);
   ins_beg(newptr);
   newptr = create(57);
   ins_beg(newptr);
   display(start);
   
    return 0;
}