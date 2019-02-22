/******************************************************************************
 * Copyright (c) 2018-2019, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

/// \file
/// \brief Helper class for handling platform specific operations.


#ifndef MDL_SDK_EXAMPLES_MDL_BROWSER_PLATFORM_HELPER_H
#define MDL_SDK_EXAMPLES_MDL_BROWSER_PLATFORM_HELPER_H

#include <string>
#include <functional>
#include <vector>

class Platform_helper
{
public:

    // get the current working directory
    static std::string get_working_directory();

    // get the path of the executable of this application
    static std::string get_executable_directory();

    // get date of the last modification of a file
    static time_t get_file_change_time(const std::string& path);

    // get the current point in time for measuring time differences in seconds
    static double get_time();

    // measure the time required to run some function
    static double tic_toc(const std::function<void()>& action);

    // measure the time required to run some function and print it to the log
    static double tic_toc_log(const std::string& name, const std::function<void()>& action);

    // Ensures that the console with the log messages does not close immediately. On Windows, users
    // are asked to press enter. On other platforms, nothing is done as the examples are most likely
    // started from the console anyway.
    static void keep_console_open();

    // get the value of a given environment variable or an empty string if the variable is not
    // defined or empty
    static std::string get_environment_variable(const std::string& env_var);

    // returns the paths configured by material library installers (environment variable)
    // or if non is defined, the platform dependent standard folder
    static std::vector<std::string> get_mdl_admin_space_directories();

    // returns the paths configured by material library installers (environment variable)
    // or if non is defined the platform dependent standard folder
    static std::vector<std::string> get_mdl_user_space_directories();
};



#endif
