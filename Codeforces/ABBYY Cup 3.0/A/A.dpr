Program P1;

Uses
	SysUtils, Math;

Var
	s: string;
	r, i, n, q: integer;
	k: int64;
	z: array ['A' .. 'J'] of boolean;

begin
//	reset (input, '.in');
//	rewrite (output, '.out');

	readln (s);
	n := length (s);
	k := 1;
	r := 10;
	q := 0;

	for i := 1 to n do
	begin	
		if (s [i] = '?') and (i <> 1) then
			inc (q);

		if (s [i] = '?') and (i = 1) then
			k := k * 9;	

		if (s [i] >= 'A') and (s [i] <= 'J') and (z [s [i]] = false) and (i <> 1) then
		begin
			z [s [i]] := true;
			k := k * r;
			dec (r);
		end;

		if (s [i] >= 'A') and (s [i] <= 'J') and (z [s [i]] = false) and (i = 1) then
		begin
			z [s [i]] := true;
			dec (r);
			k := k * r;
		end;	
	end;	
			
	writeln (k, '.0E+', q);

//	close (input);
//	close (output);
end.	