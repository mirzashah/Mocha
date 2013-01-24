#include <Font.h>
#include <FontCache.h>
#include <MochaException.h>
#include <iostream>

namespace Mocha
{
/**********************************************/
CFont::CFont(string fontName, unsigned int fontSize) :
_fontName(fontName),
_fontSize(fontSize),
_lowLevelFont(NULL)
/**********************************************/
{
    LowLevelFont(FontCache().GetFont(fontName, fontSize));
    if(LowLevelFont()==NULL)
        throw(CMochaException());
}

/**********************************************/
CFont::~CFont()
/**********************************************/
{
}

/**********************************************/
void CFont::DrawMe(string text, const CCartesianPoint& position)
/**********************************************/
{
    DrawMe(text, ToDevice(position));
}

/**********************************************/
void CFont::DrawMe(string text, const CGeographicalPoint& position)
/**********************************************/
{
    DrawMe(text, ToDevice(position));
}

/**********************************************/
void CFont::DrawMe(string text, const CDevicePoint& position)
/**********************************************/
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WindowWidth(), 0, WindowHeight());
    LowLevelFont()->Render(text.c_str(), -1, FTPoint(position.X(), position.Y()), FTPoint(), FTGL::RENDER_ALL);
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
}

/**********************************************/
void CFont::DrawMe(string text, const CDevicePoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment, float lineSpacing)
/**********************************************/
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WindowWidth(), 0, WindowHeight());

    FTSimpleLayout layout;
    layout.SetFont(LowLevelFont());
    layout.SetLineLength(lineLengthInPixels);
    layout.SetLineSpacing(lineSpacing);
    layout.SetAlignment((FTGL::TextAlignment)(alignment));

    glMatrixMode(GL_MODELVIEW); //Note:: The position argument for the Render call layout doesn't seem to work, had to use a modelview transform to get it to work..
    glPushMatrix();
    glTranslated(position.X(), position.Y(),0);
    layout.Render(text.c_str(), -1, FTPoint(), 0);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

}

/**********************************************/
void CFont::DrawMe(string text, const CCartesianPoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment, float lineSpacing)
/**********************************************/
{
    DrawMe(text, ToDevice(position), lineLengthInPixels, alignment, lineSpacing);
}

/**********************************************/
void CFont::DrawMe(string text, const CGeographicalPoint& position, float lineLengthInPixels, Mocha::TextAlignment alignment, float lineSpacing)
/**********************************************/
{
    DrawMe(text, ToDevice(position), lineLengthInPixels, alignment, lineSpacing);
}

/**********************************************/
CFontCache& CFont::FontCache()
/**********************************************/
{
    return(CFontCache::Instance());
}

/**********************************************/
string CFont::FontName() const
/**********************************************/
{
    return(_fontName);
}

/**********************************************/
unsigned int CFont::FontSize() const
/**********************************************/
{
    return(_fontSize);
}

/**********************************************/
FTTextureFont* CFont::LowLevelFont() const
/**********************************************/
{
    return(_lowLevelFont);
}

/**********************************************/
void CFont::LowLevelFont(FTTextureFont* font)
/**********************************************/
{
    _lowLevelFont = font;
}

};
