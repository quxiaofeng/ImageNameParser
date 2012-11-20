@ECHO OFF
set CONVERTCMD=E:\code\imageNameParser\imageNameConverter-build-desktop-Qt_4_8_1_for_Desktop_-_MSVC2010__Qt_SDK____\release\imageNameConverter.exe
set DSTFOLDER=E:\data\lineardata
set SRCFOLDER=E:\data\2012\20121111_last

FOR /R "%SRCFOLDER%" %%s IN (*.bmp) DO (
  call %CONVERTCMD% -f "%%~fs"  -p %DSTFOLDER%
)
Echo "Finished"
