#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define _GNU_SOURCE
float choose(float expr1,float expr2,float expr3,float expr4) ;
float choose(float expr1,float expr2,float expr3,float expr4){
    if (expr1 == 0) {
        return expr2 ;
    }
    else if (expr1 > 0 ){
        return expr3 ;
    }
    else {
        return expr4 ;
    }
}
/* This Code taken from https://stackoverflow.com/questions/4770985/how-to-check-if-a-string-starts-with-another-string-in-c 
to check a string starts with another string
*/
bool startsWith(const char *pre, const char *str)
{
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? false : memcmp(pre, str, lenpre) == 0;
}
int is_scalar(char *param_string){
    if(startsWith("choose(",param_string)){
        /*DOĞUKAN iki kere kontrol edebilir miyim bilemedim bir daha gelirse , delimeterları da yetmez*/
        return 1;
    }
    else if(startsWith("sqrt(",param_string)){
        char *cpy_param;
        strcpy(cpy_param,param_string);
        memmove(cpy_param, cpy_param+5, strlen(cpy_param) - 5 + 1);
        cpy_param[strlen(cpy_param)-1] = '\0';
        return is_scalar(cpy_param);
    }
    else if(startsWith("{",param_string)){
        return 0;
    }
    else{
        return 1;
    }
}

char* for_parse(char *param_string){
    char return_str[500];
    char cpy_param[256];
    memset(cpy_param, '\0', sizeof(cpy_param));
    strcpy(cpy_param,param_string);

    char *parantheses_index = strstr(param_string, "(");
    int len_first_parantheses = parantheses_index-param_string;
    memmove(cpy_param, cpy_param+len_first_parantheses+1, strlen(cpy_param) - len_first_parantheses + 1 );

    char *in_index = strstr(cpy_param, " in ");
    char declaration_part[256];
    memset(declaration_part, '\0', sizeof(declaration_part));
    int len_declaration_part = in_index-cpy_param;
    strncpy(declaration_part, cpy_param, len_declaration_part) ;
    memmove(cpy_param, cpy_param+len_declaration_part, strlen(cpy_param) - len_declaration_part + 1);

    int c = 0;
    int is_nested = 0;
    while (declaration_part[c]!='\0'){
        if(declaration_part[c]==','){
            is_nested = 1;
        }
        c++;
    } 
    if(is_nested == 0){
        char *first_index = strchr(cpy_param,':');
    char initilization_part[256];
    memset(initilization_part, '\0', sizeof(initilization_part));
    int len_initilization_part = first_index-cpy_param;
    strncpy(initilization_part, cpy_param+4, len_initilization_part-4) ;
    memmove(cpy_param, cpy_param+len_initilization_part+1, strlen(cpy_param) - len_initilization_part  );

    char *second_index = strchr(cpy_param,':');
    char upper_bound_part[256];
    memset(upper_bound_part, '\0', sizeof(upper_bound_part));
    int len_upper_bound_part = second_index-cpy_param;
    strncpy(upper_bound_part, cpy_param, len_upper_bound_part) ;
    memmove(cpy_param, cpy_param+len_upper_bound_part+1, strlen(cpy_param) - len_upper_bound_part +1);

    char *third_index = strrchr(cpy_param,')');
    char incremention_part[256];
    memset(incremention_part, '\0', 256);
    int len_incremention_part = third_index-cpy_param;
    strncpy(incremention_part, cpy_param, len_incremention_part) ;
        sprintf(return_str,"for(int %s=%s;i<%s;i+=%s){",declaration_part,initilization_part,upper_bound_part,incremention_part);
    
    }

    else{
    char* declaration_part_one;
    char* declaration_part_two = strtok(declaration_part,',');
    declaration_part_one = declaration_part_two;
    declaration_part_two = strtok(NULL, ',');

    char *first_index = strchr(cpy_param,':');
    char initilization_part[256];
    memset(initilization_part, '\0', sizeof(initilization_part));
    int len_initilization_part = first_index-cpy_param;
    strncpy(initilization_part, cpy_param+4, len_initilization_part-4) ;
    memmove(cpy_param, cpy_param+len_initilization_part+1, strlen(cpy_param) - len_initilization_part  );

    char *second_index = strchr(cpy_param,':');
    char upper_bound_part[256];
    memset(upper_bound_part, '\0', sizeof(upper_bound_part));
    int len_upper_bound_part = second_index-cpy_param;
    strncpy(upper_bound_part, cpy_param, len_upper_bound_part) ;
    memmove(cpy_param, cpy_param+len_upper_bound_part+1, strlen(cpy_param) - len_upper_bound_part +1);

    char *third_index = strchr(cpy_param,',');
    char incremention_part[256];
    memset(incremention_part, '\0', sizeof(incremention_part));
    int len_incremention_part = third_index-cpy_param;
    strncpy(incremention_part, cpy_param, len_incremention_part) ;
    memmove(cpy_param, cpy_param+len_incremention_part+1, strlen(cpy_param) - len_upper_bound_part +1);


    char *fourth_index = strchr(cpy_param,':');
    char initilization_part_2[256];
    memset(initilization_part_2, '\0', sizeof(initilization_part_2));
    int len_initilization_part_2 = fourth_index-cpy_param;
    strncpy(initilization_part_2, cpy_param, len_initilization_part_2) ;
    memmove(cpy_param, cpy_param+len_initilization_part_2+1, strlen(cpy_param) - len_initilization_part_2  );

    char *fifth_index = strchr(cpy_param,':');
    char upper_bound_part_2[256];
    memset(upper_bound_part_2, '\0', sizeof(upper_bound_part_2));
    int len_upper_bound_part_2 = fifth_index-cpy_param;
    strncpy(upper_bound_part_2, cpy_param, len_upper_bound_part_2) ;
    memmove(cpy_param, cpy_param+len_upper_bound_part_2+1, strlen(cpy_param) - len_upper_bound_part +2);

    char *sixth_index = strrchr(cpy_param,')');
    char incremention_part_2[256];
    memset(incremention_part_2, '\0', sizeof(incremention_part_2));
    int len_incremention_part_2 = sixth_index-cpy_param;
    strncpy(incremention_part_2, cpy_param, len_incremention_part_2) ;
    memmove(cpy_param, cpy_param+len_incremention_part_2+1, strlen(cpy_param) - len_upper_bound_part_2 +1);
    sprintf(return_str,"for(int %s=%s;i<%s;i+=%s){\nfor(int %s=%s;i<%s;i+=%s){",declaration_part_one,initilization_part,upper_bound_part,incremention_part,declaration_part_two,initilization_part_2,upper_bound_part_2,incremention_part_2);
    }
        return return_str;

    /*memmove(cpy_param, cpy_param+len_incremention_part, strlen(cpy_param) - len_incremention_part +2);*/
}




