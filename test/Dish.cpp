# include "pch.h"
# include "Dish.h"

IMPLEMENT_SERIAL(Dish, CObject, 1);
IMPLEMENT_SERIAL(Hamburger, CObject, 1);
IMPLEMENT_SERIAL(LambChops, CObject, 1);
IMPLEMENT_SERIAL(AngusSteak, CObject, 1);
IMPLEMENT_SERIAL(Fries, CObject, 1);
IMPLEMENT_SERIAL(AppetizerCarnivore, CObject, 1);
IMPLEMENT_SERIAL(CarnivoreCelebration, CObject, 1);
IMPLEMENT_SERIAL(Falafel, CObject, 1);
IMPLEMENT_SERIAL(Kebab, CObject, 1);
IMPLEMENT_SERIAL(EggplantSalad, CObject, 1);
IMPLEMENT_SERIAL(Drinks, CObject, 1);
IMPLEMENT_SERIAL(Water, CObject, 1);
IMPLEMENT_SERIAL(SoftDrinks, CObject, 1);
IMPLEMENT_SERIAL(Wine, CObject, 1);

//Dish class
Dish::Dish(const char* name, const double price) : name("dish"), price(200)
{}

double Dish::getPrice()
{
	return price;
}

const char* Dish::getName()
{
	return name;
}

double Dish::getDiscountPrice()
{
	return discountPrice;
}

void Dish::setPrice(double n)
{
	this->price = n;
}

//Appetizer Carnivore class

AppetizerCarnivore::AppetizerCarnivore(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* AppetizerCarnivore::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s, price: %.2lf NIS", this->getName(), this->getPrice());
	return str;
}

///////////////////////////////////////////Drinks////////////////////////////////////////////
Drinks::Drinks(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* Drinks::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s price: %.2lf NIS", this->getName(), this->getPrice());
	return str;
}

//////////////////////////////////SoftDrinks///////////////////////////////////////////
SoftDrinks::SoftDrinks(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* SoftDrinks::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s %s                         price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}

////////////////////////////////Water///////////////////////////////////////////////////
Water::Water(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* Water::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s %s                                price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}
////////////////////////////////////Wine/////////////////////////////////////////////////////
Wine::Wine(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* Wine::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s %s                                 price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}

//Falafel class

Falafel::Falafel(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* Falafel::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s %s                               price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}
///////////////////////////////////////////////////////////////////////
EggplantSalad::EggplantSalad(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* EggplantSalad::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s %s                    price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}

/////////////////////////////////////////////////////////
Kebab::Kebab(const char* size, const char* name, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->size = (char*)size;
}

char* Kebab::getRecietData()
{
	char *str = new char[80];
	snprintf(str, 80, "%s - %s                  price: %.2lf NIS", this->name, this->size, this->price);
	return str;
}


/////////////////////////////////////////////////////////

// Fries class

Fries::Fries(const char*size, const char* name, double price)
{
	this->name = (char*)name;
	this->size = (char*)size;
	this->price = price;
}

char* Fries::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s%s                   price: %.2lf NIS", this->size, this->name, this->price);
	return str;
}

//Carnivore Celebration CLASS
CarnivoreCelebration::CarnivoreCelebration(double price, int gram, const char* name)
{
	this->name = (char*)name;
	this->price = price;
	this->gram = gram;
}

char* CarnivoreCelebration::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s - price %.2lf NIS", this->name, this->price);
	return str;
}

void CarnivoreCelebration::setGram(int n)
{
	this->gram = n;
}

int CarnivoreCelebration::getGram()
{
	return gram;
}


//HAMBURGER CLASS
Hamburger::Hamburger(int gram,double price ,const char* name)
{
	this->name = (char*)name;
	this->gram = gram;
	this->price = price;
}


char* Hamburger::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s - %d gram   price: %.2lf NIS", this->name, this->gram, this->price);
	return str;
}


// CLASS LambChopsCount
LambChops::LambChops(const char* name, int gram, double price)
{
	this->name = (char*)name;
	this->price = price;
	this->gram = gram;
}

char* LambChops::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s - %d gram        price: %.2lf NIS", this->name, this->gram, this->price);
	return str;
}

//CLASS Angus Steak
AngusSteak::AngusSteak(const char* name, int gram, double price)
{
	this->name = (char*)name;
	this->gram = gram;
	this->price = price;
}

char* AngusSteak::getRecietData()
{
	char* str = new char[80];
	snprintf(str, 80, "%s - %d gram        price: %.2lf NIS", this->name, this->gram, this->price);
	return str;
}