/* -*- mode: C++; c-basic-offset: 2; indent-tabs-mode: nil -*- */
/*
 *  Main authors:
 *     Christian Schulte <schulte@gecode.org>
 *     Vincent Barichard <Vincent.Barichard@univ-angers.fr>
 *
 *  Copyright:
 *     Christian Schulte, 2012
 *     Vincent Barichard, 2012
 *
 *  Last modified:
 *     $Date$ by $Author$
 *     $Revision$
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

#ifndef __GECODE_FLOAT_BRANCH_HH__
#define __GECODE_FLOAT_BRANCH_HH__

#include <gecode/float.hh>

/**
 * \namespace Gecode::Float::Branch
 * \brief Float branchers
 */

namespace Gecode { namespace Float { namespace Branch {

  /**
   * \defgroup FuncFloatViewSel Merit-based float view selection for branchers
   *
   * Contains merit-based view selection strategies on float
   * views that can be used together with the generic view/value
   * brancher classes.
   *
   * All merit-based float view selection classes require 
   * \code #include <gecode/float/branch.hh> \endcode
   * \ingroup Other
   */

  /**
   * \brief Merit class for mimimum
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritMin : public MeritBase<FloatView,double> {
  public:
    /// Constructor for initialization
    MeritMin(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritMin(Space& home, bool shared, MeritMin& m);
    /// Return minimum as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
  };

  /**
   * \brief Merit class for maximum of float view
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritMax : public MeritBase<FloatView,double> {
  public:
    /// Constructor for initialization
    MeritMax(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritMax(Space& home, bool shared, MeritMax& m);
    /// Return maximum as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
  };

  /**
   * \brief Merit class for size of float view
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritSize : public MeritBase<FloatView,double> {
  public:
    /// Constructor for initialization
    MeritSize(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritSize(Space& home, bool shared, MeritSize& m);
    /// Return size as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
  };

  /**
   * \brief Merit class for size over degree
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritSizeDegree : public MeritBase<FloatView,double> {
  public:
    /// Constructor for initialization
    MeritSizeDegree(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritSizeDegree(Space& home, bool shared, MeritSizeDegree& m);
    /// Return size over degree as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
  };

  /**
   * \brief Merit class for size over afc
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritSizeAfc : public MeritBase<FloatView,double> {
  public:
    /// Constructor for initialization
    MeritSizeAfc(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritSizeAfc(Space& home, bool shared, MeritSizeAfc& m);
    /// Return size over AFC as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
  };

  /**
   * \brief Merit class for size over activity
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatViewSel
   */
  class MeritSizeActivity : public MeritBase<FloatView,double> {
    /// Activity information
    Activity activity;
  public:
    /// Constructor for initialization
    MeritSizeActivity(Space& home, const VarBranch& vb);
    /// Constructor for cloning
    MeritSizeActivity(Space& home, bool shared, MeritSizeActivity& m);
    /// Return size over activity as merit for view \a x at position \a i
    double operator ()(const Space& home, FloatView x, int i);
    /// Whether dispose must always be called (that is, notice is needed)
    bool notice(void) const;
    /// Dispose view selection
    void dispose(Space& home);
  };

}}}

#include <gecode/float/branch/merit.hpp>

namespace Gecode { namespace Float { namespace Branch {

  /// Return view selectors for float views
  GECODE_FLOAT_EXPORT
  ViewSel<FloatView>* viewsel(Space& home, const FloatVarBranch& fvb);

}}}

namespace Gecode { namespace Float { namespace Branch {

  /**
   * \defgroup FuncFloatValSel Float value selection for brancher
   *
   * Contains a description of value selection strategies on float
   * views that can be used together with the generic view/value
   * branchers.
   *
   * All value selection classes require 
   * \code #include <gecode/float/branch.hh> \endcode
   * \ingroup Other
   */

  /**
   * \brief Value selection class for median of view
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatValSel
   */
  class ValSelMed : public ValSel<FloatView,FloatNum> {
  public:
    /// Constructor for initialization
    ValSelMed(Space& home, const ValBranch& vb);
    /// Constructor for cloning
    ValSelMed(Space& home, bool shared, ValSelMed& vs);
    /// Return value of view \a x
    FloatNum val(const Space& home, FloatView x);
  };

  /**
   * \brief Value selection class for random value of view
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatValSel
   */
  class ValSelRnd 
    : public ValSel<FloatView,std::pair<FloatNum,bool> > {
  protected:
    /// The used random number generator
    Rnd r;
  public:
    /// Constructor for initialization
    ValSelRnd(Space& home, const ValBranch& vb);
    /// Constructor for cloning
    ValSelRnd(Space& home, bool shared, ValSelRnd& vs);
    /// Return value of view \a x
    Val val(const Space& home, FloatView x);
    /// Whether dispose must always be called (that is, notice is needed)
    bool notice(void) const;
    /// Delete value selection
    void dispose(Space& home);
  };

}}}

#include <gecode/float/branch/val-sel.hpp>

namespace Gecode { namespace Float { namespace Branch {

  /**
   * \defgroup FuncFloatValCommit Float value commit classes
   *
   * Contains the value commit classes for float
   * views that can be used together with the generic view/value
   * branchers.
   *
   * All value commit classes require 
   * \code #include <gecode/float/branch.hh> \endcode
   * \ingroup Other
   */

  /**
   * \brief Value commit class for less or equal
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatValCommit
   */
  class ValCommitLq : public ValCommit<FloatView,FloatNum> {
  public:
    /// Constructor for initialization
    ValCommitLq(Space& home, const ValBranch& vb);
    /// Constructor for cloning
    ValCommitLq(Space& home, bool shared, ValCommitLq& vc);
    /// Commit view \a c to value \a n for alternative \a a
    ModEvent commit(Space& home, unsigned int a, FloatView x, FloatNum n);
  };

  /**
   * \brief Value commit class for greater or equal
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatValCommit
   */
  class ValCommitGq : public ValCommit<FloatView,FloatNum> {
  public:
    /// Constructor for initialization
    ValCommitGq(Space& home, const ValBranch& vb);
    /// Constructor for cloning
    ValCommitGq(Space& home, bool shared, ValCommitGq& vc);
    /// Commit view \a c to value \a n for alternative \a a
    ModEvent commit(Space& home, unsigned int a, FloatView x, FloatNum n);
  };

  /**
   * \brief Value commit class for less or equal or greater or equal
   *
   * Requires \code #include <gecode/float/branch.hh> \endcode
   * \ingroup FuncFloatValCommit
   */
  class ValCommitLqGq 
    : public ValCommit<FloatView,std::pair<FloatNum,bool> > {
  public:
    /// Constructor for initialization
    ValCommitLqGq(Space& home, const ValBranch& vb);
    /// Constructor for cloning
    ValCommitLqGq(Space& home, bool shared, ValCommitLqGq& vc);
    /// Commit view \a c to value \a n for alternative \a a
    ModEvent commit(Space& home, unsigned int a, FloatView x, Val n);
  };

}}}

#include <gecode/float/branch/val-commit.hpp>

namespace Gecode { namespace Float { namespace Branch {

  /// Return value and commit for float views
  GECODE_FLOAT_EXPORT
  ValSelCommitBase<FloatView,FloatNum>* 
  valselcommit(Space& home, const FloatValBranch& svb);

  /// Return value and commit for float views
  GECODE_FLOAT_EXPORT
  ValSelCommitBase<FloatView,FloatNum>* 
  valselcommit(Space& home, const FloatAssign& ia);

}}}

#endif

// STATISTICS: float-branch
