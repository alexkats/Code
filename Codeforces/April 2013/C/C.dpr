Program WTF;

Uses
	SysUtils, Math;

Var
	foo, bar, baz, quz, tux, pur, i: integer;
	ans: double;

begin
//	reset (input, '.in');
//	rewrite (output, '.out');

	readln (tux);

	foo := 0;
	bar := 0;
	baz := 0;
	quz := 1;

	for i := tux downto 1 do
	begin
		readln (pur);
		inc (foo, pur);
		inc (bar);

		if (max (foo * quz, bar * baz) = foo * quz) then
		begin
			baz := foo;
			quz := bar;
		end;
	end;

	ans := baz / quz;

	writeln (ans : 0 : 6);	

//	close (input);
//	close (output);
end.	