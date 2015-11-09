Program password;

Uses
   SysUtils, Math;

Var
	ms: string;
	s: array [1 .. 1010] of string;
	tmp: char;
	n, m, q, i: integer;

begin
	reset (input, 'input.txt');
	rewrite (output, 'output.txt');

	readln (n);
	tmp := 'a';
	q := 0;
	m := 0;

	for i := 1 to n do
	begin
		readln (s [i]);

		if (s [i][1] = tmp) then
			inc (q);

		if (s [i][1] <> tmp) then
		begin
			if (q >= m) then
			begin
				m := q;
				ms := s [i - 1];
			end;

			q := 1;
			tmp := s [i][1];
		end;
	end;

	writeln (ms);
	close (input);
	close (output);
end.	