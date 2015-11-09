Program Army;

Uses
   SysUtils, Math;

Var
   k, x, i, n, m: integer;
   s: string;
   a: array [1 .. 100000] of integer;

Function check: boolean;

Var
  i: integer;

begin
  for i := 1 to (n - 1) do
  	if (a [i] > a [i + 1]) then
  	begin
  		result := false;
  		exit;
  	end;

  result := true;
end;	

begin
	reset (input, 'army.in');
	rewrite (output, 'army2.out');

	readln (n, m);

	for i := 1 to n do
		read (a [i]);

  readln;

	for i := 1 to m do
	begin
		readln (s);

		if (s = '?') then
			if (check) then
				writeln ('YES')
			else
				writeln ('NO');	

		if (s [1] = '!') then
		begin
			delete (s, 1, 2);
			k := ord (s [1]) - 48;
			x := ord (s [3]) - 48;                                             	
			a [k] := x;
		end;
	end;

	close (input);
	close (output);
end.	