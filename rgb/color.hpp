//! @file color.hpp
#ifndef __rgb_color_hpp__
#define __rgb_color_hpp__

#include <iostream>

namespace rgb {
    typedef unsigned char rgb_value;

    class color {
    private:
      //! \param r Integer in the range 0–255, represents the red component of the color.
      rgb_value r;
      //! \param g Integer in the range 0–255, represents the green component of the color.
      rgb_value g;
      //! \param b Integer in the range 0–255, represents the blue component of the color.
      rgb_value b;
    public:
        //! \param RED Represents color red
        static const color RED;

        //! \param GREEN Represents color green
        static const color GREEN;

        //! \param BLUE Represents color blue
        static const color BLUE;

        //! \param BLACK Represents color black
        static const color BLACK;

        //! \param WHITE Represents color white
        static const color WHITE;

        //! Creates a new color, and r,b,g initialized with zeros
        color();

        //! Creates a new color, with the addition of a specified color
        //! \param c Represents the combined color components
        color(const color &c);

        //! Creates a new color, with the specified red, green, and blue values, in the range 0-255
        //! \param r The red component
        //! \param g The blue component
        //! \param b The blue component
        color(rgb_value r, rgb_value g, rgb_value b);

        //! Returns the red component in the range 0-255 in the default color space
        //! \return The red component to use
        rgb_value red() const;

        //! Returns the red component in the range 0-255 in the default color space
        //! \return The red component just for checking
        rgb_value& red();

        //! Returns the green component in the range 0-255 in the default color space
        //! \return The green component to use
        rgb_value green() const;

        //! Returns the green component in the range 0-255 in the default color space
        //! \return The green component just for checking
        rgb_value& green();

        //! Returns the blue component in the range 0-255 in the default color space
        //! \return The blue component to use
        rgb_value blue() const;

        //! Returns the red component in the range 0-255 in the default color space
        //! \return The red component just for checking
        rgb_value& blue();

        //! Matches a default color to another
        //! \param c Represents the combined color components to match with
        //! \return The color matched
        color& operator=(const color&c);

        //! Compares if a default color Is equal to another one
        //! \param c Represents the combined color components to compare to
        //! \return The boolean, that represents if it's equal
        bool operator==(const color &c) const;

        //! Compares if a default color Is different to another one
        //! \param c Represents the combined color components to compare to
        //! \return The boolean, that represents if it's different
        bool operator!=(const color &c) const;

        //! Inverts the color components, subtracting 255 for each of the components
        void invert();

        //! Converts the color components to a gray scale, summing each component and dividing them with
        //!3
        void to_gray_scale();

        //! Mix the color components with an Integer between 0 and 100
        //! the whole operation it's
        //! (r,g,b) -> (m(r, c*r), m(g,c*g), m(b,c*b))
        //! where m(a,b) = ((100-f)a + f b) /100
        //! \param c Represents the combined color components to mix with
        //! \param f Represents the Integer to do the operations
        void mix(const color& c, int f);
    };
}
#endif
