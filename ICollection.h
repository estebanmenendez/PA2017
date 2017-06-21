/*
 * Collection.h
 *
 *  Created on: 8 de jun. de 2016
 *      Author: apias
 */

#ifndef ICOLLECTION_H_
#define ICOLLECTION_H_

#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include <string>

#include "IIterator.h"
#include "ICollectible.h"

class ICollection {
public:
    virtual void add(ICollectible* elem)=0;
    virtual bool member(ICollectible* elem)=0;
    virtual bool remove(ICollectible* elem)=0;
    virtual unsigned int size()=0;
    virtual IIterator* getIterator()=0;
    virtual ICollectible* first()=0;
    virtual ICollectible* last()=0;
    virtual ~ICollection();
};

#endif

#endif /* ICOLLECTION_H_ */
