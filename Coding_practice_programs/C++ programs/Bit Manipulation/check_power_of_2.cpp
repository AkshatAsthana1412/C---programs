
using namespace std;

bool check_power_of_2(unsigned int n){     //only for positive integers <= 2^32 - 1
    if (n == 0){
        return false;
    }
    if (n & (n-1)){
        return false;
    }
    else{
        return true;
    }
}