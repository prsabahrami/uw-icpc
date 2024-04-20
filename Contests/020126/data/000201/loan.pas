program LOAN_CHECK;
uses
  testlib, symbols;

type
  real = extended;

var
  wa: boolean;
  wm: string;
  souf, sans: string;
  xo, xa, yo, ya, xold: longint;
  qold, q, p, k, i: longint;

procedure GetLine(const line: string; var x, y: longint);
var
  s: string;
  qd: real;
  code, c2: integer;
begin
  if wa then exit;
  s:= compress(line);
  if (s = '') or (s[1] <> '$') then
    Quit(_PE, '"$" expected in: ' + line);
  delete(s, 1, 1);
  val(s, qd, code);
  if code <= 1 then
    Quit(_PE, 'Wrong dollar format: ' + line);
  val(copy(s,1,code-1), qd, c2);
  if (qd <= 0) or (qd > 2000000) then begin
    {Quit(_PE, 'Insane dollar value: ' + line);}
    wa:= true;
    wm:= 'Insane dollar value: ' + line;
    exit;
  end;
  x:= round(qd*100);
  delete(s, 1, code-1);
  s:= compress(s);
  if copy(s, 1, 3) <> 'for' then
    Quit(_PE, '"for" exprected in: ' + line);
  delete(s, 1, 3);
  val(s, y, code);
  if code <= 1 then
    Quit(_PE, 'Wrong year format: ' + line);
  val(copy(s,1,code-1), y, c2);
  if (y < 1) or (y > 100) then begin
    {Quit(_PE, 'Insane year value: ' + line);}
    wa:= true;
    wm:= 'Insane year value: ' + line;
    exit;
  end;
  delete(s, 1, code-1);
  s:= compress(s);
  if s <> 'year(s)' then
    Quit(_PE, '"year(s)" expected at the end in: ' + line);
end;

begin
  wa:= false;

  souf:= compress(ouf.readString);
  sans:= compress(ans.readString);

  if (cmpstr(souf, 'Impossible') = 0) <>
     (cmpstr(sans, 'Impossible') = 0) then begin
    wa:= true;
    wm:= 'Wrong answer: ' + souf + ' <> ' + sans;
  end;

  if cmpstr(souf, 'Impossible') <> 0 then begin
    GetLine(souf, xo, yo);
    if not wa then {!}
      GetLine(sans, xa, ya);
    if not wa and (xo <> xa) then begin
      wa:= true;
      wm:= 'Wrong 1st payment: ' + souf + ' <> ' + sans;
    end;

    q:= round(inf.readReal*100);
    p:= inf.readLongint;
    k:= inf.readLongint;

    while true do begin
      {if yo <= 0 then
        Quit(_PE, 'Insane year value in: ' + souf);}

      if not wa then begin
        dec(k, yo);
        if k < 0 then begin
          wa:= true;
          wm:= 'Too many years after: ' + souf;
        end;
      end;

      if not wa then begin
        for i:= 1 to yo do begin
          qold:= q;
          q:= q + trunc ( 0.01 * q * p + 0.5001 ) - xo;
          if (q < 0) or (q > qold) then begin
            wa:= true;
            wm:= 'Over/under payment in: ' + souf;
            break;
          end;
        end;
      end;

      if ouf.seekeof then break;

      souf:= compress(ouf.readString);
      xold:= xo;
      GetLine(souf, xo, yo);
      if not wa and (xo <> xold - 1) then begin
        {Quit(_PE, 'Payment sequence violated');}
        wa:= true;
        wm:= 'Payment sequence violated';
      end;
    end;

    if not wa and (k <> 0) then begin
      wa:= true;
      wm:= 'Invalid number of years, differs by ' + str(k,0);
    end;

    if not wa and (q <> 0) then begin
      wa:= true;
      wm:= 'Invalud payments, differs by ' + str(q, 0);
    end;
  end;

  if not ouf.seekeof then Quit(_PE, 'Extra data in file');
  if wa then Quit(_WA, wm);
  Quit(_OK, 'Ok');
end.
