#include<stdio.h>
#include"234.h"
void main()
{
	puts("hello world!");
	pairing_t pairing;
	init_pairing(pairing);
	t g1;
	G1(g1,pairing);
	t g2;
	G1(g2,pairing);
	t a,b;
	Zr(a,pairing);
	Zr(b,pairing);

	t g1_A,g2_A,g1_B,g2_B;
	G1(g1_A,pairing);
	G1(g2_A,pairing);
	G1(g1_B,pairing);
	G1(g2_B,pairing);
	element_pow_zn(g1_A,g1,a);
	element_pow_zn(g2_B,g2,b);

	element_pow_zn(g1_B,g1,b);
	element_pow_zn(g2_A,g2,a);
	
	t left,right;
	GT(left,pairing);
	GT(right,pairing);
	element_pairing(left,g1_A,g2_B);
	element_pairing(right,g2_A,g1_B);

	puts("e(g1^a,g2^b)=");
	element_printf("%B\n",left);
	puts("e(g1^b,g2^a)=");
	element_printf("%B\n",right);
	
	if(!element_cmp(left,right))
		puts("Succeed!");
	else
		puts("Verify failed!");
	
	double TimeRecord;
	TimeRecord=pbc_get_time();
	element_pairing(left,g1_A,g1_B);
	element_pairing(right,g2_A,g2_B);
	TimeRecord=pbc_get_time()-TimeRecord;


	puts("e(g1^a,g1^b)=");
	element_printf("%B\n",left);
	puts("e(g2^b,g2^a)=");
	element_printf("%B\n",right);

	if(!element_cmp(left,right))
		puts("Succeed!");
	else
		puts("Verify failed!");

	printf("The pairing time is %.3f ms.\n",TimeRecord*1000/2);

	helloworld();
}
