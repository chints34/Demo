	AREA RESET,CODE,READONLY
	ARM
	ENTRY
START
	mov r0,#0x12
	
	ldr r1,=0x40000000
	str r0,[r1]
	ldr r1,=0x40000004
	strh r0,[r1]
	ldr r1,=0x40000006
	strb r0,[r1]
HERE
	B HERE
	END