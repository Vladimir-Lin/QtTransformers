set MODNAME=QtTransformers
nmake clean
del /s /q include\QtTransformers\QtTransformersDepends
del /s /q include\QtTransformers\QtTransformersVersion
del /s /q include\QtTransformers\qttransformersversion.h
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
