#ifndef STAN_MATH_PRIM_MAT_FUN_EIGENVALUES_HPP
#define STAN_MATH_PRIM_MAT_FUN_EIGENVALUES_HPP

#include <stan/math/prim/scal/err/check_nonzero_size.hpp>
#include <stan/math/prim/mat/err/check_symmetric.hpp>
#include <stan/math/prim/mat/fun/Eigen.hpp>

namespace stan {
  namespace math {

    template <typename T>
    Eigen::Matrix<T, Eigen::Dynamic, 1>
    eigenvalues(const Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>& m) {
      stan::math::check_nonzero_size("eigenvalues_sym", "m", m);

      typedef Eigen::EigenSolver
          <Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic> >
          EigenSolverInst;
      EigenSolverInst solver(m, Eigen::EigenvaluesOnly);
      
      typedef EigenSolverInst::EigenvalueType EigenvalueType;

      EigenvalueType evs = solver.eigenvalues();

      EigenvalueType::RealReturnType evsR = evs.real();
      EigenvalueType::ImagReturnType evsI = evs.imag();

      Eigen::Matrix<T, Eigen::Dynamic, 1> evsRI;
      evsRI << evsR, evsI;

      return evsRI;
    }

  }
}
#endif
