#include <stdbool.h>
#include <ctype.h>


/**
 * @brief finite automate
 * @perf: 100, 39
 */
// state sequence:      0
// regex:               [ ]?
// expecting:           space           sign            num             point
// next state:          0               3               4               1
bool state_0(char* s, int index);
// state sequence:      01              031
// regex:               [ ]?\.          [ ]?[+-].
// expecting:           num
// next state:          2
bool state_1(char* s, int index);
// state sequence:      1312                    012
// regex:               [ ]?[+-].[0-9]+         \.[0-9]+
// expecting:           num                     space           e
// next state:          2                       9               6
bool state_2(char* s, int index);
// state sequence:      13
// regex:               [ ]?[+-]
// expecting:           num             point
// next state:          4               1
bool state_3(char* s, int index);
// state sequence:      04              034
// regex:               [ ]?[0-9]+      [ ]?[+-][0-9]+
// expecting:           num             point           e               space
// next state:          4               5               6               9
bool state_4(char* s, int index);
// state sequence:      1345                    145
// regex:               [ ]?[+-][0-9]+\.        [ ]?[0-9]+\.
// expecting:           num             e       space
// next state:          8               6       9
bool state_5(char* s, int index);
bool state_6(char* s, int index);
bool state_7(char* s, int index);
bool state_8(char* s, int index);
bool state_9(char* s, int index);
bool state_10(char* s, int index);


bool state_0(char* s, int index){
        while(s[index] == ' ')
                index++;
        char c = s[index];
        if(c == '+' || c == '-')
                return state_3(s, index + 1);
        if(isdigit(c))
                return state_4(s, index + 1);
        if(c == '.')
                return state_1(s, index + 1);
        return false;
}

bool state_1(char* s, int index){
        char c = s[index];
        if(isdigit(c))
                return state_2(s, index + 1);
        return false;
}

bool state_2(char* s, int index){
        while(isdigit(s[index]))
                index++;
        char c = s[index];
        if(c == 'e')
                return state_6(s, index + 1);
        if(c == ' ')
                return state_9(s, index + 1);
        if(c == '\0')
                return true;
        return false;
}

bool state_3(char* s, int index){
        char c = s[index];
        if(isdigit(c))
                return state_4(s, index + 1);
        if(c == '.')
                return state_1(s, index + 1);
        return false;
}

bool state_4(char* s, int index){
        while(isdigit(s[index]))
                index++;
        char c = s[index];
        if(c == '.')
                return state_5(s, index + 1);
        if(c == 'e')
                return state_6(s, index + 1);
        if(c == ' ')
                return state_9(s, index + 1);
        if(c == '\0')
                return true;
        return false;
}

bool state_5(char* s, int index){
        char c = s[index];
        if(isdigit(c))
                return state_8(s, index + 1);
        if(c == 'e')
                return state_6(s, index + 1);
        if(c == ' ')
                return state_9(s, index + 1);
        if(c == '\0')
                return true;
        return false;
}

bool state_6(char* s, int index){
        if(isdigit(s[index]))
                return state_7(s, index + 1);
        if(s[index] == '+' || s[index] == '-')
                return state_10(s, index + 1);
        return false;
}

bool state_7(char* s, int index){
        while(isdigit(s[index]))
                index++;
        char c = s[index];
        if(c == '\0')
                return true;
        if(c == ' ')
                return state_9(s, index + 1);
        return false;
}

bool state_8(char* s, int index){
        while(isdigit(s[index]))
                index++;
        char c = s[index];
        if(c == 'e')
                return state_6(s, index + 1);
        if(c == ' ')
                return state_9(s, index + 1);
        if(c == '\0')
                return true;
        return false;
}

bool state_9(char* s, int index){
        while(s[index] == ' ')
                index++;
        return s[index] == '\0';
}

bool state_10(char* s, int index){
        if(isdigit(s[index]))
                return state_7(s, index + 1);
        return false;
}

bool isNumber(char * s){
        return state_0(s, 0);
}

int main(){
        isNumber("3.");
        return 0;
}
