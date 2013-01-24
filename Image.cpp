#include <Image.h>
#include <IL/ilut.h>
#include <cstring>

namespace Mocha
{

/**************************************************/
bool CImage::_hasDevILBeenInitialized = false;
ImageReferenceCountMap CImage::_imageReferenceCounts = ImageReferenceCountMap();
/**************************************************/

/**************************************************/
CImage::CImage(string imageFilename) : _imageFilename(imageFilename)
/**************************************************/
{
    InitializeDevILIfNecessary();
    LoadAndInitializeImage();
}

/**************************************************/
CImage::CImage(const CImage& image)
/**************************************************/
{
    HeightInPixels(image.HeightInPixels());
    WidthInPixels(image.WidthInPixels());
    ImageFilename(image.ImageFilename());
    ImageTexture(image.ImageTexture());
    ImageReferenceCounts()[ImageTexture()] += 1;
}

/*********************************************/
CImage CImage::operator=(const CImage& image)
/*********************************************/
{
    if(&image != this)
    {
        return(CImage(image));
    }
    else
        return(*this);
}

/**************************************************/
CImage::~CImage()
/**************************************************/
{
    UnloadImageTextureIfNecessary();
}

/**************************************************/
CCartesianPoint CImage::DetermineBottomLeftPointBasedOnAlignment(const CCartesianPoint& p, ImageAlignment alignment)
/**************************************************/
{
    unsigned int imageHeightCartesian = HeightInPixels() * CartesianToDeviceScaleYAxis();
    unsigned int imageWidthCartesian  = WidthInPixels() * CartesianToDeviceScaleXAxis();
    switch(alignment)
    {
        case IA_TOPLEFT:
            return(CCartesianPoint(p.X(), p.Y() - imageHeightCartesian));
        case IA_BOTTOMRIGHT:
            return(CCartesianPoint(p.X() - imageWidthCartesian, p.Y()));
        case IA_TOPRIGHT:
            return(CCartesianPoint((p.X() - imageWidthCartesian), (p.Y() - imageHeightCartesian)));
        case IA_BOTTOMLEFT:
            return(p);
        case IA_CENTER:
            return(CCartesianPoint((p.X() - (imageWidthCartesian/2)), (p.Y() - (imageHeightCartesian/2))));
        default:
            throw;
    };

}

/**************************************************/
void CImage::DrawMe(const CCartesianPoint& p, ImageAlignment alignment)
/**************************************************/
{
    CCartesianPoint bottomLeft = DetermineBottomLeftPointBasedOnAlignment(p, alignment);
    CCartesianPoint topRight(bottomLeft.X()+WidthInCartesian(), bottomLeft.Y() + HeightInCartesian());

    DrawMe(bottomLeft, topRight);
}

/**************************************************/
void CImage::DrawMe(const CDevicePoint& p, ImageAlignment alignment)
/**************************************************/
{
    DrawMe(ToCartesian(p), alignment);
}

/**************************************************/
void CImage::DrawMe(const CGeographicalPoint& p, ImageAlignment alignment)
/**************************************************/
{
    DrawMe(ToCartesian(p), alignment);
}

/**************************************************/
void CImage::DrawMe(const CCartesianPoint& bottomLeft, const CCartesianPoint& topRight)
/**************************************************/
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ImageTexture());
    double left = bottomLeft.X();
    double bottom = bottomLeft.Y();
    double right = topRight.X();
    double top = topRight.Y();

    glBegin(GL_QUADS);
        glTexCoord2d(0.0,0.0); glVertex2d(left, bottom);
        glTexCoord2d(1.0,0.0); glVertex2d(right,bottom);
        glTexCoord2d(1.0,1.0); glVertex2d(right, top);
        glTexCoord2d(0.0,1.0); glVertex2d(left, top);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/**************************************************/
void CImage::DrawMe(const CDevicePoint& bottomLeft, const CDevicePoint& topRight)
/**************************************************/
{
    DrawMe(ToCartesian(bottomLeft), ToCartesian(topRight));
}

/**************************************************/
void CImage::DrawMe(const CGeographicalPoint& bottomLeft, const CGeographicalPoint& topRight)
/**************************************************/
{
    DrawMe(ToCartesian(bottomLeft), ToCartesian(topRight));
}

/**************************************************/
bool CImage::HasDevILBeenInitialized() const
/**************************************************/
{
    return(_hasDevILBeenInitialized);
}

/**************************************************/
void CImage::HasDevILBeenInitialized(bool hasIt)
/**************************************************/
{
    _hasDevILBeenInitialized = hasIt;
}

/**************************************************/
double CImage::HeightInCartesian()
/**************************************************/
{
    return(HeightInPixels()*CartesianToDeviceScaleYAxis());
}

/**************************************************/
int CImage::HeightInPixels() const
/**************************************************/
{
    return(_imageHeight);
}

/**************************************************/
void CImage::HeightInPixels(int height)
/**************************************************/
{
    _imageHeight = height;
}

/**************************************************/
string CImage::ImageFilename() const
/**************************************************/
{
    return(_imageFilename);
}

/**************************************************/
void CImage::ImageFilename(string imageFilename)
/**************************************************/
{
    _imageFilename = imageFilename;
}

/**************************************************/
ImageReferenceCountMap& CImage::ImageReferenceCounts()
/**************************************************/
{
    return(_imageReferenceCounts);
}

/**************************************************/
GLuint CImage::ImageTexture() const
/**************************************************/
{
    return(_imageTexture);
}

/**************************************************/
void CImage::ImageTexture(GLuint textureID)
/**************************************************/
{
    _imageTexture = textureID;
}

/**************************************************/
void CImage::InitializeDevILIfNecessary()
/**************************************************/
{
    if(!HasDevILBeenInitialized())
    {
        ilInit();
        iluInit();
        ilutRenderer(ILUT_OPENGL);
        HasDevILBeenInitialized(true);
    }
}

/**************************************************/
void CImage::LoadAndInitializeImage()
/**************************************************/
{
    ImageTexture(LoadImageTexture(ImageFilename()));
    HeightInPixels(ilGetInteger(IL_IMAGE_HEIGHT));
    WidthInPixels(ilGetInteger(IL_IMAGE_WIDTH));
    ImageReferenceCounts()[ImageTexture()] = 1;
}

/**************************************************/
GLuint CImage::LoadImageTexture(string imageFilename)
/**************************************************/
{
    char* name = new char[imageFilename.size()+1];
    strcpy(name, imageFilename.c_str());
    GLuint toReturn = ilutGLLoadImage(name);
    delete[](name);
    return(toReturn);
}

/**************************************************/
double CImage::WidthInCartesian()
/**************************************************/
{
    return(WidthInPixels()*CartesianToDeviceScaleXAxis());
}

/**************************************************/
int CImage::WidthInPixels() const
/**************************************************/
{
    return(_imageWidth);
}

/**************************************************/
void CImage::WidthInPixels(int width)
/**************************************************/
{
    _imageWidth = width;
}

/**************************************************/
void CImage::UnloadImageTextureIfNecessary()
/**************************************************/
{
    GLuint textureID = ImageTexture();
    ImageReferenceCounts()[textureID] -= 1;
    if(ImageReferenceCounts()[textureID] == 0)
    {
        glDeleteTextures(1, &textureID);
    }
}


};
