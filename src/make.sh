clear

echo "REMOVENDO ARQUIVOS ANTIGOS..."
echo " "
make clean
echo " "
echo " "
echo "COMPILANDO..."
echo " "
make &> logCompilation.txt
cat < logCompilation.txt
echo " "
echo " "
echo "RODANDO APLICACAO..."
echo " "
make run &> logExecution.txt
cat < logExecution.txt
rm temp.txt