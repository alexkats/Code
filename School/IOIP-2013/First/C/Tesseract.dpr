Program Tesseract;

Uses
   SysUtils, Math;

Var

begin
	reset (input, 'tesseract.in');
	rewrite (output, 'tesseract.out');

	readln (s);
	n := length (s);

	for i := 1 to n do
	begin
		