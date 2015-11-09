@echo off

:test

	gen.exe
	old.exe
	R.exe

	fc smallnim.out old.out || exit

goto exit	