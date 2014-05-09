/*SEVSEG SEGMENT CODE
RSEG SEVSEG
SEG_LUT:DB 40H
	DB 79H
	DB 24H
	DB 30H
	DB 19H
	DB 12H
	DB 02H
	DB 78H
	DB 00H
	DB 10H
*/
SEG_2_MUX EQU P0
SEL1 BIT P2^0
SEL2 BIT P2^1

LUT_SEG SEGMENT CODE
RSEG LUT_SEG

SEG_LUT : DB 40H,79H,24H,30H,19H,12H,02H,78H,00H,10H



DISP_2_MUX_SEG:
MOV A,R4
MOV B,#10
DIV AB
MOVC A,@A+DPTR
ORL A,#80H
MOV SEG_2_MUX,A
CLR SEL1
ACALL DELAY1MS
SETB SEL1

MOV A,B
MOVC A,@A+DPTR
ORL A,#80H
MOV SEG_2_MUX,A
CLR SEL2
ACALL DELAY1MS
SETB SEL2

RET
end
