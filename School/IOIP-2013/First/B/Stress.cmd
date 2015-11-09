@echo off

:test

	Gen.exe
	P2.exe
	Army.exe

	fc army.out army2.out || exit

goto test	