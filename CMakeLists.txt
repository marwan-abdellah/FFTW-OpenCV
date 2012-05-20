# Copyright (c) 2012 Marwan Abdellah <abdellah.marwan@gmail.com>

# Minimum required CMake version 
cmake_minimum_required(VERSION 2.6)

# FFT 
PROJECT(FFT_CV)

# Add CMake modules 
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

# FFTW 
SET(FFTW_ROOT ${PROJECT_SOURCE_DIR}/../install)
FIND_PACKAGE(FFTW REQUIRED)

# OpenCV
SET(OpenCV_DIR ${PROJECT_SOURCE_DIR}/../install/share/OpenCV)
FIND_PACKAGE(OpenCV REQUIRED)

# Add the heade files to the include directories
INCLUDE_DIRECTORIES("${FFTW_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS}")

# Generate the executable 
ADD_EXECUTABLE(FFT_CV FFT_CV.cxx)

# Link aginst the FFTW libraries 
TARGET_LINK_LIBRARIES(FFT_CV ${FFTW_LIBRARIES} ${OpenCV_LIBS})

# Installation directory 
SET(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/../install" 
CACHE PATH "Install path prefix" FORCE)

# Packaging 
include(CPackConfig)
