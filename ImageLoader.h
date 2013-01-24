/*****************************************************************************/
// Filename: ImageLoader.h
/*****************************************************************************/
// Description: This class represents a singleton that manages loading of image
// files used in drawing. The ImageLoader utilizes the open source DevIL library
// in order to load images. This class caches image files as they are loaded
// so that they do not have to be reloaded again, giving a convenient interface
// for dealing with images.
/*****************************************************************************/

#ifndef IMAGE_LOADER_H_DEFINED
#define IMAGE_LOADER_H_DEFINED

#include <MochaObject.h>

namespace Mocha
{

typedef map<string, GLint> FileImageMap;
class CImageLoader : public CMochaObject
{
    public:        
        static CImageLoader& Instance();
        virtual ~CImageLoader();

        GLint LoadImageTexture(string filename);
        void  UnloadImageTexture(string filename);

    private:
        CImageLoader();
        FileImageMap& ImageCache();
        

    private:
        FileImageMap         _imageCache;
        static CImageLoader* _instance;
};

};


#endif
