#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
 
 int sitio=0;
 int nv;
 int sitio_1=0;
 int pos_asig=0;
 int pos_asig_1=0;
 
 //DATOS DE ALUMNOS//
 
 struct dt_alumno{
 	char nombre[30];
 	char direccion[30];
 	float carnet;
 }alum_absolutos[10];
 
  int ya_existe(int num1){
 	if(sitio==0){
 		return false;
 	}
 	for(int i=0;i<sitio;i++){
 		if(alum_absolutos[i].carnet==num1){
 			return true;
 		}
 	}
 	return false;
 } 
 
  void dt_alumno(){
 	system("cls");
 	char nombre[30];
 	char direccion[30];
 	int carnet;
 	cout<<"Ingrese nombre del alumno:"<<endl;
 	cin>>nombre;
 	cout<<"ingrese su Direccion:"<<endl;
 	cin>>direccion;
 	cout<<"Ingrese numero de carnet:"<<endl;
 	cin>>carnet;
 	if(!ya_existe(carnet)){
 		alum_absolutos[sitio].carnet=carnet;
 		strcpy(alum_absolutos[sitio].nombre,nombre);
 		strcpy(alum_absolutos[sitio].direccion,nombre);
 		sitio++;
 	}
 	else{
 		cout<<"El registro de carnet ya aparece"<<endl;
 		
 	}
 }
 
 void visual_alumnos(){
 	system ("cls");
 	cout<<"Los datos capturados son:"<<endl;
 	for(int i=0;i>sitio;sitio++){
 		cout<<"El carnet es:"<<alum_absolutos[i].carnet<<endl;
 		cout<<"El nombre del alumnos es:"<<alum_absolutos[i].nombre<<endl;
 		cout<<"La direccion del alumno es:"<<alum_absolutos[i].direccion<<endl;
 		
 	}
 }
 
 void consult_alumnos(){
 	system ("cls");
 	cout<<"Ingrese carnet para obtener datos:"<<endl;
 	cin>>nv;
 	if(ya_existe(nv)){
 		cout<<"Carnet no valido"<<endl;
 	}
 	for(int i=0;i>sitio;i++){
 		if(nv==alum_absolutos[i].carnet){
 			cout<<"Carnet de alumno:"<<" "<<alum_absolutos[i].carnet<<endl;
 			cout<<"Nombre de alumno:"<<" "<<alum_absolutos[i].nombre<<endl;
 			cout<<"Direccion de alumno:"<<" "<<alum_absolutos[i].direccion<<endl;
 		}
 	}
 }
 
  void descar_alumnos(){
 	FILE*estfile;
 	estfile=fopen("ALUMNOS.txt","w");
 	for(int a_des=0;a_des<sitio;a_des++){
 		if(estfile!=NULL){
 			fprintf(estfile,"El carnet es:",alum_absolutos[a_des].carnet);
 			fprintf(estfile,"El nombre del estudiante es:",alum_absolutos[a_des].nombre);
 			fprintf(estfile,"La direccion del estudiante es:",alum_absolutos[a_des].direccion);
 		}
 	}
 	fclose(estfile);
 	cout<<"Ya se descargo el archivo ALUMNOS"<<endl;
 }
 
 //DATOS DE CURSOS//
 
 struct dt_cursos{
 	char nombre_1[30];
 	int cred;
 	int cod_curso;
 }cursos_tot[5];
 

 int curso_exist (int num2){
	if(sitio==0){
	   return false;  
	}                                  
	for (int i=0;i<sitio;i++){
			if(cursos_tot[i].cod_curso==num2){
			return true;
			
			}
		}
	return false;
}

 void ingr_cursos(){
 	system ("cls");
 	int cod;
 	char nom_1[30];
 	int cred_1;
 	cout<<"Ingrese codigo de curso"<<endl;
 	cin>>cod;
 	cout<<"Ingrese nombre de curso"<<endl;
 	cin>>nom_1;
 	cout<<"Ingrese creditos"<<endl;
 	cin>>cred_1;
 	if(!curso_exist(cod)){
 		cursos_tot[sitio_1].cod_curso=cod;
 		strcpy(cursos_tot[sitio].nombre_1,nom_1);
 		cursos_tot[sitio_1].cred=cred_1;
 		sitio_1++;
 	}
 	else{
 		cout<<"Curso ya registrado"<<endl;
 	}
 }
 
 void visual_cursos(){
 	system ("cls");
 	cout<<"La informacion del curso es:"<<endl;
 	for(int i=0;i<sitio;sitio++){
 		cout<<"Codigo de curso:"<<"Son:"<<cursos_tot[i].cod_curso<<endl;
 		cout<<"Nombre del curso:"<<"Es:"<<cursos_tot[i].nombre_1<<endl;
 		cout<<"Creditos de curso:"<<"Son:"<<cursos_tot[i].cred<<endl;
 	}
 }
 
 void consult_cursos(){
 	system ("cls");
 	int consul;
 	cout<<"Ingresar codigo de curso:"<<endl;
 	cin>>consul;
 	if(!curso_exist(consul)){
 		cout<<"Carnet valido"<<endl;
 	}
 	else{
 		for(int i=0;i<sitio;i++){
 			cout<<"El codigo de curso es:"<<" "<<cursos_tot[i].cod_curso<<endl;
 			cout<<"El curso es:"<<" "<<cursos_tot[i].nombre_1<<endl;
 			cout<<"El credito del curso es:"<<cursos_tot[i].cred<<endl;
 		}
 	}
 }
 
  void descar_cursos(){
 	FILE*curfile;
 	curfile=fopen("CURSOS.txt","w");
 	for(int i=0;i<sitio_1;i++){
 		if(curfile!=NULL){
 			fprintf(curfile,"EL codigo del curso es:",cursos_tot[i].cod_curso);
 			fprintf(curfile,"El nombre del curso es:",cursos_tot[i].nombre_1);
 			fprintf(curfile,"Los creditos del curso son:",cursos_tot[i].cred);
 		}
 	}
 	fclose(curfile);
 	cout<<"Archivo descargado"<<endl;
 }
 
 //DATOS DE ASIGNACIONES//

