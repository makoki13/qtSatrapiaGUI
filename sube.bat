@echo off
set /p comentario=Comentario:
echo "Subiendo GUI"
cd C:\Qt\proyectos\qtSatrapiaGUI\
git add .
git commit -m "%comentario%"
git push origin master
echo "Subiendo Clases"
cd C:\Qt\proyectos\QtSatrapia\
git add .
git commit -m "%comentario%"
git push origin master
echo "fin!"
exit