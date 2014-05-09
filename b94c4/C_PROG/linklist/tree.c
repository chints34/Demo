#include<stdio.h>
#include<stdlib.h>
typedef struct bst
		{
		 int data;
	 	 struct bst *left,*right;
		}tree;
void print(tree *ptr)
 {
           if(ptr)
             {
              printf("%d\n",(ptr)->data);
              print((ptr)->left);
              print((ptr)->right);
              }


}
void add(tree **ptr,int n)
{
             if(*ptr==NULL)
              {
               *ptr=calloc(1,sizeof(tree));
               (*ptr)->data=n;
               }
	     else
	         {
	          if(n<=(*ptr)->data)
		     add(&(*ptr)->left,n);
	   	  else
		     add(&(*ptr)->right,n);
		}
}
tree *search(tree *ptr,int n)
{
if(ptr)
{
 if(ptr->data==n)
   {
    return ptr;   
   }
 else if(ptr->data>n)
    return (search(ptr->left,n));
else
   return (search(ptr->right,n));
}
return 0;

}
main()
{
tree *root=NULL;
char choise;
int d,v;
printf("menu\n");
while(1)
{
printf("a>add the list\n");
printf("p>print the list\n");
printf("s>search the list\n");
printf("d>delete the list\n");
printf("e>exit\n");
scanf(" %c",&choise);
switch(choise)
{
case 'a':printf("enter the data\n");
	 scanf("%d",&d);
	 add(&root,d);
	 break;
case 'p':print(root);
	 break;
case 's':printf("enter the data\n");
	 scanf("%d",&v);
	 if(search(root,v)==NULL)
	  {
	    printf("not found\n");
          }
	 else
	   printf("found\n");
	   break;
case 'e':return;
//default:printf("invalid choise\n");

}
}


}
