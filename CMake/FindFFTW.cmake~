# Copyright (c) 2012 Marwan Abdellah <abdellah.marwan@gmail.com>

find_path(FFTW_INCLUDE_DIR "fftw3.h" 
  HINTS ${FFTW_ROOT}/include
  /usr/include
  /usr/local/include
  /opt/local/include 
)

find_library(FFTW_LIBRARIES NAMES fftw3 
  HINTS ${FFTW_ROOT}/lib
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FFTW DEFAULT_MSG FFTW_LIBRARIES FFTW_INCLUDE_DIR)

if(HWLOC_FOUND)
  message(STATUS "Found FFTW in ${FFTW_INCLUDE_DIR} ${FFTW_LIBRARIES}")
endif(HWLOC_FOUND)


