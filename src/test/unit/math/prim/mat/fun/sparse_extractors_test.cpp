#include <stan/math/prim/mat/fun/assign.hpp>
#include <stan/math/prim/mat/fun/sparse_extractors.hpp>
#include <stan/math/prim/mat/fun/typedefs.hpp>
#include <gtest/gtest.h>
#include <vector>

TEST(SparseStuff,extract_csc_w) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  stan::math::vector_d result = stan::math::extract_w(a);
  EXPECT_FLOAT_EQ( 2.0,result(0));
  EXPECT_FLOAT_EQ( 8.0,result(1));
  EXPECT_FLOAT_EQ( 4.0,result(2));
  EXPECT_FLOAT_EQ(10.0,result(3));
  EXPECT_FLOAT_EQ( 6.0,result(4));
  EXPECT_FLOAT_EQ(12.0,result(5));
}

TEST(SparseStuff,extract_csr_w) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double, Eigen::RowMajor> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  stan::math::vector_d result = stan::math::extract_w(a);
  EXPECT_FLOAT_EQ( 2.0,result(0));
  EXPECT_FLOAT_EQ( 4.0,result(1));
  EXPECT_FLOAT_EQ( 6.0,result(2));
  EXPECT_FLOAT_EQ( 8.0,result(3));
  EXPECT_FLOAT_EQ(10.0,result(4));
  EXPECT_FLOAT_EQ(12.0,result(5));
}

TEST(SparseStuff,extract_csc_v) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
	std::vector<int> result = stan::math::extract_v(a);
  EXPECT_EQ(1,result[0]);
  EXPECT_EQ(2,result[1]);
  EXPECT_EQ(1,result[2]);
  EXPECT_EQ(2,result[3]);
  EXPECT_EQ(1,result[4]);
  EXPECT_EQ(2,result[5]);
}

TEST(SparseStuff,extract_csr_v) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double,Eigen::RowMajor> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
	std::vector<int> result = stan::math::extract_v(a);
  EXPECT_EQ(1,result[0]);
  EXPECT_EQ(2,result[1]);
  EXPECT_EQ(3,result[2]);
  EXPECT_EQ(1,result[3]);
  EXPECT_EQ(2,result[4]);
  EXPECT_EQ(3,result[5]);
}


TEST(SparseStuff,extract_csc_u) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  std::vector<int> result = stan::math::extract_u(a);
  EXPECT_EQ(1,result[0]);
  EXPECT_EQ(3,result[1]);
  EXPECT_EQ(5,result[2]);
  EXPECT_EQ(7,result[3]);
}

TEST(SparseStuff,extract_csr_u) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double,Eigen::RowMajor> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  std::vector<int> result = stan::math::extract_u(a);
  EXPECT_EQ(1,result[0]);
  EXPECT_EQ(4,result[1]);
  EXPECT_EQ(7,result[2]);
}


TEST(SparseStuff,extract_csc_z) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  std::vector<int> result = stan::math::extract_z(a);
  EXPECT_EQ(2,result[0]);
  EXPECT_EQ(2,result[1]);
  EXPECT_EQ(2,result[2]);
}

TEST(SparseStuff,extract_csr_z) {
  stan::math::matrix_d m(2,3);
	Eigen::SparseMatrix<double,Eigen::RowMajor> a;
  m << 2.0, 4.0, 6.0, 8.0, 10.0, 12.0;
	a = m.sparseView();
  std::vector<int> result = stan::math::extract_z(a);
  EXPECT_EQ(3,result[0]);
  EXPECT_EQ(3,result[1]);
}


