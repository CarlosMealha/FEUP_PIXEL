
//! @file script.hpp
#ifndef __rgb_script_hpp__
#define __rgb_script_hpp__

#include <fstream>
#include <rgb/image.hpp>

namespace rgb {
    class script {
    private:
        //! Mixes every pixel with the correspondent pixel in the image
        //! with the factor f applied
        void mix();

        //! Adds content to image, beginning in the coordinates given,
        //! but doesn't add if
        //! the pixel color is the color given
        void add();

        //! Fills with some specific color every pixel between the
        //! coordinates given
        void fill();

        //! Inverts the whole pixels of an image
        void invert();

        //! Converts the whole pixels of an image to gray scale
        void to_gray_scale();

        //! Replaces every pixel in some specific color to another
        void replace();

        //! Rotates the image to the left
        void rotate_left();

        //! Rotates the image to the right
        void rotate_right();

        //! Changes the image dimensions
        void crop();

        //! Opens and initializes an image from a file
        void open();

        //! Initializes the image with all pixels in white color
        void blank();

        //! Saves the image in a file, already implemented
        void save();
    public:
        //! Process scripts of a text with commands to manipulate an the
        //! image
        //! \param filename file with commands to manipulate
        script(const std::string& filename);

        //! Script destructor
        ~script();

        //! Processes the scripts
        void process();
    private:
        //! Image to script
        image* img;
        //! File input reader
        std::ifstream input;
        //! Root path to the input file
        std::string root_path;
    };
}
#endif
