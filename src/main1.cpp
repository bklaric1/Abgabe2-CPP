//============================================================================
// Name        : main1.cpp
// Author      : Benjamin Klaric
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "halbaddierer.h"
#include "volladdierer.h"

void test2(Bausteine* b)
{
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				b->eingang.at(0)->setPegel(i);
				b->eingang.at(1)->setPegel(j);

				b->update();
				b->print();
				std::cout<<std::endl;
			}
		}

		std::cout<<"------------------------"<<std::endl<<std::endl;
}

void test3(Bausteine* b)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			for(int k = 0; k < 2; k++)
			{
				b->eingang.at(0)->setPegel(i);
				b->eingang.at(1)->setPegel(j);
				b->eingang.at(2)->setPegel(k);

				b->update();
				b->print();

				std::cout<<std::endl;
			}
		}
	}

	std::cout<<std::endl<<std::endl;
}

int main() {
	char c;

	Schnittstelle* e0 = new Schnittstelle;
	Schnittstelle* e1 = new Schnittstelle;
	Schnittstelle* e2 = new Schnittstelle;
	Schnittstelle* a0 = new Schnittstelle;
	Schnittstelle* a1 = new Schnittstelle;

	Und2* undProbe = new Und2(e0, e1, a0);
//	test2(undProbe);

	Oder2* oderProbe = new Oder2(e0,e1, a0);
//	test2(oderProbe);

	Xor2* xorProbe = new Xor2(e0, e1, a0);
//	test2(xorProbe);

	Halbaddierer* haProbe = new Halbaddierer(e0, e1, a0, a1);
//	test2(haProbe);

	Volladdierer* vaProbe = new Volladdierer(e0, e1, e2, a0, a1);
//	test3(vaProbe);

	std::cin >> c;
	return 0;
}
