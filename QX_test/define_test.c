//经典宏定义  
// //下等解法
// #define MAX(x,y)  x > y  ? x : y

// int32_t main(void)
// {
//     printf("max = %d",MAX(1,2));
//     printf("max = %d",MAX(2,1));
//     printf("max = %d",MAX(2,2));
//     printf("max = %d",MAX(1!=1,1!=2));
//     //为什么这一句函数输出的不是1而是0
//     /*因为这个语句拆分打开是这样的
//     printf("max = %d",1!1>1!=2?1!=1:1!=2);
//     因为比较运算符>的优先级是6级 大于！=（优先级位7级）
//     */
//     return 0;
// }



// //中等解法
// #define MAX(x,y)  (x) > (y) ? (x) : (y)

// int main(void){
//     printf("max = %d",3+MAX(1,2));
//     //为什么这个语句输出不是5而是3
//     /*因为这个是语句函数拆开之后就是
//     printf("max =%d",3+(1)>(2)?(1)(2))                                                                       
//     因为运算符+的优先级大于比较运算符>所以这个表达式
//     就变成了4>2?1:2,
//     */
//     return 0;
// }



// //良好解法
// #define MAX(x,y) ((x)>(y))?((x):(y))

// int32_t main(void)
// {
//     int8_t i = 2;
//     int8_t j = 6;
//     printf("max = %d",MAX (i++,j++));
//     /*在程序中，我们定义两个变量i和j，然后比较两个变量的大小
//     ，并做自增运算。实际执行结果max=7， 而不是预期结果max=6，这是
//     因为变量i和j在宏展开后，做了两次自增运算，导致打印出来的i的值为7
//     当然在C语言的规范里，使用宏时一般 时不允许参数变化的
//     */

//     return 0;
// }


// //高等解法
// #define MAX(x,y)({      \
//     int8_t _x = x;      \
//     int8_t _y = y;      \
//     _x > _y ? _x :  _y; \
// })
// /*我们使用数据来表达宏，在语句表达式中定义两个临时变量，分别来展示存储
// i和j的值，然后使用临时变量进行比较，这样就避免了两次自增和自减的问题*/
// int main(void)
// {
//     int8_t i = 2;
//     int8_t j = 6;
//     printf("max = %d",MAX (i++,j++));


// //高等解法优化版本  支持所有类型的数据类型
// #define MAX(type,x,y)({ \
//     type _x = x;\
//     type _y = y;\
//     _x > _y ? _x :_y;\
// })

// int32_t main(void)
// {
//     int8_t i = 2;
//     int8_t j = 6;
//     printf("max =%d\n",MAX(int ,i++ ,j++));
//     printf("max =%f\n",MAX(float,3.14,3.15));
//     return 0;
// }


//终极无敌至尊高等解法

#define MAX(x,y)({\
    typeof(x) _x = (x);\
    typeof(y) _y = (y);\
    /*(void)(&_x == &_y)*/\
    /*这个比较难理解，这句话看起来很多余，仔细分析一下
    你会发现这个语句一共有两个作用，一就是用来给用户提示一个警告，
    对于不同类型的指针比较，编译器会发出一个警告，提示两张数据的类型的不同
    warning：comparison of distinct pointer typers lacks a cast
    二是两个数字进行比较运算，运算结果却没有用到，有些编译器可能会给出
    一个warning加一个（void ）后，就可以消除这个警告l
    */\
    _x > _y ? _x : _y;\    
})


int32_t main(void)
{
    printf("max =%d\n",MAX(9 ,9));
    printf("max =%f\n",MAX(3.14,3.15));
    return 0;
}