/*
 * und2.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef UND2_H_
#define UND2_H_

#include "bausteine.h"

class Und2: public Bausteine
{
public:
	Und2(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0)
	{
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		name = "Und2";
	}

	void update()
	{
		short eingang1 = eingang.at(0)->getPegel();
		short eingang2 = eingang.at(1)->getPegel();

		if((eingang1 == Schnittstelle::UNDEFINED) || (eingang2 == Schnittstelle::UNDEFINED))
		{
			ausgang.at(0)->setPegel(Schnittstelle::UNDEFINED);
		}
		else if((eingang1 == Schnittstelle::HIGH) && (eingang2 == Schnittstelle::HIGH))
		{
			ausgang.at(0)->setPegel(Schnittstelle::HIGH);
		}
		else{
			ausgang.at(0)->setPegel(Schnittstelle::LOW);
		}
	}
};

#endif /* UND2_H_ */
