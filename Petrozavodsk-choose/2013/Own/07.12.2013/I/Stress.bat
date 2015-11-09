@echo off

:test

	gen.exe
	old.exe
	I.exe

	fc paradox.out old.out || exit

goto test	