struct asignaciones{
	int carnet;
	int curso;
	int p_p;
	int s_p;
	int z;
	int nota;
	int ex_f;
	int nota_f;
}tot_asignaciones[50];


int asig_exist(int num_asig){
	if (pos_asig==0){
	    return false;
	} 
	for (int i=0;i<pos_asig;i++){
		if (tot_asignaciones[i].carnet==num_asig){
		return true;
		}
	}
	return false;
}

 
 void ingr_asig(){
 	system ("cls");
 	cout<<"Ingreso de asignaciones"<<endl;
 	int numeasig;
 	int cod_cur;
 	cout<<"Ingrese el numero de carnet:"<<endl;
 	cin>>numeasig;
 	cout<<"Ingrese codigo de curso:"<<endl;
 	cin>>cod_cur;
 	if(curso_exist(cod_cur)){
 		if(ya_existe(numeasig)){
 			alum_absolutos[sitio].carnet=numeasig;
 			cursos_tot[sitio_1].cod_curso=cod_cur;
 			pos_asig++;
 			for(int i=0;i<sitio_1;i++){
 				if(numeasig=alum_absolutos[i].carnet){
 					if(cod_cur==cursos_tot[i].cod_curso){
 						cout<<"Ya asignado"<<endl<<cursos_tot[i].nombre_1<<endl;
 					}
 				}
 			}
 		}
 	}
 	else{
 		cout<<"NO existe carnet NI codigo de curso"<<endl;
 	}
 }
 
 void visul_asig(){
 	system ("cls");
 	cout<<"Datos ya asignados:"<<endl;
 	for(int i=0;i<pos_asig;i++){
 		cout<<"El carnet es:"<<alum_absolutos[i].carnet<<endl;
 		cout<<"El codigo del curso es:"<<cursos_tot[i].cod_curso<<endl;
 		
 	}
 }
 
 void consult_asig(){
 	system ("cls");
 	cout<<"Consulta de asignaciones"<<endl;
 	int nume_consul;
 	int nume_consul_1;
 	cout<<"Ingrese el codigo de curso a consultar:"<<endl;
 	cin>>nume_consul;
 	cout<<"Ingrese el carnet de alumno para consultar:"<<endl;
 	cin>>nume_consul_1;
 	if(!curso_exist(nume_consul)){
 		
 	}
 	if(!ya_existe(nume_consul_1)){
 		cout<<"Codigos ingresados no existen"<<endl;
 	}
 	else{
 		for(int i=0;i<pos_asig;i++){
 			if((nume_consul==cursos_tot[i].cod_curso)&&(nume_consul_1==alum_absolutos[i].carnet)){
 				cout<<"El nombre del curso es:"<<cursos_tot[i].nombre_1<<endl;
 			}
 		}
 	}
 }
 
  void descar_asig(){
 	FILE*curfile;
 	curfile=fopen("ASIGNACIONES.txt","w");
 	for(int i=0;i<pos_asig;i++){
 		if(curfile!=NULL){
 			fprintf(curfile,"El codigo del curso es:",cursos_tot[i].cod_curso);
 			fprintf(curfile,"El numero de carnet es:",alum_absolutos[i].carnet);
 			fprintf(curfile,"El curso asignado es:",cursos_tot[i].nombre_1);
 		}
 		fclose (curfile);
 		cout<<"Archivo de asignaciones descargado"<<endl;
 	}
 }
 
 //INGRESO DE NOTAS//
 
 void ingr_notas(){
 	cout<<"Ingreso de notas"<<endl;
 	int nume;
 	int codigo_cur;
 	int primer;
 	int segundo;
 	int exa;
 	int zona;
 	int notaf;
 	cout<<"Ingrese el numero del carnet:"<<endl;
 	cin>>nume;
 	cout<<"Ingrese el codigo del curso:"<<endl;
 	cin>>codigo_cur;
 	cout<<"Ingrese la nota del primer parcial:"<<endl;
 	cin>>primer;
 	cout<<"Ingrese la nota del segundo parcial:"<<endl;
 	cin>>segundo;
 	cout<<"Ingrese la zona total:"<<endl;
 	cin>>zona;
 	cout<<"Ingrese la nota del examen final:"<<endl;
 	cin>>exa;
 	if(ya_existe(nume)){
 		alum_absolutos[pos_asig_1].carnet=nume;
 		cursos_tot[pos_asig_1].cod_curso=codigo_cur;
 		tot_asignaciones[pos_asig_1].p_p=primer;
 		tot_asignaciones[pos_asig_1].s_p=segundo;
 		tot_asignaciones[pos_asig_1].z=zona;
 		tot_asignaciones[pos_asig_1].ex_f=exa;
 		tot_asignaciones[pos_asig_1].nota_f=notaf+zona+exa+primer+segundo;
 		pos_asig_1++;
 		cout<<"La nota final es de:"<<"\n"<<notaf<<endl;
 		for(int i=0;i<pos_asig_1;i++){
 			if(codigo_cur==cursos_tot[i].cod_curso);
 			if(nume==alum_absolutos[i].carnet);
 			
 		}
 	}
 	else{
 		cout<<"Carnet y cursos no existentes"<<endl;
 	}
 }
 
 void visul_notas(){
 	for(int i=0;i<pos_asig_1;i++){
 		cout<<"El carnet es:"<<alum_absolutos[i].carnet<<endl;
 		cout<<"El codigo del curso es:"<<cursos_tot[i].cod_curso<<endl;
 		cout<<"La nota del primer parcial es:"<<tot_asignaciones[i].p_p<<endl;
 		cout<<"La nota del segundo parcial es:"<<tot_asignaciones[i].s_p<<endl;
 		cout<<"la zona total es:"<<tot_asignaciones[i].z<<endl;
 		cout<<"la nota final es:"<<tot_asignaciones[i].nota_f<<endl;
 	}
 }
 
 void consult_notas(){
 	int codigo_1;
 	int carnet_1;
 	cout<<"Ingrese el codigo del curso que desea consultar:"<<endl;
 	cin>>codigo_1;
 	cout<<"Ingrese el numero de carnet a consultar:"<<endl;
 	cin>>carnet_1;
 	     if(!curso_exist(codigo_1)){
 	     	if(ya_existe(carnet_1)){
 	     		cout<<"El codigo no existe"<<endl;
 	     			
 	     	}
 	     }
 	     else{
 	     	for(int i=0;i<pos_asig_1;i++){
 	     		if(codigo_1==cursos_tot[i].cod_curso){
 	     			cout<<"El curso asignado es:"<<cursos_tot[i].nombre_1;
 	     			cout<<"Nota del primer parcial:"<<tot_asignaciones[i].p_p;
 	     			cout<<"Nota del segundo parcial:"<<tot_asignaciones[i].s_p;
 	     			cout<<"La zona es:"<<tot_asignaciones[i].z;
 	     			cout<<"Nota de examen final:"<<tot_asignaciones[i].ex_f;
 	     			cout<<"Nota final de curso:"<<tot_asignaciones[i].nota_f;
 	     		}
 	     		
 	     	}
 	     }
 }
 
 
 void descar_notas(){
 	FILE*curfile;
 	curfile=fopen("NOTAS.txt","w");
 	for(int i=0;i<pos_asig_1;i++){
 		if(curfile!=NULL){
 			fprintf(curfile,"El codigo del curso:",cursos_tot[i].cod_curso);
 			fprintf(curfile,"numero de carnet:",alum_absolutos[i].carnet);
 			fprintf(curfile,"El nombre de curso asignado:",cursos_tot[i].nombre_1);
 			fprintf(curfile,"Primer parcial:",tot_asignaciones[i].p_p);
 			fprintf(curfile,"Segundo parcial:",tot_asignaciones[i].s_p);
 			fprintf(curfile,"Zona total:",tot_asignaciones[i].z);
 			fprintf(curfile,"Examen final:",tot_asignaciones[i].ex_f);
 			fprintf(curfile,"Nota final:",tot_asignaciones[i].nota_f);
 		}
 	}
 	fclose (curfile);
 	cout<<"Archivo de notas descargado"<<endl;
 }
 
 
