void build_cgram(char *s,unsigned int n)
{
unsigned char i;
cmd_lcd(0x40);
for(i=0;i<n;i++)
{
disp_lcd(s[i]);

}
cmd_lcd(ox80);


}
