#pragma
#include"List.h"
class Poly
{
public:
	Poly();
	Poly(const Poly&);
	Poly(List&);
	~Poly();
	void read();
	void show();
	Poly& operator=(const Poly&);
	Poly plus(Poly&);
	Poly mult(Poly&);
private:
	List list;

};

