<<<<<<< HEAD
# Install script for directory: /home/user/Feup2021/Programação/Praticas/project/Pixel
=======
# Install script for directory: /home/username/2aulas/Prog/Projeto_1/progp1
>>>>>>> 0fc86db0bfef5e44f1b4a138412bae0a34636314

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
<<<<<<< HEAD
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rgb" TYPE DIRECTORY FILES "/home/user/Feup2021/Programação/Praticas/project/Pixel/rgb")
=======
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/rgb" TYPE DIRECTORY FILES "/home/username/2aulas/Prog/Projeto_1/progp1/rgb")
>>>>>>> 0fc86db0bfef5e44f1b4a138412bae0a34636314
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
<<<<<<< HEAD
  include("/home/user/Feup2021/Programação/Praticas/project/Pixel/build/external/gtest/cmake_install.cmake")
=======
  include("/home/username/2aulas/Prog/Projeto_1/progp1/build/external/gtest/cmake_install.cmake")
>>>>>>> 0fc86db0bfef5e44f1b4a138412bae0a34636314

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/home/user/Feup2021/Programação/Praticas/project/Pixel/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/username/2aulas/Prog/Projeto_1/progp1/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 0fc86db0bfef5e44f1b4a138412bae0a34636314
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
