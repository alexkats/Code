Program Chairs;

Uses
   SysUtils, Math;

Var
  i, j, n, m: integer;
  s: array [1 .. 100] of string;

begin
  reset (input, 'input.txt');
  rewrite (output, 'output.txt');

  readln (n, m);

  for i := 1 to (n * 3) do
   readln (s [i]);

  if (n = 1) and (m = 1) then
  begin
   for i := 1 to (n * 3) do
    writeln (s [i]);
   halt;
  end;

  for i := 1 to (n - 1) do
   for j := 1 to (m - 1) do
    if (s [i * 3 - 1][j * 3] <> '.') and (s [i * 3 - 1][j * 3 + 1] <> '.') and (s [i * 3][j * 3 - 1] <> '.') and (s [i * 3 + 1][j * 3 - 1] <> '.') and (s [i * 3 + 2][j * 3] <> '.') and (s [i * 3 + 2][j * 3 + 1] <> '.') and (s [i * 3][j * 3 + 2] <> '.') and (s [i * 3 + 1][j * 3 + 2] <> '.') then
     s [i * 3 - 1][j * 3] := '.';
      
  for i := 1 to (n * 3) do
   writeln (s [i]);

  close (input);
  close (output);
end.