int main(){
	system("color 0a");
	fflush(stdin);
	int opcion_de_ingreso;
	while(opcion_de_ingreso!=17){
		system("cls");
		cout<<"MENU DE INFORMACION DE ALUMNOS"<<endl;
		cout<<"------ALUMNOS------"<<endl;
		cout<<"1:  Ingresar alumnos:"<<endl;
		cout<<"2:  Visualizar alumnos"<<endl;
		cout<<"3:  Consultar alumnos"<<endl;
		cout<<"4:  Descargar a archivo .txt de alumnos"<<endl;
		cout<<"------CURSOS------"<<endl;
		cout<<"5:  Ingreso de cursos:"<<endl;
		cout<<"6:  Visualizar cursos"<<endl;
		cout<<"7:  Consultar cursos"<<endl;
		cout<<"8:  Descargar a archivo .txt de cursos"<<endl;
		cout<<"------ASIGNACIONES------"<<endl;
		cout<<"9:  Ingresar asignaciones:"<<endl;
		cout<<"10: Visualizar asignaciones"<<endl;
		cout<<"11: Consultar asignaciones"<<endl;
		cout<<"12: Descargar a archivo .txt de asignaciones"<<endl;
		cout<<"-------NOTAS------"<<endl;
		cout<<"13: Ingreso de notas:"<<endl;
		cout<<"14: Visualizar notas"<<endl;
		cout<<"15: Consultar notas"<<endl;
		cout<<"16: Descargar notas a archivo .txt de notas"<<endl;
		cout<<"17:       SALIDA"<<endl;
		cout<<"<<<ESCOJA UNA OPCION DE LAS ANTERIORES>>>"<<endl;
		cin>>opcion_de_ingreso;
		if(opcion_de_ingreso==1){
		    dt_alumno();
			system("cls");
		}
		if(opcion_de_ingreso==2){
			system("cls");
			visual_alumnos();
		}
		if(opcion_de_ingreso==3){
			system("cls");
			consult_alumnos();
		}
		if(opcion_de_ingreso==4){
			system("cls");
			descar_alumnos();
		}
		if(opcion_de_ingreso==5){
			system("cls");
			ingr_cursos();
		}
		if(opcion_de_ingreso==6){
			system("cls");
			visual_cursos();
		}
		if(opcion_de_ingreso==7){
			system("cls");
			consult_cursos();
		}
		if(opcion_de_ingreso==8){
			system("cls");
			descar_cursos();
		}
		if(opcion_de_ingreso==9){
			system("cls");
			ingr_asig();
		}
		if(opcion_de_ingreso==10){
			system("cls");
			visul_asig();
		}
		if(opcion_de_ingreso==11){
			system("cls");
			consult_asig();
		}
		if(opcion_de_ingreso==12){
			system("cls");
			descar_asig();
		}
		if(opcion_de_ingreso==13){
			system("cls");
			ingr_notas();
		}
		if(opcion_de_ingreso==14){
			system("cls");
			visul_notas();
		}
		if(opcion_de_ingreso==15){
			system("cls");
			consult_notas();
		}
		if(opcion_de_ingreso==16){
			system("cls");
			descar_notas();
		}
		
	}
	getch();
	return 0;
	Sleep(30);
	
}

