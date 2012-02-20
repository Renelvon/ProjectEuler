% GCD.
% Generalised for negative numbers.
% Implementation as arithmetic function pending...
gcd(N, M, G) :-
	integer(N), integer(M),
	Nabs is abs(N), Mabs is abs(M),
	(Nabs > Mabs -> gcd_P(Nabs, Mabs, G) ; gcd_P(Mabs, Nabs, G)).

gcd_P(X, 0, X) :- !.
gcd_P(X, Y, G) :- Z is X mod Y, gcd_P(Y, Z, G).

% LCM
lcm(N, M, L) :- gcd(N, M, G), L is N * M div G.

% Extended LCM over lists of integers.
lcm_l([N], N).
lcm_l([N, M], G) :- !, lcm(N, M, G).
lcm_l([N, M | T], G) :- lcm(N, M, NewL), lcm_l([NewL | T], G).

range(A, B, L) :- (A =< B -> NewA is A + 1, range(NewA, B, NewL), L = [A | NewL]) ; L = [].

sol5(LCM) :- range(1, 20, L), lcm_l(L, LCM).
