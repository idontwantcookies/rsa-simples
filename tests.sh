./codificador.out a AEDS b 29 31
./codificador.out a AEDS b 101 37
./codificador.out a AEDS b 11 13
./codificador.out a AEDS b 2 11
./codificador.out a AEDS b 2 31
echo "----Problemas----"
./codificador.out a AEDSA b 29 31
./codificador.out a AEDSAE b 29 31
./codificador.out a AEDSAED b 29 31
./codificador.out a AEDSAEDSAEDS b 29 31
./codificador.out a AEDSAEDSAEDSOIDASCOE b 29 31
echo "----Erros esperados----"
./codificador.out a AEDS b 3 2
./codificador.out a AEDS b -3 3
./codificador.out a AEDS b -11 31
./codificador.out a AEDS b 0 12
./codificador.out a AEDS b 2 2
./codificador.out a aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa b 31 29