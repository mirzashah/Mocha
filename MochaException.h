/*****************************************************************************/
// Filename: MochaException.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_EXCEPTION_H_DEFINED
#define MOCHA_EXCEPTION_H_DEFINED

#include <MochaObject.h>
#include <string>

namespace Mocha
{

class CMochaException : public CMochaObject
{
    public:
        CMochaException();
        virtual ~CMochaException();
};

};


#endif
