set MODNAME=QtUUID
nmake clean
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
del /s /q *.pro.user
