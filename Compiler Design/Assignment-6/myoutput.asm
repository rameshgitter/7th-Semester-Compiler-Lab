; Generated 8086 Assembly Code
; Input: Three Address Code
; Strategy: Aho-Sethi-Ullman Code Generation

.MODEL SMALL
.STACK 100H

.DATA
    ; Declare all variables as words
    ; Add variable declarations here, e.g.:
    ; a DW ?
    ; b DW ?
    ; c DW ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; ===== Generated Code Begins =====
    ; t = a - b
    MOV AX, a
    SUB AX, b
    MOV t, AX
    ; u = a - c
    MOV BX, a
    SUB BX, c
    MOV u, BX
    ; v = t + u
    ADD AX, u
    MOV v, AX
    ; d = v + u
    ADD AX, u
    MOV d, AX
    ; if x < 0 goto L1
    MOV AX, x
    CMP AX, 0
    JL L1
    ; y = x + 1
    MOV CX, x
    ADD CX, 1
    MOV y, CX
    ; goto L2
    JMP L2
    ; L1:
L1:
    ; y = x - 1
    MOV DX, x
    SUB DX, 1
    MOV y, DX
    ; L2:
L2:
    ; z = y * 2
    MOV AX, DX
    IMUL 2
    MOV z, AX
    ; ===== Generated Code Ends =====

    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN
