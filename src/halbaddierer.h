/*
 * halbaddierer.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef HALBADDIERER_H_
#define HALBADDIERER_H_

#include "schaltung.h"
#include "und2.h"
#include "xor2.h"

class Halbaddierer : public Schaltung
{
public:
	Halbaddierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* a0, Schnittstelle* a1)
	{
		addEingang(e0);
		addEingang(e1);
		addAusgang(a0);
		addAusgang(a1);

		Xor2* xor2halb = new Xor2(e0, e1, a0);
		Und2* und2halb = new Und2(e0, e1, a1);

		bausteine.push_back(xor2halb);
		bausteine.push_back(und2halb);

		name = "Halbaddierer";
	}

	void update()
	{
		for(int i = 0; i < bausteine.size(); i++)
		{
			bausteine.at(i)->update();
		}
	}
};

#endif /* HALBADDIERER_H_ */
