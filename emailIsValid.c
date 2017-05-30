bool emailIsValid(char* email){
    int counter = 0;
    while(*email != '\0'){
        if(*email == '@'){
            counter++;
        }
        email++;
    }
    if(counter > 1){
        return false;
    }
    return true;
}

int main() {
    char* email = "haitmoran@gmail.co@m";
    bool is_valid = emailIsValid(email);
    if(is_valid == true){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}