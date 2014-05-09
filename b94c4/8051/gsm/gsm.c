/** DESIGN OF GSM BASED DEVICE CONTROL (ON OFF) SYSTEM **/
/**COMPILER DIRECTIVES**/
#include<reg51.h>
#include<string.h>

/**LCD CONNECTIONS**/
#define LCD P0

/**DEVICES CONNECTION**/
sbit bulb = P2^1;
sbit fan = P1^1;

/**VARIABLES DECLARATION**/
bit flag=0;
bit r_flag = 0;
bit sucess = 0;
int i=0;
int l,k;
char idata buff[150];
char phone1[12];

/**FUNCTIONS DECLARATION**/
void init_lcd(void);
void cmd_lcd(unsigned char var);
void data_lcd(unsigned char var);
void display_lcd(char *str);
void delay_ms(int cnt);

/**GSM FUNCTIONS DECLARATION**/
void gsm_init(void);
void print(char *); //to send string to the serialcom window
int recv_sms(void);
void SEND_CHR(unsigned char);  //to send character to the serialcom window
void send_sms(unsigned char *p,unsigned char *d);


/**SERIAL INTERRUPT SERVICE ROUTINE**/
void serial_intr(void) interrupt 4
{
	if(TI == 1)
	{
		TI = 0;
		flag = 1;
	}
	else if(RI==1)
	{
		RI = 0;
		r_flag = 1;
		if(i < 150)
		buff[i++] = SBUF;
	}	
	else
	{
		;
	}
}

/**MAIN FUNCTION**/
main()
{
	unsigned int x;

	TMOD = 0x21; //USART INITIALIZATION REGISTERS
	SCON = 0x50;
	TH1 = -3; //9600 BUADRATE
	TR1 = 1;

	IE = 0x90; //INTERRUPT REGISTER

	bulb=fan=0; //DEVICES OFF

	init_lcd(); //LCD INITIALIZATION FUNCTION CALLING

	display_lcd("** GSM BASED ***"); //DISPLAY STRING ON LCD
	cmd_lcd(0xc0); //2ND LINE DISPLAY
	display_lcd("*DEVICE CONTROL*");//DISPLAY STRING ON LCD
	delay_ms(500);

	gsm_init(); //GSM INITIALIZATION FUNCTION CALLING

	IE=0x91; //INTERRUPT REGISTER

	while(1)
	{
		cmd_lcd(0x01);//CLEAR SCREEN
		display_lcd("WAITING FOR     ");
		cmd_lcd(0xc0);
		display_lcd("MESSAGE.........");

		x = recv_sms();	//WAITING FOR MESSAGE

		if(x==0)
		{
			cmd_lcd(0x01);
			display_lcd("WRONG FORMAT"); //INVALID MESSAGE
			delay_ms(100);
			send_sms("9949753456","--->MESSAGE IS IN WRONG FORMAT");
			delay_ms(1500);
			//send_sms("9030040239","--->MESSAGE IS IN WRONG FORMAT");
			//delay_ms(1500);

		}
		else if(x==1)
		{
			cmd_lcd(0x01);
			display_lcd("FAN ON");
			fan=1; //FAN ON
			delay_ms(100);
			send_sms("9949753456","***FAN ON***");
			delay_ms(1500);
			//send_sms("9030040239","***FAN ON***");
			//delay_ms(1500);
		}
		else if(x==2)
		{
			cmd_lcd(0x01);
			display_lcd("FAN OFF");
			fan=0; //FAN OFF
			delay_ms(100);
			send_sms("9949753456","***FAN OFF***");
			delay_ms(1500);
		//	send_sms("9030040239","***FAN OFF***");
		//	delay_ms(1500);
		}
		else if(x==3)
		{
			cmd_lcd(0x01);
			display_lcd("BULB ON");
			bulb=1; //BULB ON
			delay_ms(100);
			send_sms("9949753456","***BULB ON***");
			delay_ms(1500);
		//	send_sms("9030040239","***BULB ON***");
		//	delay_ms(1500);
			
		}
		else if(x==4)
		{
			cmd_lcd(0x01);
			display_lcd("BULB OFF");
			bulb=0; //BULB OFF
			delay_ms(100);
			send_sms("9949753456","***BULB OFF***");
			delay_ms(1500);
		//	send_sms("9030040239","***BULB OFF***");
		//	delay_ms(1500);
		}
		else
		{
			;
		}
		delay_ms(1000);
	}
}


