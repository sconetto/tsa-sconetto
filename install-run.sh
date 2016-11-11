#!/bin/bash
clear
printf '\e[8;35;140t'
echo "Script de  compilação e execução do TSA-III"
echo "Trabalho de Sala de Aula III - Conselho Federal de Odontologia (CFO)"
echo "Aluno: João Pedro Sconetto     Matrícula: 14/0145940"
echo "Disciplina: Estrutura de Dados e Algoritmos"
echo "Professor: Nilton Correia"
echo "           Fabricio Braz"
sleep 5
clear
gcc -v -Wall -ansi -W -pedantic -pedantic-errors -L. *.c -o bin/cfo-exe
sleep 1
echo "Programa compilado!"
sleep 3
clear
currentUser=$(whoami)
echo "Por favor conceda as permissões para execução do programa"
sudo chown root:$currentUser ./bin/cfo-exe
sudo chmod +x ./bin/cfo-exe
clear
echo "Executando arquivo compilado"
sleep 2
./bin/cfo-exe
