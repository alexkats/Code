Program Fib;

Uses
   SysUtils;

Var
  a: array [0 .. 45] of integer;
  i, n: integer;

begin
  reset (input, 'fib.in');
  rewrite (output, 'fib.out');
  readln (n);
  a [0] := 1;
  a [1] := 1;

  for i := 2 to n do
   a [i] := a [i - 1] + a [i - 2];

  writeln (a [n]);
  close (input);
  close (output);
end.