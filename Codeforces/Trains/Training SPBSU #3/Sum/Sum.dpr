Program Sum;

Uses
   SysUtils;

Var
  a, b: integer;

begin
  reset (input, 'sum.in');
  rewrite (output, 'sum.out');
  readln (a, b);
  writeln (a + b);
  close (input);
  close (output);
end.