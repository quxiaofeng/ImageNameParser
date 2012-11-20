rmdir imageNameConverter-build-desktop-Qt_4_8_1_for_Desktop_-_MSVC2010__Qt_SDK____ /s /q

FOR /R "." %%s IN (*~) DO call del "%%~fs" /q
FOR /R "." %%s IN (*.pro.user) DO call del "%%~fs" /q

