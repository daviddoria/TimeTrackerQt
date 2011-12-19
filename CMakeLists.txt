cmake_minimum_required(VERSION 2.6)

PROJECT(TimeTrackerQt)
ENABLE_TESTING()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}) # Let subdirectories find headers in the root directory

# Where to copy executables when 'make install' is run
SET( INSTALL_DIR ${CMAKE_INSTALL_PREFIX} )

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_QTSQL_INCLUDE_DIR}) # for QSqlDatabase

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})# Let Qt find it's MOCed files

QT4_WRAP_UI(TimeTrackerUISrcs EditAssociateWidget.ui TimeTrackerWidget.ui)
QT4_WRAP_CPP(TimeTrackerMOCSrcs EditAssociateWidget.h TimeTrackerWidget.h)

ADD_EXECUTABLE(TimeTracker TimeTracker.cpp TimeTrackerWidget.cpp
Associate.cpp
CommissionedAssociate.cpp
Company.cpp
CompanyModel.cpp
Day.cpp
EditAssociateWidget.cpp
ManagerAssociate.cpp
TimedAssociate.cpp
${TimeTrackerUISrcs} ${TimeTrackerMOCSrcs})
TARGET_LINK_LIBRARIES(TimeTracker ${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)
#set_target_properties(TimeTrackerQt PROPERTIES COMPILE_DEFINITIONS "${DEFINITIONS}")
INSTALL( TARGETS TimeTracker RUNTIME DESTINATION ${INSTALL_DIR} )
#ADD_TEST(NAME PoissonCloningTest COMMAND ${EXECUTABLE_OUTPUT_PATH}/PoissonCloning ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Source.png ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Mask.png ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Target.png cloning.png)

add_subdirectory(Configuration)
add_subdirectory(Tests)