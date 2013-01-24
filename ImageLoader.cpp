#include <ImageLoader.h>
#include <IL/ilut.h>

namespace Mocha
{

/**********************************/
CImageLoader* CImageLoader::_instance = NULL;
/**********************************/

/**********************************/
CImageLoader::CImageLoader()
/**********************************/
{
    ilInit();
    ilutRenderer(ILUT_OPENGL); 
}

/**********************************/
CImageLoader::~CImageLoader()
/**********************************/
{
}

/**********************************/
CImageLoader& CImageLoader::Instance()
/**********************************/
{
    if(_instance==NULL)
        _instance = new CImageLoader();
    return(*_instance);
}

/**********************************/
GLint CImageLoader::LoadImageTexture(string filename)
/**********************************/
{
    throw;
}

/**********************************/
void CImageLoader::UnloadImageTexture(string filename)
/**********************************/
{
}

};