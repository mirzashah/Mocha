/*****************************************************************************/
// Filename: Color.h
/*****************************************************************************/
// Description:
/*****************************************************************************/

#ifndef MOCHA_COLOR_H_DEFINED
#define MOCHA_COLOR_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

class CColor : public CMochaObject
{
    public:
        CColor(unsigned char r = 0, unsigned char g = 0, unsigned char b = 0, unsigned char a = 255);
        virtual ~CColor();

        unsigned char Red() const;
        void Red(unsigned char r);
        unsigned char Green() const;
        void Green(unsigned char g);
        unsigned char Blue() const;
        void Blue(unsigned char b);
        unsigned char Alpha() const;
        void Alpha(unsigned char a);

        void SetAsCurrentColor();

    private:
        unsigned char _red;
        unsigned char _green;
        unsigned char _blue;
        unsigned char _alpha;
};

};


#endif
