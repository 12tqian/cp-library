SET location="C:\Users\12tqi\Documents\GitHub\cp-library"
FOR /R %location% %%A in (*.cpp) do ren "%%A" *.hpp  
GOTO :eof 

:rename
SET "_filename=%~nx1"
REN %1 "%_filename:_=-%"