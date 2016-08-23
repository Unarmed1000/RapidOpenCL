#ifndef RAPIDOPENCL_PROGRAM_HPP
#define RAPIDOPENCL_PROGRAM_HPP
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

// Auto-generated OpenCL 1.1 C++11 RAII classes based on RAIIGen V0.2.5 (https://github.com/Unarmed1000)

#include <RapidOpenCL/Values.hpp>
#include <RapidOpenCL/Util.hpp>
#include <CL/cl.h>
#include <cassert>

namespace RapidOpenCL
{
  // This object is movable so it can be thought of as behaving in the same was as a unique_ptr and is compatible with std containers
  class Program
  {
    cl_program m_program;
  public:
    Program(const Program&) = delete;
    Program& operator=(const Program&) = delete;
  
    //! @brief Move assignment operator
    Program& operator=(Program&& other)
    {
      if (this != &other)
      {
        // Free existing resources then transfer the content of other to this one and fill other with default values
        if (IsValid())
          Reset();

        // Claim ownership here
        m_program = other.m_program;

        // Remove the data from other
        other.m_program = RapidValues::INVALID_PROGRAM;
      }
      return *this;
    }
  
    //! @brief Move constructor
    Program(Program&& other)
      : m_program(other.m_program)
    {
      // Remove the data from other
      other.m_program = RapidValues::INVALID_PROGRAM;
    }

    //! @brief Create a 'invalid' instance (use Reset to populate it)
    Program()
      : m_program(RapidValues::INVALID_PROGRAM)
    {
    }

    //! @brief Assume control of the Program (this object becomes responsible for releasing it)
    explicit Program(const cl_program program)
      : Program()
    {
      Reset(program);
    }
    
      //! @brief Create the requested resource
    Program(const cl_context context, const cl_uint count, const char ** ppStrings, const size_t * pLengths)
      : Program()
    {
      Reset(context, count, ppStrings, pLengths);
    }

      //! @brief Create the requested resource
    Program(const cl_context context, const cl_uint numDevices, const cl_device_id * pDeviceId, const size_t * lengths, const unsigned char ** ppBinaries, cl_int * pBinaryStatus)
      : Program()
    {
      Reset(context, numDevices, pDeviceId, lengths, ppBinaries, pBinaryStatus);
    }
    
    ~Program()
    {
      Reset();
    }

    //! @brief returns the managed handle and releases the ownership.
    cl_program Release()
    {
      const auto resource = m_program;
      m_program = RapidValues::INVALID_PROGRAM;
      return resource;
    }

    //! @brief Destroys any owned resources and resets the object to its default state.
    void Reset()
    {
      if (! IsValid())
        return;

      assert(m_program != RapidValues::INVALID_PROGRAM);

      clReleaseProgram(m_program);
      m_program = RapidValues::INVALID_PROGRAM;
    }

    //! @brief Destroys any owned resources and assume control of the Program (this object becomes responsible for releasing it)
    void Reset(const cl_program program)
    {
      if (IsValid())
        Reset();

      
      m_program = program;
    }    
    
    //! @brief Destroys any owned resources and then creates the requested one
    void Reset(const cl_context context, const cl_uint count, const char ** ppStrings, const size_t * pLengths)
    {
      // We do the check here to be user friendly, if it becomes a performance issue switch it to a assert.

      // Free any currently allocated resource
      if (IsValid())
        Reset();

      // Since we want to ensure that the resource is left untouched on error we use a local variable as a intermediary
      cl_int errorCode;
      const cl_program program = clCreateProgramWithSource(context, count, ppStrings, pLengths, &errorCode);
      Util::Check(errorCode, "clCreateProgramWithSource", __FILE__, __LINE__);

      // Everything is ready, so assign the members
      m_program = program;
    }

    //! @brief Destroys any owned resources and then creates the requested one
    void Reset(const cl_context context, const cl_uint numDevices, const cl_device_id * pDeviceId, const size_t * lengths, const unsigned char ** ppBinaries, cl_int * pBinaryStatus)
    {
      // We do the check here to be user friendly, if it becomes a performance issue switch it to a assert.

      // Free any currently allocated resource
      if (IsValid())
        Reset();

      // Since we want to ensure that the resource is left untouched on error we use a local variable as a intermediary
      cl_int errorCode;
      const cl_program program = clCreateProgramWithBinary(context, numDevices, pDeviceId, lengths, ppBinaries, pBinaryStatus, &errorCode);
      Util::Check(errorCode, "clCreateProgramWithBinary", __FILE__, __LINE__);

      // Everything is ready, so assign the members
      m_program = program;
    }

    //! @brief Get the associated resource handle
    cl_program Get() const
    {
      return m_program;
    }

    //! @brief Check if this object contains a valid resource
    inline bool IsValid() const
    {
      return m_program != RapidValues::INVALID_PROGRAM;
    }
  };
}


#endif
