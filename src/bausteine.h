/*
 * baustein.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef BAUSTEINE_H_
#define BAUSTEINE_H_

#include <iostream>
#include <string>
#include <vector>
#include "schnittstelle.h"

class Bausteine
{
protected:
	std::string name;
	std::vector<Schnittstelle*> eingang;
	std::vector<Schnittstelle*> ausgang;

public:
	void addEingang(Schnittstelle* schnittstelle)
	{
		if(schnittstelle == NULL)
		{
			return;
		}

		eingang.push_back(schnittstelle);
	}

	void addAusgang(Schnittstelle* schnittstelle)
	{
		if(schnittstelle == NULL)
		{
			return;
		}

		ausgang.push_back(schnittstelle);
	}

	virtual void print()
	{
		std::cout <<"Baustein: " << name << std::endl;

		for(int i = 0; i < eingang.size(); i++)
		{
			std::cout << "Eingang " << i << ": " << "Pegel = " << eingang.at(i)->getPegel() << std::endl;
		}

		for(int i = 0; i < ausgang.size(); i++)
		{
			std::cout << "Ausgang " << i << ": " << "Pegel = " << ausgang.at(i)->getPegel() << std::endl;
		}
	}

	virtual void update() = 0;

	friend void test2(Bausteine* b);
	friend void test3(Bausteine* b);

//	virtual ~Bausteine();
};



#endif /* BAUSTEINE_H_ */
