#include<iostream>
#include<algorithm>
using namespace std;
class Fraction {
	int num;
	int den;
public:
	Fraction() {
		num = 0;
		den = 1;
	}
	Fraction(int a, int b) {
		num = a;
		den = b;
	}
	Fraction operator+(const Fraction& f)const {
		Fraction retf;
		retf.num = num *f.den+ f.num*den;
		retf.den = den * f.den;
		retf.R();
		return retf;
	}
	Fraction operator-(const Fraction& f)const {
		Fraction retf;
		retf.num = num * f.den - f.num*den;
		retf.den = den * f.den;
		retf.R();
		return retf;
	}
	Fraction operator*(const Fraction& f)const {
		Fraction retf;
		retf.num = num * f.num;
		retf.den = den * f.den;
		retf.R();
		return retf;
	}
	Fraction operator/( Fraction& f) const{
		Fraction retf,tmpf;
		tmpf = f.I();
		retf=*this*(tmpf);
		retf.R();
		return retf;
	}
	ostream& display(ostream& out) {
		if (den == 1) {
			out << num;
		}
		else {
			out << num << "/" << den;
		}
		return out;
	}
	istream& read(istream& in) {
		char tmp;
		in >> num;
		if (in.peek() == '/') {
			in >> tmp;
			in >> den;
		}
		else {
			den = 1;
		}
		return in;
	}
	int G() {
		if (num*den == 0) {
			return 1;
		}
		return gcd(max(den, num),min(den,num));
	}
	int gcd(int a, int b) {
			return a%b == 0 ? b : gcd(b, a%b);
	}
	Fraction& R() {
		int g = G();
		num /= g;
		den /= g;
		return *this;
	}
	Fraction& I() {
		swap(num, den);
		return *this;
	}
	void M() {
		if (num / den != 0) {
			cout << num / den;
			if (num%den != 0) {
				cout << "+" << num % den << "/" << den;
			}
			cout << endl;
		}
		else {
			cout << "input error" << endl;
		}
	}
	int L(const Fraction& f) {
		int ret = den * f.den / gcd(max(den, f.den), min(den, f.den));
		return ret;
	}
	bool operator < (const Fraction& f)const {
		return (num*1.0 / den) < (f.num*1.0 / f.den);
	}
	bool operator > (const Fraction& f)const {
		return (num*1.0 / den) > (f.num*1.0 / f.den);
	}
	bool operator ==(Fraction& f) {
		return (num / G() == f.num / f.G()) && (den / G() == f.den / f.G());
	}
	bool operator <=(Fraction& f) {
		return *this < f || *this == f;
	}
	bool operator >=(Fraction& f) {
		return *this > f || *this == f;
	}
	Fraction X(const Fraction& f1, const Fraction& f2) {
		Fraction retf;
		retf = retf + f2;
		retf = retf - f1;
		retf = retf / *this;
		retf.R();
		return retf;
	}
		
};
ostream& operator<<(ostream& out,Fraction& f) {
		f.display(out);
		return out;
}
istream& operator>>(istream& in,Fraction& f) {
		f.read(in);
		return in;
}

