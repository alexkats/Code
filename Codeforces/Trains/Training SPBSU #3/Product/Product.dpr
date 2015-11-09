Program Product;

Uses
   SysUtils;

Var
  a, b, q: int64;

begin
  reset (input, 'product.in');
  rewrite (output, 'product.out');
  readln (a, b);
  q := a * b;
  writeln (q);
  close (input);
  close (output);
end.