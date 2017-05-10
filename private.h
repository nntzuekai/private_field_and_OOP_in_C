#ifndef PRIVATE_H_INCLUDED
#define PRIVATE_H_INCLUDED
#include <stdbool.h>

#define prvt_type(type,X)  prvt_##type_##X

#define def(type,X) \
	static void _set_##type_##X(type val,type *p,bool ini){	\
		static type *pv;	\
		if(ini){	\
			pv=p;	\
		}	\
		*pv=val;	\
	}	\
	static type _get_##type_##X(type *p,bool ini){	\
		static type *pv;	\
		if(ini){	\
			pv=p;	\
		}	\
		return *pv;	\
	}	\
	static void _new_##type_##X(type n){	\
		static type val;	\
		_set_##type_##X(n,&val,true);	\
		_get_##type_##X(&val,true);	\
	}	\
	static void set_##type_##X(type val){	\
		_set_##type_##X(val,NULL,false);	\
	}	\
	static type get_##type_##X(void){	\
		return _get_##type_##X(NULL,false);	\
	}	\
	typedef struct _prvt_##type_##X{		\
		void (*new)(type val);	\
		void (*set)(type val);	\
		type (*get)(void);	\
	}prvt_##type_##X;	\
	prvt_##type_##X X={_new_##type_##X,set_##type_##X,get_##type_##X};	\

#endif // PRIVATE_H_INCLUDED
