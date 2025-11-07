# cmake/cdash_submit.cmake
# This script is executed by ctest -S to submit results to CDash.

# Set CDash project details from the provided CTest.cmake
set(CTEST_PROJECT_NAME "alg-fabbri-IPRJ-UERJ")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

# Determine submission URL based on CMake version
if(CMAKE_VERSION VERSION_GREATER 3.14)
  set(CTEST_SUBMIT_URL "https://my.cdash.org/submit.php?project=alg-fabbri-IPRJ-UERJ")
else()
  set(CTEST_DROP_METHOD "https")
  set(CTEST_DROP_SITE "my.cdash.org")
  set(CTEST_DROP_LOCATION "/submit.php?project=alg-fabbri-IPRJ-UERJ")
endif()

set(CTEST_DROP_SITE_CDASH TRUE)

# Set the build directory for this specific CTest run
# This variable is passed from run-tests.sh via ctest -S -D <build_dir>
set(CTEST_BINARY_DIRECTORY "${CTEST_SCRIPT_ARG}")

# CTEST_SCRIPT_ARGV is a list of arguments passed after -D <build_dir>
# We expect the build name as the first additional argument
if(ARGC GREATER 1)
  set(CTEST_BUILD_NAME "${ARGV1}")
else()
  # Fallback if no build name is provided
  set(CTEST_BUILD_NAME "DefaultBuild")
endif()

# We expect a submission control flag as the second additional argument
if(ARGC GREATER 2 AND ARGV2 STREQUAL "NO_SUBMIT")
  set(DO_SUBMIT FALSE)
else()
  set(DO_SUBMIT TRUE)
endif()

# Run tests and submit
ctest_start("Experimental") # Or "Nightly", "Continuous" - adjust as needed
ctest_configure()
ctest_build()
ctest_test()

if(DO_SUBMIT)
  ctest_submit()
else()
  message(STATUS "Skipping CDash submission (DO_SUBMIT is FALSE).")
endif()
