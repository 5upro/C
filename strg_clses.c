/* extarnal storage class/variable can also be
 * called as global variable based on it's scope
 * 
 * scope: the whole program, global
 * lifespan: until the program terminition
 * default value: 0
 * memory: data segment
 */
int external_var = 100;
extern int extnl_var;

int func1(){
    /* static storage class/variable can only be 
     * initialized once throughout the whole program 
     * and existes until the terminition of the program 
     * itself but can't be accessed from an another function
     * 
     * scope: the function it is defined in, local 
     * lifespan: until the programs terminition
     * default value: 0
     * memory: data segment
     */
    static int run_count = 0;
    return ++run_count;
}

int main(){
    /* automatic storage class/variables can also be called 
     * as local variable based on it's scope, this type of 
     * variables gets 
     * 
     * scope: the function it is denifined in, local
     * lifespan: until the function's(it is in) terminition
     * default value: garbage
     * memeory: the stack
     */
    int local_var = 5;
    auto int auto_var = 50;
    /* register storage class/variable stores the a value
     * inside of the registers of the CPU instead of memory,
     * though one must keep in mind that shall the compiler
     * fails to allocate any free register at the compile time
     * then, it will allocate memory from stack and convert it
     * into an automatic storage class/variable  
     * 
     * scope: the function it is denifined in, local
     * lifespan: until the function's(it is in) terminition
     * default value: garbage
     * memory: CPU register
    */
    register int reg_var = 10;

    return 0;
}