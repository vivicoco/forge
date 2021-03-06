/*******************************************************
* Copyright (c) 2015-2019, ArrayFire
* All rights reserved.
*
* This file is distributed under 3-clause BSD license.
* The complete license agreement can be obtained at:
* http://arrayfire.com/licenses/BSD-3-Clause
********************************************************/

#pragma once

#include <common.hpp>
#include <array>

namespace forge
{
namespace opengl
{

constexpr unsigned int ForgeNumColorMaps = 11;

class colormap_impl {
    private:
        /*
         * READ THIS BEFORE ADDING NEW COLORMAP
         *
         * each of the following buffers will point
         * to the data from floating point arrays
         * defined in cmap.hpp header. Currently,
         * the largest colormap is 259 colors(1036 floats).
         * Hence the shader of internal::image_impl uses
         * uniform array of vec4 with size 259.
         * when a new colormap is added, make sure
         * the size of array declared in the shaders
         * used by *_impl objects to reflect appropriate
         * size */
        std::array<GLuint, ForgeNumColorMaps> mMapIds;
        std::array<GLuint, ForgeNumColorMaps> mMapLens;

    public:
        colormap_impl();
        ~colormap_impl();

        GLuint cmapUniformBufferId(forge::ColorMap cmap) const;
        GLuint cmapLength(forge::ColorMap cmap) const;
};

}
}
