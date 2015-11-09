Program B;

Uses
   SysUtils, Math;

Var
  s: string;
  k: integer;

begin
  readln (s);

  while (pos ('xy', s) <> 0) or (pos ('yx', s) <> 0) do
  begin
   while (pos ('yx', s) <> 0) do
   begin
    k := pos ('yx', s);
    s [k] := 'x';
    s [k + 1] := 'y';
   end;
   if (pos ('xy', s) <> 0) then
   begin
    k := pos ('xy', s);
    delete (s, k, 2);
   end;
  end;

  writeln (s);
end.