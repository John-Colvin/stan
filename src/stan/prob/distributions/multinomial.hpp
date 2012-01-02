#ifndef __STAN__PROB__DISTRIBUTIONS__MULTINOMIAL_HPP__
#define __STAN__PROB__DISTRIBUTIONS__MULTINOMIAL_HPP__

#include <stan/prob/traits.hpp>
#include <stan/prob/error_handling.hpp>
#include <stan/prob/constants.hpp>

namespace stan {

  namespace prob {
    using boost::math::tools::promote_args;
    using boost::math::policies::policy;

    using Eigen::Matrix;
    using Eigen::Dynamic;

    // Multinomial(ns|N,theta)   [0 <= n <= N;  SUM ns = N;   
    //                            0 <= theta[n] <= 1;  SUM theta = 1]
    template <bool propto = false,
	      typename T_prob, class Policy = policy<> >
    inline typename promote_args<T_prob>::type
    multinomial_log(const std::vector<int>& ns,
		    const Matrix<T_prob,Dynamic,1>& theta, 
		    const Policy& = Policy()) {
      // FIXME: domain checks
      using stan::maths::multiply_log;

      typename promote_args<T_prob>::type lp(0.0);
      if (include_summand<propto>::value) {	
	double sum = 1.0;
	for (unsigned int i = 0; i < ns.size(); ++i) 
	  sum += ns[i];
	lp += lgamma(sum);
	for (unsigned int i = 0; i < ns.size(); ++i)
	  lp -= lgamma(ns[i] + 1.0);
      }
      if (include_summand<propto,T_prob>::value)
	for (unsigned int i = 0; i < ns.size(); ++i)
	  lp += multiply_log(ns[i], theta[i]);
      return lp;
    }


  }
}
#endif
