.586P													;система команд (процессор Pentium)
.MODEL FLAT, STDCALL									;модель памяти, соглашение о вызовах
includelib kernel32.lib									;компановщику: компоновать с kernel32
includelib user32.lib

ExitProcess PROTO : DWORD								;прототип функции для завершения процесса Windows
MessageBoxA PROTO : DWORD, : DWORD, : DWORD, : DWORD	;прототип API-функции MessageBoxA (вывод в окно)

.STACK 4096												;выделение стека объемом 4 мегабайта

.DATA													;сегмент данных
		myBytes		BYTE	10h, 20h, 30h, 40h
		myWords		WORD	8Ah, 3Bh, 44h, 5Fh, 99h
		myDoubles	DWORD	1, 2, 3, 4, 5, 6, 7
		SUM			DWORD   0
		TimeVal		DWORD	0

		str0		db		"Kravchenko Aleksey, course_2, POIT_5 ", 0
		str1		db		"Массив содержит 0 ", 0
		str2		db		"Массив не содержит 0 ", 0

.CODE													;сегмент кода
main PROC												;точка входа main
start:	
		mov ESI, OFFSET myWords
		mov AX, [ESI + 0]
		mov BX, [ESI + 2]

		mov edi, OFFSET myDoubles
		mov ecx, 7
CYCLE:
		mov eax, [edi]
		add SUM, eax
		add edi, type myDoubles
loop CYCLE

		mov edi, OFFSET myDoubles
		mov ecx, 7
CYCLE_2:
		mov eax, [edi]
		add edi, type myDoubles
		
		cmp eax, 0
		jz  EXIT

		cmp ecx,1
		jz  EXIT_2
loop CYCLE_2

EXIT:													;содержит ноль
		mov eax, SUM
		mov EBX, 0
		invoke MessageBoxA, 0, offset str1, offset str0, 0
		push 0											;код возврата процесса Windows (параметр ExitProcess)
		call ExitProcess								;так завершается любой процесс Windows


EXIT_2:													;не содержит нуля
		mov eax, SUM
		mov EBX, 1
		invoke MessageBoxA, 0, offset str2, offset str0, 0
		push 0											;код возврата процесса Windows (параметр ExitProcess)
		call ExitProcess								;так завершается любой процесс Windows

main ENDP												;конец процедуры

end main	