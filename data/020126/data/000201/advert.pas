{$I OPTIONS.INC}
program ADVERT_CHECK;
uses
  testlib, symbols;

const
  maxabs = 10000;
  maxad = 2*maxabs+1;

var
  wa: boolean;
  wm: string;
  ad_cnt, ad, ans_ad_cnt: longint;
  i: longint;
  k, n, a, b, a_ad, b_ad, l, r, x, req: integer;
  ads: array[1..maxad] of integer;

begin
  wa:= false;

  { Read output }
  ad_cnt:= ouf.readLongint;
  if ad_cnt < 0 {(ad_cnt < 1) or (ad_cnt > maxad)} then
    Quit(_PE, 'Insane number of advertisements: ' + str(ad_cnt,0));
  for i:= 1 to ad_cnt do begin
    ad:= ouf.readLongint;
    if not wa and (abs(ad) > maxabs) then begin
      {Quit(_PE, 'Insane advertisement number: ' + str(ad,0));}
      wa:= true;
      wm:= 'Insane advertisement number: ' + str(ad,0);
    end;
    if not wa then begin
      ads[i]:= ad;
      if (i > 1) and (ads[i] <= ads[i-1]) then begin
        {Quit(_PE, 'Advertisements do not ordered properly: ' + str(ad,0));}
        wa:= true;
        wm:= 'Advertisements do not ordered properly: ' + str(ad,0);
      end;
    end;
  end;
  if not ouf.seekeof then Quit(_PE, 'Extra data in file');

  if wa then Quit(_WA, wm);

  { Read input }
  k:= inf.readLongint;
  n:= inf.readLongint;
  for i:= 1 to n do begin
    a:= inf.readLongint;
    b:= inf.readLongint;
    if a > b then begin
      x:= a;
      a:= b;
      b:= x;
    end;
    { Binary search for a }
    l:= 0;        { Exclusive: ads[l] < a  }
    r:= ad_cnt+1; { Inclusive: ads[r] >= a }
    while r - l > 1 do begin
      x:= (longint(l) + r) div 2;
      if ads[x] < a then
        l:= x
      else
        r:= x;
    end;
    a_ad:= r;
    { Binary search for b }
    l:= 0;        { Inclusive: ads[l] <= b  }
    r:= ad_cnt+1; { Exclusive: ads[r] > b }
    while r - l > 1 do begin
      x:= (longint(l) + r) div 2;
      if ads[x] <= b then
        l:= x
      else
        r:= x;
    end;
    b_ad:= l;
    { Now we know the count! }
    req:= b - a + 1;
    if req > k then req:= k;
    if b_ad - a_ad + 1 < req then
      Quit(_WA, 'Not enough ads for [' + str(a,0) + ', ' + str(b,0) + ']');
  end;

  { Read answer }
  ans_ad_cnt:= ans.readLongint;

  if ad_cnt > ans_ad_cnt then
    Quit(_WA, 'Output is not optimal: ' + str(ad_cnt,0) + ' > ' + str(ans_ad_cnt,0));

  if ad_cnt < ans_ad_cnt then
    Quit(_Fail, 'Correct answer is not optimal: ' + str(ad_cnt,0) + ' < ' + str(ans_ad_cnt,0));

  Quit(_OK, 'Ok');
end.
