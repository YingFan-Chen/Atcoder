@echo off

:: Prompt the user for folder name
set /p folderName="Enter folder name: "

:: Create the directory
mkdir "contest\%folderName%"

:: Copy the template.cpp file to A.cpp, B.cpp, ..., F.cpp
copy template.cpp "contest\%folderName%\A.cpp"
copy template.cpp "contest\%folderName%\B.cpp"
copy template.cpp "contest\%folderName%\C.cpp"
copy template.cpp "contest\%folderName%\D.cpp"
copy template.cpp "contest\%folderName%\E.cpp"
copy template.cpp "contest\%folderName%\F.cpp"

:: Print success message
echo Directory "%folderName%" created with template files.
