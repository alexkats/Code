@echo off

:test
	Gen.exe
	Right.exe
	I.exe
	
	fc right.out i.out || exit

goto test	