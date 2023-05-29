/*
 * schaltung.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef SCHALTUNG_H_
#define SCHALTUNG_H_

#include "bausteine.h"

class Schaltung : public Bausteine
{
protected:
	std::vector<Schnittstelle*> intern;
	std::vector<Bausteine*> bausteine;
};

#endif /* SCHALTUNG_H_ */
