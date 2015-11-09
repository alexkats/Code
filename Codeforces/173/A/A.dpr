Program A;

Uses
   SysUtils;

Var
	i, n, x: integer;
	s: string;

begin
	readln (n);
	x := 0;

	for i := 1 to n do
	begin
		readln (s);

		if (s [2] = '+') then
			inc (x)
		else
			dec (x);
	end;

	writeln (x);	
end.                     