//round();四舍五入 返回的是double类型，头文件math
//abs();对整数取绝对值   fabs();对浮点型取绝对值 头文件math 或者 stdlib

//min(a,b) 返回a,b中的较小者，大于两个参数可以多次嵌套使用 头文件algorithm 

//map<string,int> dict 定义映射。赋值的方式：
//1.dict.insert(made_pair("Tom",1)); pair会将Tom映射到1，需要引头文件Utility
//	dict.insert(pair<string,int>("Tom",1));
//2.dict.insert(map<string,int>::value_type("Tom",1));
//3.dict["Tom"] = 1; 第三种方式可以覆盖值
//判断是否生成映射：dict.count("Tom"); 是返回1，否则返回0
//遍历map是按照关键字从小到大遍历的。
//map<string,int>::iterator it

//string 不可以给 char [] 赋值; 但char[]可以给 string 赋值 
//用scanf输入string形式的数据：string a; scanf("%s",&a[0]); 
//弊端：无法使用a.length();a.size();reverse等功能; 用char[]给string赋值则可正常使用
//用printf输出string:  printf("%s",a.c_str()); 
