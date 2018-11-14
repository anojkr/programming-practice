#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int a[7];

void read_data(){
	FILE *fp = fopen("Student.dat","r");
	for(int i=0; i < 7; i++){
		fread(&a[i],sizeof(int),1,fp);
		//a[i] = a[i];
	}

}

void write_data(){
	for(int i=0; i < 7; i++){
		scanf("%d", &a[i]);
	}
}

void print_write_data(){

	FILE *fp = fopen("Student.dat","w");
	int item;

	for(int i=0; i < 7; i++){
		printf("%d ", a[i]);
		fwrite(&a[i],sizeof(int),1,fp);
	}
}

void print_data(){

	for(int i=0; i < 7; i++){
		printf("%d ", a[i]);	
	}
}

void main(){
	//write_data(&a);
	//print_write_data(&a);
	read_data(&a);
	print_data(&a);
}