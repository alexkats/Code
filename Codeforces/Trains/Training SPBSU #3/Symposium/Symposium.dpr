Program Symposium;

Uses
   SysUtils;

Var
  n, q, i: integer;
  a: array [1 .. 1000] of integer;

Procedure swap (Var a, b: integer);

Var
  t: integer;

begin
  t := a;
  a := b;
  b := t;
end;

Procedure QSort (l, r: integer);

Var
  i, j, x: integer;

begin
  i := l;
  j := r;
  x := a [l + random (r - l + 1)];

  while (i <= j) do
  begin
   while (a [i] > x) do
    inc (i);
   while (a [j] < x) do
    dec (j);
   if (i <= j) then
   begin
    swap (a [i], a [j]);
    inc (i);
    dec (j);
   end;
  end;

  if (l < j) then
   QSort (l, j);

  if (i < r) then
   QSort (i, r);
end;

begin
  reset (input, 'symposium.in');
  rewrite (output, 'symposium.out');
  readln (n);
  q := n;

  for i := 1 to n do
   read (a [i]);

  QSort (1, n);

  for i := 1 to (n - 1) do
   if (a [i] / 2 >= a [i + 1]) then
    dec (q);

  writeln (q);
  close (input);
  close (output);
end.