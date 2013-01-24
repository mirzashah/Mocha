/*****************************************************************************/
// Filename: FontCache.h
/*****************************************************************************/
// Description: To improve performance of font generation, this class caches
// fonts as they are created by the user. When a CFont object is created,
// it asks the cache to give it the low-level FTGL font. If the cache does not
// have it, it creates it, adds it to the cache, and passes the user back
// the newly created font. If it does have it, it just simply passes it back.
/*****************************************************************************/

#ifndef MOCHA_FONT_CACHE_H_DEFINED
#define MOCHA_FONT_CACHE_H_DEFINED

#include <MochaObject.h>

class FTTextureFont;

namespace Mocha
{

typedef map<string, FTTextureFont*> CachedFontMap;

class CFontCache : public CMochaObject
{
    friend class CFont;

    public:
        virtual ~CFontCache();

    private:
        CFontCache();
        CachedFontMap&     CachedFonts();
        FTTextureFont*     CreateFTGLFont(string fontName, unsigned int fontSize);
        FTTextureFont*     GetFont(string fontName, unsigned int fontSize);
        static CFontCache& Instance();

    private:
        CachedFontMap      _cachedFonts;
        static CFontCache* _instance;

};

};


#endif
