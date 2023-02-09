% CSP using boolean variables
int: n;
set of int: DIM = 1..n;
array [DIM, DIM] of var bool: q;

constraint forall (i in DIM) ( sum (j in DIM) (q[i,j]) == 1 ); % one queen in each row
constraint forall (i in DIM) ( sum (j in DIM) (q[j,i]) == 1 ); % one queen in each column

% at most one queen in each bottom left to top right diagonal
constraint forall (s in 2..n*2) (
	sum (i in max(s-n,1)..min(s-1,n)) (q[i,s-i]) <= 1
);

% at most one queen in each top left to bottom right diagonal
constraint forall (s in 1-n..n-1) (
	sum (i in max(1-s,1)..min(n-s,n)) (q[i,s+i]) <= 1
);

solve satisfy;
      
% printing output in chess format
output ["N = " ++ show(n) ++ "\n"] ++
	   [ if fix(q[i,j]) then "Q" else "." endif ++
		 if j==n then "\n" else "" endif | i,j in DIM ]