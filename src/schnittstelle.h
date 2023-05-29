/*
 * schnitstelle.h
 *
 *  Created on: 14.04.2023
 *      Author: bklaric01
 */

#ifndef SCHNITTSTELLE_H_
#define SCHNITTSTELLE_H_

class Schnittstelle
{
private:
	short pegel;

public:
	const static short HIGH = 1;
	const static short LOW = 0;
	const static short UNDEFINED = -1;

	Schnittstelle()
	{
		pegel = LOW;
	}

	short getPegel()
	{
		return pegel;
	}

	bool setPegel(short pegel)
	{
		if((pegel != HIGH) && (pegel != LOW))
		{
			this->pegel = UNDEFINED;
			return false;
		}
		else{
			this->pegel = pegel;
			return true;
		}
	}

};

#endif /* SCHNITTSTELLE_H_ */
