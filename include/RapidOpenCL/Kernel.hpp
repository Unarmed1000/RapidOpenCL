#ifndef RAPIDOPENCL_KERNEL_HPP
#define RAPIDOPENCL_KERNEL_HPP
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

// Auto-generated OpenCL 1.1 C++11 RAII classes based on RAIIGen V0.2.4 (https://github.com/Unarmed1000)

#include <RapidOpenCL/Values.hpp>
#include <RapidOpenCL/Util.hpp>
#include <CL/cl.h>
#include <cassert>

namespace RapidOpenCL
{
  // This object is movable so it can be thought of as behaving in the same was as a unique_ptr and is compatible with std containers
  class Kernel
  {
    cl_kernel m_kernel;
  public:
    Kernel(const Kernel&) = delete;
    Kernel& operator=(const Kernel&) = delete;
  
    //! @brief Move assignment operator
    Kernel& operator=(Kernel&& other)
    {
      if (this != &other)
      {
        // Free existing resources then transfer the content of other to this one and fill other with default values
        if (IsValid())
          Reset();

        // Claim ownership here
        m_kernel = other.m_kernel;

        // Remove the data from other
        other.m_kernel = RapidValues::INVALID_KERNEL;
      }
      return *this;
    }
  
    //! @brief Move constructor
    Kernel(Kernel&& other)
      : m_kernel(other.m_kernel)
    {
      // Remove the data from other
      other.m_kernel = RapidValues::INVALID_KERNEL;
    }

    //! @brief Create a 'invalid' instance (use Reset to populate it)
    Kernel()
      : m_kernel(RapidValues::INVALID_KERNEL)
    {
    }

    //! @brief Assume control of the Kernel (this object becomes responsible for releasing it)
    explicit Kernel(const cl_kernel kernel)
      : Kernel()
    {
      Reset(kernel);
    }
    
      //! @brief Create the requested resource
    Kernel(const cl_program program, const char * pszKernelName)
      : Kernel()
    {
      Reset(program, pszKernelName);
    }
    
    ~Kernel()
    {
      Reset();
    }

    //! @brief returns the managed handle and releases the ownership.
    cl_kernel Release()
    {
      const auto resource = m_kernel;
      m_kernel = RapidValues::INVALID_KERNEL;
      return resource;
    }

    //! @brief Destroys any owned resources and resets the object to its default state.
    void Reset()
    {
      if (! IsValid())
        return;

      assert(m_kernel != RapidValues::INVALID_KERNEL);

      clReleaseKernel(m_kernel);
      m_kernel = RapidValues::INVALID_KERNEL;
    }

    //! @brief Destroys any owned resources and assume control of the Kernel (this object becomes responsible for releasing it)
    void Reset(const cl_kernel kernel)
    {
      if (IsValid())
        Reset();

      
      m_kernel = kernel;
    }    
    
    void Reset(const cl_program program, const char * pszKernelName)
    {
      // We do the check here to be user friendly, if it becomes a performance issue switch it to a assert.

      // Free any currently allocated resource
      if (IsValid())
        Reset();

      // Since we want to ensure that the resource is left untouched on error we use a local variable as a intermediary
      cl_int errorCode;
      const cl_kernel kernel = clCreateKernel(program, pszKernelName, &errorCode);
      Util::Check(errorCode, "clCreateKernel", __FILE__, __LINE__);

      // Everything is ready, so assign the members
      m_kernel = kernel;
    }

    //! @brief Get the associated resource handle
    cl_kernel Get() const
    {
      return m_kernel;
    }

    //! @brief Check if this object contains a valid resource
    inline bool IsValid() const
    {
      return m_kernel != RapidValues::INVALID_KERNEL;
    }
  };
}


#endif
