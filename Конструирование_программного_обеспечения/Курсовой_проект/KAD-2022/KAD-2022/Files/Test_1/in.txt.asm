.586							; система команд (процессор Pentium)
.model flat, stdcall			; модель памяти, соглашение о вызовах
includelib kernel32.lib
includelib libucrt.lib
includelib StaticLib.lib

ExitProcess PROTO: dword		; прототип функции для завершения процесса Windows

EXTRN lenght_str: proc
EXTRN write_int: proc
EXTRN write_str : proc
EXTRN copy_str: proc

.stack 4096

.const							; сегмент констант - литералы
	L0 sdword 100
	L1 sdword 5
	L2 sdword 1
	L3 sdword 0
	L4 byte "Это проект с названием KAD-2022", 0
	L5 byte "POIT_5", 0
	L6 byte " ", 0
	L7 byte "Вывод всех чисел, которые делятся на 5 нацело (в диапазоне от 0 до 100):", 0
	L8 sdword 4
	L9 byte "Количество чисел, которые делятся на 5: ", 0
	L10 byte "Hello", 0
	L11 byte "How are you?", 0
	L12 byte "Первых три элемента, скопированных из первой строки во вторую :", 0
	L13 sdword 3
	L14 byte "Длина наибольшей строки из двух: ", 0
.data							; сегмент данных - переменные и параметры
	i_DivisionByFive sdword 0
	countOfNumber_DivisionByFive sdword 0
	result_repeat0 sdword 0
	lenghtOfFirstStroke_findMaxStroke sdword 0
	lenghtOfSecondStroke_findMaxStroke sdword 0
	result_findMaxStroke sdword 0
	group_main dword ?
	count_main sdword 0
	strokeOne_main dword ?
	strokeSecond_main dword ?
	ns_main dword ?
	maxL_main sdword 0
.code							; сегмент кода

;----------- DivisionByFive ------------
DivisionByFive PROC,	count_DivisionByFive : sdword  
; --- сохранить регистры ---
push ebx
push edx
; ----------------------
push count_DivisionByFive
pop i_DivisionByFive

cyclenext0:
mov edx, i_DivisionByFive
cmp edx, L0
jg cycle0
push i_DivisionByFive
push L1
pop ebx
pop eax
cdq
idiv ebx
push edx
pop result_repeat0

push result_repeat0
push L2
pop ebx
pop eax
sub eax, ebx
push eax
pop result_repeat0

mov edx, result_repeat0
cmp edx, L3

jl true1
jmp next1
true1:
push i_DivisionByFive
call write_int

push countOfNumber_DivisionByFive
push L2
pop ebx
pop eax
add eax, ebx
push eax
pop countOfNumber_DivisionByFive

next1:

push i_DivisionByFive
push L2
pop ebx
pop eax
add eax, ebx
push eax
pop i_DivisionByFive

jmp cyclenext0
cycle0:

; --- восстановить регистры ---
pop edx
pop ebx
; -------------------------
mov eax, countOfNumber_DivisionByFive
ret
DivisionByFive ENDP
;------------------------------


;----------- findMaxStroke ------------
findMaxStroke PROC,	strOne_findMaxStroke : dword, strTwo_findMaxStroke : dword  
; --- сохранить регистры ---
push ebx
push edx
; ----------------------
push strOne_findMaxStroke
call lenght_str
push eax
pop lenghtOfFirstStroke_findMaxStroke

push strTwo_findMaxStroke
call lenght_str
push eax
pop lenghtOfSecondStroke_findMaxStroke

mov edx, lenghtOfFirstStroke_findMaxStroke
cmp edx, lenghtOfSecondStroke_findMaxStroke

jg true2
jl false2
true2:
push lenghtOfFirstStroke_findMaxStroke
pop result_findMaxStroke

jmp next2

false2:
push lenghtOfSecondStroke_findMaxStroke
pop result_findMaxStroke

next2:

; --- восстановить регистры ---
pop edx
pop ebx
; -------------------------
mov eax, result_findMaxStroke
ret
findMaxStroke ENDP
;------------------------------


;----------- MAIN ------------
main PROC


push offset L4
call write_str

mov group_main, offset L5
push group_main
call write_str


push offset L6
call write_str


push offset L7
call write_str

push L8
call DivisionByFive
push eax
pop count_main


push offset L9
call write_str

push count_main
call write_int


push offset L6
call write_str

mov strokeOne_main, offset L10
mov strokeSecond_main, offset L11
push strokeOne_main
call write_str

push strokeSecond_main
call write_str


push offset L12
call write_str

push L13
push strokeSecond_main
push strokeOne_main
call copy_str
mov ns_main, eax
push ns_main
call write_str


push offset L6
call write_str


push offset L14
call write_str

push strokeSecond_main
push strokeOne_main
call findMaxStroke
push eax
pop maxL_main

push maxL_main
call write_int

push 0
call ExitProcess
main ENDP
end main