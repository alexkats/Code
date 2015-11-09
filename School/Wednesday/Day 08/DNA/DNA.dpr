Program DNA;

Uses
   SysUtils;

Var
  n, i: integer;
  t, s1, s2: string;
  s: array [1 .. 200] of char;

begin
  reset (input, 'dna.in');
  rewrite (output, 'dna.out');
  s2 := '';
  readln (s1);
  readln (t);
  n := length (s1);

  for i := 1 to n do
  begin
   if (s1 [i] = 'A') then
    s [n - i + 1] := 'T';
   if (s1 [i] = 'T') then
    s [n - i + 1] := 'A';
   if (s1 [i] = 'G') then
    s [n - i + 1] := 'C';
   if (s1 [i] = 'C') then
    s [n - i + 1] := 'G';
  end;

  for i := 1 to n do
   s2 := s2 + s [i];

  if (pos (t, s1) = 0) and (pos (t, s2) = 0) then
   writeln ('No')
  else
   writeln ('Yes');

  close (input);
  close (output);
end.