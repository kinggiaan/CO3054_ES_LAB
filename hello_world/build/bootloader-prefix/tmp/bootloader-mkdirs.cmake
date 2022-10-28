# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Espressif/frameworks/esp-idf-v4.4.2/components/bootloader/subproject"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix/tmp"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix/src/bootloader-stamp"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix/src"
  "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/HK221/CO3054_Embed/LAB/hello_world/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
