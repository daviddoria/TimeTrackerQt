ENABLE_TESTING()

# Let Qt find it's MOCed files
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

QT4_WRAP_UI(EditAssociateWidgetUISrcs ../EditAssociateWidget.ui)
QT4_WRAP_CPP(EditAssociateWidgetMOCSrcs ../EditAssociateWidget.h)

ADD_EXECUTABLE(TestEditAssociateWidget TestEditAssociateWidget.cpp
../EditAssociateWidget.cpp
${EditAssociateWidgetUISrcs} ${EditAssociateWidgetMOCSrcs})
TARGET_LINK_LIBRARIES(TestEditAssociateWidget
${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)

ADD_EXECUTABLE(GenerateCompanyTable GenerateCompanyTable.cpp)
TARGET_LINK_LIBRARIES(GenerateCompanyTable
${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)

ADD_EXECUTABLE(GenerateAssociateTable GenerateAssociateTable.cpp)
TARGET_LINK_LIBRARIES(GenerateAssociateTable
${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)

ADD_EXECUTABLE(GenerateExampleDatabase GenerateExampleDatabase.cpp)
TARGET_LINK_LIBRARIES(GenerateExampleDatabase
${QT_LIBRARIES}
${QT_QTSQL_LIBRARY_RELEASE} # for QSqlDatabase
)
