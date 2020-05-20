@echo off
set /p comentario=Comentario:
cd C:\Qt\proyectos\qtSatrapiaGUI\
git add .
git commit -m "%comentario%"
git push origin master
pause
cd C:\Qt\proyectos\QtSatrapia\
git add .
git commit -m "%comentario%"
git push origin master
echo "fin!"
pause
exit