/**
 * @brief 0ms, 75
 * 
 * @param str 
 * @return char* 
 */
char* _1(char* str){
        int diff = 'a' - 'A';
        char* ret = str;
        while(*str != '\0'){
                if(*str >= 'A' && *str <= 'Z')
                        *str += diff;
                ++str;
        }
        return ret;
}

char * toLowerCase(char * str){
        return _1(str);
}
