#include <rgb/image.hpp>
#include <iostream>

namespace rgb {
    image::image(int w, int h, const color& fill) {
      iwidth = w;
      iheight = h;
      pixels = new color*[iwidth];

      for(int j=0;j<iwidth;j++)
        pixels[j] = new color[iheight];

      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++) {
          pixels[i][j].red() = fill.red();
          pixels[i][j].green() = fill.green();
          pixels[i][j].blue() = fill.blue();
        }
    }
    image::~image() {
      for(int i=0;i<iwidth;i++)
        delete [] pixels[i];
      delete [] pixels;
    }
    int image::width() const {
        return iwidth;
    }
    int image::height() const {
        return iheight;
    }
    color& image::at(int x, int y) {
        return pixels[x][y];
    }
    const color& image::at(int x, int y) const {
        return pixels[x][y];
    }
    void image::invert() {
      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          pixels[i][j].invert();
    }
    void image::to_gray_scale() {
      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          pixels[i][j].to_gray_scale();
    }
    void image::fill(int x, int y, int w, int h, const color& c) {
      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          if( i>=x && i < (x+w) && j>=y && j < (y+h)) {
            pixels[i][j].red() = c.red();
            pixels[i][j].green() = c.green();
            pixels[i][j].blue() = c.blue();
          }
    }
    void image::replace(const color& a, const color& b) {
      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          if(pixels[i][j] == a)
            pixels[i][j] = b;
    }
    void image::add(const image& img, const color& neutral, int x, int y) {
      for(int i=0;i<img.iwidth;i++)
        for(int j=0;j<img.iheight;j++)
          if(img.pixels[i][j] != neutral)
            pixels[x+i][y+j] = img.pixels[i][j];
    }
    void image::crop(int x, int y, int w, int h) {
      image l(w,h);
      for(int i=x;i<(x+w);i++)
        for(int j=y;j<(y+h);j++)
          l.pixels[i-x][j-y] = this->pixels[i][j];

      delete [] pixels;

      this->iwidth = w;
      this->iheight = h;
      this->pixels = new color*[this->iwidth];
      for(int j=0;j<this->iwidth;j++)
        this->pixels[j] = new color[this->iheight];

      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          this->pixels[i][j] = l.pixels[i][j];
    }
    void image::rotate_left() {
      image l(this->iheight, this->iwidth);
      for(int i=0;i<l.iwidth;i++)
        for(int j=0;j<l.iheight;j++)
          l.pixels[i][j] = this->pixels[iwidth - j - 1][i];

      delete [] this->pixels;

      this->iwidth = l.iwidth;
      this->iheight = l.iheight;

      this->pixels = new color*[this->iwidth];
      for(int j=0;j<this->iwidth;j++)
        this->pixels[j] = new color[this->iheight];

      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          this->pixels[i][j] = l.pixels[i][j];
    }
    void image::rotate_right() {
      image l(this->iheight, this->iwidth);
      for(int i=0;i<l.iwidth;i++)
        for(int j=0;j<l.iheight;j++)
          l.pixels[i][j] = this->pixels[j][iheight - i - 1];

      delete [] this->pixels;

      this->iwidth = l.iwidth;
      this->iheight = l.iheight;

      this->pixels = new color*[this->iwidth];
      for(int j=0;j<this->iwidth;j++)
        this->pixels[j] = new color[this->iheight];

      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          this->pixels[i][j] = l.pixels[i][j];
    }
    void image::mix(const image& img, int factor) {
      for(int i=0;i<iwidth;i++)
        for(int j=0;j<iheight;j++)
          pixels[i][j].mix(img.pixels[i][j],factor);
    }
}
