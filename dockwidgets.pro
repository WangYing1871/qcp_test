QT += widgets gui core
requires(qtConfig(listwidget))
qtHaveModule(printsupport): QT += printsupport

QMAKE_CXXFLAGS += \
  -Wno-deprecated-copy \
  -Wno-deprecated-enum-enum-conversion


HEADERS         += qcustomplot.h axis_tag.h MainWindow.h

SOURCES         += main.cpp qcustomplot.cpp axis_tag.cpp MainWindow.cpp
RESOURCES       = dockwidgets.qrc


FORMS += mainwindow.ui

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/mainwindows/dockwidgets
INSTALLS += target
