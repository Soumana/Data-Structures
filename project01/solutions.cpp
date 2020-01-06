#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.

int numSublists(list p) {
    if(is_null(p))
        return 0;

    return numSublists(cdr(p)) + 1;
}

list nthSublist(list p, int n) {
    if( n == 1 )
        return car(p);

    return nthSublist(cdr(p), n - 1);
}

int numAtoms(list p) {
    if(is_null(p))
        return 0;

    if( is_atom( car(p) ))
        return 1 + numAtoms(cdr(p));

    return numAtoms(cdr(p));

}

bool member(list p, list q) {
    if(is_null(q)) {
        return false;
    }
    if(is_atom(car(q))) {
        if(eq(p, car(q))) {
            return true;
        }
        return member(p, cdr(q));
    }
    return member(p, car(q));
}

list append(list p, list q) {
    if(is_null(p))
        return q;
    return cons(car(p), append(cdr(p), q));
}

list atomsAtLevel(list p, int level) {
    if(level == 0 || is_null(p))
        return null();

    if(is_atom(car(p)))
        return level == 1 ? cons(car(p), atomsAtLevel(cdr(p), level)) :
                                         atomsAtLevel(cdr(p), level);
    return append(atomsAtLevel(car(p), level -1 ), atomsAtLevel(cdr(p), level));
}

bool is_lat(list p) {
    if(is_null(p)) {
        return true;
    }
    else if(is_atom(car(p))) {
        return is_lat(cdr(p));
    }
    return false;
}

list last(list p) {
    if(is_null(cdr(p))) {
        return car(p);
    }
    return last(cdr(p));
}

list list_pair(list p, list q) {
    if(is_null(p)) {
        return p;
    }
    return cons(cons(car(p), cons(car(q), null())), list_pair(cdr(p), cdr(q)));
}

list firsts(list p) {
   if(is_null(p)) {
       return p;
   }
   return cons(car(car(p)), firsts(cdr(p)));
}

list flat(list p) {
    if(is_null(p)) {
        return p;
    }
    if(is_atom(car(p))) {
        return cons(car(p), flat(cdr(p)));
    }
    if(is_null(car(p))) {
        return flat(cdr(p));
    }
    return flat(append(car(p), cdr(p)));
}

bool two_the_same(list p, list q) {
    if(is_null(p) || is_null(q)) {
        return false;
    }
    if(is_atom(p)) {
        if(is_atom(q)) {
            return eq(p, q);
        }
        return two_the_same(p, car(q)) || two_the_same(p, cdr(q));
    }
    return two_the_same(car(p), q) || two_the_same(cdr(p), q);
}

bool equal(list p, list q) {
    if(is_null(p) && is_null(q)) {
        return true;
    }
    if((!is_null(p) && is_null(q)) || (is_null(p) && !is_null(q))) {
        return false;
    }
    if((is_atom(car(p)) && !is_atom(car(q))) || (!is_atom(car(p)) && is_atom(car(q)))) {
        return false;
    }
    if(is_atom(car(p)) && is_atom(car(q))) {
        return eq(car(p), car(q)) && equal(cdr(p), cdr(q));
    }
    return equal(car(p), car(q)) && equal(cdr(p), cdr(q));
}

list total_reverse(list p) {
    if(is_null(p) || is_atom(p)) {
        return p;
    }
    return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
}

list shape(list p) {
    if(is_null(p)) {
        return null();
    }
    if(is_atom(car(p))) {
        return shape(cdr(p));
    }
    return cons(shape(car(p)), shape(cdr(p)));
}

list intersection(list p, list q) {
    if(is_null(p) || is_null(q)) {
        return null();
    }
    if(member(car(p), q)) {
        return cons(car(p), intersection(cdr(p), q));
    }
    return intersection(cdr(p), q);
}

list list_union(list p, list q) {
    if(is_null(p)) {
        return q;
    }
    if(!member(car(p), q)) {
        return cons(car(p), list_union(cdr(p), q));
    }
    return list_union(cdr(p), q);
}
