Program Petrol;

Uses
   SysUtils;

Var
  i, n, a, b, c, ans: integer;
  min: extended;

begin
  reset (input, 'petrol.in');
  rewrite (output, 'petrol.out');
  readln (n);
  min := maxint;

  for i := 1 to n do
  begin
   readln (a, b, c);
   if (a / (c - b) < min) then
   begin
    min := a / (c - b);
    ans := i;
   end;
  end;

  writeln (ans);
  close (input);
  close (output);
end.