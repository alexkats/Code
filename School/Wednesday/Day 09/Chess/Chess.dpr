Program Chess;

Uses
   SysUtils;

Const
  n = 8;

Var
  s: char;
  str: string;
  i, j, k, istart, jstart, ifinish, jfinish: integer;
  a: array [1 .. 8, 1 .. 8] of integer;

Procedure convert (s: char);

begin
  if (s = '.') then
   a [i][j] := 0;
  if (s = 'k') then
   a [i][j] := -1;
  if (s = 'K') then
   a [i][j] := 1;
  if (s = 'q') then
   a [i][j] := -2;
  if (s = 'Q') then
   a [i][j] := 2;
  if (s = 'r') then
   a [i][j] := -3;
  if (s = 'R') then
   a [i][j] := 3;
  if (s = 'n') then
   a [i][j] := -4;
  if (s = 'N') then
   a [i][j] := 4;
  if (s = 'b') then
   a [i][j] := -5;
  if (s = 'B') then
   a [i][j] := 5;
  if (s = 'p') then
   a [i][j] := -6;
  if (s = 'P') then
   a [i][j] := 6;
end;

Procedure print;

begin
  if (a [ifinish][jfinish] = -1) then
   write ('k');
  if (a [ifinish][jfinish] = 1) then
   write ('K');
  if (a [ifinish][jfinish] = -2) then
   write ('q');
  if (a [ifinish][jfinish] = 2) then
   write ('Q');
  if (a [ifinish][jfinish] = -3) then
   write ('r');
  if (a [ifinish][jfinish] = 3) then
   write ('R');
  if (a [ifinish][jfinish] = -4) then
   write ('n');
  if (a [ifinish][jfinish] = 4) then
   write ('N');
  if (a [ifinish][jfinish] = -5) then
   write ('b');
  if (a [ifinish][jfinish] = 5) then
   write ('B');
  if (a [ifinish][jfinish] = -6) then
   write ('p');
  if (a [ifinish][jfinish] = 6) then
   write ('P');
end;
          
begin
  reset (input, 'chess.in');
  rewrite (output, 'chess.out');

  for i := 1 to n do
  begin
   readln (str);
   for j := 1 to n do
   begin
    s := str [j];
    convert (s);
   end;
  end;

  readln (k);

  for i := 1 to k do
  begin
   readln (str);
   jstart := ord (str [1]) - ord ('`');
   istart := 9 - ord (str [2]) + ord ('0');
   jfinish := ord (str [3]) - ord ('`');
   ifinish := 9 - ord (str [4]) + ord ('0');
   a [ifinish][jfinish] := a [istart][jstart];
   a [istart][jstart] := 0;
   print;
  end;

  close (input);
  close (output);
end.