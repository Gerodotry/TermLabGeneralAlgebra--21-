#ifndef LAB_BIGINTEGER_H
#define LAB_BIGINTEGER_H
#pragma once
#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <complex>
namespace BigInt
{
	using namespace std;
	typedef long long ll;
	const int maxn = 1e2 + 14, lg = 15;
	const int base = 1000000000;
	const int base_digits = 9;
	struct bigint {
		vector<int> a;
		int sign;
		
		int size();

		bigint operator ^(const bigint& v);
		string to_string();
		int sumof();
		/*</arpa>*/
		bigint();

		bigint(long long v);

		bigint(const string& s);

		void operator=(const bigint& v);

		void operator=(long long v);

		bigint operator+(const bigint& v) const;

		bigint operator-(const bigint& v) const;

		void operator*=(int v);

		bigint operator*(int v) const;

		void operator*=(long long v);

		bigint operator*(long long v) const;

		friend pair<bigint, bigint> divmod(const bigint& a1, const bigint& b1);

		bigint operator/(const bigint& v) const;

		bigint operator%(const bigint& v) const;

		void operator/=(int v);

		bigint operator/(int v) const;

		int operator%(int v) const;

		void operator+=(const bigint& v);
		void operator-=(const bigint& v);
		void operator*=(const bigint& v);
		void operator/=(const bigint& v);

		bool operator<(const bigint& v) const;
		bool operator>(const bigint& v) const;
		bool operator<=(const bigint& v) const;
		bool operator>=(const bigint& v) const;
		bool operator==(const bigint& v) const;
		bool operator!=(const bigint& v) const;

		void trim();

		bool isZero() const;

		bigint operator-() const;
		bigint abs() const;

		long long longValue() const;

		friend bigint gcd(const bigint& a, const bigint& b);
		friend bigint lcm(const bigint& a, const bigint& b);

		void read(const string& s);

		friend istream& operator>>(istream& stream, bigint& v);

		friend ostream& operator<<(ostream& stream, const bigint& v);

		static vector<int> convert_base(const vector<int>& a, int old_digits, int new_digits);

		typedef vector<long long> vll;

		static vll karatsubaMultiply(const vll& a, const vll& b);

		bigint operator*(const bigint& v) const;
	};
}
#endif //LAB_BIGINTEGER_H