#include <gtest.h>
#include "../lib_polynomial/polynomial.h"

TEST(TMonomial, can_create_monomial) {
	ASSERT_NO_THROW(CMonomial monomial);
}

TEST(TMonomial, can_add_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(2, degrees), monomial2(4, degrees), monomial4;
	CMonomial monomial3(6, degrees);
	monomial4 = monomial1 + monomial2;
	ASSERT_NO_THROW(monomial1 + monomial2);
	EXPECT_TRUE(monomial4 == monomial3);
}

TEST(TMonomial, can_subscract_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(2, degrees), monomial2(4, degrees), monomial4;
	CMonomial monomial3(-2, degrees);
	monomial4 = monomial1 - monomial2;
	ASSERT_NO_THROW(monomial1 - monomial2);
	EXPECT_TRUE(monomial4 == monomial3);
}

TEST(TMonomial, can_multiply_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(2, degrees), monomial2(4, degrees), monomial4;
	CMonomial monomial3(8, degrees);
	monomial4 = monomial1 * monomial2;
	ASSERT_NO_THROW(monomial1 * monomial2);
	EXPECT_TRUE(monomial4 == monomial3);
}

TEST(TMonomial, can_divide_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(4, degrees), monomial2(2, degrees), monomial4;
	CMonomial monomial3(2, degrees);
	monomial4 = monomial1 / monomial2;
	ASSERT_NO_THROW(monomial1 / monomial2);
	EXPECT_TRUE(monomial4 == monomial3);
}

TEST(TMonomial, can_find_derivative_monomials) {
	int degrees[3] = { 1, 0, 0 };
	int degrees2[3] = { 0, 0, 0 };
	CMonomial monomial1(4, degrees), monomial3(4, degrees2);
	CMonomial monomial2;
	monomial2 = monomial1.getDerivative(monomial1);
	ASSERT_NO_THROW(monomial1.getDerivative(monomial1));
	EXPECT_TRUE(monomial2 == monomial3);
}

TEST(TMonomial, can_compare_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(4, degrees), monomial3(4, degrees);
	EXPECT_TRUE(monomial1 == monomial3);
}

TEST(TMonomial, can_assign_monomials) {
	int degrees[3] = { 1, 0, 0 };
	CMonomial monomial1(4, degrees), monomial2(2, degrees), monomial3(2, degrees);
	monomial1 = monomial2;
	EXPECT_TRUE(monomial1 == monomial3);
}

TEST(TPolynomial, can_create_polynomial) {
	ASSERT_NO_THROW(CPolynomial poly);
}

TEST(TPolynomial, can_add_monomial_to_polynomial) {
	int degrees[3] = { 0, 1, 0 };
	CPolynomial poly1, poly2, poly3, poly4;
	CMonomial monomial1(4, degrees);
	poly1.Parse("2x");
	poly3.Parse("2x+4y");
	poly4 = poly1 + monomial1;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_substract_monomial_from_polynomial) {
	int degrees[3] = { 0, 1, 0 };
	CPolynomial poly1, poly2, poly3, poly4;
	CMonomial monomial1(4, degrees);
	poly1.Parse("2x");
	poly3.Parse("2x-4y");
	poly4 = poly1 - monomial1;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_multiply_monomial_to_polynomial) {
	int degrees[3] = { 0, 1, 0 };
	CPolynomial poly1, poly2, poly3, poly4;
	CMonomial monomial1(4, degrees);
	poly1.Parse("2x");
	poly3.Parse("8xy");
	poly4 = poly1 * monomial1;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_divide_polynomial_on_monomial) {
	int degrees[3] = { 1, 0, 0 };
	CPolynomial poly1, poly2, poly3, poly4;
	CMonomial monomial1(2, degrees);
	poly1.Parse("2x");
	poly3.Parse("x");
	poly4 = poly1 / monomial1;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_multiply_polynomial_on_scalar) {
	CPolynomial poly1, poly2, poly3, poly4;
	poly1.Parse("2x");
	poly3.Parse("4x");
	poly4 = poly1 * 2;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_add_polynomials) {
	CPolynomial poly1, poly2, poly3, poly4;
	poly1.Parse("2x");
	poly2.Parse("2y");
	poly3.Parse("2x+2y");
	poly4 = poly1 + poly2;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_subscract_polynomials) {
	CPolynomial poly1, poly2, poly3, poly4;
	poly1.Parse("2x");
	poly2.Parse("2y");
	poly3.Parse("2x-2y");
	poly4 = poly1 - poly2;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_multiply_polynomials) {
	CPolynomial poly1, poly2, poly3, poly4;
	poly1.Parse("2x");
	poly2.Parse("2y");
	poly3.Parse("4xy");
	poly4 = poly1 * poly2;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_divide_polynomials) {
	CPolynomial poly1, poly2, poly3, poly4;
	poly1.Parse("4x^2+2x");
	poly2.Parse("2x");
	poly3.Parse("2x+1");
	poly4 = poly1 / poly2;
	EXPECT_EQ(poly3, poly4);
}

TEST(TPolynomial, can_find_derivative_polynomials) {
	CPolynomial poly1, poly2, poly4;
	poly1.Parse("4x^2");
	poly2.Parse("8x");
	poly4 = poly1.getDerivative(poly1);
	EXPECT_EQ(poly2, poly4);
}

TEST(TPolynomial, can_compare_polynomials) {
	CPolynomial poly1, poly2;
	poly1.Parse("4x^2");
	poly2.Parse("4x^2");
	EXPECT_EQ(poly1, poly2);
}

TEST(TPolynomial, can_assign_polynomials) {
	CPolynomial poly2, poly4;
	poly2.Parse("8x");
	poly4 = poly2;
	EXPECT_EQ(poly2, poly4);
}

TEST(TPolynomial, can_find_result_of_polynomials) {
	CPolynomial poly1, poly2;
	std::string maths = "4x^2";
	poly1.Parse(maths);
	EXPECT_EQ(4, poly1.findResult(1, 0 , 0, maths));
}