/*****************************************************************************/
// Filename: Image.h
/*****************************************************************************/
// Description: This class represents an image file. The image is loaded in as
// a texture on object construction, using the open source library DevIL.
// Users can use the copy constructor to make more copies of the object. A reference
// counter is used to unload the texture once all objects referring to the texture
// are destroyed.
/*****************************************************************************/

#ifndef MOCHA_IMAGE_H_DEFINED
#define MOCHA_IMAGE_H_DEFINED

#include <Drawable.h>

namespace Mocha
{

typedef map<GLuint, unsigned int> ImageReferenceCountMap;

enum ImageAlignment
{
    IA_BOTTOMLEFT,
    IA_BOTTOMRIGHT,
    IA_CENTER,
    IA_TOPLEFT,
    IA_TOPRIGHT
};

class CImage : public CDrawable
{
    public:
        CImage(string imageFilename);
        CImage(const CImage& image);
        CImage operator=(const CImage& image);
        virtual ~CImage();

        /**
        * Draws the image in device space using the passed point as the anchor. The alignment determines the placement
        * of the anchor in respect to the image.
        */
        void                           DrawMe(const CCartesianPoint& p,             ImageAlignment alignment);

        /**
        * Draws the image in device space using the passed point as the anchor. The alignment determines the placement
        * of the anchor in respect to the image.
        */
        void                           DrawMe(const CDevicePoint& p,                ImageAlignment alignment);

        /**
        * Draws the image in device space using the passed point as the anchor. The alignment determines the placement
        * of the anchor in respect to the image.
        */
        void                           DrawMe(const CGeographicalPoint& p,          ImageAlignment alignment);

        /**
        * Stretches an image bound by the rectangle specified by bottomLeft and topRight
        */
        void                           DrawMe(const CCartesianPoint& bottomLeft,    const CCartesianPoint& topRight);

        /**
        * Stretches an image bound by the rectangle specified by bottomLeft and topRight
        */
        void                           DrawMe(const CDevicePoint& bottomLeft,       const CDevicePoint& topRight);

        /**
        * Stretches an image bound by the rectangle specified by bottomLeft and topRight
        */
        void                           DrawMe(const CGeographicalPoint& bottomLeft, const CGeographicalPoint& topRight);

        double                         HeightInCartesian();
        int                            HeightInPixels() const;
        string                         ImageFilename() const;
        GLuint                         ImageTexture() const;
        double                         WidthInCartesian();
        int                            WidthInPixels() const;

    private:
        CCartesianPoint                DetermineBottomLeftPointBasedOnAlignment(const CCartesianPoint& p, ImageAlignment alignment);
        bool                           HasDevILBeenInitialized() const;
        void                           HasDevILBeenInitialized(bool hasIt);
        void                           HeightInPixels(int height);
        void                           ImageFilename(string imageFilename);
        static ImageReferenceCountMap& ImageReferenceCounts();
        void                           ImageTexture(GLuint textureID);
        void                           InitializeDevILIfNecessary();
        void                           LoadAndInitializeImage();
        GLuint                         LoadImageTexture(string imageFilename);
        void                           WidthInPixels(int width);
        void                           UnloadImageTextureIfNecessary();

    private:
        static bool                   _hasDevILBeenInitialized;
        string                        _imageFilename;
        int                           _imageHeight;
        GLuint                        _imageTexture;
        int                           _imageWidth;
        static ImageReferenceCountMap _imageReferenceCounts;
};

};

#endif
