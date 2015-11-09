Program Apbtest;

Uses
   SysUtils;

Var
  a, b, q: int64;

begin
  reset (input, 'apbtest.in');
  rewrite (output, 'apbtest.out');
  readln (q);
  a := q div 2;
  b := q - a;
  writeln (a, ' ', b);
  close (input);
  close (output);
end.