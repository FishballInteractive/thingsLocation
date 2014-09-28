//
//  ILogable.h
//  
//
//  Created by Kirill_Mag on 09.06.13.
//
//

#ifndef __ILOGABLE_H_
#define __ILOGABLE_H_

class ILogable
{
public:
    virtual ~ILogable(){}
    
    virtual void log() = 0;
};

#endif
