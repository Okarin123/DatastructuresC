#include<stdio.h> 

struct a
{
int test; 
};

struct b
{
struct a call;
};


void function(struct a *ptr)
{
printf("enter: ");
scanf("%d", &(ptr->test));
}

void main()
{
struct b obj;

function(&obj.call);}
