$INCLUDE(DELAY.ASM)
LEDS EQU P2
CSEG AT 0
MAIN:
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
MOV A,#0FEH
MOV R4,#8
AGAIN:
MOV LEDS,A
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
RL A
DJNZ R4,AGAIN
MOV LEDS,#0FFH
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
ACALL DELAY100MS
MOV A,#055H
AGAIN1:
MOV LEDS,A
ACALL DELAY100MS
CPL A
SJMP AGAIN1
END