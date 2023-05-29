/*
 * xor2.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef XOR2_H_
#define XOR2_H_

#include "bausteine.h"

class Xor2: public Bausteine
{
public:
	Xor2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
	{
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		name = "Xor2";
	}

	void update()
	{
		short eingang1 = eingang.at(0)->getPegel();
		short eingang2 = eingang.at(1)->getPegel();

		if((eingang1 == Schnittstelle::UNDEFINED) || (eingang2 == Schnittstelle::UNDEFINED))
		{
			ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
		}
		else if((eingang1 == Schnittstelle::HIGH) && (eingang2 == Schnittstelle::LOW))
		{
			ausgang.at(0)->setPegel(Schnittstelle::HIGH);
		}
		else if((eingang1 == Schnittstelle::LOW) && (eingang2 == Schnittstelle::HIGH))
		{
			ausgang.at(0)->setPegel(Schnittstelle::HIGH);
		}
		else{
			ausgang.at(0)->setPegel(Schnittstelle::LOW);
		}
	}
};

#endif /* XOR2_H_ */