//
//TEST(MathMatrix,multiply_c_rv) {
//  stan::math::row_vector_d rv(3);
//  rv << 1, 2, 3;
//  stan::math::row_vector_d result = stan::math::multiply(2.0,rv);
//  EXPECT_FLOAT_EQ(2.0,result(0));
//  EXPECT_FLOAT_EQ(4.0,result(1));
//  EXPECT_FLOAT_EQ(6.0,result(2));
//}
//TEST(MathMatrix,multiply_c_m) {
//  stan::math::matrix_d m(2,3);
//  m << 1, 2, 3, 4, 5, 6;
//  stan::math::matrix_d result = stan::math::multiply(2.0,m);
//  EXPECT_FLOAT_EQ(2.0,result(0,0));
//  EXPECT_FLOAT_EQ(4.0,result(0,1));
//  EXPECT_FLOAT_EQ(6.0,result(0,2));
//  EXPECT_FLOAT_EQ(8.0,result(1,0));
//  EXPECT_FLOAT_EQ(10.0,result(1,1));
//  EXPECT_FLOAT_EQ(12.0,result(1,2));
//}
//
//TEST(MathMatrix,multiply_rv_v_exception) {
//  stan::math::row_vector_d rv;
//  stan::math::vector_d v;
//  
//  rv.resize(3);
//  v.resize(3);
//  EXPECT_NO_THROW(stan::math::multiply(rv, v));
//
//  rv.resize(0);
//  v.resize(0);
//  EXPECT_NO_THROW(stan::math::multiply(rv, v));
//
//  rv.resize(2);
//  v.resize(3);
//  EXPECT_THROW(stan::math::multiply(rv, v), std::invalid_argument);
//}
//TEST(MathMatrix,multiply_m_v_exception) {
//  stan::math::matrix_d m;
//  stan::math::vector_d v;
//  
//  m.resize(3, 5);
//  v.resize(5);
//  EXPECT_NO_THROW(stan::math::multiply(m, v));
//
//  m.resize(3, 0);
//  v.resize(0);
//  EXPECT_THROW(stan::math::multiply(m, v),
//               std::invalid_argument);
//
//  m.resize(2, 3);
//  v.resize(2);
//  EXPECT_THROW(stan::math::multiply(m, v), std::invalid_argument);  
//}
//TEST(MathMatrix,multiply_rv_m_exception) {
//  stan::math::row_vector_d rv;
//  stan::math::matrix_d m;
//    
//  rv.resize(3);
//  m.resize(3, 5);
//  EXPECT_NO_THROW(stan::math::multiply(rv, m));
//
//  rv.resize(0);
//  m.resize(0, 3);
//  EXPECT_THROW(stan::math::multiply(rv, m),
//               std::invalid_argument);
//
//  rv.resize(3);
//  m.resize(2, 3);
//  EXPECT_THROW(stan::math::multiply(rv, m), std::invalid_argument);
//}
//TEST(MathMatrix,multiply_m_m_exception) {
//  stan::math::matrix_d m1, m2;
//  
//  m1.resize(1, 3);
//  m2.resize(3, 5);
//  EXPECT_NO_THROW(stan::math::multiply(m1, m2));
//
//  
//  m1.resize(2, 0);
//  m2.resize(0, 3);
//  EXPECT_THROW(stan::math::multiply(m1, m2),
//               std::invalid_argument);
//
//  m1.resize(4, 3);
//  m2.resize(2, 3);
//  EXPECT_THROW(stan::math::multiply(m1, m2), std::invalid_argument);
//}
//
//TEST(MathMatrix, multiply) {
//  stan::math::vector_d v0;
//  stan::math::row_vector_d rv0;
//  stan::math::matrix_d m0;
//
//  using stan::math::multiply;
//  EXPECT_NO_THROW(multiply(v0,2.0));
//  EXPECT_NO_THROW(multiply(rv0,2.0));
//  EXPECT_NO_THROW(multiply(m0,2.0));
//  EXPECT_NO_THROW(multiply(2.0,v0));
//  EXPECT_NO_THROW(multiply(2.0,rv0));
//  EXPECT_NO_THROW(multiply(2.0,m0));
//}
//
//
//TEST(AgradRevMatrix,multiply_int) {
//  using stan::math::multiply;
//  using stan::math::assign;
//
//  typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
//  
//  int d_int = 2;
//  vector_d vec(4);
//  vec << 1, 2, 3, 4;
//  vector_d t_vec(4);
//  assign(t_vec, multiply(vec,d_int));
//
//}
//
//TEST(AgradRevMatrix,multiply_vector_int) {
//  using stan::math::multiply;
//  using stan::math::vector_d;
//
//  vector_d dvec(3);
//  dvec << 1, 2, 3;
//  int a = 2;
//  vector_d prod_vec = multiply(dvec,a);
//  EXPECT_EQ(3,prod_vec.size());
//  EXPECT_EQ(2.0, prod_vec[0]);
//  EXPECT_EQ(4.0, prod_vec[1]);
//  EXPECT_EQ(6.0, prod_vec[2]);
//}