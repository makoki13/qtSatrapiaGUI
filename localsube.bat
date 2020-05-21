@echo off
set /p comentario=Comentario:
echo "Subiendo GUI"
cd D:\home\Makoki\qt\proyectos\qtSatrapiaGUI\
git add .
git commit -m "%comentario%"
git push origin master
echo "Subiendo Clases"
cd D:\home\Makoki\qt\proyectos\QtSatrapia\
git add .
git commit -m "%comentario%"
git push origin master
cd D:\home\Makoki\qt\proyectos\qtSatrapiaGUI\
echo "fin!"
exit