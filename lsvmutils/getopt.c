/*
**==============================================================================
**
** LSVMTools 
** 
** MIT License
** 
** Copyright (c) Microsoft Corporation. All rights reserved.
** 
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
** 
** The above copyright notice and this permission notice shall be included in 
** all copies or substantial portions of the Software.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE
**
**==============================================================================
*/
#include "config.h"
#include "getopt.h"
#include <string.h>

int GetOpt(
    int* argc,
    const char* argv[],
    const char* optname,
    const char** optarg)
{
    int i;

    for (i = 0; i < *argc; i++)
    {
        if (strcmp(argv[i], optname) == 0)
        {
            if (!optarg)
            {
                /* Found */
                memmove((char**)&argv[i], &argv[i+1], (*argc - i) * sizeof(char*));
                (*argc)--;
                return 1;
            }

            if (i + 1 == *argc)
            {
                /* Missing option argument */
                return -1;
            }

            *optarg = argv[i+1];
            memmove((char**)&argv[i], &argv[i+2], (*argc - i - 1) * sizeof(char*));
            (*argc) -= 2;
            return 1;
        }
    }

    /* Not found */
    return 0;
}
