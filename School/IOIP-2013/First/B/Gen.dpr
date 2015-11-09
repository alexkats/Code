Program Gen;

Uses
   SysUtils, Math;

Var
   n, m, i, k: integer;

begin
	rewrite (output, 'army.in');

	randomize;

	n := 1 + random (10000);
	m := 1 + random (10000);
	writeln (n, ' ', m);

	for i := 1 to n do
		write (1 + random (1000000000), ' ');

	writeln;

	for i := 1 to m do
	begin
		k := 1 + random (2);

		if (k = 1) then
			writeln ('?');

		if (k = 2) then
			writeln ('! ', 1 + random (n), ' ', 1 + random (1000000000));
	end;

	close (output);
end.	