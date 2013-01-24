/*****************************************************************************/
// Filename: Font.h
/*****************************************************************************/
// Description: This class represents a text font. Users can create a a CFont
// object by passing the constructor a TrueType font path/name, as well
// as the font size. The object will then create a texture-based font
// using the FTGL open source library (which in turn uses the Freetype2)
// open source library.
/*****************************************************************************/

#ifndef MOCHA_FONT_H_DEFINED
#define MOCHA_FONT_H_DEFINED

#include <Drawable.h>
#include <FTGL/ftgl.h>

class FTTextureFont;

namespace Mocha
{
class CFontCache;

enum TextAlignment
{
    TA_ALIGN_LEFT    = FTGL::ALIGN_LEFT,
    TA_ALIGN_CENTER  = FTGL::ALIGN_CENTER,
    TA_ALIGN_RIGHT   = FTGL::ALIGN_RIGHT,
    TA_ALIGN_JUSTIFY = FTGL::ALIGN_JUSTIFY
};

class CFont : public CDrawable
{
    public:
        CFont(string fontName = "arial.ttf", unsigned int fontSize = 12);
        virtual ~CFont();

        void           DrawMe(string text, const CDevicePoint& position);
        void           DrawMe(string text, const CCartesianPoint& position);
        void           DrawMe(string text, const CGeographicalPoint& position);
        void           DrawMe(string text, const CDevicePoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment = TA_ALIGN_LEFT, float lineSpacing = 1);
        void           DrawMe(string text, const CCartesianPoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment = TA_ALIGN_LEFT, float lineSpacing = 1);
        void           DrawMe(string text, const CGeographicalPoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment = TA_ALIGN_LEFT, float lineSpacing = 1);

        string         FontName() const;
        unsigned int   FontSize() const;

    private:
        CFontCache&    FontCache();
        FTTextureFont* LowLevelFont() const;
        void           LowLevelFont(FTTextureFont* font);



    private:
        string         _fontName;
        unsigned int   _fontSize;
        FTTextureFont* _lowLevelFont;
};

};


#endif
