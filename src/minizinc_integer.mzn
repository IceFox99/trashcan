% CSP using integer variables
int: n;
set of int: DIM = 1..n;
array [DIM] of var DIM: q; % queen in row i is in column q[i]

include "alldifferent.mzn";

constraint alldifferent(q); % different column
constraint alldifferent([ q[i] + i | i in DIM]); % from bottom left to top right diagonal
constraint alldifferent([ q[i] - i | i in DIM]); % from top left to bottom right diagonal

% search
solve satisfy;
      
% printing output in chess format    
output ["N = " ++ show(n) ++ "\n"] ++
	   [ if fix(q[j]) == i then "Q" else "." endif ++
         if j == n then "\n" else "" endif | i,j in 1..n]