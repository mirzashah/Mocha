#include <FontCache.h>
#include <Font.h>
#include <FTGL/ftgl.h>
#include <iostream>
#include <sstream>

namespace Mocha
{

/****************************************/
CFontCache* CFontCache::_instance = NULL;
/****************************************/

/****************************************/
CFontCache::CFontCache()
/****************************************/
{
}

/****************************************/
CFontCache::~CFontCache()
/****************************************/
{
}

/****************************************/
CachedFontMap& CFontCache::CachedFonts()
/****************************************/
{
    return(_cachedFonts);
}

/**********************************************/
FTTextureFont* CFontCache::CreateFTGLFont(string fontName, unsigned int fontSize)
/**********************************************/
{
    FTTextureFont* font = new FTTextureFont(fontName.c_str());

    if(font->Error()!=0) //Couldn't open
    {
        std::cerr<<"Mocha::CFont -> Couldn't open font "<<fontName<<std::endl;
        delete(font);
        return(NULL);
    }

    if(!font->FaceSize(fontSize)) //Couldn't set face size
    {
        std::cerr<<"Mocha::CFont -> Couldn't set font face."<<std::endl;
        delete(font);
        return(NULL);
    }

    return(font);
}

/****************************************/
FTTextureFont* CFontCache::GetFont(string fontName, unsigned int fontSize)
/****************************************/
{
    std::ostringstream fullname;
    fullname<<fontName<<"_"<<fontSize;
    FTTextureFont* font = CachedFonts()[fullname.str()];
    if(font!=NULL)
        return(font);
    else
    {
        font = CreateFTGLFont(fontName, fontSize);
        CachedFonts()[fullname.str()] = font;
        return(font);
    }
}

/****************************************/
CFontCache& CFontCache::Instance()
/****************************************/
{
    if(_instance==NULL)
        _instance = new CFontCache();
    return(*_instance);
}



};
