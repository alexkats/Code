Program Sort;

{$APPTYPE CONSOLE}

Uses
   SysUtils;

Var
  n, i: integer;

begin
  readln (n);

  if (n = 1) or (n = 2) then
  begin
   writeln (-1);
   halt;
  end;

  write (10, ' ', 9, ' ');

  for i := 3 to n do
   write (7, ' ');

end.