char* remove_spaces(char *param_string){
    char cpy_param[256];
    memset(cpy_param, '\0', 256);
    int j = 0;
     for(int i=0;i<256;i++){
            if(param_string[i]=='\0'){
                break;
            }
           if(param_string[i] == ' '){
               continue;
           }
           cpy_param[j] = param_string[i];
           j++;
       }

       return cpy_param;
}

char* replace_braces(char *param_string){
    char cpy_param[256];
    memset(cpy_param, '\0', 256);
    int brace_strated = 0;
    int j = 0;
    for(int i=0;i<256;i++){
        if(param_string[i]=='\0'){
            break;
        }
        if(brace_strated == 0){
            cpy_param[j] = param_string[i];
            if(cpy_param[i]=='['){
                brace_strated = 1;
            }
        }
       else if(brace_strated == 1){
           
           if(param_string[i] != ','){
                cpy_param[j] = param_string[i];
           }
           else{
                cpy_param[j] = '-';
                j++;
                cpy_param[j] = '1';
                j++;
                cpy_param[j] = ']';
                j++;
                cpy_param[j] = '[';
           }
           if(param_string[i] == ']'){
               brace_strated = 0;
                cpy_param[j] = '-';
                j++;
                cpy_param[j] = '1';
                j++;
                cpy_param[j] = ']';
           }
       }
       j++;
    }
    return cpy_param;
}

