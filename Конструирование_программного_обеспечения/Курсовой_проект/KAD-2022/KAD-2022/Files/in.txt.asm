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
.data							; ������� ������ - ���������� � ���������
.code							; ������� ����

;----------- MAIN ------------
main PROC


push offset L0
call write_str

push 0
call ExitProcess
main ENDP
end main