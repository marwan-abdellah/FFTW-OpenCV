# -----------------------------------------------------------------------------
# Author: Marwan Abdellah <abdellah.marwan@gmail.com>

# General CPack configuration 
# Info: http://www.itk.org/Wiki/CMake:Component_Install_With_CPack
# -----------------------------------------------------------------------------

# Package Name 
set(CPACK_PACKAGE_NAME "FFT_CV")

# Vendor 
set(CPACK_PACKAGE_VENDOR "ABDELLAH") 

# Summary 
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple application to test the FFTW library with OpenCV")

# Maintainer 
set(CPACK_PACKAGE_CONTACT "Marwan Abdellah <abdellah.marwan@gmail.com")

# Package version 
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 0)

# Select package generator
if(MSVC)
  set(CPACK_GENERATOR "NSIS")
endif(MSVC)

if (${CMAKE_SYSTEM_NAME} MATCHES Linux)
  find_program(RPM_EXE rpmbuild)
  if(${RPM_EXE} MATCHES RPM_EXE-NOTFOUND)
    set(CPACK_GENERATOR "TGZ;DEB")
  else()
    set(CPACK_GENERATOR "TGZ;DEB;RPM")
  endif()
endif()

# Debian specific configuration (minimum)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${CPACK_PACKAGE_CONTACT}")

# X11 dependency 
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libfftw3-dev libopencv-dev")

# RPM specific configuration (minimum)
set(CPACK_RPM_PACKAGE_LICENSE "LGPL")
set(CPACK_RPM_PACKAGE_GROUP "Miscellaneous")
set(CPACK_RPM_PACKAGE_VERSION ${VERSION})

include(InstallRequiredSystemLibraries)
include(CPack)

