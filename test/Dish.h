#pragma once

#include "pch.h"

//class Dish
class Dish : public CObject

{
public:

	DECLARE_SERIAL(Dish);

	Dish(const char* = "dish", const double = 200);

	~Dish() {};
	double getPrice();
	void setPrice(double);
	const char* getName();
	double getDiscountPrice();
	virtual void setDiscountPrice() {}
	virtual char* getRecietData() { return new char(); }
	void Serialize(CArchive& ar)
	{
		CObject::Serialize(ar);
		if (ar.IsStoring())
		{
			ar << price;
			ar << discountPrice;
			sizeName = strlen(name);
			ar << sizeName;

			for (int i = 0; i < sizeName; i++) {
				ar << name[i];
			}
		}
		else // Loading
		{
			ar >> price;
			ar >> discountPrice;
			ar >> sizeName;
			name = new char[sizeName + 1];
			for (int i = 0; i < sizeName; i++) { ar >> name[i]; }
			name[sizeName] = '\0';
		}
	}

protected:
	double price;
	double discountPrice;
	char* name;
	int sizeName = 0;
};


//CLASS Appetizer Carnivore
class AppetizerCarnivore : public Dish
{
public:

	DECLARE_SERIAL(AppetizerCarnivore)

	void Serialize(CArchive& ar)
	{
		Dish::Serialize(ar);
		if (ar.IsStoring()) { // true is save
			sizeS = strlen(size);
			ar << sizeS;
			for (int i = 0; i < sizeS; i++) {
				ar << size[i];
			}
		}
		else { //loaded
			ar >> sizeS;
			size = new char[sizeS + 1];
			for (int i = 0; i < sizeS; i++) { 
				ar >> size[i]; 
			}
			size[sizeS] = '\0';
		}
	}

	AppetizerCarnivore(const char* = " ", const char* = "", double = 40);
	~AppetizerCarnivore() {}
	char* getRecietData();
protected:
	 char* size;
	 int sizeS = 0;
};

////////////////////////////////////Drinks///////////////////////////////////////
class Drinks : public Dish
{
public:

	DECLARE_SERIAL(Drinks)
	void Serialize(CArchive& ar)
	{
		Dish::Serialize(ar);
		if (ar.IsStoring()) { // true is save
			sizeS = strlen(size);
			ar << sizeS;
			for (int i = 0; i < sizeS; i++) {
				ar << size[i];
			}
		}
		else // loaded
		{
			ar >> sizeS;
			size = new char[sizeS + 1];
			for (int i = 0; i < sizeS; i++) {
				ar >> size[i]; 
			}
			size[sizeS] = '\0';
		}
	}

	Drinks(const char* = " ", const char* = " ", double = 10);
	~Drinks() {}
	char* getRecietData();
protected:
	char* size;
	int sizeS = 0;
};

/////////////////////////////////////////////////////////////////////////////////
class SoftDrinks : public Drinks
{
public:

	DECLARE_SERIAL(SoftDrinks)

	SoftDrinks(const char* = " ", const char* = "Soft Drinks", double = 10);
	~SoftDrinks() {}
	char* getRecietData();
};

//////////////////////////////////Water//////////////////////////////////////////
class Water : public Drinks
{
public:

	DECLARE_SERIAL(Water)

	Water(const char* = " ", const char* = "Water", double = 7);
	~Water() {}
	char* getRecietData();
};

////////////////////////////////////Wine////////////////////////////////////////
class Wine : public Drinks
{
public:

	DECLARE_SERIAL(Wine)

	Wine(const char* = " ", const char* = "Wine", double = 20);
	~Wine() {}
	char* getRecietData();
};
////////////////////////////////////////////////////////////////////////////////
//CLASS Falafel
class Falafel : public AppetizerCarnivore
{
public:

	DECLARE_SERIAL(Falafel)

	Falafel(const char* = " ", const char* = "Falafel", double = 7);
	~Falafel() {}
	char* getRecietData();
};
/////////////////////////////////////////////
class EggplantSalad : public AppetizerCarnivore
{
public:

	DECLARE_SERIAL(EggplantSalad)

	EggplantSalad(const char* = " ", const char* = "Eggplant salad", double = 15);
	~EggplantSalad() {}
	char* getRecietData();
};

//////////////////////////////////////////////
class Kebab : public AppetizerCarnivore
{
public:

	DECLARE_SERIAL(Kebab)
	Kebab(const char* = "200gram", const char* = "kebab", double = 60);
	~Kebab() {}
	//void setDiscountPrice();
	char* getRecietData();
};

/////////////////////////////////////////////

//CLASS FRIES
class Fries : public AppetizerCarnivore
{
public:

	DECLARE_SERIAL(Fries)

	Fries(const char* = "", const char* = "Fries and Salad  ", double = 12);
	~Fries() {}
	char* getRecietData();
};

//CLASS Carnivore Celebration
class CarnivoreCelebration : public Dish
{
public:

	DECLARE_SERIAL(CarnivoreCelebration)
	void Serialize(CArchive& ar)
	{
		Dish::Serialize(ar);
		if (ar.IsStoring()) {
			ar << gram;
		}
		else {
			ar >> gram;
		}
	}

	CarnivoreCelebration(double = 250, int = 220, const char* = "");
	~CarnivoreCelebration() {}
	char* getRecietData();
	int getGram();
	void setGram(int);
protected:
	int gram;
};

//CLASS Butchers Burger
class Hamburger : public CarnivoreCelebration
{
	DECLARE_SERIAL(Hamburger)

public:
	Hamburger(int = 220, double = 80, const char* = "Butchers Burger");
	~Hamburger() {}
	char* getRecietData();
};

//CALSS	Lamb Chops
class LambChops : public CarnivoreCelebration
{
public:

	DECLARE_SERIAL(LambChops)
	LambChops(const char* = "Lamb Chops", int = 220, double = 100);
	~LambChops() {}
	char* getRecietData();
};

//CLASS Angus Steak
class AngusSteak :public CarnivoreCelebration
{

	DECLARE_SERIAL(AngusSteak)

public:
	AngusSteak(const char* = "Angus Steak", int = 220, double = 110);
	~AngusSteak() {}
	char* getRecietData();
};