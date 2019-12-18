
find_program(CTEST_GIT_COMMAND NAMES git git.cmd)
find_program(CTEST_COVERAGE_COMMAND NAMES gcov)
find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)

set(CTEST_UPDATE_COMMAND "${CTEST_GIT_COMMAND}")

ctest_start(Continuous)

ctest_update()

ctest_configure(OPTIONS "${CTEST_BUILD_OPTIONS}")

ctest_build()

ctest_test()

if (WITH_COVERAGE AND CTEST_COVERAGE_COMMAND)
  ctest_coverage()
endif (WITH_COVERAGE AND CTEST_COVERAGE_COMMAND)

if (WITH_MEMCHECK AND CTEST_MEMORYCHECK_COMMAND)
  ctest_memcheck()
endif (WITH_MEMCHECK AND CTEST_MEMORYCHECK_COMMAND)

ctest_submit()
