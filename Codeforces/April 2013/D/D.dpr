Program Orange;

Uses
	SysUtils, Math;

Var
	s, t: string;
	i, n, k: integer;
	r: char;

begin
//	reset (input, '.in');
//	rewrite (output, '.out');

	readln (s);
	readln (k);

	n := length (s);

	for i := 1 to n do
		if (s [i] = upcase (s [i])) then
			s [i] := chr (ord (s [i]) + 32);

	for i := 1 to n do
	begin
		r := s [i];

		if (ord (r) < k + 97) then
			t := t + upcase (r)
		else
			t := t + r;
	end;	

	writeln (t);	

//	close (input);
//	close (output);
end.	