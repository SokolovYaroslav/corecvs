/**
 * \file main_test_morphologic.cpp
 * \brief This is the main file for the test morphologic 
 *
 * \date Aug 11, 2011
 * \author alexander
 *
 * \ingroup autotest  
 */

#include <stdint.h>
#include <iostream>
#include "gtest/gtest.h"

#include "core/utils/global.h"
#include "core/buffers/g12Buffer.h"
#include "core/fileformats/bmpLoader.h"
#include "core/buffers/morphological/morphological.h"

using namespace std;
using namespace corecvs;

uint16_t inputData12[10*10] =
{
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0000, 0x0000, 0x0000, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0000, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000,

   0x0000, 0x0000, 0x0000, 0x0FFF, 0x0FFF, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0000, 0x0000, 0x0000, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0FFF, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
   0x0000, 0x0FFF, 0x0FFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

uint8_t inputData8[10*10] =
{
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,

   0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint16_t elementData[3*3] =
{
   0x0000, 0x0FFF, 0x0000,
   0x0FFF, 0x0FFF, 0x0FFF,
   0x0000, 0x0FFF, 0x0000
};

TEST(Morphologic, testErodeDilate12)
{
    G12Buffer *input   = new G12Buffer(10,10, inputData12);
    G12Buffer *element = new G12Buffer(3,3, elementData);

    BMPLoader().save("input.bmp", input);

    G12Buffer *erode  = Morphological::erode(input, element, 1, 1);
    BMPLoader().save("erode.bmp", erode);

    G12Buffer *dilate = Morphological::dilate(input, element, 1, 1);
    BMPLoader().save("dilate.bmp", dilate);

    delete erode;
    delete dilate;
    delete input;
    delete element;
}

TEST(Morphologic, testErodeDilate8)
{
    G8Buffer  *input   = new  G8Buffer(10,10, inputData8);
    G12Buffer *element = new G12Buffer( 3, 3, elementData);

    BMPLoader().save("input8.bmp", input);

    G8Buffer *erode  = Morphological::erode(input, element, 1, 1);
    BMPLoader().save("erode8.bmp", erode);

    G8Buffer *dilate = Morphological::dilate(input, element, 1, 1);
    BMPLoader().save("dilate8.bmp", dilate);

    delete erode;
    delete dilate;
    delete input;
    delete element;
}
