Program Lock;

Uses
	SysUtils, Math;

Var

begin
	reset (input, '.in');
	rewrite (output, '.out');

	readln (h, w, k);

	for i := 1 to h do
	begin
		readln (s);
		
		for j := 1 to w do
			if (s [j] = '.') then
				a [i][j] := 0
			else
				a [i][j] := 1;
	end;

	for i := 1 to n do
	begin
			

	close (input);
	close (output);
end.	