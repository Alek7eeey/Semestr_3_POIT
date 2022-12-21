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
	L0 byte "hello", 0
.data							; сегмент данных - переменные и параметры
.code							; сегмент кода

;----------- MAIN ------------
main PROC


push offset L0
call write_str

push 0
call ExitProcess
main ENDP
end main