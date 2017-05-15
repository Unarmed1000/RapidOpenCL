#ifndef RAPIDOPENCL1_1__IMAGE_HPP
#define RAPIDOPENCL1_1__IMAGE_HPP
//***************************************************************************************************************************************************
//* BSD 3-Clause License
//*
//* Copyright (c) 2016, Rene Thrane
//* All rights reserved.
//*
//* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//*
//* 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//* 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
//*    documentation and/or other materials provided with the distribution.
//* 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
//*    software without specific prior written permission.
//*
//* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//* THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
//* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//* EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//***************************************************************************************************************************************************

// Auto-generated OpenCL 1.1 C++11 RAII classes by RAIIGen (https://github.com/Unarmed1000)

#include <RapidOpenCL/Config.hpp>
#include <RapidOpenCL/CustomTypes.hpp>
#include <RapidOpenCL/Util.hpp>
#include <CL/cl.h>
#include <cassert>

namespace RapidOpenCL
{
  // This object is movable so it can be thought of as behaving in the same was as a unique_ptr and is compatible with std containers
  class Image
  {
    cl_mem m_mem;
  public:
    Image(const Image&) = delete;
    Image& operator=(const Image&) = delete;

    //! @brief Move assignment operator
    Image& operator=(Image&& other)
    {
      if (this != &other)
      {
        // Free existing resources then transfer the content of other to this one and fill other with default values
        if (IsValid())
          Reset();

        // Claim ownership here
        m_mem = other.m_mem;

        // Remove the data from other
        other.m_mem = nullptr;
      }
      return *this;
    }

    //! @brief Move constructor
    Image(Image&& other)
      : m_mem(other.m_mem)
    {
      // Remove the data from other
      other.m_mem = nullptr;
    }

    //! @brief Create a 'invalid' instance (use Reset to populate it)
    Image()
      : m_mem(nullptr)
    {
    }

    //! @brief Assume control of the Image (this object becomes responsible for releasing it)
    explicit Image(const cl_mem mem)
      : Image()
    {
      Reset(mem);
    }

    //! @brief Create the requested resource
    //! @note  Function: clCreateImage2D
    Image(const cl_context context, const cl_mem_flags memFlags, const cl_image_format& imageFormat, const size_t imageWidth, const size_t imageHeight, const size_t imageRowPitch, void * pHost)
      : Image()
    {
      Reset(context, memFlags, imageFormat, imageWidth, imageHeight, imageRowPitch, pHost);
    }

    //! @brief Create the requested resource
    //! @note  Function: clCreateImage3D
    Image(const cl_context context, const cl_mem_flags memFlags, const cl_image_format& imageFormat, const size_t imageWidth, const size_t imageHeight, const size_t imageDepth, const size_t imageRowPitch, const size_t imageSlicePitch, void * pHost)
      : Image()
    {
      Reset(context, memFlags, imageFormat, imageWidth, imageHeight, imageDepth, imageRowPitch, imageSlicePitch, pHost);
    }

    ~Image()
    {
      Reset();
    }

    //! @brief returns the managed handle and releases the ownership.
    cl_mem Release() RAPIDOPENCL_FUNC_POSTFIX_WARN_UNUSED_RESULT
    {
      const auto resource = m_mem;
      m_mem = nullptr;
      return resource;
    }

    //! @brief Destroys any owned resources and resets the object to its default state.
    void Reset()
    {
      if (! IsValid())
        return;

      assert(m_mem != nullptr);

      clReleaseMemObject(m_mem);
      m_mem = nullptr;
    }

    //! @brief Destroys any owned resources and assume control of the Image (this object becomes responsible for releasing it)
    void Reset(const cl_mem mem)
    {
      if (IsValid())
        Reset();


      m_mem = mem;
    }

    //! @brief Destroys any owned resources and then creates the requested one
    //! @note  Function: clCreateImage2D
    void Reset(const cl_context context, const cl_mem_flags memFlags, const cl_image_format& imageFormat, const size_t imageWidth, const size_t imageHeight, const size_t imageRowPitch, void * pHost)
    {
      // We do the check here to be user friendly, if it becomes a performance issue switch it to a assert.

      // Free any currently allocated resource
      if (IsValid())
        Reset();

      // Since we want to ensure that the resource is left untouched on error we use a local variable as a intermediary
      cl_int errorCode;
      const cl_mem mem = clCreateImage2D(context, memFlags, &imageFormat, imageWidth, imageHeight, imageRowPitch, pHost, &errorCode);
      Util::Check(errorCode, "clCreateImage2D", __FILE__, __LINE__);

      // Everything is ready, so assign the members
      m_mem = mem;
    }

    //! @brief Destroys any owned resources and then creates the requested one
    //! @note  Function: clCreateImage3D
    void Reset(const cl_context context, const cl_mem_flags memFlags, const cl_image_format& imageFormat, const size_t imageWidth, const size_t imageHeight, const size_t imageDepth, const size_t imageRowPitch, const size_t imageSlicePitch, void * pHost)
    {
      // We do the check here to be user friendly, if it becomes a performance issue switch it to a assert.

      // Free any currently allocated resource
      if (IsValid())
        Reset();

      // Since we want to ensure that the resource is left untouched on error we use a local variable as a intermediary
      cl_int errorCode;
      const cl_mem mem = clCreateImage3D(context, memFlags, &imageFormat, imageWidth, imageHeight, imageDepth, imageRowPitch, imageSlicePitch, pHost, &errorCode);
      Util::Check(errorCode, "clCreateImage3D", __FILE__, __LINE__);

      // Everything is ready, so assign the members
      m_mem = mem;
    }

    //! @brief Get the associated resource handle
    cl_mem Get() const
    {
      return m_mem;
    }

    //! @brief Get a pointer to the associated resource handle
    const cl_mem* GetPointer() const
    {
      return &m_mem;
    }
    
    //! @brief Check if this object contains a valid resource
    inline bool IsValid() const
    {
      return m_mem != nullptr;
    }
  };
}


#endif
