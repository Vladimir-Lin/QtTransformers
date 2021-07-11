set MODNAME=QtUUID
nmake clean
del /s /q .qmake.cache
del /s /q .qmake.stash
del /s /q Makefile
del /s /q src\Makefile
del /s /q src\QtUUID\Makefile*
del /s /q include\QtUUID\QtUUID
del /s /q include\QtUUID\QtUUIDDepends
del /s /q include\QtUUID\QtUUIDVersion
del /s /q include\QtUUID\qtuuidversion.h
rd  /s /q bin
rd  /s /q lib
rd  /s /q mkspecs
cd src/%MODNAME%
rd  /s /q .moc
rd  /s /q .obj
rd  /s /q .pch
del /s /q *_resource.rc
cd ../../
del /s /q tests\Makefile
del /s /q tests\auto\Makefile
