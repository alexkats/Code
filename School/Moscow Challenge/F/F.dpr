Program F;

Uses
   SysUtils, Math;

Var
  ans, r, q, n, i: integer;
  s: string;

begin
  reset (input, 'input.txt');
  rewrite (output, 'output.txt');
  readln (n);
  readln (s);
  r := 0;
  q := 0;

  for i := 1 to n do
  begin
   if (s [i] <> '0') and (s [i] <> '1') and (s [i] <> '8') and (s [i] <> '*') then
   begin
    writeln (0);
    halt;
   end;
   if (s [i] = '*') then
   begin
    if (i = 1) or (i = n) then
     inc (r);
    inc (q);
   end;
  end;

  ans := 3 * (q - r) + 2 * r;
  writeln (ans);
  close (input);
  close (output);
end.