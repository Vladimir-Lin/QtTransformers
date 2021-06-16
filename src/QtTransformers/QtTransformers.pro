NAME         = QtTransformers
TARGET       = $${NAME}
QT           = core
QT          -= gui
QT          -= script
QT          += QtUUID

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/QtTransformers

HEADERS     += $${PWD}/../../include/QtTransformers/QtTransformers
HEADERS     += $${PWD}/../../include/QtTransformers/qttransformers.h

SOURCES     += $${PWD}/transformers.cpp

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)
