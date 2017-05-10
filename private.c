#include <stdlib.h>
#include <stdbool.h>
#include "private.h"

static void _set_safe_int(int n,int *p,bool ini);
static int _get_safe_int(int *p,bool ini);
static void new_safe_int(int n);
static void set_safe_int(int n);
static int get_safe_int(void);

prvt_int *new_prvt(int x){
    prvt_int *p=(prvt_int *)malloc(sizeof(prvt_int));

    p->get=get_safe_int;
    p->set=set_safe_int;

    new_safe_int(x);

    return p;
}

void _set_safe_int(int n,int *p,bool ini){
	static int *pv;
	if(ini){
		pv=p;
	}

	*pv=n;
}
int _get_safe_int(int *p,bool ini){
	static int *pv;
	if(ini){
		pv=p;
	}
	return *pv;
}
void new_safe_int(int n){
	static int val;
	_set_safe_int(n,&val,true);
	_get_safe_int(&val,true);
}
void set_safe_int(int n){
	_set_safe_int(n,NULL,false);
}
int get_safe_int(void){
	return _get_safe_int(NULL,false);
}
