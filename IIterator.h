/*
 * IIterator.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef IIterator_H_
#define IIterator_H_

#include "ICollectible.h"

class IIterator {
	public:
		virtual ICollectible* getCurrent()=0;
		virtual bool hasCurrent()=0;
		virtual void next()=0;
		virtual ~IIterator();
};

#endif