const
  maxs=1 << 8;
  maxn=55;
  con=1061109567;
var
  f,g: array[0..maxn,0..maxs,0..maxs]of longint;
  n,m,max: longint;
  cost: array[0..maxn,0..maxs,0..2]of longint;
procedure init();
var
  i,j,k,x: longint;
begin
  readln(n,m);
  max:=(1 << m)-1;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(x);
      for k:=0 to max do
        if k and (1 << (j-1))>=(1 << (j-1)) then begin
          inc(cost[i][k][1],x); inc(cost[i][k][2]);
        end;
    end;
  end;
  fillchar(f,sizeof(f),63);
  fillchar(g,sizeof(g),63);
  for k:=0 to max do begin
    f[1][k][0]:=cost[1][k][1];
    g[1][k][0]:=cost[1][k][2];
  end;
end;
procedure main();
var
  i,j,k,n_l,a1,a2: longint;
begin
  for i:=1 to n do
    for j:=0 to max do
      for k:=0 to max do begin
        if f[i][j][k]=con then continue;
        for n_l :=0 to max do
         if (n_l or j or k or (j<<1) or (j>>1))and max=max then
           if f[i][j][k]+cost[i+1][n_l][1]<f[i+1][n_l][j] then begin
           f[i+1][n_l][j]:=f[i][j][k]+cost[i+1][n_l][1];
           g[i+1][n_l][j]:=g[i][j][k]+cost[i+1][n_l][2];
         end;
      end;
  a2:=maxlongint;
  for k:=0 to max do
    if (f[n+1][0][k]<a2)or((f[n+1][0][k]=a2)and(g[n+1][0][k]<a1)) then begin
    a1:=g[n+1][0][k];
    a2:=f[n+1][0][k];
  end; writeln(a1,' ',a2);
end;
begin
  init();
  main();
end.