int main(int argc, char* argv[])
{
//read any text file from currect directory

char const* const fileName = "cmpe230test.txt";
 FILE *fp;

   fp = fopen("cmpe230write.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fputs("float choose(float expr1,float expr2,float expr3,float expr4) ; \n" ,fp);
   fputs("float choose(float expr1,float expr2,float expr3,float expr4) { \n" ,fp);
   fputs("   if (expr1 == 0) { \n return expr2 ; \n { \n" ,fp);   
   fputs(" else if (expr1 > 0 ){ \n return expr3 ; \n } \n" ,fp);
   fputs("else { \n return expr4 ; \n } \n } \n",fp);

FILE* file = fopen(fileName, "r"); 

char delim[] = " ";

if(!file){
printf("\n Unable to open : %s ", fileName);
return -1;
}



char line[500];
char vars[256][256];
int size1[256];
int size2[256];
bool isassigned[256];
char scalars[256][256];
bool isscalarfloat[256]; // added
bool isvarfloat[256];  // added
int varcount = 0 ;
int linecount = 0 ;
int scalarcount = 0 ;
while (fgets(line, sizeof(line), file)) {
  line[sizeof(line)-1] = 0;
  char thisline[500]; // string of iterated line, stable

  memcpy(thisline, line, sizeof(line));

  char *ptr = strtok(line, delim);
  char types[8];
  strncpy(types,thisline,7);
  types[7] = 0; 

  bool definition = (strstr("scalar ",types) || strstr("vector ",types) || strstr("matrix ",types)) ; // true if line is a definition line
  bool assignment = (strstr( thisline, "{") && strstr(thisline, "}"));  // true if line is a matrix or vector
  bool hascomments = (strstr(thisline, "#"));
  bool isscalardef = (strcmp(ptr,"scalar") == 0);
  bool isfloat = (strstr(thisline,"."));
/*
  printf("---- \n") ;
  printf(types);
  printf("%d\n",definition);
*/
  bool addline = true ;
    while(ptr != NULL)
    {
      if ( strcmp("scalar",ptr) == 0 && isscalardef){  // case: scalar definition
        fputs("float ", fp);  // changed from int to float
      }

      else if(strstr(thisline, "[") && definition ){ // case non-scalar definition
        ptr = strtok(NULL, delim);
        fputs("float " , fp) ;
        if (strstr(thisline, ",")){ // case 2d array definition

          char *comma;
          int commaindex;
          char *bracket;
          int bracketindex;  

          comma = strchr(ptr, ',');
          commaindex = (int)(comma - ptr);

          bracket = strchr(ptr, '[');
          bracketindex = (int)(bracket - ptr);

          char firstdimension[256];
          strncpy(firstdimension, &ptr[bracketindex+1], commaindex-bracketindex-1) ;
          char varname[256];
          strncpy(varname,ptr,bracketindex);
          varname[bracketindex] = 0;
         // fputs(varname,fp);
          firstdimension[commaindex-bracketindex-1] = 0 ;
        // printf (firstdimension) ;

        //  fputs(firstdimension,fp); 

          int len = strlen(ptr) ;

          char seconddimension[256]  ;
          strncpy(seconddimension,&ptr[commaindex+1], strlen(ptr)- commaindex -3);
          seconddimension[strlen(ptr)- commaindex -3] = 0;
        //  fputs(seconddimension,fp ) ;
          
          strncpy(vars[varcount], varname, strlen(varname));
          printf("\n\n\n");
        
          size1[varcount] = atoi(firstdimension);
          size2[varcount] = atoi(seconddimension);  
          int numofelements = size1[varcount] * size2[varcount];
          int zeros;
          fputs(varname, fp);
          fputs("[" ,fp);
          fputs(firstdimension, fp);
          fputs("][" , fp);
          fputs(seconddimension,fp);
          fputs("] = ", fp);
          fputs("{", fp) ;
          for (zeros = 0 ; zeros < numofelements -1 ; zeros++  ){
            fputs(" 0.0 , ", fp);
          }
          fputs("0.0 }",fp) ;
          varcount = varcount + 1 ;

          break ;
        }
        else {  // case 1d array definition

          char *e;
          int index;
          e = strchr(ptr, '[');
          index = (int)(e - ptr);
          char varname[256];
          strncpy(varname,ptr,index);
          varname[index] = 0;
          strcpy(vars[varcount],varname);
        //  fputs(varname,fp);
          int len = strlen(ptr)  ;
          char vectorsize[256];
          strncpy(vectorsize,&ptr[index+1],len-index-3);
          int vectsizeint = atoi(vectorsize);
          size1[varcount] = vectsizeint ;
          size2[varcount] = 1;
        //  fputs(vectorsize,fp);
          int numofelements = size1[varcount] * size2[varcount];
          int zeros;
          fputs(varname, fp);
          fputs("[ " ,fp);
          fputs(vectorsize, fp);
          fputs("][" , fp);
          fputs("1",fp);
          fputs( "] = ", fp);
          fputs("{", fp) ;
          for (zeros = 0 ; zeros < numofelements -1 ; zeros++  ){
            fputs(" 0.0 , ", fp);
          }
          fputs("0.0 }",fp) ;
          varcount = varcount + 1 ;
          break;
        }

      }
      else if (assignment){  // case assign vector or matrix
          int i ;
            

           
          for(i = 0; i < varcount; ++i)
          {
              if(!strcmp(vars[i], ptr))
              {
                if(!isfloat) {  // added
                  isvarfloat[i] == false;  // added
                } // added
                fputs(vars[i],fp);
             
                fputs(" = {",fp);

                char *e;
                int index;
                e = strchr(thisline, '{');
                index = (int)(e - thisline);
                char *end;
                end = strchr(thisline, '}');
                int endindex ;
                endindex  = (int)(end-thisline); 
                char nums[256];
                strncpy(nums,&thisline[index+1], endindex - index-1 );



                char *commaptr = strtok(nums,delim);

                int numofelements = size1[i] * size2[i];
                int elementcounter = 0 ;
                isassigned[i] = true ; // added
                while (commaptr != NULL){
                  elementcounter = elementcounter + 1 ;
                  if (elementcounter<numofelements){
                    fputs(commaptr,fp);
                    fputs (",",fp);
                  }
                  if (elementcounter == numofelements){
                    fputs(commaptr,fp);
                  }
                  commaptr = strtok(NULL,delim);
                }
                //fputs(nums,fp);
                fputs("}",fp);
                break;
              }
          }
          break;
      }
      else if (strstr(ptr,"printsep()")) { // case printsep
        fputs("printf(\"------------\n\")",fp);
      }
      else {
        if (strstr(thisline, "{") && assignment){ // case not used

          break; 
          char *e;
          int index;
          e = strchr(ptr, '{');
          index = (int)(e - ptr);

          char allelements [256];
          strncpy(allelements,thisline,index);
          fputs("float",fp);
          fputs(ptr,fp) ;
          fputs(" = ", fp);
          char *elementptr = strtok(allelements, delim);
            
          while(elementptr != NULL)
      {
          fputs(ptr,fp);
          fputs(",",fp);
          elementptr = strtok(NULL,delim);
      }
          break ;
        }
        else {
          if (isscalardef){ // case scalar initialize to 0 
            strncpy(scalars[scalarcount], ptr, strlen(ptr));
            isscalarfloat[scalarcount] = true ;
            scalarcount = scalarcount + 1 ; 
            fputs(ptr,fp); 
            fputs( " = 0", fp);

          }
          else {
                if(startsWith("for(",thisline)){
                    char* t = for_parse(thisline);
                    if(strchr(t,'\n')){
                        int a = 2;
                    }
                        fputs(t,fp);
                }   
                else{

              char temp[500];
              sprintf(temp,"%s;",replace_braces(thisline));
                printf("%s\n",replace_braces(thisline));
                fputs(temp,fp);
                }
              
                        
            fputs("bad choice \n",fp);
          }
          break;
        }

      }
      fputs(" ",fp); 

      ptr = strtok(NULL, delim); // get new token
    }
    if (addline){
    fputs(";\n",fp);
    } // end of line
  }

fclose(file);
fclose(fp);


return 0;
}

    
