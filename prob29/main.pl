% SWI-Prolog

raise(_, [], []).
raise(A, [H | T], [Hr | Tr]) :-
    Hr is H**A,
    raise(A, T, Tr).

listraise([], _, []).
listraise([H | T], L, [Hr | Tr]) :-
    raise(H, L, Hr),
    listraise(T, L, Tr).

sol(MaxA, MaxB, Sol) :-
    numlist(2, MaxA, La),
    numlist(2, MaxB, Lb),
    listraise(Lb, La, Acc),
    flatten(Acc, Lf),
    sort(Lf, Lu),
    length(Lu, Sol).

sol29(Sol) :- sol(100, 100, Sol).
