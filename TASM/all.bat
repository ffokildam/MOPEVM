@echo off
cls

rem --------------------------------
echo ------ Assembling... -------------------------------------------------
echo.
TASM.EXE -L -ZI %1.asm
IF errorlevel 1 goto err_end
echo ------ Assembling completed succesfully ------------------------------
echo.
echo.
rem pause

rem --------------------------------

echo ------ Linking... ----------------------------------------------------
echo.
TLINK.EXE -M -V %1.obj
IF errorlevel 1 goto err_end
echo.
echo ------ Linking completed succesfully ---------------------------------
echo.
echo.
rem pause

rem --------------------------------

echo.
echo === Build completed succesfully ======================================
TD.EXE %1.exe
goto end

:err_end
echo.
echo ====== There are errors ! Building has been cancelled ================
pause
:end
@echo on
