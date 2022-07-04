typedef struct stack{
    char *s;
    int size;
    int topIndex;
}stack;


void push(stack *destStack, char element)
{
    destStack->s[destStack->topIndex+1] = element;
    destStack->topIndex++;
}

char pop(stack *destStack)
{
    char element;
    if(destStack->topIndex != -1)
    {
        element = destStack->s[destStack->topIndex];
        destStack->s[destStack->topIndex] = '\0';
        destStack->topIndex--;
    }
    
    return element;
    
}


bool isValid(char * s){
    
    int len = strlen(s);
    
    if(len % 2 != 0)
        return 0;
    
    stack *bracketStack = (stack*)malloc(sizeof(stack));
    bracketStack->size = len;
    bracketStack->s = (char*)malloc(len*sizeof(char));
    bracketStack->topIndex = -1;
    
    
    char sent;
    int topIndex;
    
    for(int i=0; i<len; i++)
    {
        sent = s[i];
        topIndex = bracketStack->topIndex;
        if(i == 0 && (sent == ')' || sent == '}' || sent == ']'))
           return false;
        else if(sent == ')' || sent == '}' || sent == ']')
        {
            if(topIndex == -1)
                return false;
            
            if(bracketStack->s[topIndex] == '(' && sent == ')')
            {
                pop(bracketStack);
            }
            else if(bracketStack->s[topIndex] == '{' && sent == '}')
            {
                pop(bracketStack);
            }
            else if(bracketStack->s[topIndex] == '[' && sent == ']')
            {
                pop(bracketStack);  
            }
            else
                return false;
        }
        else if(sent == '(' || sent == '{' || sent == '[')
        {
            push(bracketStack, sent);
        }
    }
    
    if(bracketStack->topIndex == -1)
        return true;
    else
        return false;
    
}