bool isValid(char* s) {
    char stack[10001]; int top = -1;
    
    for(int i = 0; s[i]; i++) {
        char c = s[i];
        
        // Opening → PUSH
        if(c == '(' || c == '[' || c == '{')
            stack[++top] = c;
        
        // Closing → POP + MATCH
        else {
            if(top == -1) return false;  // No opening
            
            char open = stack[top--];
            
            if( (c==')' && open!='(') ||
                (c==']' && open!='[') ||
                (c=='}' && open!='{') )
                return false;  // Wrong match
        }
    }
    
    return top == -1;  // Empty stack = perfect
}
