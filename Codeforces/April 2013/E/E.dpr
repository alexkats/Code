Program ;

Uses
	SysUtils, Math;

Var
	s: string;
	n, qh, qq, i: integer;

begin
//	reset (input, '.in');
//	rewrite (output, '.out');

	readln (s);
	n := length (s);
	qh := 0;
	qq := 0;

	for i := 1 to n do
	begin
		if (s [i] = 'H') then
			inc (qh)
		else
			inc (qq);
	end;

	if (qh mod 2 = 0) and (qq mod 2 = 0) then
		writeln ('YES')
	else
		writeln ('NO');	

//	close (input);
//	close (output);
end.	