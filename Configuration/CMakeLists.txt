# Let Qt find it's MOCed files
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(UISrcs TimeTrackerConfigurationWidget.ui EditCompanyWidget.ui) #ui files
QT4_WRAP_CPP(MOCSrcs TimeTrackerConfigurationWidget.h EditCompanyWidget.h) #h files

ADD_EXECUTABLE(TimeTrackerConfiguration TimeTrackerConfiguration.cpp
EditCompanyWidget.cpp
TimeTrackerConfigurationWidget.cpp
../Company.cpp
../CompanyModel.cpp
${UISrcs} ${MOCSrcs})
TARGET_LINK_LIBRARIES(TimeTrackerConfiguration
${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)
#set_target_properties(TimeTrackerQt PROPERTIES COMPILE_DEFINITIONS "${DEFINITIONS}")
INSTALL( TARGETS TimeTrackerConfiguration RUNTIME DESTINATION ${INSTALL_DIR} )
#ADD_TEST(NAME PoissonCloningTest COMMAND ${EXECUTABLE_OUTPUT_PATH}/PoissonCloning ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Source.png ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Mask.png ${CMAKE_SOURCE_DIR}/Testing/data/F16/F16Target.png cloning.png)
