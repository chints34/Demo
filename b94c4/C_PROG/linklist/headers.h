#include<stdio.h>
#include<stdlib.h>
typedef struct student
			{
			int roll;
			float marks;
			char name[20];
			struct student *link;			
			}st;
