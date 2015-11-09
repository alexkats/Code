Program H2O;

Uses
   SysUtils;

Var
  i, n, k, t: integer;
  m: int64;
  s: string;

begin
  reset (input, 'h2o.in');
  rewrite (output, 'h2o.out');
  readln (s);
  n := length (s);
  m := 0;
  k := 0;

  for i := 1 to n do
  begin
   if (ord (s [i]) > 65) and (k <> 0) then
    inc (m, k);
   if (s [i] = 'H') then
    k := 1
   else
    if (s [i] = 'C') then
     k := 12
    else
     if (s [i] = 'N') then
      k := 14
     else
      if (s [i] = 'O') then
       k := 16
      else
      begin
       t := ord (s [i]) - ord ('0');
       inc (m, t * k);
       k := 0;
      end;
  end;

  if (ord (s [n]) > 65) then
   inc (m, k);

  writeln (m);
  close (input);
  close (output);
end.