/*
 * volladdierer.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef VOLLADDIERER_H_
#define VOLLADDIERER_H_

#include "schaltung.h"
#include "oder2.h"

class Volladdierer : public Schaltung
{
public:
	Volladdierer(Schnittstelle* e0, Schnittstelle* e1, Schnittstelle* e2, Schnittstelle* a0, Schnittstelle* a1)
	{
		addEingang(e0);
		addEingang(e1);
		addEingang(e2);
		addAusgang(a0);
		addAusgang(a1);

		Schnittstelle* i0 = new Schnittstelle;
		Schnittstelle* i1 = new Schnittstelle;
		Schnittstelle* i2 = new Schnittstelle;

		intern.push_back(i0);
		intern.push_back(i1);
		intern.push_back(i2);

		Halbaddierer* ha0 = new Halbaddierer(e0, e1, i1, i0);
		Halbaddierer* ha1 = new Halbaddierer(i1, e2, a0, i2);
		Oder2* oder2voll = new Oder2(i0, i2, a1);

		bausteine.push_back(ha0);
		bausteine.push_back(ha1);
		bausteine.push_back(oder2voll);

		name = "Volladdierer";
	}

	void update()
	{
		for(int i = 0; i < bausteine.size(); i++)
		{
			bausteine.at(i)->update();
		}

		/*
		 * oder: for(Bausteine* b : bausteine)
		 * 		 {
		 * 		   b->update();
		 * 		 }
		 */
	}
};

#endif /* VOLLADDIERER_H_ */