/**RECEIVE SMS FUNCTION**/
int recv_sms()
{
	sucess = 0;
	do{
	strcpy(buff," ");
	r_flag = 0;
	i = 0;
	print("AT+CMGD=1\r\n"); // DELETE FIRST MESSAGE IN SIM MEMORY
	while(i <= 2);	//WAITING FOR RESPONCE AS 'O','K',' '
	delay_ms(100);
	delay_ms(100);
	l = 0;
	while(buff[l] != '\0')
	{
	if(buff[l++] == 'O')
		sucess = 1;
	}
	delay_ms(100);
	}
	while(sucess != 1);//UPTO RECEIVING OK IT IS CHECKING

	do{
	i = 0;
	strcpy(buff,"");
	r_flag = 0;
	while(r_flag == 0)
	if(buff[2] == '+')//WAITING FOR MESSAGE +CMTI: "SM",1
	sucess = 1;
	}while(sucess != 1);

	cmd_lcd(0x01);
	display_lcd("MESSAGE RECEIVED");
	delay_ms(500);
	i = 0;
	strcpy(buff,"");
	print("AT+CMGR=1\r\n"); //READ FIRST MESSAGE IN SIM MEMORY


/* +CMGR: "REC UNREAD","+919039344372",,"11/07/05,11:19:41+22 
	
	FON */


	delay_ms(500);
	l=0;
	while(buff[l++] != ',');	//WAITING FOR FIRST ','
	cmd_lcd(0x01);
	display_lcd("CELL NO : ");
	cmd_lcd(0xC0);
	l = l+4;//REMOVE THE "+91
	k=0;
	while(buff[l] != '"')
	{
		phone1[k++]=buff[l++]; //SAVING PHONE NUMBER IN THE PHONE ARRAY 
	}
	phone1[k]='\0';
	display_lcd(phone1);
	delay_ms(500);
	l++;
	while(buff[l++] != '"');//END OF PHGONE NUMBER
	//cmd_lcd(0x01);
	//cmd_lcd(0xC0);
	while(buff[l] != ',')//AFTER PHONE NUMBER
	(buff[l++]);
	while(buff[l++] != ',');
	//cmd_lcd(0x01);
	//cmd_lcd(0xC0);
	while(buff[l] != '"') //FINAL 
	(buff[l++]);
	l = l+3;

	cmd_lcd(0x01);
	display_lcd("MESSAGE IS : ");


	if(buff[l]=='F' && buff[l+1]=='O' && buff[l+2]=='N' ) //FON
	{
		cmd_lcd(0xC0);
		data_lcd(buff[l]);
		data_lcd(buff[l+1]);
		data_lcd(buff[l+2]);
		delay_ms(100);
		return 1;
	}

	else if(buff[l]=='F' && buff[l+1]=='O' && buff[l+2]=='F' && buff[l+3]=='F' ) //FOFF
	{
		cmd_lcd(0xC0);
		data_lcd(buff[l]);
		data_lcd(buff[l+1]);
		data_lcd(buff[l+2]);
		data_lcd(buff[l+3]);
		delay_ms(100);
		return 2;
	}

	else if(buff[l]=='B' && buff[l+1]=='O' && buff[l+2]=='N' ) //BON
	{
		cmd_lcd(0xC0);
		data_lcd(buff[l]);
		data_lcd(buff[l+1]);
		data_lcd(buff[l+2]);
		delay_ms(100);
		return 3;
	}

	else if(buff[l]=='B' && buff[l+1]=='O' && buff[l+2]=='F' && buff[l+3]=='F' ) //BOFF
	{
		cmd_lcd(0xC0);
		data_lcd(buff[l]);
		data_lcd(buff[l+1]);
		data_lcd(buff[l+2]);
		data_lcd(buff[l+3]);
		delay_ms(100);
		return 4;
	}
	else
		return 0;
}


