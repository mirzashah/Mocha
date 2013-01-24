#include <Color.h>

namespace Mocha
{

/*********************************************/
CColor::CColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) :
_red(r),
_green(g),
_blue(b),
_alpha(a)
/*********************************************/
{
}

/*********************************************/
CColor::~CColor()
/*********************************************/
{
}

/*********************************************/
unsigned char CColor::Red() const
/*********************************************/
{
    return(_red);
}

/*********************************************/
void CColor::Red(unsigned char r)
/*********************************************/
{
    _red = r;
}

/*********************************************/
unsigned char CColor::Green() const
/*********************************************/
{
    return(_green);
}

/*********************************************/
void CColor::Green(unsigned char g)
/*********************************************/
{
    _green = g;
}

/*********************************************/
unsigned char CColor::Blue() const
/*********************************************/
{
    return(_blue);
}

/*********************************************/
void CColor::Blue(unsigned char b)
/*********************************************/
{
    _blue = b;
}

/*********************************************/
unsigned char CColor::Alpha() const
/*********************************************/
{
    return(_alpha);
}

/*********************************************/
void CColor::Alpha(unsigned char a)
/*********************************************/
{
    _alpha = a;
}

/*********************************************/
void CColor::SetAsCurrentColor()
/*********************************************/
{
    glColor4ub(Red(), Green(), Blue(), Alpha());
}

};
