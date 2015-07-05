#ifndef MACRODEFINE_H_
#define MACRODEFINE_H_

//�궨�壬��ʵ�궨�岻�������ռ�Լ����ֻ��Ϊ��ͳһ��д��
namespace mdk
{

#ifndef SAFE_FREE
#define SAFE_FREE(p)	{if(p) free(p);p=NULL;}
#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)	{if(p) delete p;p=NULL;}
#endif

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr) {if(ptr){delete []ptr;ptr=NULL;}}
#endif

//�򵥵�ʵ��
#ifndef SYNTHESIZE
#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: virtual varType get##funName(void) const { return varName; }\
public: virtual void set##funName(varType var){ varName = var; }
#endif

};
#endif //MACRODEFINE_H_