/**GSM INITIALIZATION FUNCTION**/
void gsm_init() //GSM INITIALIZATION FUNCTION
{
	cmd_lcd(0x01);
	cmd_lcd(0x80);
	display_lcd("GSM TESTING"); // DISPLAY PREDEFINED STRING ON LCD
	delay_ms(100);
	cmd_lcd(0x01);
	display_lcd("INITIALIZING...."); // DISPLAY PREDEFINED STRING ON LCD
	i = 0;
	print("AT\r\n");
	delay_ms(300);
	print("AT+CMGF=1\r\n"); // TEXT MESSAGE FORMAT
	delay_ms(100);
	print("ATE0\r\n"); // ECHO OFF
	delay_ms(100);
	sucess = 0;
	do{
		strcpy(buff," ");
		r_flag = 0;
		i = 0;
		print("AT+CMGD=1\r\n"); // delete first message in the SIM memory
		while(i <= 2);
		delay_ms(100);
		delay_ms(100);
		l = 0;
		while(buff[l] != '\0')
		{
			if(buff[l++] == 'O')
			sucess = 1;
		}
		delay_ms(100);
		}while(sucess != 1);
}

/**SENDING SMS FUNCTION**/
void send_sms(unsigned char *p,unsigned char *d)		
{
		cmd_lcd(0x01);
		display_lcd("sending sms..");   // DISPLAY PREDEFINED STRING ON LCD
		print("AT+CMGS=");//FOR SEND MESSAGE
		SEND_CHR('"');
		print(p);  // ENTER PHONE NUMBER
		SEND_CHR('"');
		print("\r\n");
		delay_ms(2);
		print(d);  // ENTER MESSAGE 

		SEND_CHR(0x1A); // Ctrl+Z
		SEND_CHR(0x1A);
}

/**CHARACTER SENDING FUNCTION**/
void SEND_CHR(unsigned char c) 
{
	flag = 0;
	SBUF = c;
	while(flag == 0);
}


/**STRING SEND FUNCTION**/
void print(char *str)
{
	while(*str)
	{
		flag = 0;
		SBUF = *str++;
		while(flag == 0);
	}
}



/**LCD INITIALIZATION FUNCTION**/
void init_lcd(void)
{
	cmd_lcd(0x02);//RETURN HOME
	cmd_lcd(0x28);//4BIT MODE
	cmd_lcd(0x0C);//DISPLAY ON CURSOR OFF
	cmd_lcd(0x06);//SHIFT CURSOR TO RIGHT
	cmd_lcd(0x01);//CLEAR SCREEN
}

/**LCD COMMAND FUNCTION**/
void cmd_lcd(unsigned char var)
{
	LCD = ((var & 0xF0) | 0x08);//RS=0,EN=1
	LCD = 0;
	LCD = ((var << 4) | 0x08);//RS=0,EN=1
	LCD = 0;
	delay_ms(2);
}

/**LCD DATA FUNCTION**/
void data_lcd(unsigned char var)
{
	LCD = ((var & 0xF0) | 0x0a); //RS=1,EN=1
	LCD = 0;
	LCD = ((var << 4) | 0x0a); //RS=1,EN=1
	LCD = 0;
	delay_ms(2);
}

/**LCD STRING FUNCTION**/
void display_lcd(char *str)
{
	while(*str)
	data_lcd(*str++);
}

/**MILLISECOND DELAY FUNCTION**/
void delay_ms(int cnt)
{
	int i;
	while(cnt--)
	for(i=0;i<400;i++);
}