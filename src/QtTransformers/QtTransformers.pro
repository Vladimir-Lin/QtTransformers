NAME         = QtTransformers
TARGET       = $${NAME}
QT           = core
QT          -= gui
QT          -= script
QT          += QtUUID

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}
HEADERS     += $${PWD}/qttransformers.h

SOURCES     += $${PWD}/transformers.cpp
