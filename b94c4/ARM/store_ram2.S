	AREA RESET,CODE,READONLY
	ARM
	ENTRY
START
	ldr r0,=0x12345678
	
	ldr r1,=0x40000000
	str r0,[r1]
	ldrb r2,[r1]
	ldrh r3,[r1]
	ldr r4,[r1]
	
HERE
	B HERE
	END