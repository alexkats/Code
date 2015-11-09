Program Typewriter;

Uses
   SysUtils, Math;

Var
	s: array [1 .. 200010] of string;
	i, j, n, q, e, r: integer;
	m: array [1 .. 200010] of integer;

begin
	reset (input, 'typewriter.in');
	rewrite (output, 'typewriter.out');

	readln (n);

	for i := 1 to n do
	begin
		readln (s [i]);
		m [i] := length (s [i]);
	end;

	q := m [1] + 1;

	for i := 2 to n do
	begin
		r := 0;

		for j := 1 to min (m [i], m [i - 1]) do
			if (s [i][j] <> s [i - 1][j]) then
			begin
				r := j;
				break;
			end;

		if (r = 0) and (m [i] >= m [i - 1]) then
		begin
			inc (q, m [i] - m [i - 1] + 2);
			continue;
		end;

		if (r = 0) then
			e := m [i - 1] - m [i] + 1
		else	
			e := 2 * (m [i] - r + 1) + 1;

		inc (q, min (e, m [i]) + 1);
	end;

	writeln (q - 1);	

	close (input);
	close (output);
end.	