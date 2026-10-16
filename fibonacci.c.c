int fibonacci(int n){
    if (n<2) {return n;}
    else {return fibonnacci(n-1)+fibonacci(n-2);}
}