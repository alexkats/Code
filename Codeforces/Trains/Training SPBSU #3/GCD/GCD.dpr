Program GCD;

Uses
   SysUtils;

Var
  a, b: integer;

Function NOD (a, b: integer): integer;

Var
  t: integer;

begin
  if (a = 0) then
  begin
   result := b;
   exit;
  end;

  if (b = 0) then
  begin
   result := a;
   exit;
  end;

  if (a = b) then
  begin
   result := a;
   exit;
  end;

  if (a = 1) or (b = 1) then
  begin
   result := 1;
   exit;
  end;

  if (a mod 2 = 0) and (b mod 2 = 0) then
  begin
   a := a div 2;
   b := b div 2;
   result := 2 * NOD (a, b);
   exit;
  end;

  if (a mod 2 = 0) then
  begin
   a := a div 2;
   result := NOD (a, b);
   exit;
  end;

  if (b mod 2 = 0) then
  begin
   b := b div 2;
   result := NOD (a, b);
   exit;
  end;

  if (a < b) then
  begin
   t := a;
   a := (b - a) div 2;
   b := t;
   result := NOD (a, b);
   exit;
  end;

  t := b;
  b := (a - b) div 2;
  a := t;
  result := NOD (a, b);
end;

begin
  reset (input, 'gcd.in');
  rewrite (output, 'gcd.out');
  readln (a, b);
  writeln (NOD (a, b));
  close (input);
  close (output);
end.