.586							; ������� ������ (��������� Pentium)
.model flat, stdcall			; ������ ������, ���������� � �������
includelib kernel32.lib
includelib libucrt.lib
includelib StaticLib.lib

ExitProcess PROTO: dword		; �������� ������� ��� ���������� �������� Windows

EXTRN lenght_str: proc
EXTRN write_int: proc
EXTRN write_str : proc
EXTRN copy_str: proc

.stack 4096

.const							; ������� �������� - ��������
	L0 byte "hello", 0
	L1 sdword 12
	L2 byte "Hello, how are you?", 0
	L3 byte "����� ������: ", 0
.data							; ������� ������ - ���������� � ���������
	a_main sdword 0
	stroke_main dword ?
	lenght_main sdword 0
.code							; ������� ����

;----------- MAIN ------------
main PROC


push offset L0
call write_str

push L1
pop a_main

mov stroke_main, offset L2
push stroke_main
call lenght_str
push eax
pop lenght_main


push offset L3
call write_str

push lenght_main
call write_int

push 0
call ExitProcess
main ENDP
end main