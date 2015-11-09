program BB1;

uses
   SysUtils, Math;

var
  k, c:Int64;
  i: Integer;
  n, m: array[1..1000000] of double;
  t, ch: double;

Procedure swap (Var a, b: double);

Var
  t: double;

begin
  t := a;
  a := b;
  b := t;
end;

Procedure QSort (l, r: integer);

Var
  i, j: integer;
  x: double;

begin
  i := l;
  j := r;
  x := n [l + random (r - l + 1)];
  
  while (i <= j) do
  begin
   while (n [i] < x) do
    inc (i);
   while (n [j] > x) do
    dec (j);
   if (i <= j) then
   begin
    swap (n [i], n[j]);
    swap (m [i], m [j]);
    inc (i);
    dec (j);
   end;
  end;

  if (l < j) then
   QSort (l, j);

  if (i < r) then
   QSort (i, r);
end;

begin
  reset (input, 'input.txt');
  rewrite (output, 'output.txt');
  read(t);
  k := 0;
  ch := sqrt(t);
  for i := 1 to round(ch)-1 do
  begin
   if (trunc((t - 1 + i) / (2 * i + 1)) = (t - 1 + i) / (2 * i + 1)) and (i<= (t - 1 + i)/(2 * i + 1)) then
     begin
      inc(k);
      m[k] := i;
      n[k] := (t - 1 + i)/(2 * i + 1);
     end
     
   else

   if (trunc((t  - i) / (2 * i - 1)) = (t - i) / (2 * i - 1)) and (i > (t - i)/(2 * i - 1)) and (t <> i) then
     begin
      inc(k);
      m[k] := i;
      n[k] := (t - i)/(2 * i - 1);
     end

   else

   if (trunc((t  + i) / (2 * i + 1)) = (t + i) / (2 * i + 1)) and (i < (t + i)/(2 * i + 1))  then
     begin
      inc(k);
      n[k] := i;
      m[k] := (t + i)/(2 * i + 1);
     end

   else

   if (trunc((t  - i - 1) / (2 * i - 1)) = (t - i - 1) / (2 * i - 1)) and (i >= (t - i - 1)/(2 * i - 1)) and (t <> i +1) then
     begin
      inc(k);
      n[k] := i;
      m[k] := (t - i - 1)/(2 * i - 1);
     end;
  end;

  QSort (1, k);
  c := k;

  for i := 1 to (k - 1) do
   if (n [i] = n[i + 1]) and (m [i] = m [i + 1]) then
   begin
    n [i] := 0;
    m [i] := 0;
    dec (c);
   end;

  Writeln(c);
  for i:= 1 to k do
  if (n [i] <> 0) and (m [i] <> 0) then
   writeln(n[i] : 0 : 0,' ',m[i] : 0 : 0);
  
  close (input);
  close (output);
end.