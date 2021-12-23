//! @file image.hpp
#ifndef __rgb_image_hpp__
#define __rgb_image_hpp__
#include <cassert>
#include <rgb/color.hpp>

namespace rgb {
    class image {
    private:
        //! \param iwidth Integer that represents the width of an image
        int iwidth;

        //! \param iheight Integer that represents the height of an image
        int iheight;

        //! \param pixels Multi-dimensional pointers array, that represents the field to store the image pixels
        color **pixels;
    public:
        //! Creates a new image, with all pixels in color white
        //! \param w Integer that represents the width of the new image
        //! \param h Integer that represents the height of the new image
         //! \param fill Initial color that Is going to fill every pixel of the image
        image(int w, int h, const color& fill = color::WHITE);

        //! Image destructor
        ~image();

        //! Returns an Integer
        //! \return The Integer width of the image
        int width() const;

        //! Returns an Integer
        //! \return The Integer height of the image
        int height() const;

        //! Return a color
        //! \param x Integer that represents the width position that the color Is located
        //! \param y Integer that represents the height position that the color Is located
        //! \return The color in the position given, just for checking
        color& at(int x, int y);

        //! Return a color
        //! \param x Integer that represents the width position that the color Is located
        //! \param y Integer that represents the height position that the color Is located
        //! \return the color in the position given
        const color& at(int x, int y) const;

        //! Inverts the whole pixels of an image
        void invert();

        //! Converts the whole pixels of an image to gray scale
        void to_gray_scale();

        //! Replaces every pixel in some specific color to another
        //! \param a Color to replace
        //! \param b Color to replace with
        void replace(const color& a, const color& b);

        //! Fills with some specific color every pixel between the coordinates given
        //! \param x Width lower limit
        //! \param y Height lower limit
        //! \param w Width upper limit when summed with x
        //! \param h Height upper limit when summed with y
        void fill(int x, int y, int w, int h, const color& c);

        //! Mixes every pixel with the correspondent pixel in the image with the factor f applied
        //! \param img Image to mix with
        //! \param factor Integer to multiply with every image pixel
        void mix(const image& img, int factor);

        //! Changes the image dimensions
        //! \param x Integer that represents the width position that the new image will begin
        //! \param y Integer that represents the height position that the new image will begin
        //! \param w Integer that represents the with of the new image
        //! \param h Integer that represents the height of the new image
        void crop(int x, int y, int w, int h);

        //! Rotates the image to the left
        void rotate_left();

        //! Rotates the image to the right
        void rotate_right();

        //! Adds content to image, beginning in the coordinates given, but doesn't add if
        //! the pixel color is the color given
        //! \param img Image to add
        //! \param neutral Color that can't be changed
        //! \param x Integer that represents the width position to begin the addition
        //! \param y Integer that represents the height position to begin the addition
        void add(const image& img, const color& neutral, int x, int y);
    };
}


#endif
