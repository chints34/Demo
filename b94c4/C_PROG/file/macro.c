#define M 1
main()
{
extern int i;
printf("i=%d\n",i);
printf("M=%d\n",M);
#undef M 1
printf("M=%d\n",M);

}
int i=M;
