Program dt2;

Uses
	SysUtils, Math;

Const maxn = 1000;	

Var
	t: array [0 .. maxn * 4, 0 .. maxn * 4] of integer;
	a: array [0 .. maxn, 0 .. maxn] of integer;
	n, m, i, j: integer;

Procedure build_y (vx, lx, rx, vy, ly, ry: integer);

Var
	my: integer;

begin
	if (ly = ry) then
		if (lx = rx) then
			t [vx][vy] := a [lx][ly]
		else
			t [vx][vy] := t [vx * 2][vy] + t [vx * 2 + 1][vy]
	else
	begin
		my := (ly + ry) div 2;
		build_y (vx, lx, rx, vy * 2, ly, my);
		build_y (vx, lx, rx, vy * 2 + 1, my + 1, ry);
		t [vx][vy] := t [vx][vy * 2] + t [vx][vy * 2 + 1];
	end;
end;

Procedure build_x (vx, lx, rx: integer);

Var
	mx: integer;

begin
	if (lx = rx) then
		build_y (vx, lx, rx, 1, 0, m - 1)
	else
	begin
		mx := (lx + rx) div 2;
		build_x (vx * 2, lx, mx);
		build_x (vx * 2 + 1, mx + 1, rx);
	end;
end;

Function sum_y (vx, vy, trly, trry, ly, ry: integer): integer;

Var
	trmy: integer;

begin
	if (ly > ry) then
	begin
		result := 0;
		exit;
	end;

	if (ly = trly) and (ry = trry) then
	begin
		result := t [vx][vy];
		exit;
	end;

	trmy := (trly + trry) div 2;

	result := sum_y (vx, vy * 2, trly, trmy, ly, min (ry, trmy)) + sum_y (vx, vy * 2 + 1, trmy + 1, trry, max (ly, trmy + 1), ry);
end;

Function sum_x (vx, tlx, trx, lx, rx, ly, ry: integer): integer;

Var
	tmx: integer;

begin
	if (lx > rx) then
	begin
		result := 0;
		exit;
	end;

	if (lx = tlx) and (rx = trx) then
	begin
		result := sum_y (vx, 1, 0, m - 1, ly, ry);
		exit;
	end;

	tmx := (tlx + trx) div 2;

	result := sum_x (vx * 2, tlx, tmx, lx, min (rx, tmx), ly, ry) + sum_x (vx * 2 + 1, tmx + 1, trx, max (lx, tmx + 1), rx, ly, ry);
end;	

begin
	reset (input, 'dt2.in');
	rewrite (output, 'dt2d.out');

	readln (n, m);

	for i := 0 to (m - 1) do
		for j := 0 to (n - 1) do
			read (a [i][j]);

	build_x (1, 0, n - 1);

	writeln (sum_x (1, 0, n - 1, 2, 4, 1, 2));	

	close (input);
	close (output);
end.	