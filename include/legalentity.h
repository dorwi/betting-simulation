#ifndef GUARD__legalentity_h
#define GUARD__legalentity_h


class Legal_entity{
public:
	Legal_entity(): b(0) {}
	Legal_entity(double d): b(d) {}
	void pay(double);
	void recieve(double);
	double balance() const {return b;}
private:
	double b;
};

#endif