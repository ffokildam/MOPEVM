        .model small   ; memory model
        .386           ; 386 processor instructions enabled
stack   100h           ; stack size: 256 bytes
        dataseg        ; define data segment
vA      dw 2           ; define 4x 2 byte variables
vB      dw 12
vC      dw 1
vX      dw ?           ; result
        codeseg        ; Lab. work 1, Variant 3
start:                 ; beginning prog. exec.
        startupcode    ; address of dataseg beginnin

        mov     AX, vA ; AX = A
        sar     AX, 1  ; AX = A/2
        mov     BX, vB ; BX = B
        sal     BX, 1  ; BX = 2B
        add     BX, vB ; BX = 3B
        add     AX, BX ; AX = A/2 + 3B
        sar     AX, 2  ; AX = (A/2 + 3B)/4
        mov     BX, vC ; BX = C
        sal     BX, 2  ; BX = 4C
        add     BX, vC ; BX = 5C
        sub     AX, BX ; AX = (A/2 + 3B) / 4 - 5C
        add     AX, 3  ; AX = (A/2 + 3B) / 4 - 5C + 3
        mov     vX, AX ; X = (A/2 + 3B) / 4 - 5C + 3
quit:                  ; end of prog.
        exitcode 0     ; return control ro OS, return code 0
end start              ; prog. end mark