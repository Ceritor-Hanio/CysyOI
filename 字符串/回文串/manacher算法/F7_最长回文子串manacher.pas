var s1:ansistring;
    i,id,mi,l,ans:longint;
    s:array[0..230000] of char;
    rad:array[0..230000] of longint;
function max(x,y:longint):longint;
begin
  if x>y then exit(x);
  exit(y);
end;
function min(x,y:longint):longint;
begin
  if x<y then exit(x);
  exit(y);
end;
begin
  while not eof do begin
    fillchar(rad,sizeof(rad),0);
    ans:=0;
    readln(s1);
    l:=length(s1);
    s[0]:='$'; s[1]:='#';
    for i:=1 to l do begin
      s[i*2]:=s1[i];
      s[i*2+1]:='#';
    end;
    l:=l*2+2;
    s[l]:='*';
    id:=0; mi:=0; ans:=1;
    for i:=1 to l do begin
      if mi>i then rad[i]:=min(rad[id*2-i],mi-i)
      else rad[i]:=1;
      while s[i+rad[i]]=s[i-rad[i]] do inc(rad[i]);
      if i+rad[i]>mi then begin
        mi:=i+rad[i];
        id:=i;
      end;
      if rad[i]>ans then ans:=rad[i];
    end;
    writeln(ans-1);
    readln;
  end;
end.