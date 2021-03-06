/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Gabor Szokoli <szokoli@gecode.org>
 *     Guido Tack <tack@gecode.org>
 *     Christian Schulte <schulte@gecode.org>
 *
 *  Copyright:
 *     Gabor Szokoli, 2004
 *     Guido Tack, 2004
 *     Christian Schulte, 2004
 *
 *  This file is part of Gecode, the generic constraint
 *  development environment:
 *     http://www.gecode.org
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <gecode/set.hh>
#include <gecode/set/int.hh>

namespace Gecode {

  void
  cardinality(Home home, SetVar x, unsigned int i, unsigned int j) {
    Set::Limits::check(i, "Set::cardinality");
    Set::Limits::check(j, "Set::cardinality");
    GECODE_POST;
    Set::SetView _x(x);
    GECODE_ME_FAIL(_x.cardMin(home, i));
    GECODE_ME_FAIL(_x.cardMax(home, j));
  }

  void
  cardinality(Home home, const SetVarArgs& x, unsigned int i, unsigned int j) {
    Set::Limits::check(i, "Set::cardinality");
    Set::Limits::check(j, "Set::cardinality");
    GECODE_POST;
    for (int k=x.size(); k--; ) {
      Set::SetView _x(x[k]);
      GECODE_ME_FAIL(_x.cardMin(home, i));
      GECODE_ME_FAIL(_x.cardMax(home, j));
    }
  }

  void
  cardinality(Home home, SetVar s, IntVar x) {
    GECODE_POST;
    GECODE_ES_FAIL(Set::Int::Card<Set::SetView>::post(home,s, x));
  }

  void
  cardinality(Home home, SetVar s, IntVar x, Reify r) {
    IntVar y(home, 0, static_cast<int>(Set::Limits::card));
    rel(home, x, IRT_EQ, y, r);
    cardinality(home, s, y);
  }

}

// STATISTICS: set-post
